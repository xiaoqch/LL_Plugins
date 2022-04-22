#include "pch.h"
#include "OperationAgentCommand.h"
#include "AgentManager.h"
#include <MC/Level.hpp>
#include <EventAPI.h>
#include <map>
#include <sstream>
#include <string>
#include <ScheduleAPI.h>
#include <filesystem>

void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        OperationAgentCommand::setup(*ev.mCommandRegistry);
        return true;
        });
    if (Config::autoRideWhenJoin) {
        Event::PlayerJoinEvent::subscribe([](Event::PlayerJoinEvent const& ev)->bool {
            auto& manager = AgentManager::getManager();
            Player* player = ev.mPlayer;
            if (player == nullptr)
                return true;

            auto& playerUID = player->getUniqueID();
            auto mountsUIDOpt = manager.tryGetRideData(playerUID);
            if (!mountsUIDOpt.set)
                return true;
            auto& mountsUID = mountsUIDOpt.val();
            Schedule::delay([playerUID, mountsUID]() {
                auto& manager = AgentManager::getManager();
                Player* player = getPlayer(playerUID);
                if (player == nullptr) {
                    return;
                }
                Actor* mounts = getActor(mountsUID);
                if (mounts != nullptr) {
                    player->startRiding(*mounts);
                    std::cout << "玩家" << getActorDescription(player) << "上线自动骑乘" << std::endl;
                }
                else {
                    std::cout << "没找到骑乘目标，清除玩家" << getActorDescription(player) << "自动骑乘数据" << std::endl;
                    manager.removeAgent(player);
                }
                }, 100);
            return true;
            });
    }
}

// 如果实体类型为玩家，发送消息，否则，记录到控制台
void sendTextOrLog(Actor* actor, std::string text) {
    if (actor->isPlayer()) {
        ((Player*)actor)->sendText(text);
    }
    else {
        logger.info("{} <- {}", getActorDescription(actor), text);
    }
}

// ===== onSpawnProjectile =====
THook(Actor*, "?spawnProjectile@Spawner@@QEAAPEAVActor@@AEAVBlockSource@@AEBUActorDefinitionIdentifier@@PEAV2@AEBVVec3@@3@Z",
    void* _this, BlockSource* bs, ActorDefinitionIdentifier* adi, Actor* spawner, const Vec3* pos, Vec3* direct) {
    if (!Config::forProjectile) {
        return original(_this, bs, adi, spawner, pos, direct);
    }
    if (Config::useNewProjectMode) {
        auto master = AgentManager::tryGetMaster(spawner);
        if (master != nullptr) {
            sendTextOrLog(spawner, "代理" + getActorDescription(master) + "投掷");
            auto mpos = &master->getPosition();
            return original(_this, bs, adi, master, mpos, direct);
        }
        return original(_this, bs, adi, spawner, pos, direct);
    }
    Actor* proj = original(_this, bs, adi, spawner, pos, direct);
    if (!proj||!spawner) {
        return proj;
    }
    if (auto master = AgentManager::tryGetMaster(spawner)) {
        auto& masterUID = master->getUniqueID();
        auto& projUID = proj->getUniqueID();
        Schedule::delay([projUID, masterUID]() { // 延迟以防止投掷物伤害投掷的实体
            Actor* tempProj = getActor(projUID); // 延迟后重新获取
            if (tempProj != nullptr) {
                tempProj->setOwner(masterUID);
            }
            }, 1);
        //auto master = getMasterOrNull(spawner);
        if (master) {
            sendTextOrLog(spawner, "代理" + getActorDescription(master) + "投掷");
        }
        else {
            AgentManager::getManager().removeAgent(master);
            sendTextOrLog(spawner, "获取被代理实体失败，清除该代理");
        }
    }
    return proj;
}

// ===== Mob::startRiding =====
THook(bool, "?startRiding@Mob@@UEAA_NAEAVActor@@@Z", Mob* _this, Actor* actor) {
    if (!Config::forRide) 
        return original(_this, actor);

    auto master = AgentManager::tryGetMaster(_this);
    if (master != nullptr) {
        auto& manager = AgentManager::getManager();
        string msg = "代理" + getActorDescription(master) + "骑乘";
        if (master->isPlayer()) {
            master->teleport(actor->getPosition(), actor->getDimensionId());
            manager.setRideData((Player*)master, actor);
        }
        if (Config::cancelAfterRide) {
            msg += "，并取消代理设置";
            manager.removeAgent(_this);
        }
        sendTextOrLog(_this, msg);
        return original(master, actor);
    }
    return original(_this, actor);
}

// ===== startSleepInBed =====
THook(bool, "?startSleepInBed@Player@@UEAA?AW4BedSleepingResult@@AEBVBlockPos@@@Z",
    Player* player, BlockPos* bpos) {
    if (!Config::forSleep) {
        return original(player, bpos);
    }
    auto master = AgentManager::tryGetMaster(player);
    auto& manager = AgentManager::getManager();
    if (master && !master->isSleeping()) {
        // 传送以防止假人掉到底下方块里，假人客户端的问题
        Vec3 aboveBed = { bpos->x + 0.5f, bpos->y + 2.0f, bpos->z + 0.5f };
        master->teleport(aboveBed, player->getDimensionId());
        auto rtn = original(master, bpos);
        manager.setSleepData(master, *bpos);
        string msg = "代理" + getActorDescription(master) + "睡觉";
        if (master->isSleeping()) {
            msg += "成功，并设置自动睡觉位置";
        }
        else {
            msg += "失败，但已设置自动睡觉位置";
        }
        sendTextOrLog(player, msg);
        if (Config::cancelAfterSleep) {
            sendTextOrLog(player, "已取消代理设置");
            manager.removeAgent(player);
        }
        return rtn;
    }

    // 让所有已设置过自动睡觉的玩家睡觉
    auto rtn = original(player, bpos);
    if (!Config::autoSleep || !player->isSleeping()) {
        return rtn;
    }

    for (auto playerIter : Level::getAllPlayers()) {
        if (playerIter->isSleeping())
            continue;
        auto bposOpt = manager.tryGetSleepData(playerIter);
        if (!bposOpt.set)
            continue;
        BlockPos pbpos = bposOpt.val();
        // 传送以防止假人掉到底下方块里，假人客户端的问题
        Vec3 aboveBed = { pbpos.x + 0.5f, pbpos.y + 2.0f, pbpos.z + 0.5f };
        playerIter->teleport(aboveBed, player->getDimensionId());
        original(playerIter, &pbpos);
        if (!playerIter->isSleeping()) {
            manager.removeAgent(playerIter);
            std::cout << playerIter->getNameTag() << "自动睡觉失败，已移除床坐标数据" << std::endl;
        }
    }
    return rtn;
}

// ===== attack =====
THook(bool, "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
    Player* player, Actor* actor, int* damageCause) {
    if (!Config::forAttack) {
        return original(player, actor, damageCause);
    }
    auto master = AgentManager::tryGetMaster(player);
    if (master) {
        if (Config::autoSwapAttack && master == actor) {
            sendTextOrLog(player, "代理" + getActorDescription(master) + "攻击" + CommandUtils::getActorName(*player));
            return original(master, player, damageCause);
        }
        else {
            sendTextOrLog(player, "代理" + getActorDescription(master) + "攻击" + CommandUtils::getActorName(*actor));
            return original(master, actor, damageCause);
        }
    }
    return original(player, actor, damageCause);
}

// ===== Player::move =====
//THook(void, "?move@Player@@UEAAXAEBVVec3@@@Z", Player* player, Vec3* v3) {
//    if (!Config::forMove) {
//        return original(player, v3);
//    }
//    auto master = AgentManager::tryGetMaster(player);
//    if (master != nullptr) {
//        sendTextOrLog(player, "代理" + getActorDescription(master) + "移动");
//        auto mpos = (Vec3&)master->getStateVector();
//        logger.info(mpos.toString());
//        Vec3 dst = mpos + *v3 + Vec3{0.0f,-1.619996f,0.0f};
//        master->teleport(dst, master->getDimensionId());
//    }
//    return original(player, v3);
//}
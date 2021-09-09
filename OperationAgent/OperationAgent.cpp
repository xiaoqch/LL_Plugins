#include "pch.h"
#include "loader/Loader.h"
#include "SymHelper.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "seh_exception.hpp"
#include "JsonHelper.h"
#include "mc/OffsetHelper.h"
#include "ScheduleHelper.h"


const std::string HELP_TEXT_FOR_PLAYER = "\
[操作代理] 帮助\n\
注：方括号为可选参数，默认值为当前玩家\n\
opagent help                      // 显示帮助信息\n\
opagent set 被代理实体 [操作实体] // 设置操作代理\n\
opagent list                      // 列出当前代理设置，格式：操作实体 -> 被代理实体\n\
opagent clear [操作实体]          // 清除某（些）实体的代理设置\n\
opagent clearall                  // 清除所有实体的代理设置，效果同opagent clear @e";
const std::string HELP_TEXT = "\
[操作代理] 帮助\n\
注：方括号为可选参数，默认值为当前玩家\n\
opagent set 被代理实体 [操作实体] - 设置代理\n\
opagent list - 列出当前代理\n\
opagent clear [操作实体] - 清除代理\n\
opagent clearall - 清除所有\n\
";

std::map<long long, long long> agentMap;

bool autoClean = true;
bool cancelAfterSleep = true;
bool cancelAfterRide = true;
bool autoSleep = true;
bool autoRideWhenJoin = true;
bool useNewProjectMode = true;
bool forProjectile = true;
bool forAttack = true;
bool forSleep = true;
bool forMove = false;
bool forRide = true;

// 如果实体类型为玩家，发送消息，否则，记录到控制台
void sendTextOrLog(Actor* actor, std::string text) {
	if (isPlayer(actor)) {
		sendPlayerText((Player*)actor, text);
	}
	else {
		std::cout << getActorDescription(actor) << " <- " << text << std::endl;
	}
}

bool hasMaster(Actor* actor) {
	return actor && agentMap.size() > 0 && agentMap.end() != agentMap.find(actor->getUniqueID().id);
}
ActorUniqueID getMasterUID(Actor* agent) {
	ActorUniqueID agentUID = agent->getUniqueID();
	return ActorUniqueID(agentMap[agentUID.id]);
}
Player* getMaster(Player* agent) {
	return getPlayerByAUID(getMasterUID(agent));
}
Mob* getMaster(Mob* agent) {
	return getMobByAUID(getMasterUID(agent));
}
Actor* getMaster(Actor* agent) {
	return getActorByAUID(getMasterUID(agent));
}
template<typename T>
T getMasterOrNull(T agent) {
	if (!hasMaster(agent)) {
		return nullptr;
	}
	T master = getMaster(agent);
	if (autoClean && !master) {
		agentMap.erase(agent->getUniqueID().id);
		sendTextOrLog(agent, "获取被代理实体失败，清除代理");
	}
	return master;
}

bool deleteAgent(long long auid) {
	auto k = agentMap.find(auid);
	if (k != agentMap.end()) {
		agentMap.erase(k);
		return true;
	}
	return false;
}
bool deleteAgent(Actor* actor) {
	if (!actor)
		return false;
	return deleteAgent(actor->getUniqueID().id);
}

enum class AGENT_SET : int { set = 1 };
bool oncmd_agentSet(CommandOrigin const& ori, CommandOutput& outp,
	MyEnum<AGENT_SET>& op, CommandSelector<Actor>& masterSel,
	optional<CommandSelector<Actor>>& agentSel) {
	Actor* master;
	Actor* agent;
	auto masterRes = masterSel.results(ori);
	if (masterRes.count() != 1) {
		outp.addMessage("只能设置一个被代理实体");
		return false;
	}
	master = *masterRes.begin();
	if (agentSel.set) {
		auto agentRes = agentSel.val().results(ori);
		if (agentRes.count() != 1) {
			outp.addMessage("只能设置一个代理实体");
			return false;
		}
		agent = *agentRes.begin();
	}
	else {
		agent = ori.getEntity();
		if (agent == nullptr) {
			outp.addMessage("控制台执行时必须设置代理实体");
			return false;
		}
	}
	agentMap[agent->getUniqueID().id] = master->getUniqueID().id;
	outp.addMessage("代理设置成功");
	outp.addMessage(getActorDescription(agent) + " -> " + getActorDescription(master));
	return true;
}

enum class AGENT_WITH_ONE_ARG : int { clear = 1, query = 2 };
bool oncmd_agentOperate1(CommandOrigin const& ori, CommandOutput& outp,
	MyEnum<AGENT_WITH_ONE_ARG>& op,
	optional<CommandSelector<Actor>>& agent) {
	switch (op.val)
	{
	case AGENT_WITH_ONE_ARG::clear:
		if (agent.set) {
			int count = 0;
			auto res = agent.val().results(ori);
			for (auto actor : res) {
				count += deleteAgent(actor);
			}
			switch (count) {
			case 0:
				outp.addMessage("没有需要清除的代理设置");
				return false;
			case 1:
				outp.addMessage("清除了 " + (*res.begin())->getNameTag() + " 的代理");
				return true;
			default:
				outp.addMessage("清除了 " + std::to_string(count) + " 个代理");
				return true;
			}
		}
		else { // 没有输入实体，默认为执行指令的实体
			Actor* entity = ori.getEntity();
			if (deleteAgent(entity)) {
				outp.addMessage("清除代理成功");
				return true;
			}
			else if (ori.getOriginType() != OriginType::Player && ori.getOriginType() != OriginType::Actor) {
				outp.addMessage("控制台执行时必须选择需要清除的代理");
				return false;
			}
			else {
				outp.addMessage("没有需要清除的代理设置");
				return false;
			}
		}
		break;
	case AGENT_WITH_ONE_ARG::query: {
		Actor* actor = nullptr;
		if (agent.set) {
			auto res = agent.val().results(ori);
			if (res.count() == 1) {
				actor = *res.begin();
			}
		}
		else {
			actor = ori.getEntity();
		}
		if (!actor) {
			outp.addMessage("此指令需要且仅允许输入一个实体");
			return false;
		}
		auto master = getMaster(actor);
		if (!master) {
			outp.addMessage("" + getActorDescription(actor) + " 没有设置任何代理");
		}
		else {
			outp.addMessage("" + getActorDescription(actor) + " -> " + getActorDescription(master));
		}
		break;
	}
	default:
		break;
	}
	return true;
}

enum class AGENT_WITHOUT_ARG : int {
	help = 1,
	list = 2,
	clearall = 3,
	version = 4
};
bool oncmd_agentOthers(CommandOrigin const& ori, CommandOutput& outp, MyEnum<AGENT_WITHOUT_ARG>& op) {
	switch (op.val) {
	case AGENT_WITHOUT_ARG::help:
		if (ori.getOriginType() == OriginType::Player) {
			outp.addMessage(HELP_TEXT_FOR_PLAYER);
		}
		else {
			outp.addMessage(HELP_TEXT);
		}
		return true;
		break;
	case AGENT_WITHOUT_ARG::list:
		outp.addMessage("代理列表(Agent->Master):  ");
		for (auto it = agentMap.begin(); it != agentMap.end(); ++it) {
			auto agent = getActorByAUID((*it).first);
			auto master = getActorByAUID((*it).second);
			if (agent == nullptr || master == nullptr) {
				agentMap.erase((*it).first);
			}
			else {
				std::string strAgent = getActorDescription(agent);
				std::string strMaster = getActorDescription(master);
				outp.addMessage(strAgent + " -> " + strMaster);
			}
		}
		break;
	case AGENT_WITHOUT_ARG::clearall: {
		auto count = agentMap.size();
		agentMap.clear();
		if (count > 0) {
			outp.addMessage("已清除所有代理设置，共 " + std::to_string(count) + " 个");
			return true;
		}
		else {
			outp.addMessage("当前没有已设置代理");
			return false;
		}
		break;
	}
	case AGENT_WITHOUT_ARG::version:
		outp.addMessage("OperationAgent v1.1.0");
		return true;
	default:
		return false;
	}
	return false;
}

void regListener() {
	Event::addEventListener([](RegCmdEV ev) {
		CMDREG::SetCommandRegistry(ev.CMDRg);
		MakeCommand("opagent", "代理实体执行某些操作", 1);  //注册指令
		CEnum<AGENT_SET> _1("set", { "set" });
		CEnum<AGENT_WITH_ONE_ARG> _2("op", { "clear" ,"query" });
		CEnum<AGENT_WITHOUT_ARG> _3("op2", { "help", "list", "clearall" ,"version" });
		CmdOverload(opagent, oncmd_agentSet, "set", "master", "agent");  //重载指令
		CmdOverload(opagent, oncmd_agentOperate1, "op", "agent");  //重载指令
		CmdOverload(opagent, oncmd_agentOthers, "op2");  //重载指令
		});
	if (autoRideWhenJoin) {
		Event::addEventListener([](JoinEV ev) {
			Player* player = ev.Player;
			if (player == nullptr) {
				return true;
			}
			long long auid = player->getUniqueID().id;
			if (getDataType(auid) != DataType::Ride) {
				return true;
			}
			setTimeOut([auid]() {
				Player* player = getPlayerByAUID(auid);
				if (player == nullptr) {
					return;
				}
				long long  mountsUID = getRideData(auid);
				Actor* mounts = getActorByAUID(mountsUID);
				if (mounts != nullptr) {
					player->startRiding(*mounts);
					std::cout << "玩家" << getActorDescription(player) << "上线自动骑乘" << std::endl;
				}
				else {
					std::cout << "没找到骑乘目标，清除玩家" << getActorDescription(player) << "自动骑乘数据" << std::endl;
					deleteData(auid);
				}
				}, 100);
			return true;
			});
	}
}

void entry() {
	if (loadConf()) {
		autoClean = getConf("autoClean", autoClean);;
		cancelAfterSleep = getConf("cancelAfterSleep", cancelAfterSleep);;
		cancelAfterRide = getConf("cancelAfterRide", cancelAfterRide);;
		autoSleep = getConf("autoSleep", autoSleep);;
		autoRideWhenJoin = getConf("autoRideWhenJoin", autoRideWhenJoin);;
		useNewProjectMode = getConf("useNewProjectMode", useNewProjectMode);;
		forProjectile = getConf("forProjectile", forProjectile);;
		forAttack = getConf("forAttack", forAttack);;
		forSleep = getConf("forSleep", forSleep);;
		forMove = getConf("forMove", forMove);;
		forRide = getConf("forRide", forRide);;
	}
	regListener();
	std::cout << "[Operation Agent] 操作代理已加载。版本：v0.1" << std::endl;
}

// ===== onSpawnProjectile =====
THook(Actor*, "?spawnProjectile@Spawner@@QEAAPEAVActor@@AEAVBlockSource@@AEBUActorDefinitionIdentifier@@PEAV2@AEBVVec3@@3@Z",
	void* _this, BlockSource* bs, ActorDefinitionIdentifier* adi, Actor* spawner, Vec3* pos, Vec3* direct) {
	if (!forProjectile) {
		return original(_this, bs, adi, spawner, pos, direct);
	}
	if (useNewProjectMode) {
		auto master = getMasterOrNull(spawner);
		if (master != nullptr) {
			sendTextOrLog(spawner, "代理" + getActorDescription(master) + "投掷");
			Vec3 mpos = master->getPos();
			return original(_this, bs, adi, master, &mpos, direct);
		}
		return original(_this, bs, adi, spawner, pos, direct);
	}
	Actor* proj = original(_this, bs, adi, spawner, pos, direct);
	if (proj == nullptr) {
		return proj;
	}
	if (spawner != nullptr && hasMaster(spawner)) {
		auto masterUID = agentMap[spawner->getUniqueID().id];
		ActorUniqueID projUID = proj->getUniqueID();
		setTimeOut([projUID, masterUID]() { // 延迟以防止投掷物伤害投掷的实体
			Actor* tempProj = getActorByAUID(projUID); // 延迟后重新获取
			if (tempProj != nullptr) {
				setOwner(tempProj, masterUID);
			}
			}, 1);
		//auto master = getMasterOrNull(spawner);
		auto master = getActorByAUID(masterUID);
		if (master != nullptr) {
			sendTextOrLog(spawner, "代理" + getActorDescription(master) + "投掷");
		}
		else {
			agentMap.erase(spawner->getUniqueID().id);
			sendTextOrLog(spawner, "获取被代理实体失败，清除该代理");
		}
	}
	return proj;
}

// ===== Mob::startRiding =====
THook(bool, "?startRiding@Mob@@UEAA_NAEAVActor@@@Z", Mob* _this, Actor* actor) {
	if (!forRide) {
		return original(_this, actor);
	}
	auto master = getMasterOrNull(_this);
	if (master != nullptr) {
		sendTextOrLog(_this, "代理" + getActorDescription(master) + "骑乘成功");
		if (isPlayer(master)) {
			WPlayer(*(Player*)master).teleport(actor->getPos(), actor->getDimensionId());
			setRideData(master->getUniqueID().id, actor->getUniqueID().id, getActorName(master) + "->" + getActorName(actor));
		}
		if (cancelAfterRide) {
			deleteAgent(_this);
		}
		return original(master, actor);
	}
	return original(_this, actor);
}

// ===== startSleepInBed =====
THook(bool, "?startSleepInBed@Player@@UEAA?AW4BedSleepingResult@@AEBVBlockPos@@@Z",
	Player* player, BlockPos* bpos) {
	if (!forSleep) {
		return original(player, bpos);
	}
	auto master = getMasterOrNull(player);
	if (master && !isSleeping(master)) {
		// 传送以防止假人掉到底下方块里，假人客户端的问题
		Vec3 aboveBed = { bpos->x + 0.5f, bpos->y + 2.0f, bpos->z + 0.5f };
		WPlayer(*(Player*)master).teleport(aboveBed, player->getDimensionId());
		auto rtn = original(master, bpos);
		setSleepData(master->getUniqueID().id, *bpos, getActorName(master) + " -> (" + bpos->toString() + ")");
		if (isSleeping(master)) {
			sendTextOrLog(player, "代理" + getActorDescription(master) + "睡觉成功，并设置自动睡觉位置");
		}
		else {
			sendTextOrLog(player, "代理" + getActorDescription(master) + "睡觉失败，但已设置自动睡觉位置");
		}
		if (cancelAfterSleep) {
			deleteAgent(player);
		}
		return rtn;
	}

	// 让所有已设置过自动睡觉的玩家睡觉
	auto rtn = original(player, bpos);
	if (!autoSleep || !isSleeping(player)) {
		return rtn;
	}
	auto players = liteloader::getAllPlayers();
	for (auto pl : players) {
		if (isSleeping(pl))
			continue;
		long long puid = pl->getUniqueID().id;
		if (getDataType(puid) != DataType::Sleep)
			continue;
		BlockPos pbpos = getSleepData(puid);
		// 传送以防止假人掉到底下方块里，假人客户端的问题
		Vec3 aboveBed = { pbpos.x + 0.5f, pbpos.y + 2.0f, pbpos.z + 0.5f };
		WPlayer(*(Player*)pl).teleport(aboveBed, player->getDimensionId());
		original(pl, &pbpos);
		if (!isSleeping(pl)) {
			deleteData(std::to_string(pl->getUniqueID().id));
			std::cout << pl->getNameTag() << "自动睡觉失败，已移除床坐标数据" << std::endl;
		}
	}
	return rtn;
}

// ===== attack =====
THook(bool, "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
	Player* player, Actor* actor, int* damageCause) {
	if (!forAttack) {
		return original(player, actor, damageCause);
	}
	auto master = getMasterOrNull(player);
	if (master != nullptr) {
		sendTextOrLog((Player*)player, "代理" + getActorDescription(master) + "攻击" + getActorName(actor));
		return original(master, actor, damageCause);
	}
	return original(player, actor, damageCause);
}



// ===== Player::move =====
THook(void, "?move@Player@@UEAAXAEBVVec3@@@Z", Player* player, Vec3* v3) {
	if (!forMove) {
		return original(player, v3);
	}
	auto master = getMasterOrNull(player);
	if (master != nullptr) {
		sendTextOrLog(player, "代理" + getActorDescription(master) + "移动");
		std::cout << v3->toString() << std::endl;
		Vec3 mpos = master->getPos();
		Vec3 dst = mpos + *v3;
		WPlayer(*master).teleport(dst, master->getDimensionId());
		//original(master, v3);
	}
	return original(player, v3);
}

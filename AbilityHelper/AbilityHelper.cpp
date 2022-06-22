#include "pch.h"
#include "AbilityHelper.h"
#include <MC/Packet.hpp>
#include <MC/SynchedActorData.hpp>
#include <MC/Level.hpp>
#include <MC/ServerPlayer.hpp>
#include <third-party/magic_enum/magic_enum.hpp>

#include "AbilityHelperCommand.h"
#include <EventAPI.h>
void entry()
{
    Event::RegCmdEvent::subscribe_ref([](Event::RegCmdEvent ev) {
        AbilityHelperCommand::setup(*ev.mCommandRegistry);
        return true;
    });
}

// static_assert(offsetof(AdventureSettingsPacket, mCustomStoredPermissions) == 76);
#if false
inline struct AdventureSettings& getAdventureSettings()
{
    struct AdventureSettings& (Level::*rv)();
    *((void**)&rv) = dlsym("?getAdventureSettings@Level@@UEAAAEAUAdventureSettings@@XZ");
    return (Global<Level>->*rv)();
}

inline void sendAllPlayerAbilities(class Player const& a0)
{
    void (Level::*rv)(class Player const&);
    *((void**)&rv) = dlsym("?sendAllPlayerAbilities@Level@@UEAAXAEBVPlayer@@@Z");
    return (Global<Level>->*rv)(std::forward<class Player const&>(a0));
}

inline class Abilities* getPlayerAbilities(struct ActorUniqueID const& a0)
{
    class Abilities* (Level::*rv)(struct ActorUniqueID const&);
    *((void**)&rv) = dlsym("?getPlayerAbilities@Level@@UEAAPEAVAbilities@@AEBUActorUniqueID@@@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID const&>(a0));
}

inline void sendNetworkPacket(Player& player, class Packet& a0)
{
    void (Player::*rv)(class Packet&);
    *((void**)&rv) = dlsym("?sendNetworkPacket@ServerPlayer@@UEBAXAEAVPacket@@@Z");
    return (player.*rv)(std::forward<class Packet&>(a0));
}

void _updateAbility(Player& player, AbilitiesIndex index, bool value)
{
}
#endif

Abilities* AbilitiesHelper::getAbilities(Player& player)
{
    return &dAccess<Abilities>(&player, 2512);
}

void AbilitiesHelper::setPlayerAbility(Player& player, AbilitiesIndex index, bool value)
{
    auto level = Global<Level>;
    if (!level)
        return;
    ActorUniqueID uid = player.getUniqueID();
    // auto abilities = level->getPlayerAbilities(uid);
    auto abilities = getAbilities(player);
#ifdef DEBUG
    auto map = abilities->toMap();
#endif // DEBUG
    auto flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
    if (index == AbilitiesIndex::Flying && value && player.isOnGround())
    {
        abilities->setAbility(AbilitiesIndex::MayFly, value);
    }
    if (index == AbilitiesIndex::MayFly && value == false && flying)
    {
        abilities->setAbility(AbilitiesIndex::Flying, false);
    }
    abilities->setAbility(index, value);
    auto mayfly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
    auto noclip = abilities->getAbility(AbilitiesIndex::NoClip).getBool();
    player.setCanFly(mayfly || noclip);
#ifdef DEBUG
    auto map2 = abilities->toMap();
#endif // DEBUG
    flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
    AdventureSettingsPacket pkt(level->getAdventureSettings(), *abilities, uid, false);

    pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
    if (flying)
        pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
    player._sendDirtyActorData();
    player.sendNetworkPacket(pkt);
}

bool AbilitiesHelper::getPlayerAbility(Player& player, AbilitiesIndex index)
{
    // ActorUniqueID uid = player.getUniqueID();
    // auto abilities = getPlayerAbilities(uid);
    auto abilities = getAbilities(player);
    return abilities->getAbility(index).getBool();
}
float AbilitiesHelper::getPlayerAbilityFloat(Player& player, AbilitiesIndex index)
{
    // ActorUniqueID uid = player.getUniqueID();
    // auto abilities = getPlayerAbilities(uid);
    auto abilities = getAbilities(player);
    return abilities->getAbility(index).getFloat();
}

std::vector<AbilitiesIndex> AbilitiesHelper::getPlayerAbilities(Player& player)
{
    auto abilities = getAbilities(player);
    std::vector<AbilitiesIndex> indices;
    for (auto& index : magic_enum::enum_entries<AbilitiesIndex>())
    {
        if (abilities->getBool(index.first))
            indices.push_back(index.first);
    }
    return indices;
}

TInstanceHook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVRequestAbilityPacket@@@Z",
              ServerNetworkHandler, class NetworkIdentifier const& nid, class RequestAbilityPacket const& pkt)
{
    original(this, nid, pkt);
    if (Config::fixFlying)
    {
        auto index = pkt.getAbility();
        if (index == AbilitiesIndex::Flying)
        {
            auto sp = _getServerPlayer(nid, pkt.clientSubId);
            if (!sp)
                return;
            if (!sp->getUserEntityIdentifierComponent())
                return;
            bool flying;
            if (!pkt.tryGetBool(flying))
                return;
            auto abilities = AbilitiesHelper::getAbilities(*sp);
            auto mayFly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
            flying = flying && mayFly;
            AdventureSettingsPacket pkt(Global<Level>->getAdventureSettings(), *abilities, sp->getUniqueID(), false);
            pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
            if (flying)
                pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
            abilities->setAbility(AbilitiesIndex::Flying, flying);
            sp->sendNetworkPacket(pkt);
            DEBUGW("{} set may flying -> {}", getName(), flying);
        }
    }
}

#ifdef DEBUG

TInstanceHook(AdventureSettingsPacket&, "??0AdventureSettingsPacket@@QEAA@AEBUAdventureSettings@@AEBVAbilities@@UActorUniqueID@@_N@Z",
              AdventureSettingsPacket, struct AdventureSettings const& settings, class Abilities const& abilities, struct ActorUniqueID uniqueId, bool unk_0)
{
    auto map = abilities.toMap();
    auto& pkt = original(this, settings, abilities, uniqueId, unk_0);
    if (abilities.getAbility(AbilitiesIndex::MayFly).getBool() && abilities.getAbility(AbilitiesIndex::Flying).getBool())
    {
        pkt.mFlag |= (int)AdventureFlag::Flying;
    }
    return pkt;
}
TInstanceHook(bool, "?canUseAbility@Player@@QEBA_NW4AbilitiesIndex@@@Z",
              Player, enum AbilitiesIndex index)
{
    auto rtn = original(this, index);
    DEBUGW("{} {} use ability {}", getName(), rtn ? "can" : "can not", magic_enum::enum_name(index));
    return rtn;
}

TClasslessInstanceHook(bool, "?isFlying@PlayerMovement@@YA_NAEBUIPlayerMovementProxy@@@Z",
                       struct IPlayerMovementProxy const& a1)
{
    auto rtn = original(this, a1);
    DEBUGW("isFlying: {}", rtn);
    return rtn;
}
// TInstanceHook(bool, "?isFlying@Abilities@@QEBA_NXZ",
//               Abilities)
//{
//     //auto rtn = original(this);
//     auto rtn = this->getAbility(AbilitiesIndex::Flying).getBool();
//     DEBUGW("Abilities::isFlying: {}", rtn);
//     return true;
// }

#endif // DEBUG

//TInstanceHook(void, "?readAdditionalSaveData@Player@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
//              Player, class CompoundTag const& tag, class DataLoadHelper& helper)
//{
//    original(this, tag, helper);
//}

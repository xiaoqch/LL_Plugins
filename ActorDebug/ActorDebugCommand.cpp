#include "pch.h"
#include "ActorDebugCommand.h"
#include <MC/Level.hpp>

//template <>
//class OwnerPtrT<struct EntityRefTraits>
//{
//    char filler[24];
//};
//inline std::vector<class OwnerPtrT<struct EntityRefTraits>> const& getEntities()
//{
//    std::vector<class OwnerPtrT<struct EntityRefTraits>> const& (Level::*rv)();
//    *((void**)&rv) = dlsym("?getEntities@Level@@UEBAAEBV?$vector@V?$OwnerPtrT@UEntityRefTraits@@@@V?$allocator@V?$OwnerPtrT@UEntityRefTraits@@@@@std@@@std@@XZ");
//    return (Global<Level>->*rv)();
//}

inline std::vector<class Actor*> getRuntimeActorList()
{
    std::vector<class Actor*> (Level::*rv)();
    *((void**)&rv) = dlsym("?getRuntimeActorList@Level@@UEBA?AV?$vector@PEAVActor@@V?$allocator@PEAVActor@@@std@@@std@@XZ");
    return (Global<Level>->*rv)();
}

inline int getActivePlayerCount()
{
    int (Level::*rv)();
    *((void**)&rv) = dlsym("?getActivePlayerCount@Level@@UEBAHXZ");
    return (Global<Level>->*rv)();
}

std::string getActorFakeName(Actor* actor);

void refreshActorFakeName(Actor* actor, Player* player = nullptr);

ServerPlayer* tryGetDebugPlayer(NetworkIdentifier const& networkID, unsigned char clientSubID);

using namespace RegisterCommandHelper;

inline void refreshAllFakeName()
{
    for (auto actor : getRuntimeActorList())
    {
        if (!actor)
            continue;
        refreshActorFakeName(actor);
    }
}


extern std::vector<ActorUniqueID> uniqueIds;

inline void switchPlayer(class CommandOutput& output, Player* player)
{
    ActorUniqueID uid = player->getUniqueID();
    auto iter = std::find(uniqueIds.begin(), uniqueIds.end(), uid.id);
    bool switchOn = iter == uniqueIds.end();
    if (switchOn)
        uniqueIds.push_back(uid);
    else
        uniqueIds.erase(iter);
    for (auto actor : getRuntimeActorList())
    {
        if (actor)
            refreshActorFakeName(actor, player);
    }
    if (switchOn)
        output.success(fmt::format("ActorDebug is enabled for {}", player->getNameTag()));
    else
        output.success(fmt::format("ActorDebug is disabled for {}", player->getNameTag()));
}


inline void switchGlobal(class CommandOutput& output)
{
    if (Config::switchActivation())
        output.success("ActorDebug is enabled globally");
    else
        output.success("ActorDebug is disabled globally");
    refreshAllFakeName();
    uniqueIds.clear();
}

void ActorDebugCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const
{
    if (mPlayer_isSet)
    {
        auto players = mPlayer.results(origin);
        if (players.count() == getActivePlayerCount())
            return switchGlobal(output);
        
        size_t count = 0;
        if (players.count() == 0)
            return output.error("Target Not Found");

        for (auto player : players)
        {
            switchPlayer(output, player);
        }
    }
    else if ((enum OriginType)origin.getOriginType() == OriginType::DedicatedServer)
    {
        return switchGlobal(output);
    }
    else
    {
        auto player = Command::getPlayerFromOrigin(origin);
        if (!player)
            return output.error("Error in ActorDebug Command");
        if (getActivePlayerCount() == 1)
            return switchGlobal(output);
        else
            return switchPlayer(output, player);
    }
    TestFuncTime(refreshAllFakeName);
}

void ActorDebugCommand::setup(CommandRegistry& registry)
{
    registry.registerCommand("actordebug", "Actor Debug Info Display", Config::permissionLevel, {(CommandFlagValue)0}, {(CommandFlagValue)0x80});
    registry.registerAlias("actordebug", Config::commandAlias);

    auto playerParam = makeOptional(
        &ActorDebugCommand::mPlayer, "target", &ActorDebugCommand::mPlayer_isSet);

    registry.registerOverload<ActorDebugCommand>("actordebug");
    registry.registerOverload<ActorDebugCommand>("actordebug", playerParam);
}
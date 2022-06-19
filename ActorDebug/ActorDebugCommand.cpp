#include "pch.h"
#include "ActorDebugCommand.h"
#include <MC/Level.hpp>

//template <>
//class OwnerPtrT<struct EntityRefTraits>
//{
//    char filler[24];
//};

std::string getActorFakeName(Actor* actor);

void refreshActorFakeName(Actor* actor, Player* player = nullptr);

ServerPlayer* tryGetDebugPlayer(NetworkIdentifier const& networkID, unsigned char clientSubID);

using namespace RegisterCommandHelper;

inline void refreshAllFakeName()
{
    for (auto actor : Global<Level>->getRuntimeActorList())
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
    for (auto actor : Global<Level>->getRuntimeActorList())
    {
        if (actor)
            refreshActorFakeName(actor, player);
    }
    if (switchOn)
        output.success(fmt::format("ActorDebug is enabled for {}", player->getNameTag()));
    else
        output.success(fmt::format("ActorDebug is disabled for {}", player->getNameTag()));
}
inline bool switchActivation()
{
    Config::globalActive = !Config::globalActive;
    Config::saveConfig();
    return Config::globalActive;
}

inline void switchGlobal(class CommandOutput& output)
{
    if (switchActivation())
        output.success("ActorDebug is enabled globally");
    else
        output.success("ActorDebug is disabled globally");
    refreshAllFakeName();
    uniqueIds.clear();
}
#include <MC/LevelStorage.hpp>
#include <MC/CompoundTag.hpp>
void ActorDebugCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const
{
    size_t dig_count = 0;
    size_t chunk_count = 0;
    size_t actor_count = 0;
    Global<LevelStorage>->forEachKeyWithPrefix("digp", (DBHelpers::Category)4, [&](gsl::cstring_span<-1> suffix, gsl::cstring_span<-1> data) {
        chunk_count++;
        dig_count += data.size() / sizeof(ActorUniqueID);
    });
    Global<LevelStorage>->forEachKeyWithPrefix("actorprefix", (DBHelpers::Category)4, [&](gsl::cstring_span<-1> suffix, gsl::cstring_span<-1> data) {
        actor_count++;
    });
    output.success(fmt::format("chunk: {}, digp: {}, actor: {}",
                               chunk_count, dig_count, actor_count));
    if (actor_count < 100000)
    {
        std::unordered_map<std::string, size_t> countMap;
        Global<LevelStorage>->forEachKeyWithPrefix("actorprefix", (DBHelpers::Category)4, [&](gsl::cstring_span<-1> suffix, gsl::cstring_span<-1> data) {
            auto tag = CompoundTag::fromBinaryNBT((void*)data.data(), data.size());
            std::string type = tag->getString("identifier");
            if (countMap.find(type) == countMap.end())
                countMap[type] = 1;
            else
                countMap[type]++;
        });
        for (auto& [type, count] : countMap)
        {
            output.success(fmt::format("{} - {}", type, count));
        }
    }
    if (mPlayer_isSet)
    {
        auto players = mPlayer.results(origin);
        if (players.count() == Global<Level>->getActivePlayerCount())
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
        if (Global<Level>->getActivePlayerCount() == 1)
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

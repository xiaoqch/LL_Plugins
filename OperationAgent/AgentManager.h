#pragma once
#include <functional>
#include <MC/Actor.hpp>
#include <MC/Level.hpp>
#include <MC/CommandUtils.hpp>
#include <third-party/Nlohmann/json.hpp>

template<>
struct std::hash<ActorUniqueID> {
    size_t operator() (ActorUniqueID const& key) const {
        return std::hash<long long>()(key.id);
    }
};
template<>
struct std::equal_to<ActorUniqueID> {
    constexpr bool operator()(const ActorUniqueID& _Left, const ActorUniqueID& _Right) const {
        return _Left.id == _Right.id;
    }
};
class Player;
class Mob;
class Actor;

inline class Actor* getActor(struct ActorUniqueID a0) {
    return Global<Level>->fetchEntity(a0, true);
}

inline std::string getActorDescription(Actor* actor) {
    if (!actor) {
        return "Error(Nullptr)";
    }
    string nameTag = actor->getNameTag();
    if (!nameTag.empty()) {
        return nameTag;
    }
    return fmt::format("{}({})", CommandUtils::getActorName(*actor), actor->getUniqueID().id);
}
class AgentManager
{
private:
    enum class DataType {
        Sleep,
        Ride,
    };
    struct Data
    {
        DataType type;
        std::variant<ActorUniqueID, BlockPos> data;
        std::string remark;
        nlohmann::json serialize();
        static Data deserialize(nlohmann::json json);
    };
    std::unordered_map<ActorUniqueID, Data> mData;
    std::unordered_map<ActorUniqueID, ActorUniqueID> mAgentMap;
    AgentManager();
    AgentManager(const AgentManager&) = delete;
    AgentManager& operator=(const AgentManager&) = delete;
    bool loadData();
    bool saveData();
public:
    static AgentManager& getManager();
    ActorUniqueID getMasterUID(ActorUniqueID const uniqueID);
    bool hasMaster(Actor* actor);
    Player* getMaster(Player* agent);
    Mob* getMaster(Mob* agent);
    Actor* getMaster(Actor* agent);
    void forEach(std::function<void(Actor* agent, Actor* master)> callback);

    template <typename T>
    static T* tryGetMaster(T* agent) {
        auto& manager = getManager();
        if(manager.hasMaster(agent))
            return manager.getMaster(agent);
        return nullptr;
    }

    bool setAgent(Actor* agent, Actor* master);
    bool removeAgent(Actor* agent);
    size_t clearAll();
    optional<ActorUniqueID> tryGetRideData(ActorUniqueID const& uid);
    optional<BlockPos> tryGetSleepData(ActorUniqueID const& uid);
    Actor* tryGetRideData(Actor* actor);
    optional<BlockPos> tryGetSleepData(Actor* actor);
    bool setRideData(Player* master, Actor* mounts);
    bool setSleepData(Player* master, BlockPos const& bpos);

};


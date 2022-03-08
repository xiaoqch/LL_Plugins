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

inline class Player* getPlayer(struct ActorUniqueID a0) {
    class Player* (Level::*rv)(struct ActorUniqueID);
    *((void**)&rv) = dlsym("?getPlayer@Level@@UEBAPEAVPlayer@@UActorUniqueID@@@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID>(a0));
}
inline class Mob* getMob(struct ActorUniqueID a0) {
    class Mob* (Level::*rv)(struct ActorUniqueID);
    *((void**)&rv) = dlsym("?getMob@Level@@UEBAPEAVMob@@UActorUniqueID@@@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID>(a0));
}
inline class Actor* fetchEntity(struct ActorUniqueID a0, bool a1) {
    class Actor* (Level::*rv)(struct ActorUniqueID, bool);
    *((void**)&rv) = dlsym("?fetchEntity@Level@@UEBAPEAVActor@@UActorUniqueID@@_N@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID>(a0), std::forward<bool>(a1));
}
inline class Actor* getActor(struct ActorUniqueID a0) {
    return fetchEntity(a0, true);
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
        inline nlohmann::json serialize() {
            nlohmann::json json;
            switch (type)
            {
            case AgentManager::DataType::Sleep:{
                json["type"] = "Sleep";
                auto& bedPos = std::get<BlockPos>(data);
                json["bedPos"] = { bedPos.x, bedPos.y, bedPos.z };
                break; 
            }
            case AgentManager::DataType::Ride: {
                json["type"] = "Ride";
                auto& uniqueID = std::get<ActorUniqueID>(data);
                json["mounts"] = uniqueID.id;
                break;
            }
            default:
                break;
            }
            json["remark"] = remark;
            return json;
        }
        inline static Data deserialize(nlohmann::json json) {
            Data data;
            auto typeStr = json.value<std::string>("type","Unknown");
            if (typeStr == "Sleep") {
                data.type = DataType::Sleep;
                auto bedPos = json.value<std::vector<int>>("bedPos", { 0,0,0 });
                data.data = BlockPos{ bedPos[0],bedPos[1],bedPos[2] };
            }
            else if (typeStr == "Ride") {
                data.type = DataType::Ride;
                auto uniqueID = json.value<int64_t>("mounts", -1);
                data.data = ActorUniqueID{ uniqueID };
            }
            data.remark = json.value<std::string>("remark", "Unknown");
            return data;
        }
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


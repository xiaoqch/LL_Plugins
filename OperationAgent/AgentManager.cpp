#include "pch.h"
#include "AgentManager.h"
#include <MC/Player.hpp>
#include <MC/SubChunkRelighter.hpp>

AgentManager::AgentManager() {
    if (!loadData()) {
        std::filesystem::create_directories(std::filesystem::path(PLUGIN_DATA_PATH).remove_filename());
        saveData();
    }
}

bool AgentManager::loadData()
{
    auto dataStrOpt = ReadAllFile(PLUGIN_DATA_PATH);
    if (dataStrOpt.has_value()) {
        auto& dataStr = dataStrOpt.value();
        auto json = nlohmann::json::parse(dataStr);
        for (auto& item : json.items()) {
            auto uniqueID = ActorUniqueID{ std::stoll(item.key()) };
            auto data = Data::deserialize(item.value());
            mData[uniqueID] = data;
        }
        return true;
    }
    return false;
}

bool AgentManager::saveData()
{
    nlohmann::json json;
    for (auto& [uniqueID,data] : mData) {
        json[std::to_string(uniqueID.id)] = data.serialize();
    }
    return WriteAllFile(PLUGIN_DATA_PATH, json.dump(4));
}

AgentManager& AgentManager::getManager()
{
    static AgentManager manager;
    return manager;
}

ActorUniqueID AgentManager::getMasterUID(ActorUniqueID const uniqueID)
{
    return mAgentMap[uniqueID];
}

bool AgentManager::hasMaster(Actor* actor)
{
    return actor && mAgentMap.size() > 0 && mAgentMap.end() != mAgentMap.find(actor->getUniqueID());
}

Player* AgentManager::getMaster(Player* agent)
{
    return Global<Level>->getPlayer(getMasterUID(agent->getUniqueID()));
}

Mob* AgentManager::getMaster(Mob* agent)
{
    return Global<Level>->getMob(getMasterUID(agent->getUniqueID()));
}

Actor* AgentManager::getMaster(Actor* agent)
{
    return Global<Level>->fetchEntity(getMasterUID(agent->getUniqueID()), true);
}

void AgentManager::forEach(std::function<void(Actor* agent, Actor* master)> callback)
{
    for (auto& [agentUniqueID, masterUniqueID] : mAgentMap) {
        auto agent = getActor(agentUniqueID);
        auto master = getActor(masterUniqueID);
        if (agent == nullptr || master == nullptr)
            mAgentMap.erase(agentUniqueID);
        callback(agent, master);
    }
}

bool AgentManager::setAgent(Actor* agent, Actor* master)
{
    mAgentMap[agent->getUniqueID()] = master->getUniqueID();
    return true;
}

bool AgentManager::removeAgent(Actor* agent)
{
    if (hasMaster(agent)) {
        mAgentMap.erase(agent->getUniqueID());
        return true;
    }
    return false;
}

size_t AgentManager::clearAll()
{
    auto count = mAgentMap.size();
    mAgentMap.clear();
    return count;
}

optional<ActorUniqueID> AgentManager::tryGetRideData(ActorUniqueID const& uid)
{
    auto res = mData.find(uid);
    if(res == mData.end()||res->second.type!=DataType::Ride)
        return {};
    return { std::get<ActorUniqueID>(res->second.data) };
}

optional<BlockPos> AgentManager::tryGetSleepData(ActorUniqueID const& uid)
{
    auto res = mData.find(uid);
    if (res == mData.end() || res->second.type != DataType::Sleep)
        return {};
    return { std::get<BlockPos>(res->second.data) };
}

Actor* AgentManager::tryGetRideData(Actor* actor)
{
    if(!actor)
        return nullptr;
    auto uniqueIDOpt =  tryGetRideData(actor->getUniqueID());
    if(!uniqueIDOpt.set)
        return nullptr;
    return getActor(uniqueIDOpt.val());
}

optional<BlockPos> AgentManager::tryGetSleepData(Actor* actor)
{
    if (!actor)
        return {};
    return tryGetSleepData(actor->getUniqueID());
}

bool AgentManager::setRideData(Player* master, Actor* mounts)
{
    auto remark = fmt::format("{} -> {}", CommandUtils::getActorName(*master), CommandUtils::getActorName(*mounts));
    Data data{ DataType::Ride, mounts->getUniqueID(), remark };
    mData[master->getUniqueID()] = data;
    saveData();
    return true;
}

bool AgentManager::setSleepData(Player* master, BlockPos const& bpos)
{
    auto remark = fmt::format("{} -> ({})", CommandUtils::getActorName(*master) , bpos.toString());
    Data data{ DataType::Sleep, bpos, remark };
    mData[master->getUniqueID()] = data;
    saveData();
    return true;
}

nlohmann::json AgentManager::Data::serialize()
{
    nlohmann::json json;
    switch (type)
    {
        case AgentManager::DataType::Sleep:
        {
            json["type"] = "Sleep";
            auto& bedPos = std::get<BlockPos>(data);
            json["bedPos"] = {bedPos.x, bedPos.y, bedPos.z};
            break;
        }
        case AgentManager::DataType::Ride:
        {
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

AgentManager::Data AgentManager::Data::deserialize(nlohmann::json json)
{
    Data data;
    auto typeStr = json.value<std::string>("type", "Unknown");
    if (typeStr == "Sleep")
    {
        data.type = DataType::Sleep;
        auto bedPos = json.value<std::vector<int>>("bedPos", {0, 0, 0});
        data.data = BlockPos{bedPos[0], bedPos[1], bedPos[2]};
    }
    else if (typeStr == "Ride")
    {
        data.type = DataType::Ride;
        auto uniqueID = json.value<int64_t>("mounts", -1);
        data.data = ActorUniqueID{uniqueID};
    }
    data.remark = json.value<std::string>("remark", "Unknown");
    return data;
}

#include "pch.h"
#include "BdsDbHelper2.h"

/*
using namespace std;
DBStorageQueryType queryType = DBStorageQueryType::None;
unique_ptr<Tag> globalTag;
string globalKey;
std::map<std::string, PlayerIds> allPlayerIds;

bool queryReadDB(DBStorageQueryType type, string key) {
    if (queryType != DBStorageQueryType::None)
        return false;
    queryType = type;
    globalKey = key;
    // [0] = MsaId
    // [1] = // Unknown，似乎与读取数据无关
    // [2] = PlatformOnlineId // Create New If Not Exist!
    // [3] = PlatformOfflineId // Create New If Not Exist!
    // [4] = SelfSignedId // Create New If Not Exist!
    // [5] = // Unknown，但与读取数据有关，形如：5695722221326097789 的字符串，意义不明
    // 5695722221326097789 == 0x4F0B452EDD70DD7D，半个id长度
    string playerStorageIds[6];
    playerStorageIds[0] = "~local_player";
    Tag* playerTag = nullptr;// = Tag::createTag(TagType::Compound);

    // 调用 PlayerDataSystem::loadPlayerData() 会使 bds 调用 DBStorage::getCompoundTag() 方法
    // 然后hook掉该方法，已使用original()获取玩家id数据，避免直接调用崩服
    // 注意，此符号传入不存在key时或者key类型错误是会把玩家数据绑定到localplayer
    SymCall("?loadPlayerData@PlayerDataSystem@@YA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVLevelStorage@@AEBUPlayerStorageIds@@_N@Z",
        void*, Tag*&, LevelStorage*, std::string*, bool)(playerTag, getLevelStorage(), playerStorageIds, true);
    // 此时，DBStorage::getCompoundTag()内获取玩家 id 数据已完成。

    if (queryType == DBStorageQueryType::None)
        return true;
    queryType = DBStorageQueryType::None;
    return false;
}
bool queryReadDB(DBStorageQueryType type) {
    return queryReadDB(type, "");
}

bool loadAllIds() {
    return queryReadDB(DBStorageQueryType::LoadAllPlayerIds);
}

void printAllIds() {
    if (allPlayerIds.size() == 0)
        loadAllIds();
    for (auto& [key, value] : allPlayerIds) {
        cout << "MsaId:             " << value.MsaId << endl;
        cout << "PlatformOnlineId:  " << value.PlatformOnlineId << endl;
        cout << "PlatformOfflineId: " << value.PlatformOfflineId << endl;
        cout << "SelfSignedId:      " << value.SelfSignedId << endl;
        cout << "ServerId:          " << value.ServerId << endl << endl;
    }
}

Tag* getCoumpundTag(string& key) {
    cout << key << endl;
    bool result = queryReadDB(DBStorageQueryType::GetCoumpundTag, key);
    if (!result)
        return nullptr;
    return globalTag.get();
}

Tag* getPlayerDataById(string& id) {
    cout << id << endl;
    for (auto& [key, value] : allPlayerIds) {
        if (value.MsaId == id || value.PlatformOfflineId == id || value.PlatformOnlineId == id
            || value.SelfSignedId == id || value.ServerId == id)
            return getCoumpundTag(value.ServerId);
    }
    return nullptr;
}


THook(void*, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    LevelStorage* _this, unique_ptr<Tag>& tagPtr, string& key) {
    switch (queryType)
    {
    case DBStorageQueryType::None:
        break;
    case DBStorageQueryType::LoadAllPlayerIds:
        if (key == "~local_player") {
            vector<string> allIds = loadAllPlayerIDs(true);
            for (string id : allIds) {
                if (id.find("server_") != 0) {
                    string playerKey = "player_" + id;
                    original(_this, tagPtr, playerKey);
                    if (!tagPtr)
                        continue;
                    auto& playerTag = tagPtr.get()->asCompound();
                    //auto ids = PlayerIds{};
                    PlayerIds ids;
                    for (auto& idKey : playerTag) {
                        if (idKey.first == "MsaId")
                            ids.MsaId = idKey.second.asString();
                        else if (idKey.first == "PlatformOnlineId")
                            ids.PlatformOnlineId = idKey.second.asString();
                        else if (idKey.first == "PlatformOfflineId")
                            ids.PlatformOfflineId = idKey.second.asString();
                        else if (idKey.first == "SelfSignedId")
                            ids.SelfSignedId = idKey.second.asString();
                        else if (idKey.first == "ServerId")
                            ids.ServerId = idKey.second.asString();
                        else
                            cerr << "Unknown Id Type: " << idKey.first << ", Value: " << idKey.second.asString() << endl;
                    }
                    allPlayerIds[ids.ServerId] = std::move(ids);
                }
            }
            queryType = DBStorageQueryType::None;
        }
        break;
    case DBStorageQueryType::GetCoumpundTag:
        if (key == "~local_player") {
            original(_this, globalTag, globalKey);
            queryType = DBStorageQueryType::None;
        }
        break;
    default:
        break;
    }
    return original(_this, tagPtr, key);


    void* ret = original(_this, tagPtr, key);
    cout << "DBStorage::getCompoundTag(" << _this << ", " << tagPtr << ", \"" << key << "\", " << ");" << endl;
    Tag* tag = tagPtr.get();
    if (tag) {
        auto& pTag = tag->asCompound();
        auto uid = pTag.find("UniqueID");
        if (uid != pTag.end()) {
            std::cout << "UniqueID: " << endl << uid->second.asLong() << std::endl;
        }
        else {
            std::cout << "SNBT: " << endl << TagToSNBT(tag) << std::endl;

        }
    }
    return ret;
}

*/
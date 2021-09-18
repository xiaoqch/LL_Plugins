#pragma once
#include "nbt-from-lxl/NBT.h"
#include "DBStorage.h"



// Call
template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
    return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}

BlockSource* getBlockSourceByDim(int dimid);
Level* getLevel();
Dimension* getDimensionByDid(int dimid);
LevelStorage* getLevelStorage();
DBStorage* getDBStorage();
string getServerId(const string& storageId);
std::vector<string> loadAllPlayerIDs(bool b);
string getPlatformOnlineId(Player* player);
Player* getPlayerFromServerId(const string& serverId);
Player* getPlayerByName(const string& name);
string getPlayerXUID(mce::UUID uuid);
string getPlayerUuid(Player* player);




bool saveToDBStorage(string& key, Tag* tag);
void saveLevelStorage(Actor* actor);
bool deleteDBStorageData(string& key);
bool _flushWriteCacheToLevelDB();

void* forEachKeyWithPrefix(const string& prefix, function<void(string&, string&)> callback);
#pragma once
#include "nbt-from-lxl/NBT.h"
#include "DBStorage.h"



// Call
template<typename RTN = void, typename... Args>
RTN inline VirtualCall(void* _this, uintptr_t off, Args... args) {
    return (*(RTN(**)(void*, Args...))(*(uintptr_t*)_this + off))(_this, args...);
}

Level* getLevel();
Dimension* getDimensionByDid(int dimid);
LevelStorage* getLevelStorage();
DBStorage* getDBStorage();
BlockSource* getBlockSourceByDim(int dimid);
class SavedData {
public:
    bool        dirty;
    std::string buffer;
    virtual ~SavedData() = default;
    virtual void deserialize(class CompoundTag const&) = 0;
    virtual void serialize(class CompoundTag&) const = 0;
};
SavedData* getSavedData();








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
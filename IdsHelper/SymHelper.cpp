#include "pch.h"
#include "SymHelper.h"
#include "../third-party/nbt-from-lxl/NBT.h"
#include "BdsDbHelper.h"


//======= Basic Function =======
Minecraft* this_mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self)
{
	original(self);
	this_mc = (Minecraft*)self;
}

Level* getLevel() {
	return this_mc->getLevel();
};

LevelStorage* getLevelStorage() {
	return SymCall("?getLevelStorage@Level@@UEBAAEBVLevelStorage@@XZ", LevelStorage*, Level*)(getLevel());
};




//======= xuid & uuid & others =======


string getServerId(const string& storageId) {
	string serverId;
	return SymCall("?getServerId@LevelStorage@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBUPlayerStorageIds@@@Z",
		string&, LevelStorage*, string&, const string&)(getLevelStorage(), serverId, storageId);
}

string getPlatformOnlineId(Player* player) {
	return SymCall("?getPlatformOnlineId@Player@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
		string&, Player*)(player);
}
// Only online
string getPlayerXUID(mce::UUID uuid) {
	if (this_mc == nullptr) {
		return "mc is nullptr";
	}
	return SymCall("?getPlayerXUID@Level@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVUUID@mce@@@Z",
		string&, Level*, mce::UUID&)(this_mc->getLevel(), uuid);
}

string getPlayerUuid(Player* player) {
	mce::UUID tmp = dAccess<mce::UUID>(player, 3000);
	return tmp.asString();
}
// Unknown arg b
vector<string> loadAllPlayerIDs(bool b) {
	vector<string> allPlayerIDs;
	SymCall("?loadAllPlayerIDs@LevelStorage@@QEBA?AV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@_N@Z",
		vector<string>*, LevelStorage*, std::vector<std::string>&, bool)(getLevelStorage(), allPlayerIDs, b);
	return allPlayerIDs;
}

Player* getPlayerByXUID(const string& xuid) {
	return SymCall("?getPlayerByXuid@Level@@UEBAPEAVPlayer@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
		Player*, Level*, const string&)(getLevel(), xuid);
};


Player* getPlayerFromServerId(const string& serverId) {
	return SymCall("?getPlayerFromServerId@Level@@UEBAPEAVPlayer@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
		Player*, Level*, const string&)(getLevel(), serverId);
}

Player* getPlayerByName(const string& name) {
	return nullptr;
}
Tag* loadPlayerData(const string& uuid) {
	Tag* playerTag = Tag::createTag(TagType::Compound);
	SymCall("?loadPlayerData@PlayerDataSystem@@YA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVLevelStorage@@AEBUPlayerStorageIds@@_N@Z",
		void*, Tag*&, LevelStorage*, const string&, bool)(playerTag, getLevelStorage(), uuid, true);
	return playerTag;
};



// DBStorage::loadData
Tag* loadFromDBStorage(string& key) {
	string bin;
	uint64_t key_span[2] = { key.length() , (uint64_t)key.c_str() };
	bool b=SymCall("?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
		bool, LevelStorage*, uint64_t*, string&)(getLevelStorage(), key_span, bin);
	if (b == bin.empty())
		throw("Error in DBStorage::loadData()");
	if (bin.empty())
		return nullptr;
	return readFromBinary(bin);
	return BinaryNBTToTag((void*)bin.c_str(), bin.length());
}


void saveLevelStorage(Actor* actor) {
	SymCall("?save@LevelStorage@@QEAAXAEAVActor@@@Z",
		void, LevelStorage*, Actor*)(getLevelStorage(), actor);
}

// DBStorage::saveData
bool saveToDBStorage(string& key, Tag* tag) {
	string bin = TagToBinaryNBT(tag);
	void* result[2]{};
	void* rtn = SymCall("?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@@Z",
		void*, LevelStorage * , void* , string& , string& )(getLevelStorage(), result, key, bin);
	return false;
}
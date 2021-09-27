#include "pch.h"
#include "SymHelper.h"
#include "../third-party/nbt-from-lxl/NBT.h"
#include "BdsDbHelper.h"


//======= Basic Function =======
Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self)
{
	original(self);
	mc = (Minecraft*)self;
}

Level* getLevel() {
	return mc->getLevel();
};

LevelStorage* getLevelStorage() {
	return SymCall("?getLevelStorage@Level@@UEBAAEBVLevelStorage@@XZ", LevelStorage*, Level*)(getLevel());
};

Dimension* getDimensionByDid(int dimid) {
	return SymCall("?getDimension@Level@@UEBAPEAVDimension@@V?$AutomaticID@VDimension@@H@@@Z",
		Dimension*, void*, int)(mc->getLevel(), dimid);
}

BlockSource* getBlockSourceByDim(int dimid)
{
	auto dim = (int*)getDimensionByDid(dimid);
	if (dim)
		return dAccess<BlockSource*>(dim, 96);
	else
		return nullptr;
}


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
	if (mc == nullptr) {
		return "mc is nullptr";
	}
	return SymCall("?getPlayerXUID@Level@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVUUID@mce@@@Z",
		string&, Level*, mce::UUID&)(mc->getLevel(), uuid);
}

string getPlayerUuid(Player* player) {
	mce::UUID tmp = dAccess<mce::UUID>(player, 3040);
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
	bool b = SymCall("?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
		bool, LevelStorage*, uint64_t*, string&)(getLevelStorage(), key_span, bin);
	if (b == bin.empty())
		throw("Error in DBStorage::loadData()");
	if (bin.empty())
		return nullptr;
	return BinaryNBTToTag(bin);
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
		void*, LevelStorage*, void*, string&, string&)(getLevelStorage(), result, key, bin);
	return false;
}

// DBStorage::saveData
bool deleteDBStorageData(string& key) {
	void* result[2]{};
	void* rtn = SymCall("?deleteData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
		void*, LevelStorage*, void*, string&)(getLevelStorage(), result, key);
	return false;
}


bool _flushWriteCacheToLevelDB() {
	char* result[24]{};
	SymCall("?_flushWriteCacheToLevelDB@DBStorage@@AEAA?AVTaskResult@@XZ",
		void*, LevelStorage*, void*)(getLevelStorage(), result);
	return false;
}
Tag* fromJavaNbtString(string& snbt) {
	Tag* tag = Tag::createTag(TagType::Compound);
	SymCall("?fromJavaNbtString@StateSerializationUtils@@YA?AW4WallConnectionType@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
		void*, Tag*, string&)(tag, snbt);
	cout << TagToSNBT(tag) << endl;
	return tag;
}

void* forEachKeyWithPrefix(const string& prefix, function<void(string&, string&)> callback) {
	uintptr_t prifix_span[2] = { prefix.length(), (uintptr_t)prefix.c_str() };
	return SymCall("?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
		void*, void*, void*, function<void(uintptr_t&, uintptr_t&)>)(getLevelStorage(), prifix_span, [prefix, callback](uintptr_t& v_key, uintptr_t& v_data)->void {
			void* key_left_span = &v_key;
			void* data_span = &v_data;
			string key_left = string(dAccess<char*>(key_left_span, 8), v_key);
			string key = prefix + key_left;
			string data = string(dAccess<char*>(data_span, 8), v_data);
			callback(key, data);
			});
}
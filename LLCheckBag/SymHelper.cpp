#include "pch.h"
#include "SymHelper.h"


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
		string&,  LevelStorage*,string&, const string&)(getLevelStorage(), serverId, storageId);
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
		Player*, Level*,const string&)(getLevel(),serverId);
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
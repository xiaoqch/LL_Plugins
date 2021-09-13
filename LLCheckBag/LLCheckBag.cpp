#include "pch.h"
#include <mc/OffsetHelper.h>
#include "DataHelepr.h"
#include "FormHelper.h"
#include "LangHelper.h"
#include "SymHelper.h"
#include "JsonHelper.h"

#define VERSION "v0.0.1"
using namespace std;

int permissionLevel;
string language;

struct Ids {
	string serverId = "";
	string xuid = "";
	string name = "";
};

map<string, Ids> idMap;

void onPlayerSelected(std::string response) {
	if (response != "null") {
		std::cout << "response id: " << strtol(response.c_str(), nullptr, 10) << std::endl;
	}
}
enum class CheckBagOp:int
{
	all,
	iter,
	next,
};

bool oncmd_checkBag(CommandOrigin const& ori, CommandOutput& outp) {
	//Player* player = (Player*)ori.getEntity();
	//Level* level = getLevel();
	//Dimension* dim =SymCall(
	//	"?getDimension@Level@@UEBAPEAVDimension@@V?$AutomaticID@VDimension@@H@@@Z",
	//	Dimension*, void*, int)(getLevel(), 0);
	//void* gen = SymCall("?getWorldGenerator@Dimension@@QEBAPEAVWorldGenerator@@XZ",
	//	void*, Dimension*)(dim);
	//auto bs = dAccess<BlockSource*>(dim, 96);
	//Vec3 ppos = player->getPos();
	//BlockPos bpos = { (int)ppos.x,(int)ppos.y,(int)ppos.z };
	//void* lc = SymCall("?getChunkAt@BlockSource@@QEBAPEAVLevelChunk@@AEBVBlockPos@@@Z",
	//	void*, BlockSource*, BlockPos&)(bs, bpos);
	//SymCall("?loadChunk@OverworldGenerator@@UEAAXAEAVLevelChunk@@_N@Z",
	//	void*, void*, void*, bool)(gen, lc, true);
	//return true;
	Player* player = (Player*)ori.getEntity();
	if (!player) {
		outp.error("Not Player");
		return false;
	}
	vector<UuidStruct> dataList = getAllUuidData();
	vector<string> btnList;
	for (UuidStruct data : dataList) {
		if (!data.name.empty()) {
			btnList.push_back(data.name);
		}
		else {
			btnList.push_back(data.serverId);
		}
	}
	sendPlayerList(player, btnList, [dataList](string id) {
		int index = strtol(id.c_str(), nullptr, 10);
		auto &name = dataList[index].name;
		auto plSel = getPlayerByName(name);
		Tag* plData = Tag::createTag(TagType::Compound);
		if (!plSel) {
			auto suuid = findUuidByName(name);
			plData = loadPlayer(suuid);
		}
		else {
			plData = loadPlayer(plSel);
		}
		cout << TagToSNBT(plData) << endl;
		});
	return true;
}

void regListener() {
	Event::addEventListener([](RegCmdEV ev) {
		CMDREG::SetCommandRegistry(ev.CMDRg);
		MakeCommand("llcb", _TR("command.llcb.description"), 1);  //注册指令
		CmdOverload(llcb, oncmd_checkBag);  //重载指令
		});
	Event::addEventListener([](JoinEV ev) {
		UuidStruct uuidStruct;
		auto player = ev.Player;
		auto uuid = getPlayerUuid(player);
		uuidStruct.name = player->getNameTag();
		uuidStruct.xuid = offPlayer::getXUIDString(player);
		uuidStruct.serverId = getServerId(uuid).substr(7);
		tryToSaveUuid(uuid, uuidStruct);
		return true;
		});
}

// init configure and Language Pack
void init() {
	ConfigJReader jr("plugins\\LLCheckBag\\config.json");
	jr.bind("permissionLevel", permissionLevel, 1);
	jr.bind<string>("language", language, "cn");
	initLang("plugins\\LLCheckBag\\langpack_" + language + ".json");
}

void entry() {
	init();
	loadUuiddb();
	regListener();
	std::cout << _TRS("message.loaded") << VERSION << std::endl;
}

THook(string*, "?getServerId@LevelStorage@@QEAA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBUPlayerStorageIds@@@Z",
	void* _this, string& serverId, string& storageId) {
	auto rtn = original(_this, serverId, storageId);
	//cout << "serverId: " << serverId << endl;
	//cout << "storageId: " << storageId << endl;
	return rtn;
}


//void* externalFileLevelStorageSource;
//THook(void*, "??0ExternalFileLevelStorageSource@@QEAA@PEAVFilePathManager@Core@@V?$shared_ptr@VSaveTransactionManager@@@std@@@Z",
//	void* _this, void* a1, void* a2) {
//	auto rtn = original(_this, a1, a2);
//	externalFileLevelStorageSource = _this;
//	//cout << "ExternalFileLevelStorageSource" << endl;
//	//string s;
//	//SymCall("?getWorldsPath@FilePathManager@Core@@QEBA?AV?$PathBuffer@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ",
//	//	void*, void*, string*)(a1, &s);
//	//cout << s << endl;
//
//	//string s1="Bedrock level";
//	//string s2= "Bedrock level Backup";
//	//string s3= "Bedrocklevel3";
//	////ExternalFileLevelStorageSource::createBackupCopyOfWorld(string const&, string const&, string const&)
//	//SymCall("?createBackupCopyOfWorld@ExternalFileLevelStorageSource@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00@Z",
//	//	bool, void*, string*, string*, string*)(_this, &s1, &s2, &s3);
//	//cout << s1<<endl<<s2<<endl<<s3 << endl;
//
//	//cout << "storageId: " << storageId << endl;
//	return rtn;
//}
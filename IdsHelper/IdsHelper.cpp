#include "pch.h"
#include "SymHelper.h"
#include "BdsDbHelper.h"
#include <vector>
#include <sstream>
using namespace std;



bool oncmd_rpd(CommandOrigin const& ori, CommandOutput& outp, std::string id) {
	Tag* playerTag = getPlayerDataById(id);
	if (!playerTag) {
		cout << "获取玩家数据失败" << endl;
		return false;
	}
	cout << TagToSNBT(playerTag) << endl;
	return true;
}
bool oncmd_rdb(CommandOrigin const& ori, CommandOutput& outp, std::string id) {
	Tag* tag = loadFromDBStorage(id);
	if (!tag) {
		cout << "获取玩家数据失败" << endl;
		return false;
	}
	cout << TagToSNBT(tag) << endl;
	return true;
}
bool oncmd_allIds(CommandOrigin const& ori, CommandOutput& outp) {
	printAllIds();
	return true;
}

bool oncmd_tw(CommandOrigin const& ori, CommandOutput& outp, std::string id, std::string path) {
	Tag* tag = loadPlayerFromFile(path);
	if (!tag)
		return false;
	string str1 = TagToSNBT(tag);
	string bin = writeToBinary(tag);
	Tag* tag2 = readFromBinary(bin);
	string str2= TagToSNBT(tag2);
	if (str1 == str2) {
		cout << "测试成功" << endl;
	}
	else {
		cout << "测试失败" << endl;
	}
	//saveToDBStorage(id, tag);
	//saveLevelStorage();
	outp.success("Test Success!");
	return true;
}
void regCmd()
{
	Event::addEventListener([](RegCmdEV ev) {
		CMDREG::SetCommandRegistry(ev.CMDRg);
		MakeCommand("rpd", "read player data", 0);
		MakeCommand("rdb", "read database", 0);
		MakeCommand("tw", "test write", 0);
		CmdOverload(rpd, oncmd_allIds);
		CmdOverload(rpd, oncmd_rpd, "key");
		CmdOverload(rdb, oncmd_rdb, "key");
		CmdOverload(tw, oncmd_tw, "key", "path");
		});
	Event::addEventListener([](ServerStartedEV ev) {
		loadAllIds();
		});
}

void entry()
{
	regCmd();
	std::cout << "[TestSym] TestSym Loaded." << endl;
}


// Player Ids Logger
THook(void*, "?loadPlayerData@PlayerDataSystem@@YA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVLevelStorage@@AEBUPlayerStorageIds@@_N@Z",
	unique_ptr<Tag>& tagPtr, LevelStorage* ls, string psi[6], bool b) {
	cout << "PlayerDataSystem::loadPlayerData(" << tagPtr << ", " << ls << ", \"" << psi << "\", " << b << ");" << endl;
	void* ret = original(tagPtr, ls, psi, b);
	cout << "psi[0]: " << psi[0] << endl;
	cout << "psi[1]: " << psi[1] << endl;
	cout << "psi[2]: " << psi[2] << endl;
	cout << "psi[3]: " << psi[3] << endl;
	cout << "psi[4]: " << psi[4] << endl;
	cout << "psi[4]: " << psi[5] << endl;
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
// DBStorage::loadData(gsl::basic_string_span<char const,-1>,string &)
THook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
	LevelStorage* _this, void* key_span[2], string* bin) {
	string key = string((char*)key_span[1], (int)key_span[0]);
	bool ret = original(_this, key_span, bin);
	//if ((int)((uintptr_t*)bin)[2])
	//	cout << TagToSNBT(BinaryNBTToTag((void*)((uintptr_t*)bin)[0], (int)((uintptr_t*)bin)[2])).substr(0, 120) << endl;
	if (!bin->empty())
		cout << TagToSNBT(BinaryNBTToTag((char*)bin->c_str(), bin->length())).substr(0, 120) << endl;
	cout << "****DBStorage::loadData(" << _this << ", \"" << key << "\", " << key_span << ", "<< ");" << endl;
	return ret;
}

//DBStorage::saveData(string const&, string&&)
THook(void*, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@@Z",
	LevelStorage* _this, void* result, string& key, string& bin) {
	// bin 格式和 string 类似
	if (!bin.empty())
		cout << TagToSNBT(BinaryNBTToTag((void*)bin.c_str(), bin.length())).substr(0, 120) << endl;
	//void* fake_result[2]{};
	void* ret = original(_this, result, key, bin);
	cout << "****DBStorage::saveData(" << _this << ", " << result << ", \"" << key << "\", " << &bin << ");" << endl;

	return ret;
}


//DBStorage::getCompoundTag(string const &)
THook(void*, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
	LevelStorage* _this, unique_ptr<Tag>& tagPtr, string const& key) {
	return original(_this, tagPtr, key);
}

//?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z
THook(void*, "?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
	unique_ptr<Tag>& tagPtr, void** iDataInput[2]) {
	void** tmp;
	tmp = iDataInput[1];
	if (tmp!=nullptr) {
		string data = string((char*)tmp[2], (int)tmp[0]/8);
	}
	auto rtn =  original(tagPtr, iDataInput);
	return rtn;
}

// NbtIo::write(CompoundTag const *,IDataOutput &)
THook(void*, "?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
	Tag* tag, void** iDataOutput[2]) {
	void** tmp;
	tmp = iDataOutput[1];
	string str = TagToSNBT(tag);
	auto rtn = original(tag, iDataOutput);
	if (tmp != nullptr) {
		string data = string((char*)tmp[2], (int)tmp[0]/8);
	}
	return rtn;
}

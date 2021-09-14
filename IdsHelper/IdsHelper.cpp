#include "pch.h"
#include "SymHelper.h"
#include "BdsDbHelper.h"
#include <vector>
#include <sstream>
#include <regex>

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
		cout << "获取数据失败" << endl;
		return false;
	}
	cout << TagToSNBT(tag) << endl;
	return true;
}
bool oncmd_allIds(CommandOrigin const& ori, CommandOutput& outp) {
	printAllIds();
	return true;
}


string getKeyFromChunkDetail(int& cx, int& cz, int& dimid, int& type) {

}
//DBStorage::forEachKeyWithPrefix(gsl::basic_string_span<char const, -1>, std::function<void(gsl::basic_string_span<char const, -1>, gsl::basic_string_span<char const, -1>)> const&)
bool oncmd_test(CommandOrigin const& ori, CommandOutput& outp, std::string str) {
	_flushWriteCacheToLevelDB();
	forEachKeyWithPrefix(str, [](string& key, string& data) {
		if (std::regex_match(key, std::regex("[\\w ,\.\-]*")))
			cout << "key: " << key << ", data.length(): " << data.length() << endl;
		else {
			auto chunkKey = ChunkKey(key);
			string hex_key = byteToHexStr((byte*)key.c_str(), key.length());
			cout << "hex_key: " << hex_key << endl;
			cout << chunkKey.toString() << ", dataLen: " << data.length() << endl;
			if (chunkKey.type == byte('\x31') || chunkKey.type == byte('\x32')) {
				auto tag = readFromBinary(data);
				string bin = writeToBinary(tag);
				if (bin != data.substr(0,bin.length()))
					throw("Error");
				cout << TagToSNBT(tag) << endl;
			}
		}
		});
	return true;

}
bool oncmd_delall(CommandOrigin const& ori, CommandOutput& outp) {
	_flushWriteCacheToLevelDB();
	forEachKeyWithPrefix("", [](string& key, string& data) {
		if (!std::regex_match(key, std::regex("[\\w ,\.\-]*"))) {
			deleteDBStorageData(key);
			_flushWriteCacheToLevelDB();
		}
		});
	return true;
}
bool oncmd_del(CommandOrigin const& ori, CommandOutput& outp, int cx, int cz, int dimid) {
	_flushWriteCacheToLevelDB();
	forEachKeyWithPrefix(ChunkKey(cx, cz, dimid).getPosKeyPrefix(), [](string& key, string& data) {
		deleteDBStorageData(key);
		_flushWriteCacheToLevelDB();
		});
	return true;
}

bool oncmd_list(CommandOrigin const& ori, CommandOutput& outp, int cx, int cz, int dimid) {
	_flushWriteCacheToLevelDB();
	ChunkKey ck = ChunkKey(cx, cz, dimid);
	forEachKeyWithPrefix(ck.getPosKeyPrefix(), [ck](string& key, string& data) {
		if (ChunkKey::getDimid(key) != ck.dimid)
			return;
		string hex_key = byteToHexStr((byte*)key.c_str(), key.length());
		cout << "hex_key: " << hex_key << endl;
		auto chunkKey = ChunkKey(key);
		cout << chunkKey.toString() << ", dataLen: " << data.length() << endl;
		int header_size = data.find(string("\x0A\x00\x00\x00"));
		vector<string> snbts;
		int offset = 0;
		while (offset < data.length())
		{
			string snbt = TagToSNBT(readFromBinary(data, offset));
			if (snbt.length()<3)
				break;
			snbts.emplace_back(snbt);
		}
		auto bin = byteToHexStr((byte*)data.c_str(), data.length(), "\\x");
		string path = "D:\\bds\\LXL_Plugins\\leveldb\\" + hex_key + ".bin";
		saveToFile(path, data);
		for (auto& snbt : snbts) {
			cout << snbt << endl;
		}
		});
	return true;
}
void regCmd()
{
	Event::addEventListener([](RegCmdEV ev) {
		CMDREG::SetCommandRegistry(ev.CMDRg);
		MakeCommand("rpd", "read player data", 0);
		MakeCommand("rdb", "read database", 0);
		MakeCommand("test", "test write", 0);
		MakeCommand("delall", "delete all", 0);
		MakeCommand("del", "delete Chunk", 0);
		MakeCommand("listc", "delete Chunk", 0);
		CmdOverload(rpd, oncmd_allIds);
		CmdOverload(rpd, oncmd_rpd, "key");
		CmdOverload(rdb, oncmd_rdb, "key");
		CmdOverload(test, oncmd_test, "test");
		CmdOverload(delall, oncmd_delall);
		CmdOverload(del, oncmd_del, "cx", "cz", "dimid");
		CmdOverload(listc, oncmd_list, "cx", "cz", "dimid");
		});
	Event::addEventListener([](ServerStartedEV ev) {
		loadAllIds();
		});
}

void entry()
{
	//int a = -15593200;
	//byte* bytes;
	//bytes = intToBytes(a, 4);
	//int b = bytesToInt(bytes, 4);
	////269554195
	//cout << byteToHexStr(bytes, 4)<<": " << bytesToInt(bytes, 4) << endl;

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
	cout << "psi[5]: " << psi[5] << endl;
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
	cout << "****DBStorage::loadData(" << _this << ", \"" << key << "\", " << key_span << ", " << ");" << endl;
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
	//if (iDataInput[0] == dlsym("??_7RakDataInput@@6B@")) {
	//	string data = string((char*)tmp[2], (int)tmp[0] / 8);
	//}
	auto rtn = original(tagPtr, iDataInput);
	return rtn;
}

// NbtIo::write(CompoundTag const *,IDataOutput &)
THook(void*, "?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
	Tag* tag, void** iDataOutput[3]) {
	void** tmp;
	tmp = iDataOutput[1];
	string str = TagToSNBT(tag);
	auto rtn = original(tag, iDataOutput);
	return rtn;
}

//Tag::writeNamedTag(string const&, Tag const&, IDataOutput&)
THook(void*, "?writeNamedTag@Tag@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV1@AEAVIDataOutput@@@Z",
	string* key,Tag* tag,  void** iDataOutput[3]) {
	void** tmp;
	tmp = iDataOutput[1];
	//cout << "path: " << (char*)iDataOutput[2] << endl;
	//cout << "key: " << *key << endl;
	//cout << TagToSNBT(tag) << endl;
	//string str = TagToSNBT(tag);
	auto rtn = original(key, tag, iDataOutput);
	return rtn;
}

THook(void*, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
	void* _this, void** a1, void** a2) {
	string str = string((char*)a1[1], (int)a1[0]);
	auto rtn = original(_this, a1, a2);
	return rtn;
}
THook(bool, "?_hasChunk@DBChunkStorage@@AEAA_NAEBVDBChunkStorageKey@@@Z",
	void* _this, void** dbChunkStorageKey) {
	auto rtn = original(_this, dbChunkStorageKey);
	return rtn;
}
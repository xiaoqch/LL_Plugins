#include "pch.h"
#include "BdsDbHelper.h"

using namespace std;

std::map<std::string, PlayerIds> allPlayerIds;


bool loadAllIds() {
	auto ids=loadAllPlayerIDs(true);
	for (auto& id : ids) {
		if (id.find("server_") != 0) {
			string playerKey = "player_" + id;
			auto keyTag = loadFromDBStorage(playerKey);
			if (!keyTag)
				continue;
			auto& playerTag = keyTag->asCompound();
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
	return true;
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

Tag* getPlayerDataById(string& id) {
	for (auto& [key, value] : allPlayerIds) {
		if (value.MsaId == id || value.PlatformOfflineId == id || value.PlatformOnlineId == id
			|| value.SelfSignedId == id || value.ServerId == id)
			return loadFromDBStorage(value.ServerId);
	}
	return nullptr;
}

Tag* loadPlayerFromFile(string& path) {
	fstream fs(path, ios_base::in);
	string res((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
	fs.close();
	return SNBTToTag(res);
}
Tag* readFromBinary(string& bin) {
	void* vtbl = dlsym("??_7RakDataInput@@6B@");
	size_t nullVal = 0;
	size_t data_struct[3] = { bin.length()*8, nullVal, (size_t)bin.c_str() };
	void* iDataInput[2] = { vtbl , data_struct };
	Tag* tag = Tag::createTag(TagType::Compound);
	auto tagPtr = make_unique<Tag>(*tag);
	auto rtn= SymCall("?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
		unique_ptr<Tag>*, unique_ptr<Tag>&, void*)(tagPtr, (void*)iDataInput);
	return rtn->get();
}

string& writeToBinary(Tag* tag) {
	void* vtbl = dlsym("??_7RakDataOutput@@6B@");
	string str = "";
	size_t data_struct[3] = { str.length() , 0, (size_t)str.c_str() };
	void* iDataOutput[2] = { vtbl , data_struct };
	SymCall("?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
		void*, Tag*, void*)(tag, (void*)iDataOutput);
	string res = string(data_struct[2], (int)data_struct[0]/8);
	return res;
}

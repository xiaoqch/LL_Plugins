#pragma once
#include "SymHelper.h"


struct PlayerIds
{
	string MsaId;
	string PlatformOnlineId;
	string PlatformOfflineId;
	string SelfSignedId;
	string ServerId;
};
extern std::map<std::string, PlayerIds> allPlayerIds;

void printAllIds();
bool loadAllIds();
Tag* getPlayerDataById(string& id);
Tag* loadPlayerFromFile(string& path);
Tag* readFromBinary(string& bin);
string& writeToBinary(Tag* tag);
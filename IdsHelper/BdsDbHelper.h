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

class ChunkKey {
public:
	string bytes;
	int cx;
	int  cz;
	int  dimid;
	byte type;
	byte index;
	ChunkKey(const string& bytes);
	ChunkKey(int cx, int cz, int dimid, byte type = byte(0x2C), byte index = byte(0));
	bool hasIndex();
	string getPosKeyPrefix();
	string getKey();
	ChunkPos getChunkPos();
	int getDimid();
	static int getDimid(string bytes);
	string toString();
};

void printAllIds();
bool loadAllIds();
Tag* getPlayerDataById(string& id);
Tag* loadPlayerFromFile(string& path);
Tag* readFromBinary(string& bin, int& end_offset);
Tag* readFromBinary(string& bin);
string writeToBinary(Tag* tag);


std::string byteToHexStr(byte* byte_arr, int arr_len, string prefix = "");
int bytesToInt(byte* bytes, int size = 4);
byte* intToBytes(int i, int size = 4);

void saveToFile(string& path, string& data);
string loadFromFile(string& path);
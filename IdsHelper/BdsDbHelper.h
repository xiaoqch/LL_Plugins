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

    enum class ChunkKeyType : unsigned char {
        ChunkVersion = '\x2C', // byte
        HeightMapAndBiomes = '\x2D', // short[16*16] + byte[16*16]
        ChunkData = '\x2F', // version, block id, block palette, ...
        BlockEntity = '\x31', // binary_nbts
        Entity = '\x32', // binary_nbts
        ScheduleTicks = '\x33', // binary_nbts
        BlockExtraData = '\x34', // 
        BiomeState = '\x35', // num: byte  + short[num]
        ChunkStatus = '\x36', // int within [0:2]
        FireTick = '\x3A', // fire tick?
        ChunkVersion_2 = '\x76', // 

        Unknown_1 = '\x39', // 7 ints and an end (03)?
        Unknown_2 = '\x3B', // 

        Legacy2D = '\x2E', // 
        LegacyTerrain = '\x30'  // 
    };

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
Tag* readFromBinary(string& bin, size_t& offset, bool isLittleEndian = true);
Tag* readFromBinary(string& bin, bool isLittleEndian = true);
string writeToBinary(Tag* tag, bool isLittleEndian = true);

std::string byteToHexStr(byte* byte_arr, int arr_len, string prefix = "");
int bytesToInt(byte* bytes, int size = 4);
byte* intToBytes(int i, int size = 4);

void saveToFile(string& path, string& data);
string loadFromFile(string& path);
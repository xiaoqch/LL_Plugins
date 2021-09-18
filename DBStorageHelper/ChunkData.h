#pragma once
#include <nbt-from-lxl/NBT.h>
class ChunkData
{
    ChunkPos pos;
    int dimid;
    string keyPrefix;
public:
    enum class KeyType : unsigned char {
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
    ChunkData(int cx, int cy, int dimid);
    ChunkData(string& key);
    string getKey(KeyType type, int cy);
    string getData(KeyType type, int cy);
    int getVersion();
    int getHightAt(int x, int y);
    int getBiomeIdAt(int x, int y);
    vector<Tag*> getEntitys();
    vector<Tag*> getBlockEntitys();
    vector<Tag*> getScheduleTicks();
    //vector<Tag*> getBlockExtraData();
    short getBiomeState();
    int getChunkStatus();
    //void* getFireTick();
};


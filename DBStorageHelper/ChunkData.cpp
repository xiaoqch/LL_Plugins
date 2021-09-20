#include "pch.h"
#include "ChunkData.h"
#include "Utils.h"
#include "SymHelper.h"
using namespace std;

ChunkData::ChunkData(int cx, int cz, int dimid) {
	this->dbStorage = getDBStorage();
	this->pos = { cx, cz };
	this->dimid = dimid;
	size_t keyLen = dimid == 0 ? 8 : 12;
	this->keyPrefix = string("", keyLen);
	toBytes<int>((byte*)keyPrefix.c_str(), cx, true);
	toBytes<int>((byte*)keyPrefix.c_str()+4, cz, true);
	if (dimid != 0) {
		toBytes<int>((byte*)keyPrefix.c_str()+8, dimid, true);
	}
}
ChunkData::ChunkData(string& key) {
	this->dbStorage = getDBStorage();
	this->pos.x = *(int*)key.c_str();
	this->pos.z = *(int*)(key.c_str() + 4);
	reverseBytes((byte*)&(this->pos.x), 4);
	reverseBytes((byte*)&(this->pos.z), 4);
	if (key.length() >= 12) {
		this->dimid = *(int*)(key.c_str() + 8);
		reverseBytes((byte*)&(this->dimid), 4);
		this->keyPrefix = key.substr(12);
	}
	else {
		this->dimid = 0;
		this->keyPrefix = key.substr(8);
	}
}

string ChunkData::getKey(KeyType type, int cy)
{
	return this->keyPrefix+char(type)+char(cy);
}

string ChunkData::getData(KeyType type, int cy)
{
	return string();
}

int ChunkData::getVersion()
{
	return 0;
}

int ChunkData::getHightAt(int x, int y)
{
	return 0;
}

int ChunkData::getBiomeIdAt(int x, int y)
{
	return 0;
}

vector<Tag*> ChunkData::getEntitys()
{
	return vector<Tag*>();
}

vector<Tag*> ChunkData::getBlockEntitys()
{
	return vector<Tag*>();
}

vector<Tag*> ChunkData::getScheduleTicks()
{
	return vector<Tag*>();
}

short ChunkData::getBiomeState()
{
	return 0;
}

int ChunkData::getChunkStatus()
{
	return 0;
}

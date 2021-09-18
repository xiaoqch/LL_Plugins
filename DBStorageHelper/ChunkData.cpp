#include "pch.h"
#include "ChunkData.h"
#include "Utils.h"

using namespace std;

ChunkData::ChunkData(int cx, int cz, int dimid) {
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

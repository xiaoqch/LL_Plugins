#pragma once
#include <vector>
#include <string>
#include <map>
#include <api/types/types.h>

using namespace std;
enum TagType : uint8_t {
	End, Byte, Short, Int, Long, Float, Double, ByteArray, String, List, Compound,
};

class Player;
class Actor;
class Block;
class ItemStack;

struct TagMemoryChunk {
	size_t capacity = 0;
	size_t size = 0;

	unique_ptr<uint8_t[]> data;

	TagMemoryChunk(size_t size, uint8_t data[]) :capacity(size), size(size), data(data) {}
};

class Tag {
private:
	char filler[0x28];
public:
	//share
	static Tag* createTag(TagType t);
	char getTagType();

	//value
	char& asByte();
	short& asShort();
	int& asInt();
	__int64& asLong();
	float& asFloat();
	double& asDouble();
	std::string& asString();
	std::vector<Tag*>& asList();
	std::map<std::string, Tag>& asCompound();
	TagMemoryChunk& asByteArray();

	//compound
	void put(const std::string& k, Tag* v);
	void putEnd(const std::string& k);
	void putShort(const std::string& k, short v);
	void putString(const std::string& k, std::string v);
	void putInt(const std::string& k, int v);
	void putLong(const std::string& k, __int64 v);
	void putFloat(const std::string& k, float v);
	void putDouble(const std::string& k, double v);
	void putCompound(const std::string& k, Tag* v);
	void putByte(const std::string& k, char v);
	void putByteArray(const std::string& key, const TagMemoryChunk& value);
	void putByteArray(const std::string& key, void* data, size_t size);
	void destroy();

	//list
	void add(Tag* t);
	void addEnd();
	void addByte(char v);
	void addShort(short v);
	void addInt(int v);
	void addLong(__int64 v);
	void addFloat(float v);
	void addDouble(double v);
	void addString(const string& v);
	void addByteArray(void* data, size_t size);

	//static
	void setItem(ItemStack* item);
	void setBlock(Block* blk);
	bool setActor(Actor* actor);
	bool setPlayer(Player* actor);
	bool setBlockEntity(BlockActor* ble);
	static Tag* fromItem(ItemStack* item);
	static Tag* fromBlock(Block* blk);
	static Tag* fromActor(Actor* actor);
	static Tag* fromPlayer(Player* player);
	static Tag* fromBlockEntity(BlockActor* ble);
};

//std::string TagToJson(Tag* nbt, int formatIndent);
std::string TagToSNBT(Tag* nbt);
std::string TagToBinaryNBT(Tag* nbt);
Tag* SNBTToTag(const std::string& snbt);
Tag* BinaryNBTToTag(void* data, size_t len);
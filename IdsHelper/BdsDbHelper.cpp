#include "pch.h"
#include "BdsDbHelper.h"
#include <variant>
using namespace std;

std::map<std::string, PlayerIds> allPlayerIds;


bool loadAllIds() {
	auto ids = loadAllPlayerIDs(true);
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
	return SNBTToTag(loadFromFile(path));
}

string loadFromFile(string& path) {
	ifstream fs(path, ios::in | ios::binary);
	string res((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
	fs.close();
	return res;
}
void saveToFile(string& path, string& data) {
	ofstream fs(path, ios::out | ios::binary);
	fs.write(data.c_str(), data.length());
	fs.flush();
	fs.close();
}

Tag* readFromBinary2(string& bin, int& offset) {
	// bits version
	void* vtbl = dlsym("??_7RakDataInput@@6B@");
	uintptr_t data_struct[3] = { bin.length() * 8, offset, (uintptr_t)bin.c_str() };
	void* iDataInput[2] = { vtbl , data_struct };
	Tag* tag = Tag::createTag(TagType::Compound);
	auto rtn = SymCall("?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
		unique_ptr<Tag>*, Tag**, void*)(&tag, (void*)iDataInput);
	offset = data_struct[1] / 8;
	return rtn->get();
}

Tag* readFromBinary(string& bin, int& offset, bool isLittleEndian) {
	void* vtbl = dlsym("??_7StringByteInput@@6B@");
	//void* vtbl2 = dlsym("??_7BigEndianStringByteInput@@6B@");
	uintptr_t iDataInput[4] = { (uintptr_t)vtbl ,offset, bin.length(), (uintptr_t)bin.c_str() };
	Tag* tag = Tag::createTag(TagType::Compound);
	auto rtn = SymCall("?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
		unique_ptr<Tag>*, Tag**, void*)(&tag, (void*)iDataInput);
	offset = iDataInput[1];
	return rtn->get();
}

Tag* readFromBinary(string& bin, bool isLittleEndian) {
	int offset = 0;
	return readFromBinary(bin, offset);
}

// Reference to StringByteOutput and BigEndianStringByteInput
class BigEndianStringByteOutput {
	void writeBigEndianBytes(byte* bytes, size_t count) {
		auto v5 = bytes + count - 1;
		if (v5 >= bytes)
		{
			auto v7 = bytes + 1;
			do
			{
				auto v8 = *(v7 - 1);
				*(v7 - 1) = *v5;
				*v5-- = v8;
			} while (v7++ <= v5);
		}
		writeBytes(bytes, count);
	}
public:
	virtual ~BigEndianStringByteOutput() {};
	virtual void* writeString(void* string_span) {
		return SymCall("?writeString@BytesDataOutput@@UEAAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
			void*, void*, void*)((void*)this, string_span);
	}
	virtual void* writeLongString(void* string_span) {
		return SymCall("?writeLongString@BytesDataOutput@@UEAAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
			void*, void*, void*)((void*)this, string_span);
	}
	virtual void writeFloat(float data) {
		writeBigEndianBytes((byte*)&data, 4);
	}
	virtual void writeDouble(double data) {
		writeBigEndianBytes((byte*)&data, 8);
	}
	virtual void writeByte(byte data) {
		writeBytes(&data, 1);
	}
	virtual void writeShort(short data) {
		writeBigEndianBytes((byte*)&data, 2);
	}
	virtual void writeInt(int data) {
		writeBigEndianBytes((byte*)&data, 4);
	}
	virtual void writeLongLong(long long data) {
		writeBigEndianBytes((byte*)&data, 8);
	}
	virtual void* writeBytes(byte* bytes, size_t count) {
		return SymCall("?writeBytes@StringByteOutput@@UEAAXPEBX_K@Z",
			void*, void*, byte*, size_t)((void*)this, bytes, count);
	}
};

string writeToBinary(Tag* tag, bool isLittleEndian) {
	void* vtbl;
	if (isLittleEndian) {
		vtbl = dlsym("??_7StringByteOutput@@6B@");
	}
	else {
		auto tmp = BigEndianStringByteOutput();
		vtbl = *(void***)&tmp;
	}
	//void* vtbl2 = dlsym("??_7BigEndianStringByteOutput@@6B@"); // deleted
	string result = "";
	void* iDataOutput[2] = { vtbl , &result };
	SymCall("?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
		void*, Tag*, void*)(tag, (void*)iDataOutput);
	return result;
}

std::string byteToHexStr(byte* byte_arr, int arr_len, string prefix)
{
	std::string hexstr;
	//
	for (int i = 0; nullptr != byte_arr && i < arr_len; ++i)
	{
		char hex1;
		char hex2;

		/*借助C++支持的unsigned和int的强制转换，把unsigned char赋值给int的值，那么系统就会自动完成强制转换*/
		int value = (int)byte_arr[i];
		int S = value / 16;
		int Y = value % 16;

		//将C++中unsigned char和int的强制转换得到的商转成字母
		if (S >= 0 && S <= 9)
		{
			hex1 = (char)(48 + S);
		}
		else
		{
			hex1 = (char)(55 + S);
		}

		//将C++中unsigned char和int的强制转换得到的余数转成字母
		if (Y >= 0 && Y <= 9)
		{
			hex2 = (char)(48 + Y);
		}
		else
		{
			hex2 = (char)(55 + Y);
		}

		//最后一步的代码实现，将所得到的两个字母连接成字符串达到目的
		hexstr = hexstr + prefix + hex1 + hex2;
	}

	return hexstr;
}

//————————————————
//版权声明：本文为CSDN博主「一代程序码农」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/houwenbin1986/article/details/90231744

byte* intToBytes(int i, int size)
{
	byte bytes[4] = {};
	int loc = 0xff;
	int index = 0;
	while (index < size) {
		bytes[index] = (byte)((loc & i) >> 8 * index);
		++index;
		loc <<= 8;
	}
	return bytes;
}

int bytesToInt(byte* bytes, int size)
{
	int loc = 0xff;
	int index = 0;
	int addr = 0;
	while (index < size) {
		addr |= (((int)bytes[index] << 8 * index) & loc);
		++index;
		loc <<= 8;
	}
	return addr;
}

bool getChunkDetailFromKey(string& bytes, int& cx, int& cz, int& dimid, byte& type, byte& index) {
	int len = bytes.length();
	cx = bytesToInt((byte*)bytes.c_str());
	cz = bytesToInt((byte*)bytes.c_str() + 4);
	if (len == 9 || len == 10) {
		dimid = 0;
		type = (byte)bytes[8];
		if (len == 10)
			index = (byte)bytes[9];
		else
			index = (byte)-1;
	}
	else if (len == 13 || len == 14) {
		dimid = bytesToInt((byte*)bytes.c_str() + 8);
		type = (byte)bytes[12];
		if (len == 14)
			index = (byte)bytes[13];
		else
			index = (byte)-1;
	}
}

string getKeyFromChunkDetail(int cx, int cz, int dimid, byte type, byte index = (byte)-1) {
	string res = string((char*)intToBytes(cx), 4);
	res += string((char*)intToBytes(cz), 4);
	if (dimid != 0)
		res += string((char*)intToBytes(dimid), 4);

}
//struct ChunkDetail {
//	long cx;
//	long cy;
//	long cz;
//	byte type;
//	byte index;
//	bool hasIndex() {
//		return this->index == (byte)0x2F;
//	};
////};
//extern class ChunkKey {
//public:
//	string bytes;
//	int cx;
//	int  cz;
//	int  dimid;
//	byte type;
//	byte index;




ChunkKey::ChunkKey(const string& bytes) :bytes(bytes) {
	this->bytes = bytes;
	int len = bytes.length();
	cx = bytesToInt((byte*)bytes.c_str());
	cz = bytesToInt((byte*)bytes.c_str() + 4);
	if (len == 9 || len == 10) {
		dimid = 0;
		type = (byte)bytes[8];
		if (len == 10)
			index = (byte)bytes[9];
	}
	else if (len == 13 || len == 14) {
		dimid = bytesToInt((byte*)bytes.c_str() + 8);
		type = (byte)bytes[12];
		if (len == 14)
			index = (byte)bytes[13];
	}
}
ChunkKey::ChunkKey(int cx, int cz, int dimid, byte type, byte index) {
	this->cx = cx;
	this->bytes += string((char*)intToBytes(cx), 4);
	this->cz = cz;
	this->bytes += string((char*)intToBytes(cz), 4);
	this->dimid = dimid;
	if (dimid != 0)
		this->bytes += string((char*)intToBytes(dimid), 4);
	this->type = type;
	this->bytes += (char)type;
	if (ChunkKey::hasIndex()) {
		this->index = index;
		this->bytes += (char)index;
	}
}
bool ChunkKey::hasIndex() {
	return this->index == byte(0x2F);
}
string ChunkKey::getPosKeyPrefix() {
	if (dimid != 0) {
		return bytes.substr(0, 12);
	}
	else {
		return bytes.substr(0, 8);
	}
}
string ChunkKey::getKey() {
	return bytes;
}
ChunkPos ChunkKey::getChunkPos() {
	return { (int)cx, (int)cz };
}
int ChunkKey::getDimid() {
	return dimid;
}
int ChunkKey::getDimid(string bytes) {
	int len = bytes.length();
	if (len == 9 || len == 10) {
		return 0;
	}
	else {
		return bytesToInt((byte*)bytes.c_str() + 8);
	}
}
string ChunkKey::toString() {
	char buff[50] = {};
	if (hasIndex())
		sprintf_s(buff, "cx: %6d, cz: %6d, dim: %d, type: %3d-%3d", cx, cz, dimid, type, index);
	else
		sprintf_s(buff, "cx: %6d, cz: %6d, dim: %d, type: %3d    ", cx, cz, dimid, type);
	return buff;
}

void loadSubChunk(int cx, int cy, int cz) {
	string data;
	string blockIds = {};
	string blockData = {};
	string combinedPalette = {};
	string blockArray = {};
	int offset = 0;
	int storageCount;
	if (data[0] == '\x00' || (data[0] >= '\x02' && data[0] <= '\x07')) {
		++offset;
		blockIds = data.substr(offset, 16 * 16 * 16);
		offset += 16 * 16 * 16;
		blockData = data.substr(offset, 16 * 16 * 8);
	}
	else if (data[0] == '\x00' || data[0] == '\x08') {
		// load block palette
		if (data[0] == '\x00') {
			storageCount = 1;
			++offset;
		}
		else {
			storageCount == (int)data[1];
			offset += 2;
		}
		auto bits_per_block = data[offset] >> 1;
		++offset;
		auto blocks_per_word = 32 / bits_per_block;
		auto world_count = -(-4096 / blocks_per_word);
		//get blocks
		offset += 4 * world_count;
		auto palette_len = bytesToInt((byte*)data.c_str(), 4);
		offset += 4;
		vector<Tag*> palette;
		for (auto i = 0; i < palette_len; ++i) {
			palette.emplace_back(readFromBinary(data, offset));
		}
	}
	else {
		throw("Sub Chunk version unknown");
	}

}
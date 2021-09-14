#include "pch.h"
#include "BdsDbHelper.h"

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
	fstream fs(path, ios_base::in);
	string res((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
	fs.close();
	return res;
}
void saveToFile(string& path, string& data) {
	fstream fs(path, ios_base::out);
	fs.write(data.c_str(), data.length());
	fs.flush();
	fs.close();
}

Tag* readFromBinary(string& bin, int& offset) {
	void* vtbl = dlsym("??_7RakDataInput@@6B@");
	size_t data_struct[3] = { bin.length() * 8, offset, (size_t)bin.c_str() };
	void* iDataInput[2] = { vtbl , data_struct };
	Tag* tag = Tag::createTag(TagType::Compound);
	auto rtn = SymCall("?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
		unique_ptr<Tag>*, Tag**, void*)(&tag, (void*)iDataInput);
	offset = data_struct[1]/8;
	return rtn->get();
}

Tag* readFromBinary(string& bin) {
	int end_offset = 0;
	return readFromBinary(bin, end_offset);
}
string writeToBinary(Tag* tag) {
	void* vtbl = dlsym("??_7StringByteOutput@@6B@");
	string output = "";
	void* iDataOutput[2] = { vtbl , &output};
	SymCall("?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
		void*, Tag*, void*)(tag, (void*)iDataOutput);
	return output;
}

std::string byteToHexStr(byte* byte_arr, int arr_len, string prefix)
{
	std::string hexstr;
	//
	for (int i = 0; nullptr != byte_arr && i < arr_len; ++i)
	{
		char hex1;
		char hex2;

		/*����C++֧�ֵ�unsigned��int��ǿ��ת������unsigned char��ֵ��int��ֵ����ôϵͳ�ͻ��Զ����ǿ��ת��*/
		int value = (int)byte_arr[i];
		int S = value / 16;
		int Y = value % 16;

		//��C++��unsigned char��int��ǿ��ת���õ�����ת����ĸ
		if (S >= 0 && S <= 9)
		{
			hex1 = (char)(48 + S);
		}
		else
		{
			hex1 = (char)(55 + S);
		}

		//��C++��unsigned char��int��ǿ��ת���õ�������ת����ĸ
		if (Y >= 0 && Y <= 9)
		{
			hex2 = (char)(48 + Y);
		}
		else
		{
			hex2 = (char)(55 + Y);
		}

		//���һ���Ĵ���ʵ�֣������õ���������ĸ���ӳ��ַ����ﵽĿ��
		hexstr = hexstr + prefix + hex1 + hex2;
	}

	return hexstr;
}

//��������������������������������
//��Ȩ����������ΪCSDN������һ��������ũ����ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/houwenbin1986/article/details/90231744

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
ChunkKey::ChunkKey(const string& bytes):bytes(bytes) {
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
	if(hasIndex())
		sprintf_s(buff, "cx: %6d, cz: %6d, dim: %d, type: %3d-%3d", cx, cz, dimid, type, index);
	else
		sprintf_s(buff, "cx: %6d, cz: %6d, dim: %d, type: %3d    ", cx, cz, dimid, type);
	return buff;
}
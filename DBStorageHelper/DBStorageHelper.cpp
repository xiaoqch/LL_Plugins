#include "pch.h"
#include "DBStorageHelper.h"
#include "SymHelper.h"



string bytesToHexStr(byte* byte_arr, int arr_len, const string& prefix)
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
string bytesToHexStr(const string& str, const string& prefix) {
	return bytesToHexStr((byte*)str.c_str(), str.length(), prefix);
}
string keyToString(const string& key, const string& prefix) {
	if (std::regex_match(key, std::regex("[\\w ,\.\-]*")))
		return key;
	return bytesToHexStr(key, prefix);
}


string string_span::toString()
{
	return string(str, len);
}

DBStorageHelper::DBStorageHelper(DBStorage* dbStorage)
{
	this->db = dbStorage;
}
bool DBStorageHelper::hasKey(const string& key) {
	auto keySpan = string_span::fromString(key);
	return this->db->hasKey(keySpan);
}
string DBStorageHelper::getBinaryData(const string& key) {
	if (!this->hasKey(key))
		return "";
	string_span key_span = string_span::fromString(key);
	string binary;
	this->db->loadData(key_span, binary);
	return binary;
};

Tag* DBStorageHelper::getCompoundTag(const string& key) {
	if (!this->hasKey(key))
		return nullptr;
	auto tag = Tag::createTag(TagType::Compound);
	//auto tagPtr = make_unique<Tag*>(tag);
	auto rtn = this->db->getCompoundTag(&tag, key);
	return rtn->get();
}

vector<Tag*> DBStorageHelper::getCompoundTags(const string& key) {
	if (!this->hasKey(key))
		return vector<Tag*>();
	string binary = this->getBinaryData(key);
	return BinaryNBTToTags(binary);
}

bool DBStorageHelper::forEachKeyWithPrefix(const string& prefix, function<void(const string& key, string& bin)> const& func) {
	auto prefixSpan = string_span::fromString(prefix);
	return this->db->forEachKeyWithPrefix(prefixSpan, [prefixSpan, func](string_span leftSpan, string_span binSpan) {
		string key = ((string_span)prefixSpan).toString() + leftSpan.toString();
		string bin = binSpan.toString();
		func(key, bin);
		});
}

vector<string> DBStorageHelper::getKeysWithPrefix(const string& prefix) {
	vector<string> keys;
	this->forEachKeyWithPrefix(prefix, [&keys](const string& key, string& bin) {
		keys.emplace_back(key);
		});
	return keys;
}
IAsyncResult<void> DBStorageHelper::createAsyncResult() {
	return {};
}

bool DBStorageHelper::saveBinary(const string& key, string& binary) {
	auto result = this->createAsyncResult();
	this->db->saveData(result, key, binary);
	return result.completeResult->availableSetCountOfOne();
}

bool DBStorageHelper::saveTags(const string& key, vector<Tag*> tags) {
	string binary = TagsToBinaryNBT(tags);
	return this->saveBinary(key, binary);
}

bool DBStorageHelper::saveTag(const string& key, Tag* tag) {
	string binary = TagToBinaryNBT(tag);
	return this->saveBinary(key, binary);
}

vector<PortalRecord> DBStorageHelper::getPortals() {
	vector<PortalRecord> portals;
	auto portalsTag = getCompoundTag("portals");
	if (!portalsTag)
		return portals;
	auto& prList =portalsTag->asCompound()["data"].asCompound()["PortalRecords"].asList();
	for (auto& pTag : prList) {
		portals.emplace_back(PortalRecord(pTag));
	}
	return portals;
}

bool DBStorageHelper::setPortals(vector<PortalRecord> portals){
	Tag* prList = Tag::createTag(TagType::List);
	for (auto& pr : portals) {
		prList->add(pr.toTag());
	}
	Tag* data = Tag::createTag(TagType::Compound);
	data->put("PortalRecords", prList);
	Tag* portalsTag = Tag::createTag(TagType::Compound);
	//portalsTag->putCompound("data", data);
	portalsTag->put("data", data);
	cout << TagToSNBT(portalsTag) << endl;
	auto res = this->saveTag("portals", portalsTag);
	if (res) {
		SavedData* SavedDataStorage = getSavedData();
		void* a4 = dAccess<void*>(getLevel(), 277 * 8);
		//SavedDataStorage::set(SavedDataStorage, (__int64)&"portals", (__int64)v8[277].lpVtbl);
		return SymCall("?set@SavedDataStorage@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVSavedData@@@Z",
			bool, SavedData*,const string&, void*)(SavedDataStorage, "portals", a4);
	}
	return res;
}



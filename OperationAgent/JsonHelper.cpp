#include "pch.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <filesystem>
#include "JsonHelper.h"
#include "rapidjson/prettywriter.h"

const std::string CONF_PATH = "plugins/OperationAgent/config.json";
// 储存状态用（用于上线自动骑乘和晚上自动睡觉等）
const std::string DATA_PATH = "plugins/OperationAgent/data.json";

rapidjson::Document config, dataDom;


bool loadConf() {
	std::ifstream fs;
	fs.open(CONF_PATH, std::ios::in);
	if (!fs) {
		std::cout <<"[Operation Agent] 没找到 " << CONF_PATH << " 文件，即将创建新配置文件" << std::endl;
		std::filesystem::create_directory("plugins/OperationAgent");
		std::ofstream of(CONF_PATH);
		if (of) {
			std::string defaultConf = "{\n    \"autoClean\": true,\n    \"cancelAfterSleep\": true,\n    \"cancelAfterRide\": true,\n    \"autoSleep\": true,\n    \"autoRideWhenJoin\": true,\n    \"useNewProjectMode\": true,\n    \"forProjectile\": true,\n    \"forAttack\": true,\n    \"forSleep\": true,\n    \"forMove\": false,\n    \"forRide\": true\n}";
			of << defaultConf;
			config.Parse(defaultConf.c_str());
			return true;
		}
		else {
			std::cerr << "[Operation Agent] 配置文件创建失败" << std::endl;
			return false;
		}
	}
	else {
		std::string json;
		char buf[1024];
		while (fs.getline(buf, 1024)) {
			json.append(buf);
		}
		config.Parse(json.c_str());
	return true;
	}
	return false;
}

template<typename T>
T getConf(std::string key, T defaultValue) {
	if (config.IsNull()) {
		if (!loadConf()) {
			return defaultValue;
		}
	}
	if (config.HasMember(key.c_str())) {
		return config[key.c_str()].Get<T>();
	}
	else {
		return defaultValue;
	}
}
template bool getConf(std::string key, bool defaultValue);
template int getConf(std::string key, int defaultValue);


bool writeData() {
	std::filesystem::create_directory("plugins/OperationAgent");
	std::ofstream of(DATA_PATH);
	if (of) {
		rapidjson::StringBuffer buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
		dataDom.Accept(writer);
		of << buffer.GetString();
		return true;
	}
	else {
		std::cerr << "[Operation Agent] 配置文件创建失败" << std::endl;
		return false;
	}
}
bool loadData() {
	std::ifstream fs;
	fs.open(DATA_PATH, std::ios::in);
	if (!fs) {
		std::cout << "[Operation Agent] 没找到 " << DATA_PATH << " 文件，即将创建新数据文件" << std::endl;
		dataDom.Parse("{}");
		return writeData();
	}
	else {
		std::cout << "[Operation Agent] 正在加载数据文件 " << DATA_PATH << std::endl;
		std::string json;
		char buf[1024];
		while (fs.getline(buf, 1024)) {
			json.append(buf);
		}
		dataDom.Parse(json.c_str());
		return true;
	}
}


template<typename T>
T getData(std::string key) {
	if (dataDom.IsNull()) {
		if (!loadData()) {
			return NULL;
		}
	}
	if (dataDom.HasMember(key.c_str())) {
		return dataDom[key.c_str()].Get<T>();
	}
	else {
		return NULL;
	}
}

// 废弃代码
bool setData(std::string skey, rapidjson::Value& value) {
	rapidjson::Value key(rapidjson::kStringType);
	key.SetString(skey.c_str(), dataDom.GetAllocator());
	if (dataDom.HasMember(key)) {
		//dataDom[key].Set<T>(value, dataDom.GetAllocator());
		dataDom[key] = value;
	}
	else
	{
		dataDom.AddMember(key, value, dataDom.GetAllocator());
	}
	return writeData();
}


bool deleteData(std::string skey) {
	rapidjson::Value key(rapidjson::kStringType);
	key.SetString(skey.c_str(), dataDom.GetAllocator());
	if (dataDom.HasMember(key)) {
		dataDom.RemoveMember(key);
		return writeData();
	}
	return false;
}
bool deleteData(long long key) {
	return deleteData(std::to_string(key));
}

bool setSleepData(long long auid , BlockPos bpos, optional<std::string> remark) {
	if (dataDom.IsNull()) {
		if (!loadData()) {
			return false;
		}
	}
	rapidjson::Document::AllocatorType& allocator = dataDom.GetAllocator();
	rapidjson::Value dataObj(rapidjson::kObjectType);
	dataObj.SetObject();
	dataObj.AddMember("type", "Sleep", allocator);
	rapidjson::Value bposArray(rapidjson::kArrayType);
	bposArray.PushBack(bpos.x, allocator);
	bposArray.PushBack(bpos.y, allocator);
	bposArray.PushBack(bpos.z, allocator);
	dataObj.AddMember("bedPos", bposArray, allocator);
	if (remark.set) {
		rapidjson::Value strRemark(rapidjson::kStringType);
		strRemark.SetString(remark.val().c_str(), dataDom.GetAllocator());
		dataObj.AddMember("remark", strRemark, allocator);
	}
	return setData(std::to_string(auid), dataObj);
}

bool setRideData(long long riderUID, long long mountsUID, optional<std::string> remark){
	if (dataDom.IsNull()) {
		if (!loadData()) {
			return false;
		}
	}
	rapidjson::Document::AllocatorType& allocator = dataDom.GetAllocator();
	rapidjson::Value dataObj(rapidjson::kObjectType);
	dataObj.SetObject();
	dataObj.AddMember("type", "Ride", allocator); 
	dataObj.AddMember("mounts", mountsUID, allocator);
	if (remark.set) {
		rapidjson::Value strRemark(rapidjson::kStringType);
		strRemark.SetString(remark.val().c_str(), dataDom.GetAllocator());
		dataObj.AddMember("remark", strRemark, allocator);
	}
	return setData(std::to_string(riderUID), dataObj);
}

DataType getDataType(long long auid) {
	if (dataDom.IsNull()) {
		if (!loadData()) {
			return DataType::None;
		}
	}
	const std::string skey = std::to_string(auid);
	rapidjson::Value key(rapidjson::kStringType);
	key.SetString(skey.c_str(), dataDom.GetAllocator());
	if (!dataDom.HasMember(key)) {
		return DataType::None;
	}
	else {
		std::string dt = dataDom[key]["type"].GetString();
		if (dt == "Sleep") {
			return DataType::Sleep;
		}
		else if (dt == "Ride") {
			return DataType::Ride;
		}
		else {
			return DataType::None;
		}
	}
}

BlockPos getSleepData(long long auid) {
	if (dataDom.IsNull()) {
		if (!loadData()) {
			return BlockPos();
		}
	}
	const std::string skey = std::to_string(auid);
	rapidjson::Value key(rapidjson::kStringType);
	key.SetString(skey.c_str(), dataDom.GetAllocator());
	auto arr=dataDom[key]["bedPos"].GetArray();
	return { arr[0].GetInt() ,arr[1].GetInt() ,arr[2].GetInt() };
}

long long getRideData(long long auid) {
	if (dataDom.IsNull()) {
		if (!loadData()) {
			return NULL;
		}
	}
	const std::string skey = std::to_string(auid);
	rapidjson::Value key(rapidjson::kStringType);
	key.SetString(skey.c_str(), dataDom.GetAllocator());
	return dataDom[key]["mounts"].GetInt64();
}
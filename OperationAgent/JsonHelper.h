
enum class DataType :int {
	None = 0,
	Sleep = 1,
	Ride = 2
};

bool loadConf();
template<typename T>
T getConf(std::string key, T defaultValue);

bool setSleepData(long long auid, BlockPos bpos, optional<std::string> remark);
bool setRideData(long long riderUID, long long mountsUID, optional<std::string> remark);

bool deleteData(std::string skey);
bool deleteData(long long key);

DataType getDataType(long long auid);
BlockPos getSleepData(long long auid);
long long getRideData(long long auid);

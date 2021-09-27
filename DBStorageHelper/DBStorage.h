#pragma once
#include "nbt-from-lxl/NBT.h"
#include <regex>

struct string_span;
typedef void LevelStorageWriteBatch;
/*{
	void* filler[0x90/8];
public:
	virtual ~LevelStorageWriteBatch() {};
	virtual void* putKey(string const&, std::shared_ptr<string>) = 0;
	virtual void putKey(string const&, string&&) = 0;
	virtual void putKey(string const&, string const&) = 0;
	virtual void putKey(string const&, string_span) = 0;
	virtual void deleteKey(string const&) = 0;

	map<string, void*> getMap() {
		return dAccess<map<string, void*>>(this, 32);
	}
};*/
class DBChunkStorage;
class LevelData;
class ChunkSource;
class StorageVersion;
class ProfileSectionGroup;
extern class DBStorageHelper;
template <typename T>
class CompleteResult;
template <typename T>
struct IAsyncResult {
	//res {*res {bedrock_server_mod.exe!const Bedrock::Threading::AsyncResult::CompleteResult<void>::`vftable'}}
	CompleteResult<T>* completeResult;
	// ref {*ref {bedrock_server_mod.exe!const std::_Ref_count_obj2<class Bedrock::Threading::AsyncResult::CompleteResult<void> >::`vftable'}}
	std::_Ref_count_obj2<CompleteResult<T>>* ref;
};

template <typename T>
class CompleteResult {
public:
	virtual ~CompleteResult() {};
	//0x00007ff73c4f8070 {bedrock_server_mod.exe!`anonymous namespace'::availableSetCountOfOne(void)}
	virtual int availableSetCountOfOne() = 0;
	//0x00007ff73cd4b520 {bedrock_server_mod.exe!Bedrock::Threading::AsyncResult::CompleteResult<class Bedrock::Http::Response>::getError(void)const }
	virtual void* getError() = 0;
	//0x00007ff73cd4b540 {bedrock_server_mod.exe!BackgroundTask<class TaskResult,void>::getException(void)const }
	virtual void* getException() = 0;
	//0x00007ff73c494300 {bedrock_server_mod.exe!std::_Func_impl_no_alloc<<lambda_93c16ff65c96352fe9f8a88319689ec6>,void,JsonUtil::JsonParseState<JsonUtil::JsonParseState<JsonUtil::JsonParseState<JsonUtil::EmptyClass,BlockComponentGroupDescription>,BlockQueuedTickingDescription>,BlockQueuedTickingDescription> &>::_Do_call(void)}
	virtual void* _Do_call() = 0;
	//0x00007ff73cd49cb0 {bedrock_server_mod.exe!Bedrock::Threading::AsyncResult::CompleteResult<class Bedrock::Http::Response>::addOnComplete(class std::function<void >)}
	virtual void* addOnComplete(std::function<void(IAsyncResult<T> const&)>) = 0;
};

struct SnapshotFilenameAndLength {
	string path;
	size_t size;
};

struct BiomeData {
	struct Info {
		byte id;
		float snowAccumulation;
	};
	vector<Info> data;
};

struct Dimension {
	struct LimboEntitie {
		int ChunkX;
		int ChunkY;
		vector<Tag*> EntityTagList;
	};
	vector<LimboEntitie> limboEntities;
};
struct TheEnd : Dimension {
	struct DragonFight {
		byte DragonFightVersion;
		byte DragonKilled;
		byte DragonSpawned;
		long DragonUUID;
		BlockPos ExitPortalLocation;
		vector<int> Gateways;
		byte IsRespawning;
		byte PreviouslyKilled;
	};
	DragonFight dragonFight;
};

// 
struct ScoreBoard {
	struct Criteria;
	struct DisplayObjective {};
	struct Entry {
		byte IdentityType;
		long ScoreboardId;
		//map<string, string> xxx; // Uncertain, determind by idtype
	};
	struct Objective {
		struct Score {
			int Score;
			int ScoreBoard;
		};
		string Criteria;
		string DisplayName;
		string Name;
		vector<Score> Scores;
	};

};
struct PortalRecord {
	int DimId;
	byte Span;
	int TpX;
	int TpY;
	int TpZ;
	byte Xa;
	byte Za;
	Tag* toTag() {
		Tag* tag = Tag::createTag(TagType::Compound);
		tag->putInt("DimId", this->DimId);
		tag->putByte("Span", (char)this->Span);
		tag->putInt("TpX", this->TpX);
		tag->putInt("TpY", this->TpY);
		tag->putInt("TpZ", this->TpZ);
		tag->putByte("Xa", (char)this->Xa);
		tag->putByte("Za", (char)this->Za);
		return tag;
	}
	PortalRecord() {};
	PortalRecord(Tag* tag) {
		auto& cmp = tag->asCompound();
		this->DimId = cmp["DimId"].asInt();
		this->Span = (byte)cmp["Span"].asByte();
		this->TpX = cmp["TpX"].asInt();
		this->TpY = cmp["TpY"].asInt();
		this->TpZ = cmp["TpZ"].asInt();
		this->Xa = (byte)cmp["Xa"].asByte();
		this->Za = (byte)cmp["Za"].asByte();
	}
	BlockPos getPos() {
		return { this->TpX, this->TpY, this->TpZ };
	}
	string toString() {
		return TagToSNBT(this->toTag());
	}
};

struct Portals {
	vector<PortalRecord> records;
	Tag* toTag() {
		Tag* prTags = Tag::createTag(TagType::List);
		for (auto& r : records) {
			prTags->add(r.toTag());
		}
		Tag* tag = Tag::createTag(TagType::Compound);
		Tag* data = Tag::createTag(TagType::Compound);
		data->put("PortalRecords", prTags);
		tag->putCompound("data", data);
		return tag;
	}
	Portals(Tag* tag) {
		try {
			auto& prTags = tag->asCompound()["data"].asCompound()["PortalRecords"].asList();
			for (auto& prTag : prTags) {
				PortalRecord pr(prTag);
				this->records.push_back(pr);
			}
		}
		catch (...) {};
	}
};
//struct MobEvents {
//	byte events_enabled;
//	byte minecraft__ender_dragon_event;
//	byte minecraft__pillager_patrols_event;
//	byte minecraft__wandering_trader_event;
//};

// key: mobevents
struct MobEvents {
	bool events_enabled=true; 
	bool ender_dragon_event=true;
	bool pillager_patrols_event=true; 
	bool wandering_trader_event=true; 
	Tag* toTag() {
		Tag* tag = Tag::createTag(TagType::Compound);
		tag->putByte("events_enabled", (char)this->events_enabled);
		tag->putByte("minecraft:ender_dragon_event", (char)this->ender_dragon_event);
		tag->putByte("minecraft:pillager_patrols_event", (char)this->pillager_patrols_event);
		tag->putByte("minecraft:wandering_trader_event", (char)this->wandering_trader_event);
		return tag;
	}
	MobEvents() {};
	MobEvents(Tag* tag) {
		auto& cmp = tag->asCompound();
		this->events_enabled = cmp["events_enabled"].asByte();
		this->ender_dragon_event = cmp["minecraft:ender_dragon_event"].asByte();
		this->pillager_patrols_event = cmp["minecraft:pillager_patrols_event"].asByte();
		this->wandering_trader_event = cmp["minecraft:wandering_trader_event"].asByte();
	}
	string toString() {
		return TagToSNBT(this->toTag());
	}
};

// map_{id}
struct Map_ {
	TagMemoryChunk colors;
	struct Decoration {
		struct Data {
			int rot;
			int type;
			int x;
			int y;
		};
		struct Kye {
			int blockX;
			int blockY;
			int blockZ;
			int type;
		};
	};
	vector<Decoration> decorations;
	byte dimension;
	byte fullyExplored;
	short height;
	long mapId;
	byte mapLocked;
	long parentMapId;
	byte scale;
	byte unlimitedTracking;
	byte width;
	int xCenter;
	int zCenter;
};

//VILLAGE_{UUID}_INFO
struct VillageInfo {
	long BDTime;
	long GDTime;
	byte Initialized;
	long MTick;
	long PDTick;
	int RX0;
	int RX1;
	int RY0;
	int RY1;
	int RZ0;
	int RZ1;
	long Tick;
	long VHTime;
	byte Version;
	int X0;
	int X1;
	int Y0;
	int Y1;
	int Z0;
	int Z1;
};

//VILLAGE_{UUID}_DWELLERS
struct VillageDwellers {
	struct ActorInfo {
		long ID;
		long TS;
		BlockPos last_saved_pos;
		long last_worked;
	};
	vector<ActorInfo> actors_1;
	vector<ActorInfo> actors_2;
	vector<ActorInfo> actors_3;
	vector<ActorInfo> actors_4;
};

//VILLAGE_{UUID}_PLAYERS
struct VillagePlayers {
	struct PlayerInfo {
		long ID;
		int S; // Unknown
	};
	vector<PlayerInfo> players;
};

//VILLAGE_{UUID}_POI
struct VillagePOI {
	struct Instance {
		long Capacity;
		string InitEvent;
		string Name;
		long OwnerCount;
		float Radius;
		byte Skip;
		string SoundEvent;
		int Type;
		byte UseAABB;
		long Weight;
		int x;
		int y;
		int z;
	};
	long VillagerID;
	//vector<Instance> instances;
	Instance instances[3];
};
class DBStorage
{
public:
	void*** filler[0x308 / 8] = {};
	class PendingWriteResult {
		void* filler[2];
	};

	DBStorageHelper getHelper();

	virtual ~DBStorage() {};

	virtual void addStorageObserver(void* observer) = 0;

	virtual unique_ptr<Tag>* getCompoundTag(Tag** tagPtr, const string& key) = 0;

	virtual bool hasKey(string_span& key) = 0;

	// key = key_prefix + key_left
	virtual unsigned long long forEachKeyWithPrefix(const string_span key_prefix, function<void(const string_span key_left, string_span bin)> const&) = 0;

	virtual bool loadLevelData(LevelData& result) = 0;

	// uncertain
	virtual DBChunkStorage** createChunkStorage(ChunkSource** cs, StorageVersion* cv) = 0;

	virtual void* saveLevelData(LevelData& data) = 0;

	// relate to db path like: worlds/worldname
	virtual string& getFullPath() = 0;

	//0x00007ff7a00078d0 {bedrock_server_mod.exe!gametest::BaseGameTestInstance::getError(void)const }
	//virtual void* getError() = 0;

	// void* result[2] is allowed, data is binary data
	virtual IAsyncResult<void>* saveData(IAsyncResult<void>& result, string const& key, string& data) = 0;

	// unkown struct writeBatch
	virtual LevelStorageWriteBatch* saveData(IAsyncResult<void>* result, LevelStorageWriteBatch* batch) = 0;


	virtual IAsyncResult<void>* deleteData(IAsyncResult<void>& result, string const& key) = 0;

	// don't to call
	virtual void syncIO() = 0;

	virtual void* getStatistics(string const& json) = 0;

	virtual bool clonePlayerData(string_span& key_src, string_span& key_dst) = 0;

	// can get stringify state by leveldb::Status::ToString()
	virtual void* getLevelStorageState(void* result) = 0;

	virtual void startShutdown() = 0;

	virtual bool isShuttingDown() = 0;

	virtual bool checkShutdownDone() = 0;

	virtual bool loadData(string_span& key, string& result) = 0;

	virtual void getLevelStorageState2() = 0;

	// path in fdetails include world name
	virtual vector<SnapshotFilenameAndLength>& createSnapshot(vector<SnapshotFilenameAndLength>& fdetails, string& worldName) = 0;

	virtual void releaseSnapshot() = 0;

	virtual void compactStorage() = 0;

	virtual void syncAndSuspendStorage() = 0;

	virtual void resumeStorage() = 0;

	virtual void setFlushAllowed(bool) = 0;

	virtual void flushToPermanentStorage() = 0;

	virtual void freeCaches() = 0;

	virtual void setCompactionCallback(function<void(void*)>) = 0;

	virtual void setCriticalSyncSaveCallback(function<void(void)>) = 0;

	virtual void corruptLevel() = 0;

	//DBStorage::_findCacheEntry(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
	//DBStorage::_flushWriteCacheToLevelDB(void)
	//DBStorage::_getAllPendingWrites(void)
	//DBStorage::_getTelemetryMessage(leveldb::Status const &)
	//DBStorage::_markAsCorrupted(gsl::basic_string_span<char const,-1>)
	//DBStorage::_mergeIntoWriteCache(LevelStorageWriteBatch const &)
	//DBStorage::_read(gsl::basic_string_span<char const,-1>,std::function<void (gsl::basic_string_span<char const,-1>,gsl::basic_string_span<char const,-1>)> const &)
	//DBStorage::_readPendingWrite(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &)
	//DBStorage::_suspendAndPerformSaveAction(std::function<TaskResult (void)>,std::function<void (void)>)
	//DBStorage::tryRepair(Core::Path const&)

	LevelStorageWriteBatch* _findCacheEntry(pair<void*, void*>* batch, string& key);

	void* _flushWriteCacheToLevelDB(void* taskResult);

	void* _getAllPendingWrites(map<string, PendingWriteResult>& resultMap);

	void* _getTelemetryMessage(string& result, void* leveldbStatus);

	void _handleErrorStatus(void* leveldbStatus);

	void _markAsCorrupted(string_span str_span);

	void _mergeIntoWriteCache(LevelStorageWriteBatch const* batch);

	void _queueSaveCallback(bool b);

	void* _read(string_span str, function<void(string_span, string_span)> const& func);

	DBStorage::PendingWriteResult& _readPendingWrite(DBStorage::PendingWriteResult& result, string& key);

	void _scheduleNextAutoCompaction(void);

	bool _suspendAndPerformSaveAction(function<void* (void)>func, function<void(void)> func2);

	bool tryRepair(void* path);

};

class ChunkViewSource;
class Random;
enum ChunkSourceLoadMode
{

};

class DBChunkStorage {
	void* filler[0x160 / 8];
public:
	virtual ~DBChunkStorage() {};
	virtual unsigned long long getHighPerformanceThreadsCount() = 0;
	virtual bool isShutdownDone() = 0;
	virtual void* getLoggableData(void*) = 0;
	virtual void* getLoggableData2(void*) = 0;
	virtual void* createNewChunk(ChunkPos const&, ChunkSourceLoadMode, bool) = 0;
	virtual void* getOrLoadChunk(ChunkPos const&, ChunkSourceLoadMode, bool) = 0;
	virtual void* postProcess(ChunkViewSource&) = 0;
	virtual void* checkAndReplaceChunk(ChunkViewSource&, LevelChunk&) = 0;
	virtual void* loadChunk(LevelChunk&, bool) = 0;
	virtual void* postProcessMobsAt(BlockSource&, int, int, Random&) = 0;
	virtual void* saveLiveChunk(LevelChunk&) = 0;
	virtual void* hintDiscardBatchBegin(void) = 0;
	virtual void* hintDiscardBatchEnd(void) = 0;
	virtual void* acquireDiscarded(std::unique_ptr<LevelChunk>) = 0;
	virtual void* compact(void) = 0;
	virtual void* flushPendingWrites(void) = 0;
	virtual void* isArmor(void) = 0;
	virtual void* _Move(void*) = 0;
	virtual void* getStorage(void) = 0;
	virtual void* onThreadCreate(char const*) = 0;
	virtual void* parse(void*, CommandRegistry::ParseToken const&, CommandOrigin const&, int, string&, vector<string>&) = 0;
};
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
class LevelData;
class ChunkSource;
class StorageVersion;
class ProfileSectionGroup;
struct SnapshotFilenameAndLength {
    string path;
    size_t size;
};
class DBStorage
{
    void* filler[0x308/8];
public:
    class PendingWriteResult {
        void* filler[2];
    };
    virtual ~DBStorage() {};
    virtual void addStorageObserver(void* ob) = 0;
    virtual Tag* getCompoundTag(string& key) = 0;
    virtual bool hasKey(string_span key) = 0;
    virtual unsigned long long forEachKeyWithPrefix(string_span key, function<void(string_span, string_span)> const&) = 0;
    virtual bool loadLevelData(LevelData& data) = 0;
    virtual ChunkSource** createChunkStorage(ChunkSource**, StorageVersion*) = 0;
    virtual void saveLevelData(LevelData& data) = 0;
    virtual string* getFullPath() = 0;
    virtual ProfileSectionGroup* saveData(LevelStorageWriteBatch const*) = 0;
    virtual ProfileSectionGroup* saveData(string const&, string&) = 0;
    virtual ProfileSectionGroup* deleteData(string const&) = 0;
    virtual void syncIO() = 0;
    virtual void* getStatistics(string&) = 0;
    virtual bool clonePlayerData(string_span, string_span) = 0;
    virtual void* getState() = 0;
    virtual void startShutdown() = 0;
    virtual bool isShuttingDown() = 0;
    virtual bool checkShutdownDone() = 0;
    virtual bool loadData(string_span, string&) = 0;
    virtual void getState2() = 0;
    virtual ProfileSectionGroup* createSnapshot(vector<SnapshotFilenameAndLength>&) = 0;
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

    LevelStorageWriteBatch* _findCacheEntry(string const&);
    void* _flushWriteCacheToLevelDB(void* taskResult);
    void* _getAllPendingWrites(void* mapResult);
    void* _getTelemetryMessage(void* result, void* leveldbStatus);
    void _handleErrorStatus(void* leveldbStatus);
    void _markAsCorrupted(string_span);
    void _mergeIntoWriteCache(LevelStorageWriteBatch const*);
    void _queueSaveCallback(bool);
    unsigned long long _read(string_span, function<void(string_span, string_span)> const&);
    uint64_t _readPendingWrite(string&);
    void _scheduleNextAutoCompaction(void);
    bool _suspendAndPerformSaveAction(function<void* (void)>, function<void(void)>);
    bool tryRepair(void* path);

};

class ChunkViewSource;
class Random;
enum ChunkSourceLoadMode
{

};
class DBChunkStorage{
    void* filler[0x160 / 8];
public:
    virtual ~DBChunkStorage() {};
    virtual unsigned long long getHighPerformanceThreadsCount()=0;
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
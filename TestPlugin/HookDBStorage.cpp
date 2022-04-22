#include "pch.h"
#include <MC/DBStorage.hpp>


#ifdef HOOK_CLASS_DBStorage
// parent_types : 1
// private : 5
TInstanceHook(class TaskResult&, "?_flushWriteCacheToLevelDB@DBStorage@@AEAA?AVTaskResult@@XZ",
              DBStorage, class TaskResult& ret)
{
    logger.info("DBStorage::_flushWriteCacheToLevelDB");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(std::string&, "?_getTelemetryMessage@DBStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVStatus@leveldb@@@Z",
              DBStorage, std::string& ret, class leveldb::Status const& a0)
{
    logger.info("DBStorage::_getTelemetryMessage");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?_markAsCorrupted@DBStorage@@AEBAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
              DBStorage, class gsl::basic_string_span<char const, -1> a0)
{
    logger.info("DBStorage::_markAsCorrupted");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_scheduleNextAutoCompaction@DBStorage@@AEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::_scheduleNextAutoCompaction");
    original(this);
}

TInstanceHook(bool, "?_suspendAndPerformSaveAction@DBStorage@@AEAA_NV?$function@$$A6A?AVTaskResult@@XZ@std@@V?$function@$$A6AXXZ@3@@Z",
              DBStorage, class std::function<class TaskResult(void)> a0, class std::function<void(void)> a1)
{
    logger.info("DBStorage::_suspendAndPerformSaveAction");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// protected : 7
TInstanceHook(void* /*struct std::pair<class LevelStorageWriteBatch* , class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<std::string const, struct LevelStorageWriteBatch::BatchEntry> > > > >&*/, "?_findCacheEntry@DBStorage@@IEAA?AU?$pair@PEAVLevelStorageWriteBatch@@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBatchEntry@LevelStorageWriteBatch@@@std@@@std@@@std@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
              DBStorage, struct std::pair<class LevelStorageWriteBatch*, class std::_Tree_iterator<class std::_Tree_val<struct std::_Tree_simple_types<struct std::pair<std::string const, struct LevelStorageWriteBatch::BatchEntry>>>>>& ret, std::string const& a0)
{
    logger.info("DBStorage::_findCacheEntry");
    auto rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void* /*std::map<std::string, struct DBStorage::PendingWriteResult>&*/, "?_getAllPendingWrites@DBStorage@@IEBA?AV?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@@std@@@2@@std@@XZ",
              DBStorage, std::map<std::string, struct DBStorage::PendingWriteResult>& ret)
{
    //logger.info("DBStorage::_getAllPendingWrites");
    auto rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?_handleErrorStatus@DBStorage@@IEAAXAEBVStatus@leveldb@@@Z",
              DBStorage, class leveldb::Status const& a0)
{
    logger.info("DBStorage::_handleErrorStatus");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_mergeIntoWriteCache@DBStorage@@IEAAXAEBVLevelStorageWriteBatch@@@Z",
              DBStorage, class LevelStorageWriteBatch const& a0)
{
    logger.info("DBStorage::_mergeIntoWriteCache");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_queueSaveCallback@DBStorage@@IEAAX_N@Z",
              DBStorage, bool a0)
{
    logger.info("DBStorage::_queueSaveCallback");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_read@DBStorage@@IEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
              DBStorage, class gsl::basic_string_span<char const, -1> a0, enum DBHelpers::Category a1, class std::function<void(class gsl::basic_string_span<char const, -1>, class gsl::basic_string_span<char const, -1>)> const& a2)
{
    logger.info("DBStorage::_read");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(struct DBStorage::PendingWriteResult&, "?_readPendingWrite@DBStorage@@IEBA?AUPendingWriteResult@1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
              DBStorage, struct DBStorage::PendingWriteResult& ret, std::string const& a0, enum DBHelpers::Category a1)
{
    //logger.info("DBStorage::_readPendingWrite");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// public : 2
TInstanceHook(class DBStorage&, "??0DBStorage@@QEAA@UDBStorageConfig@@@Z",
              DBStorage, struct DBStorageConfig& a0)
{
    logger.info("DBStorage::DBStorage");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?tryRepair@DBStorage@@QEBA_NAEBVPath@Core@@@Z",
              DBStorage, class Core::Path const& a0)
{
    logger.info("DBStorage::tryRepair");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

// virtual : 32
#include <MC/LevelStorageObserver.hpp>
TInstanceHook(void, "?addStorageObserver@DBStorage@@UEAAXV?$unique_ptr@VLevelStorageObserver@@U?$default_delete@VLevelStorageObserver@@@std@@@std@@@Z",
              DBStorage, std::unique_ptr<class LevelStorageObserver> a0)
{
    logger.info("DBStorage::addStorageObserver");
    original(this, std::forward<decltype(a0)>(a0));
}

#include <MC/CompoundTag.hpp>
TInstanceHook(std::unique_ptr<class CompoundTag>&, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@W4Category@DBHelpers@@@Z",
              DBStorage, std::unique_ptr<class CompoundTag>& ret, std::string const& a0, enum DBHelpers::Category a1)
{
    logger.info("DBStorage::getCompoundTag({}, {})", a0, (int)a1);
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?hasKey@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@@Z",
              DBStorage, class gsl::basic_string_span<char const, -1> a0, enum DBHelpers::Category a1)
{
    //logger.info("DBStorage::hasKey");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
              DBStorage, class gsl::basic_string_span<char const, -1> a0, enum DBHelpers::Category a1, class std::function<void(class gsl::basic_string_span<char const, -1>, class gsl::basic_string_span<char const, -1>)> const& a2)
{
    logger.info("DBStorage::forEachKeyWithPrefix");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(bool, "?loadLevelData@DBStorage@@UEAA_NAEAVLevelData@@@Z",
              DBStorage, class LevelData& a0)
{
    logger.info("DBStorage::loadLevelData");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

#include <MC/ChunkSource.hpp>
TInstanceHook(std::unique_ptr<class ChunkSource>&, "?createChunkStorage@DBStorage@@UEAA?AV?$unique_ptr@VChunkSource@@U?$default_delete@VChunkSource@@@std@@@std@@V23@W4StorageVersion@@@Z",
              DBStorage, std::unique_ptr<class ChunkSource>& ret, std::unique_ptr<class ChunkSource> a0, enum StorageVersion a1)
{
    logger.info("DBStorage::createChunkStorage");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?saveLevelData@DBStorage@@UEAAXAEBVLevelData@@@Z",
              DBStorage, class LevelData const& a0)
{
    logger.info("DBStorage::saveLevelData");
    original(this, std::forward<decltype(a0)>(a0));
}

// there are 6 functions with the same rva

// ?getMobs@Biome@@QEBAAEBV?$vector@VMobSpawnerData@@V?$allocator@VMobSpawnerData@@@std@@@std@@XZ
// ?getMobsMutable@Biome@@QEAAAEAV?$vector@VMobSpawnerData@@V?$allocator@VMobSpawnerData@@@std@@@std@@XZ
// ?getPosition@StructureAnimationData@@QEBAAEBVBlockPos@@XZ
// ?getRawNameHash@Item@@QEBAAEBVHashedString@@XZ
// ?getRequestId@ItemStackRequestActionHandler@@QEBAAEBV?$TypedClientNetId@UItemStackRequestIdTag@@H$0A@@@XZ
// ?getTag@Recipe@@QEBAAEBVHashedString@@XZ

// TInstanceHook(class Core::PathBuffer<std::string > const&, "?getFullPath@DBStorage@@UEBAAEBV?$PathBuffer@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Core@@XZ",
//     DBStorage){
//     logger.info("DBStorage::getFullPath");
//     auto& rtn = original(this);
//     return rtn;
// }

#include <MC/Bedrock.hpp>
TInstanceHook(std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>&, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@W4Category@DBHelpers@@@Z",
              DBStorage, std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>& ret, std::string const& a0, std::string&& a1, enum DBHelpers::Category a2)
{
    logger.info("DBStorage::saveData");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

#include <MC/Bedrock.hpp>
TInstanceHook(std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>&, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBVLevelStorageWriteBatch@@@Z",
              DBStorage, std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>& ret, class LevelStorageWriteBatch const& a0)
{
    logger.info("DBStorage::saveData");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

#include <MC/Bedrock.hpp>
TInstanceHook(std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>&, "?deleteData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@W4Category@DBHelpers@@@Z",
              DBStorage, std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>& ret, std::string const& a0, enum DBHelpers::Category a1)
{
    logger.info("DBStorage::deleteData");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?syncIO@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::syncIO");
    original(this);
}

TInstanceHook(void, "?getStatistics@DBStorage@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              DBStorage, std::string& a0)
{
    logger.info("DBStorage::getStatistics");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?startShutdown@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::startShutdown");
    original(this);
}

TInstanceHook(bool, "?isShuttingDown@DBStorage@@UEBA_NXZ",
              DBStorage)
{
    logger.info("DBStorage::isShuttingDown");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?checkShutdownDone@DBStorage@@UEAA_NXZ",
              DBStorage)
{
    logger.info("DBStorage::checkShutdownDone");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
              DBStorage, class gsl::basic_string_span<char const, -1> a0, std::string& a1, enum DBHelpers::Category a2)
{
    //logger.info("DBStorage::loadData");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(std::vector<struct SnapshotFilenameAndLength>&, "?createSnapshot@DBStorage@@UEAA?AV?$vector@USnapshotFilenameAndLength@@V?$allocator@USnapshotFilenameAndLength@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
              DBStorage, std::vector<struct SnapshotFilenameAndLength>& ret, std::string const& a0)
{
    logger.info("DBStorage::createSnapshot");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?releaseSnapshot@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::releaseSnapshot");
    original(this);
}

TInstanceHook(void, "?compactStorage@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::compactStorage");
    original(this);
}

TInstanceHook(void, "?syncAndSuspendStorage@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::syncAndSuspendStorage");
    original(this);
}

TInstanceHook(void, "?resumeStorage@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::resumeStorage");
    original(this);
}

TInstanceHook(void, "?setFlushAllowed@DBStorage@@UEAAX_N@Z",
              DBStorage, bool a0)
{
    logger.info("DBStorage::setFlushAllowed");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?flushToPermanentStorage@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::flushToPermanentStorage");
    original(this);
}

TInstanceHook(void, "?freeCaches@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::freeCaches");
    original(this);
}

TInstanceHook(void, "?setCompactionCallback@DBStorage@@UEAAXV?$function@$$A6AXW4CompactionStatus@@@Z@std@@@Z",
              DBStorage, class std::function<void(enum CompactionStatus)> a0)
{
    logger.info("DBStorage::setCompactionCallback");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCriticalSyncSaveCallback@DBStorage@@UEAAXV?$function@$$A6AXXZ@std@@@Z",
              DBStorage, class std::function<void(void)> a0)
{
    logger.info("DBStorage::setCriticalSyncSaveCallback");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?corruptLevel@DBStorage@@UEAAXXZ",
              DBStorage)
{
    logger.info("DBStorage::corruptLevel");
    original(this);
}

// virtual.unordered : 3
TInstanceHook(class DBStorage&, "??1DBStorage@@UEAA@XZ",
              DBStorage)
{
    logger.info("DBStorage::~DBStorage");
    auto& rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getLevelStorageState@DBStorage@@UEBA?AULevelStorageResult@Core@@XZ

// TInstanceHook(struct Core::LevelStorageResult&, "?getState@DBStorage@@UEBA?AULevelStorageResult@Core@@XZ",
//     DBStorage, struct Core::LevelStorageResult& ret){
//     logger.info("DBStorage::getState");
//     auto& rtn = original(this, ret);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getState@DBStorage@@UEBA?AULevelStorageResult@Core@@XZ

// TInstanceHook(struct Core::LevelStorageResult&, "?getLevelStorageState@DBStorage@@UEBA?AULevelStorageResult@Core@@XZ",
//     DBStorage, struct Core::LevelStorageResult& ret){
//     logger.info("DBStorage::getLevelStorageState");
//     auto& rtn = original(this, ret);
//     return rtn;
// }

// vtbl_entry : 1

#endif // HOOK_CLASS_DBStorage

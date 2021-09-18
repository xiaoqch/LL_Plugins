#include "pch.h"
#include "DBStorage.h"
#include "DBStorageHelper.h"

LevelStorageWriteBatch* DBStorage::_findCacheEntry(string const& str) {
    return SymCall("?_findCacheEntry@DBStorage@@IEAA?AU?$pair@PEAVLevelStorageWriteBatch@@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBatchEntry@LevelStorageWriteBatch@@@std@@@std@@@std@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
        LevelStorageWriteBatch*, string const&)(str);
};
void* DBStorage::_flushWriteCacheToLevelDB(void* taskResult) {
    return SymCall("?_flushWriteCacheToLevelDB@DBStorage@@AEAA?AVTaskResult@@XZ",
        void*, void*)(taskResult);
};
void* DBStorage::_getAllPendingWrites(void* mapResult) {
    return SymCall("?_getAllPendingWrites@DBStorage@@IEBA?AV?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@@std@@@2@@std@@XZ",
        void*, void*)(mapResult);
};
void* DBStorage::_getTelemetryMessage(void* result, void* leveldbStatus) {
    return SymCall("?_getTelemetryMessage@DBStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVStatus@leveldb@@@Z",
        void*, void*, void*)(result, leveldbStatus);
};
void DBStorage::_handleErrorStatus(void* leveldbStatus) {
    SymCall("?_handleErrorStatus@DBStorage@@IEAAXAEBVStatus@leveldb@@@Z",
        void, void*)(leveldbStatus);
}

void DBStorage::_markAsCorrupted(string_span str_span) {
    SymCall("?_markAsCorrupted@DBStorage@@AEBAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
        void, string_span)(str_span);
};
void DBStorage::_mergeIntoWriteCache(LevelStorageWriteBatch const* batch) {
    SymCall("?_mergeIntoWriteCache@DBStorage@@IEAAXAEBVLevelStorageWriteBatch@@@Z",
        void, LevelStorageWriteBatch const*)(batch);
};
void DBStorage::_queueSaveCallback(bool b) {
    SymCall("?_queueSaveCallback@DBStorage@@IEAAX_N@Z",
        void, bool)(b);
};
//unsigned long long DBStorage::_read(string_span, function<void(string_span, string_span)> const&) {
//	SymCall("?_read@DBStorage@@IEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
//		void, bool)();
//};
uint64_t DBStorage::_readPendingWrite(string& str) {
    return SymCall("?_readPendingWrite@DBStorage@@IEBA?AUPendingWriteResult@1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        uint64_t, string&)(str);
};
void DBStorage::_scheduleNextAutoCompaction(void) {
    SymCall("?_scheduleNextAutoCompaction@DBStorage@@AEAAXXZ",
        void, void)();
};
bool DBStorage::_suspendAndPerformSaveAction(function<void* (void)>func, function<void(void)> func2) {
    return SymCall("?_suspendAndPerformSaveAction@DBStorage@@AEAA_NV?$function@$$A6A?AVTaskResult@@XZ@std@@V?$function@$$A6AXXZ@3@@Z",
        bool, function<void* (void)>, function<void(void)>)(func, func2);
};
bool DBStorage::tryRepair(void* path) {
    SymCall("?tryRepair@DBStorage@@QEBA_NAEBVPath@Core@@@Z",
        bool, void*)(path);
};

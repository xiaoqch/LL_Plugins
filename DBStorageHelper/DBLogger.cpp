#include "pch.h"
#include <shellapi.h>
#include "SymHelper.h"
#include "DBStorage.h"
#include "DBStorageHelper.h"
#include <mc/Level.h>
#include <mc/OffsetHelper.h>


#define LOG_START(name) \
string fun_name=name;\
string space="                                       ";\
cout<<space.substr(0, 2*level++)<<fun_name<<":"<<endl;
#define LOG_END \
--level;\
return;
#define LOG_END_RTN \
--level;\
return rtn;
#define LOG_VAR(var) cout << #var" :\t" << var <<endl;

//#define LOG_END \
//cout<<space.substr(0, 2*--level)<<fun_name<<endl;\
//return;
//#define LOG_END_RTN \
//cout<<space.substr(0, 2*--level)<<fun_name<<endl;\
//return rtn;

int level = 0;

string statusToString(void* dbStatus) {
    string status;
    return SymCall("?ToString@Status@leveldb@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        string&, void*, string&)(dbStatus, status);
}

THook(void*, "?addStorageObserver@DBStorage@@UEAAXV?$unique_ptr@VLevelStorageObserver@@U?$default_delete@VLevelStorageObserver@@@std@@@std@@@Z",
    void* _this, void* observer) {
    LOG_START("DBStorage:addStorageObserver");
    auto rtn = original(_this, observer);
    LOG_END_RTN
    printf_s("%s(%p, %p) -> %p\n", fun_name.c_str(), _this, observer, rtn);
    return rtn;
}

// DBStorage::getCompoundTag
THook(unique_ptr<Tag>*, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    LevelStorage* _this, unique_ptr<Tag>& tagPtr, string& key) {
    LOG_START("DBStorage::getCompoundTag");
    auto rtn = original(_this, tagPtr, key);
    LOG_END_RTN
    printf_s("DBStorage::getCompoundTag(%p, %p, %s) -> %p\n", _this, tagPtr.get(), keyToString(key, "\\x").c_str(), rtn);
    return rtn;
}

// DBStorage::hasKey
THook(bool, "?hasKey@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
    void* _this, string_span key_span) {
    //LOG_START("DBStorage::hasKey");
    auto rtn = original(_this, key_span);
    //LOG_END_RTN
    return rtn;
    string key = key_span.toString();
    //printf_s("DBStorage::hasKey(%p, %s) -> %d\n", _this, keyToString(key, "\\x").c_str(), rtn);
    cout << ".";
    return rtn;
}

// DBStorage::forEachKeyWithPrefix
THook(unsigned long long, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    void* _this, string_span key_span, function<void(string_span, string_span)> const& func) {
    LOG_START("DBStorage::forEachKeyWithPrefix");
    string key = string(key_span.str, key_span.len);
    auto rtn = original(_this, key_span, func);
    LOG_END_RTN
    printf_s("DBStorage::forEachKeyWithPrefix(%p, %s, %p) -> %d\n", _this, keyToString(key).c_str(), &func, (int)rtn);
    return rtn;
}

// DBStorage::loadLevelData
THook(bool, "?loadLevelData@DBStorage@@UEAA_NAEAVLevelData@@@Z",
    void* _this, LevelData* data) {
    LOG_START("DBStorage::loadLevelData");
    auto rtn = original(_this, data);
    LOG_END_RTN
    printf_s("DBStorage::loadLevelData(%p, %p) -> %d\n", _this, data, (int)rtn);
    return rtn;
}

// DBStorage::createChunkStorage
THook(void*, "?createChunkStorage@DBStorage@@UEAA?AV?$unique_ptr@VChunkSource@@U?$default_delete@VChunkSource@@@std@@@std@@V23@W4StorageVersion@@@Z",
    void* _this, ChunkSource** cs, StorageVersion* sv) {
    LOG_START("DBStorage::createChunkStorage");
    auto rtn = original(_this, cs, sv);
    LOG_END_RTN
    printf_s("DBStorage::createChunkStorage(%p, %p, %p) -> %p\n", _this, cs, sv, rtn);
    return rtn;
}

// DBStorage::saveLevelData
THook(void*, "?saveLevelData@DBStorage@@UEAAXAEBVLevelData@@@Z",
    void* _this, LevelData* data) {
    LOG_START("DBStorage::saveLevelData");
    auto rtn = original(_this, data);
    LOG_END_RTN
    printf_s("DBStorage::saveLevelData(%p, %p) -> %p\n", _this, data, rtn);
    return rtn;
}

// DBStorage::getFullPath
THook(string*, "?getFullPath@DBStorage@@UEBAAEBV?$PathBuffer@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Core@@XZ",
    void* _this) {
    //LOG_START("DBStorage::getFullPath");
    auto rtn = original(_this);
    //LOG_END_RTN
    //printf_s("DBStorage::getFullPath(%p) -> %s\n", _this, rtn->c_str());
    return rtn;
}


//std::map<string,LevelStorageWriteBatch::BatchEntry>
// DBStorage::saveData
THook(void*, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBVLevelStorageWriteBatch@@@Z",
    void* _this, IAsyncResult<void>* result, LevelStorageWriteBatch* batch) {
    LOG_START("DBStorage::saveData");
    auto rtn = original(_this, result, batch);
    LOG_END_RTN
    printf_s("DBStorage::saveData(%p, %p) -> %p\n", _this, batch, rtn);
    return rtn;
}

// DBStorage::saveData
THook(IAsyncResult<void>*, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@@Z",
    void* _this, IAsyncResult<void>* result, string const& key, string* data) {
    LOG_START("DBStorage::saveData2");
    size_t len = data->length();
    auto rtn = original(_this, result, key, data);
    LOG_END_RTN
    printf_s("DBStorage::saveData ss(%p, %p, %s, byte[%lld]) -> %d\n",
        _this, &result, keyToString((string&)key, "\\x").c_str(), len, rtn->completeResult->availableSetCountOfOne());
    //Tag* error = (Tag*)res->v1->getError();
    //string str = TagToSNBT(error);
    //auto exe = res->v1->getException();
    return rtn;
}

// DBStorage::deleteData
THook(void*, "?deleteData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    void* _this, IAsyncResult<void>* result, string const* key, void* a3) {
    LOG_START("DBStorage::deleteData");
    auto rtn = original(_this, result, key, a3);
    LOG_END_RTN
    printf_s("DBStorage::deleteData(%p, %s) -> %p\n", _this, keyToString((string&)key, "\\x").c_str(), rtn);
    return rtn;
}

// DBStorage::syncIO
THook(void*, "?syncIO@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::syncIO");
    auto rtn = original(_this);
    LOG_END_RTN
    printf_s("DBStorage::syncIO(%p) -> %p\n", _this, rtn);
    return rtn;
}

// DBStorage::getStatistics
THook(void*, "?getStatistics@DBStorage@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    void* _this, string& result) {
    // result is formatted json;
    //"levels": [
    //    {
    //        "level": 0,
    //        "files": 3,
    //        "sizeMB": 0.143,
    //        "tsec": 0.251,
    //        "readMB": 0.000,
    //        "writeMB": 0.318
    //    },
    //    {
    //        "level": 1,
    //        "files": 1,
    //        "sizeMB": 0.016,
    //        "tsec": 0.054,
    //        "readMB": 0.253,
    //        "writeMB": 0.031
    //    }
    //]
    //}
    LOG_START("DBStorage::getStatistics");
    auto rtn = original(_this, result);
    LOG_END_RTN
    printf_s("DBStorage::getStatistics(%p, %s) -> %p\n", _this, result.c_str(), rtn);
    return rtn;
}

// DBStorage::clonePlayerData
THook(void*, "?clonePlayerData@LevelStorage@@UEAA_NV?$basic_string_span@$$CBD$0?0@gsl@@0@Z",
    void* _this, string_span key_span_1, string_span key_span_2) {
    LOG_START("DBStorage::clonePlayerData");
    auto rtn = original(_this, key_span_1, key_span_2);
    LOG_END_RTN
    printf_s("DBStorage::clonePlayerData(%p, %s, %s) -> %p\n", _this, key_span_1.str, key_span_2.str, rtn);
    return rtn;
}

// DBStorage::getState
THook(void*, "?getState@DBStorage@@UEBA?AULevelStorageResult@Core@@XZ",
    void* _this, void* result) {
    //LOG_START("DBStorage::getState");
    auto rtn = original(_this, result);
    //LOG_END_RTN
    //printf_s("DBStorage::getState(%p) -> %p\n", _this, rtn);
    return rtn;
}

// DBStorage::startShutdown
THook(void, "?startShutdown@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::startShutdown");
    original(_this);
    LOG_END
    printf_s("DBStorage::startShutdown(%p)\n", _this);
}

// DBStorage::isShuttingDown
THook(bool, "?isShuttingDown@DBStorage@@UEBA_NXZ",
    void* _this) {
    LOG_START("DBStorage::isShuttingDown");
    auto rtn = original(_this);
    LOG_END_RTN
    printf_s("DBStorage::isShuttingDown(%p) -> %d\n", _this, rtn);
    return rtn;
}

// DBStorage::checkShutdownDone
THook(bool, "?checkShutdownDone@DBStorage@@UEAA_NXZ",
    void* _this) {
    LOG_START("DBStorage::checkShutdownDone");
    auto rtn = original(_this);
    LOG_END_RTN
    printf_s("DBStorage::checkShutdownDone(%p) -> %d\n", _this, rtn);
    return rtn;
}

// DBStorage::loadData
THook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    void* _this, string_span key_span, string& data) {
    LOG_START("DBStorage::loadData");
    //if(key_span.toString()=="portals")
    //    *((void**)0) = 0;
    string key = key_span.toString();
    auto rtn = original(_this, key_span, data);
    LOG_END_RTN
    printf_s("DBStorage::loadData(%p, %s, %p) -> %d\n", _this, keyToString(key).c_str(), &data, rtn);
    return rtn;
}

// DBStorage::releaseSnapshot
THook(void, "?releaseSnapshot@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::releaseSnapshot");
    original(_this);
    LOG_END
    printf_s("DBStorage::releaseSnapshot(%p)\n", _this);
}

// DBStorage::compactStorage
THook(void, "?compactStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::compactStorage");
    original(_this);
    LOG_END
    printf_s("DBStorage::compactStorage(%p)\n", _this);
}

// DBStorage::syncAndSuspendStorage
THook(void, "?syncAndSuspendStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::syncAndSuspendStorage");
    original(_this);
    LOG_END
    printf_s("DBStorage::syncAndSuspendStorage(%p)\n", _this);
}

// DBStorage::resumeStorage
THook(void, "?resumeStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::resumeStorage");
    original(_this);
    LOG_END
    printf_s("DBStorage::resumeStorage(%p)\n", _this);
}

// DBStorage::setFlushAllowed
THook(void, "?setFlushAllowed@DBStorage@@UEAAX_N@Z",
    void* _this, bool a1) {
    LOG_START("DBStorage::setFlushAllowed");
    original(_this, a1);
    LOG_END
    printf_s("DBStorage::setFlushAllowed(%p, %d)\n", _this, a1);
}

// DBStorage::flushToPermanentStorage
THook(void, "?flushToPermanentStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::flushToPermanentStorage");
    original(_this);
    LOG_END
    printf_s("DBStorage::flushToPermanentStorage(%p)\n", _this);
}

// DBStorage::freeCaches
THook(void, "?freeCaches@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::freeCaches");
    original(_this);
    LOG_END
    printf_s("DBStorage::freeCaches(%p)\n", _this);
}

// DBStorage::setCompactionCallback
THook(void*, "?setCompactionCallback@DBStorage@@UEAAXV?$function@$$A6AXW4CompactionStatus@@@Z@std@@@Z",
    void* _this, function<void(void*)> func) {
    LOG_START("DBStorage::setCompactionCallback");
    auto rtn = original(_this, func);
    LOG_END_RTN
    printf_s("DBStorage::setCompactionCallback(%p, %p) -> %p\n", _this, &func, rtn);
    return rtn;
}

// DBStorage::setCriticalSyncSaveCallback
THook(void*, "?setCriticalSyncSaveCallback@DBStorage@@UEAAXV?$function@$$A6AXXZ@std@@@Z",
    void* _this, function<void(void)> func) {
    LOG_START("DBStorage::setCriticalSyncSaveCallback");
    auto rtn = original(_this, func);
    LOG_END_RTN
    printf_s("DBStorage::setCriticalSyncSaveCallback(%p, %p) -> %p\n", _this, &func, rtn);
    return rtn;
}

// DBStorage::corruptLevel
THook(void, "?corruptLevel@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::corruptLevel");
    original(_this);
    LOG_END
    printf_s("DBStorage::corruptLevel(%p)\n", _this);
}

// not in vtbl

// DBStorage::PendingWriteResult
THook(LevelStorageWriteBatch*, "??0PendingWriteResult@DBStorage@@QEAA@V?$shared_ptr@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@_N@Z",
    DBStorage* _this, shared_ptr<string> bin, byte a2) {
    LOG_START("DBStorage::PendingWriteResult::PendingWriteResult");
    auto rtn = original(_this, bin, a2);
    LOG_END_RTN
    size_t len = bin.get()->length();
    printf_s("DBStorage::PendingWriteResult::PendingWriteResult(%p, byte[%d], %d) -> %p\n", _this, (int)len, a2, rtn);
    return rtn;
}

// DBStorage::_findCacheEntry
//DBStorage::_findCacheEntry(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &)
THook(LevelStorageWriteBatch*, "?_findCacheEntry@DBStorage@@IEAA?AU?$pair@PEAVLevelStorageWriteBatch@@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBatchEntry@LevelStorageWriteBatch@@@std@@@std@@@std@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    DBStorage* _this, pair<void*, void*>* batch, string& key) {
    //		(void***)batch->first	0x00007ff9e5da69d6 {msvcp140.dll!std::basic_filebuf<char,std::char_traits<char>>::_Unlock(void), 行 403} {...}	void * * *
    //		(void***)batch->second	0x00007ff9e5e25080 {msvcp140.dll!std::basic_ostream<char,std::char_traits<char>> std::cout} {0x00007ff9e5df7d88 {msvcp140.dll!const std::basic_ostream<char,struct std::char_traits<char> >::`vbtable'} {...}}	void * * *
    LOG_START("DBStorage::_findCacheEntry");
    // a1===rtn
    auto rtn = original(_this, batch, key);
    LOG_END_RTN
    printf_s("DBStorage::_findCacheEntry(%p, %p, %s) -> %p\n", _this, batch, keyToString(key).c_str(), rtn);
    return rtn;
}

// DBStorage::_flushWriteCacheToLevelDB
THook(void*, "?_flushWriteCacheToLevelDB@DBStorage@@AEAA?AVTaskResult@@XZ",
    DBStorage* _this, void* taskResult) {
    LOG_START("DBStorage::_flushWriteCacheToLevelDB");
    //taskResult {*taskResult {内部 bedrock_server_mod.exe!WorkerPool::tryPop(int)} {0x4c08508b48088b48 {...}}}
    auto rtn = original(_this, taskResult);
    LOG_END_RTN
    printf_s("DBStorage::_flushWriteCacheToLevelDB(%p, %p) -> %p\n", _this, taskResult, rtn);
    return rtn;
}

typedef void** PendingWriteResult;
// DBStorage::_getAllPendingWrites
THook(void*, "?_getAllPendingWrites@DBStorage@@IEBA?AV?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@@std@@@2@@std@@XZ",
    DBStorage* _this, std::map<string, PendingWriteResult>& resultMap, void* a) {
    LOG_START("DBStorage::_getAllPendingWrites");
    auto rtn = original(_this, resultMap, a);
    LOG_END_RTN
    printf_s("DBStorage::_getAllPendingWrites(%p, %p) -> %p\n", _this, &resultMap, rtn);
    for (auto& [key, res]: resultMap) {
        cout << keyToString((string&)key) << " -> " << res << endl;
    }
    return rtn;
}

// DBStorage::_getTelemetryMessage
THook(void*, "?_getTelemetryMessage@DBStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVStatus@leveldb@@@Z",
    DBStorage* _this, string& str, void* dbStatus) {
    LOG_START("DBStorage::_getTelemetryMessage");
    auto rtn = original(_this, str, dbStatus);
    LOG_END_RTN
    printf_s("DBStorage::_getTelemetryMessage(%p, %s, %s) -> %p\n", _this, str.c_str(), statusToString(dbStatus).c_str(), rtn);
    return rtn;
}

// DBStorage::_handleErrorStatus
THook(void, "?_handleErrorStatus@DBStorage@@IEAAXAEBVStatus@leveldb@@@Z",
    DBStorage* _this, void* dbStatus) {
    LOG_START("DBStorage::_handleErrorStatus");
    original(_this, dbStatus);
    LOG_END
    printf_s("DBStorage::_handleErrorStatus(%p, %s)\n", _this, statusToString(dbStatus).c_str());
}

// DBStorage::_markAsCorrupted
THook(void, "?_markAsCorrupted@DBStorage@@AEBAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
    DBStorage* _this, string_span str_span) {
    LOG_START("DBStorage::_markAsCorrupted");
    original(_this, str_span);
    LOG_END
    printf_s("DBStorage::_markAsCorrupted(%p, %p)\n", _this, str_span.str);
}
// DBStorage::_mergeIntoWriteCache
THook(void, "?_mergeIntoWriteCache@DBStorage@@IEAAXAEBVLevelStorageWriteBatch@@@Z",
    DBStorage* _this, LevelStorageWriteBatch* batch) {
    LOG_START("DBStorage::_mergeIntoWriteCache");
    original(_this, batch);
    LOG_END
    printf_s("DBStorage::_mergeIntoWriteCache(%p, %p)\n", _this, batch);
}

// DBStorage::_queueSaveCallback
THook(void, "?_queueSaveCallback@DBStorage@@IEAAX_N@Z",
    DBStorage* _this, bool a1) {
    LOG_START("DBStorage::_queueSaveCallback");
    original(_this, a1);
    LOG_END
    printf_s("DBStorage::_queueSaveCallback(%p, %d)\n", _this, a1);
}

// DBStorage::_read
THook(void*, "?_read@DBStorage@@IEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    DBStorage* _this, string_span str_span, void* func) {
    LOG_START("DBStorage::_read");
    auto rtn = original(_this, str_span, func);
    LOG_END_RTN
    auto key = keyToString((string&)str_span.toString());
    printf_s("DBStorage::_read(%p, %s, %p) -> %p\n", _this, key.c_str(), func, rtn);
    return rtn;
}
// DBStorage::_readPendingWrite
THook(PendingWriteResult*, "?_readPendingWrite@DBStorage@@IEBA?AUPendingWriteResult@1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    DBStorage* _this, PendingWriteResult* res, string& key) {
    LOG_START("DBStorage::_readPendingWrite");
    auto rtn = original(_this,res, key);
    LOG_END_RTN
    //printf_s("DBStorage::_readPendingWrite(%p, %p, %s) -> %p\n", _this, res, keyToString(key).c_str(), rtn);
    cout << ",";
    return rtn;
}
// DBStorage::_scheduleNextAutoCompaction
THook(void, "?_scheduleNextAutoCompaction@DBStorage@@AEAAXXZ",
    DBStorage* _this) {
    LOG_START("DBStorage::_scheduleNextAutoCompaction");
    original(_this);
    LOG_END
    printf_s("DBStorage::_scheduleNextAutoCompaction(%p)\n", _this);
}
// DBStorage::_suspendAndPerformSaveAction
THook(bool, "?_suspendAndPerformSaveAction@DBStorage@@AEAA_NV?$function@$$A6A?AVTaskResult@@XZ@std@@V?$function@$$A6AXXZ@3@@Z",
    DBStorage* _this, function<void* (void)> func1, function<void(void)>func2) {
    LOG_START("DBStorage::_suspendAndPerformSaveAction")
    auto rtn = original(_this, func1, func2);
    LOG_END_RTN
    printf_s("DBStorage::_suspendAndPerformSaveAction(%p, %p, %p) -> %d\n", _this, &func1, &func2, rtn);
    return rtn;
}

// DBStorage::_suspendAndPerformSaveAction
THook(bool, "?tryRepair@DBStorage@@QEBA_NAEBVPath@Core@@@Z",
    DBStorage* _this, void* path) {
    LOG_START("DBStorage::_suspendAndPerformSaveAction")
    auto rtn = original(_this, path);
    LOG_END_RTN
    printf_s("DBStorage::_suspendAndPerformSaveAction(%p, %p) -> %d\n", _this, path, rtn);
    return rtn;
}

// DBStorage::getState2

/*
bool backupEnd(bool success);

bool backupCopy(filesystem::path src, filesystem::path dst, size_t size) {
    try {
        auto dir = filesystem::path(dst).parent_path();
        filesystem::create_directories(dir);
        filesystem::copy_file(src, dst);
        if (filesystem::file_size(dst) != size) {
            cout << dst << ", old size: " << filesystem::file_size(dst);
            filesystem::resize_file(dst, size);
            cout << ", new size: " << filesystem::file_size(dst) << endl;;
        }
    }
    catch (filesystem::filesystem_error e) {
        cerr << "Error in Copy File, error code: " << e.code() << endl;
        return backupEnd(false);
    }
    //cout << fullPath << endl;
    return true;
}
bool backupCompress(filesystem::path dir, filesystem::path zipPath) {
    try {
        wstring cmd = L"a -mx0 \"";
        cmd += zipPath.wstring() + L"\" \"" + dir.wstring() + L"\"";
        //cout << cmd.c_str() << endl;
        //auto rtn = system(cmd.c_str());
        //auto result = ShellExecute(NULL, L"open", L".\\plugins\\LLBackup\\7z.exe", cmd.c_str() , L".", SW_HIDE);
        SHELLEXECUTEINFO ShExecInfo = { 0 };
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        ShExecInfo.hwnd = NULL;
        ShExecInfo.lpVerb = NULL;
        ShExecInfo.lpFile = L".\\plugins\\LLBackup\\7z.exe";
        ShExecInfo.lpParameters = cmd.c_str();
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_HIDE;
        ShExecInfo.hInstApp = NULL;
        auto result=ShellExecuteEx(&ShExecInfo);
        if (ShExecInfo.hProcess == 0) {
            cerr << "Error in compress file: ShExecInfo.hProcess == 0" << endl;
            return false;
        }
        WaitForSingleObjectEx(ShExecInfo.hProcess, 30000, true);
        return result;
    }
    catch (filesystem::filesystem_error e) {
        cerr << "Error in create zip file" << endl;
        return backupEnd(false);
    }
    return true;
}

string backupDir = "F:\\mcbackup";
bool backupEnd(bool success) {
    try {
        filesystem::remove_all(filesystem::path(backupDir).append("tmp"));
    }
    catch (filesystem::filesystem_error e) {
        cerr << "Error in cleanup tmp files, error code: " << e.code() << endl;
    }
    if (success) {
        cout << "备份成功" << endl;
    }
    else {
        cout << "备份失败" << endl;
    }
    //liteloader::runcmd("save resume");
    return success;
}
bool backup(vector<SnapshotFilenameAndLength>& fdetails, string& worldName) {
    bool success;
    cout << "正在复制备份文件..." << endl;
    for (auto& fdetail : fdetails) {
        filesystem::path srcPath = filesystem::path("./worlds").append(fdetail.path);
        filesystem::path dstPath = filesystem::path(backupDir).append("tmp").append(fdetail.path);
        auto& fileSize = fdetail.size;
        success = backupCopy(srcPath, dstPath, fileSize);
        if (!success)
            return backupEnd(success);
        //cout << s.filePath << ":" << s.fileSize << endl;
    }
    time_t timep=0; 
    time(&timep);
    struct tm t_tm;
    localtime_s(&t_tm, &timep);
    char timeStr[64];
    strftime(timeStr, sizeof(timeStr), "%Y%m%d-%H%M%S", &t_tm);
    string backupName = worldName + "-" + timeStr +".zip";
    filesystem::path backupPath = filesystem::path(backupDir).append("tmp").append(worldName);
    filesystem::path zipPath = filesystem::path(backupDir).append("tmp/zip/").append(backupName);
    cout << "正在打包备份文件..." << endl;
    success = backupCompress(backupPath, zipPath);
    //backupCopy();
    return backupEnd(success);
}

int resumeDelay = 0;
// DBStorage::createSnapshot
THook(vector<SnapshotFilenameAndLength>&, "?createSnapshot@DBStorage@@UEAA?AV?$vector@USnapshotFilenameAndLength@@V?$allocator@USnapshotFilenameAndLength@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    DBStorage* _this, vector<SnapshotFilenameAndLength>& fdetails, string& worldName) {
    LOG_START("DBStorage::createSnapshot");
    auto& rtn = original(_this, fdetails, worldName);
    //Sleep(10000000);
    try {
        LARGE_INTEGER freq;
        LARGE_INTEGER begin;
        LARGE_INTEGER end;
        QueryPerformanceFrequency(&freq);
        QueryPerformanceCounter(&begin);
        auto res = backup(fdetails, worldName);
        QueryPerformanceCounter(&end);
        resumeDelay = 20;
        if (!res) {
            LOG_END_RTN
        }
        double timec = (double)(end.QuadPart - begin.QuadPart) / (double)freq.QuadPart;
        cout << "Backup " << fdetails.size() << " Files, time: "<<timec<<"s" << endl;
    }
    catch (...) {
        cerr << "Unknown Error in Backup" << endl;
        LOG_END_RTN
    }
    LOG_END_RTN
        printf_s("DBStorage::createSnapshot(%p, %p) -> %p\n", _this, &fdetails, &rtn);
    return rtn;
}
typedef Actor ItemActor;
struct ActorDefinitionGroup;
struct ActorDefinitionIdentifier;
THook(ItemActor*, "??0ItemActor@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@@Z"
    , ItemActor* _this, struct ActorDefinitionGroup* adg, const struct ActorDefinitionIdentifier* adi) {
    auto rtn = original(_this, adg, adi);
    rtn->setNameTag("test");
    SymCall("?setNameTagVisible@Actor@@UEAAX_N@Z",
        void, Actor*, bool)(rtn, true);
    auto& str = rtn->getNameTag();
    return rtn;
}
THook(bool, "?canShowNameTag@Actor@@UEBA_NXZ"
    , Actor* _this) {
    auto rtn = original(_this);
    return true;
}

int holdDelay=0;
THook(void, "?tick@ServerLevel@@UEAAXXZ"
    , ServerLevel* _this) {
    original(_this);
    if (resumeDelay) {
        --resumeDelay;
        if (!resumeDelay) {
            auto res = liteloader::runcmdEx("save resume");
            if (!res.first) {
                cerr << "Error: " << res.second << endl;
                resumeDelay = 100;
            }else
                cout << res.second << endl;
            holdDelay = 100;
        }
    }
    if (holdDelay) {
        --holdDelay;
        if (!holdDelay) {
            auto res = liteloader::runcmdEx("save hold");
            if (!res.first) {
                cerr << "Error: " << res.second << endl;
                holdDelay = 100;
            }
            else
                cout << res.second << endl;
        }
    }
}

//Block::getDebugText(vector<string> &,BlockPos const &)
//THook(bool, "?mayPlace@BlockSource@@QEAA_NAEBVBlock@@AEBVBlockPos@@EPEAVActor@@_N@Z",
//    BlockSource* _this, Block* a2, BlockPos* a3, unsigned __int8 a4, Actor* a5, bool a6)
//{
//    auto rtn= original(_this, a2, a3, a4, a5, a6);
//    string rawNameId;
//    string buildDescriptionId;
//    string getDescriptionId;
//    string descriptionName;
//    //void* item=SymCall("?asItemInstance@Block@@QEBA?AVItemInstance@@AEAVBlockSource@@AEBVBlockPos@@@Z",
//    //    void*, BlockLegacy*)(offBlock::getLegacyBlock(a2));
//    rawNameId = SymCall("?getRawNameId@BlockLegacy@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
//        string&, BlockLegacy*)(offBlock::getLegacyBlock(a2));
//    SymCall("?buildDescriptionId@Block@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
//        string&, Block*, string&)(a2, buildDescriptionId);
//    SymCall("?getDescriptionId@Block@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
//        string&, Block*, string&)(a2, getDescriptionId);
//    SymCall("?buildDescriptionName@Block@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
//        string&, Block*, string&)(a2, descriptionName);
//    LOG_VAR(rawNameId)
//    LOG_VAR(buildDescriptionId)
//    LOG_VAR(getDescriptionId)
//    LOG_VAR(descriptionName)
//    return rtn;
//}
////Block::getDebugText(vector<string> &,BlockPos const &)
//THook(void*, "?mSaveAllMutex@SaveCommand@@0Vmutex@std@@A",
//    void* _this)
//{
//    return original(_this);
//}
*/
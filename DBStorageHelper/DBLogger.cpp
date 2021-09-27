#include "pch.h"
#include <shellapi.h>
#include "SymHelper.h"
#include "DBStorage.h"
#include "DBStorageHelper.h"
#include <mc/Level.h>
#include <mc/OffsetHelper.h>
#include <api/scheduler/scheduler.h>
#include <seh_exception/seh_exception.hpp>


#define LOG_START(name) \
string fun_name=name;\
string space="                                       ";\
if(level<0) level=0;\
//cout<<space.substr(0, 2*level++)<<fun_name<<":"<<endl;
#define LOG_START_WITH_KEY(name) \
string space="                                       ";\
if(level<0) level=0;\
//cout<<space.substr(0, 2*level++)<<name<<": "<<keyToString(key)<<endl;
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
}

// DBStorage::getCompoundTag
THook(unique_ptr<Tag>*, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    LevelStorage* _this, unique_ptr<Tag>& tagPtr, string& key) {
    LOG_START_WITH_KEY("DBStorage::getCompoundTag");
    auto rtn = original(_this, tagPtr, key);
    LOG_END_RTN
}

// DBStorage::hasKey
THook(bool, "?hasKey@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
    void* _this, string_span key_span) {
    //LOG_START("DBStorage::hasKey");
    auto rtn = original(_this, key_span);
    //LOG_END_RTN
    return rtn;
}

// DBStorage::forEachKeyWithPrefix
THook(unsigned long long, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    void* _this, string_span key_span, function<void(string_span, string_span)> const& func) {
    string key = string(key_span.str, key_span.len);
    LOG_START_WITH_KEY("DBStorage::forEachKeyWithPrefix");
    auto rtn = original(_this, key_span, func);
    LOG_END_RTN
}

// DBStorage::loadLevelData
THook(bool, "?loadLevelData@DBStorage@@UEAA_NAEAVLevelData@@@Z",
    void* _this, LevelData* data) {
    LOG_START("DBStorage::loadLevelData");
    auto rtn = original(_this, data);
    LOG_END_RTN
}

// DBStorage::createChunkStorage
THook(void*, "?createChunkStorage@DBStorage@@UEAA?AV?$unique_ptr@VChunkSource@@U?$default_delete@VChunkSource@@@std@@@std@@V23@W4StorageVersion@@@Z",
    void* _this, ChunkSource** cs, StorageVersion* sv) {
    LOG_START("DBStorage::createChunkStorage");
    auto rtn = original(_this, cs, sv);
    LOG_END_RTN
}

// DBStorage::saveLevelData
THook(void*, "?saveLevelData@DBStorage@@UEAAXAEBVLevelData@@@Z",
    void* _this, LevelData* data) {
    LOG_START("DBStorage::saveLevelData");
    auto rtn = original(_this, data);
    LOG_END_RTN
}

// DBStorage::getFullPath
THook(string*, "?getFullPath@DBStorage@@UEBAAEBV?$PathBuffer@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Core@@XZ",
    void* _this) {
    //LOG_START("DBStorage::getFullPath");
    auto rtn = original(_this);
    //LOG_END_RTN
    return rtn;
}


//std::map<string,LevelStorageWriteBatch::BatchEntry>
// DBStorage::saveData
THook(void*, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBVLevelStorageWriteBatch@@@Z",
    void* _this, IAsyncResult<void>* result, LevelStorageWriteBatch* batch) {
    LOG_START("DBStorage::saveData");
    auto rtn = original(_this, result, batch);
    LOG_END_RTN
}

// DBStorage::saveData
THook(IAsyncResult<void>*, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@@Z",
    void* _this, IAsyncResult<void>* result, string const& key, string* data) {
    LOG_START_WITH_KEY("DBStorage::saveData2");
    size_t len = data->length();
    auto rtn = original(_this, result, key, data);
    LOG_END_RTN
}

// DBStorage::deleteData
THook(void*, "?deleteData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    void* _this, IAsyncResult<void>* result, string const& key, void* a3) {
    LOG_START_WITH_KEY("DBStorage::deleteData");
    auto rtn = original(_this, result, key, a3);
    LOG_END_RTN
}

// DBStorage::syncIO
THook(void*, "?syncIO@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::syncIO");
    auto rtn = original(_this);
    LOG_END_RTN
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
}

// DBStorage::clonePlayerData
THook(void*, "?clonePlayerData@LevelStorage@@UEAA_NV?$basic_string_span@$$CBD$0?0@gsl@@0@Z",
    void* _this, string_span key_span_1, string_span key_span_2) {
    string key = key_span_1.toString();
    LOG_START_WITH_KEY("DBStorage::clonePlayerData");
    auto rtn = original(_this, key_span_1, key_span_2);
    LOG_END_RTN
}

// DBStorage::getState
THook(void*, "?getState@DBStorage@@UEBA?AULevelStorageResult@Core@@XZ",
    void* _this, void* result) {
    //LOG_START("DBStorage::getState");
    auto rtn = original(_this, result);
    //LOG_END_RTN
    return rtn;
}

// DBStorage::startShutdown
THook(void, "?startShutdown@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::startShutdown");
    original(_this);
    LOG_END
}

// DBStorage::isShuttingDown
THook(bool, "?isShuttingDown@DBStorage@@UEBA_NXZ",
    void* _this) {
    LOG_START("DBStorage::isShuttingDown");
    auto rtn = original(_this);
    LOG_END_RTN
}

// DBStorage::checkShutdownDone
THook(bool, "?checkShutdownDone@DBStorage@@UEAA_NXZ",
    void* _this) {
    LOG_START("DBStorage::checkShutdownDone");
    auto rtn = original(_this);
    LOG_END_RTN
}

// DBStorage::loadData
THook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    void* _this, string_span key_span, string& data) {
    string key = key_span.toString();
    //if (key == "portals") {
    //    *(void**)0 = 0;
    //}
    LOG_START_WITH_KEY("DBStorage::loadData");
    //if(key_span.toString()=="portals")
    //    *((void**)0) = 0;
    auto rtn = original(_this, key_span, data);
    LOG_END_RTN
}

// DBStorage::releaseSnapshot
THook(void, "?releaseSnapshot@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::releaseSnapshot");
    original(_this);
    LOG_END
}

// DBStorage::compactStorage
THook(void, "?compactStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::compactStorage");
    original(_this);
    LOG_END
}

// DBStorage::syncAndSuspendStorage
THook(void, "?syncAndSuspendStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::syncAndSuspendStorage");
    original(_this);
    LOG_END
}

// DBStorage::resumeStorage
THook(void, "?resumeStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::resumeStorage");
    original(_this);
    LOG_END
}

// DBStorage::setFlushAllowed
THook(void, "?setFlushAllowed@DBStorage@@UEAAX_N@Z",
    void* _this, bool a1) {
    LOG_START("DBStorage::setFlushAllowed");
    original(_this, a1);
    LOG_END
}

// DBStorage::flushToPermanentStorage
THook(void, "?flushToPermanentStorage@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::flushToPermanentStorage");
    original(_this);
    LOG_END
}

// DBStorage::freeCaches
THook(void, "?freeCaches@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::freeCaches");
    original(_this);
    LOG_END
}

// DBStorage::setCompactionCallback
THook(void*, "?setCompactionCallback@DBStorage@@UEAAXV?$function@$$A6AXW4CompactionStatus@@@Z@std@@@Z",
    void* _this, function<void(void*)> func) {
    LOG_START("DBStorage::setCompactionCallback");
    auto rtn = original(_this, func);
    LOG_END_RTN
}

// DBStorage::setCriticalSyncSaveCallback
THook(void*, "?setCriticalSyncSaveCallback@DBStorage@@UEAAXV?$function@$$A6AXXZ@std@@@Z",
    void* _this, function<void(void)> func) {
    LOG_START("DBStorage::setCriticalSyncSaveCallback");
    auto rtn = original(_this, func);
    LOG_END_RTN
}

// DBStorage::corruptLevel
THook(void, "?corruptLevel@DBStorage@@UEAAXXZ",
    void* _this) {
    LOG_START("DBStorage::corruptLevel");
    original(_this);
    LOG_END
}

// not in vtbl

// DBStorage::PendingWriteResult
THook(LevelStorageWriteBatch*, "??0PendingWriteResult@DBStorage@@QEAA@V?$shared_ptr@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@_N@Z",
    DBStorage* _this, shared_ptr<string> bin, byte a2) {
    LOG_START("DBStorage::PendingWriteResult::PendingWriteResult");
    auto rtn = original(_this, bin, a2);
    LOG_END_RTN
}

// DBStorage::_findCacheEntry
//DBStorage::_findCacheEntry(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &)
THook(LevelStorageWriteBatch*, "?_findCacheEntry@DBStorage@@IEAA?AU?$pair@PEAVLevelStorageWriteBatch@@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBatchEntry@LevelStorageWriteBatch@@@std@@@std@@@std@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    DBStorage* _this, pair<void*, void*>* batch, string& key) {
    //		(void***)batch->first	0x00007ff9e5da69d6 {msvcp140.dll!std::basic_filebuf<char,std::char_traits<char>>::_Unlock(void), 行 403} {...}	void * * *
    //		(void***)batch->second	0x00007ff9e5e25080 {msvcp140.dll!std::basic_ostream<char,std::char_traits<char>> std::cout} {0x00007ff9e5df7d88 {msvcp140.dll!const std::basic_ostream<char,struct std::char_traits<char> >::`vbtable'} {...}}	void * * *
    LOG_START_WITH_KEY("DBStorage::_findCacheEntry");
    // a1===rtn
    auto rtn = original(_this, batch, key);
    LOG_END_RTN
}

// DBStorage::_flushWriteCacheToLevelDB
THook(void*, "?_flushWriteCacheToLevelDB@DBStorage@@AEAA?AVTaskResult@@XZ",
    DBStorage* _this, void* taskResult) {
    LOG_START("DBStorage::_flushWriteCacheToLevelDB");
    //taskResult {*taskResult {内部 bedrock_server_mod.exe!WorkerPool::tryPop(int)} {0x4c08508b48088b48 {...}}}
    auto rtn = original(_this, taskResult);
    LOG_END_RTN
}

typedef void** PendingWriteResult;
// DBStorage::_getAllPendingWrites
THook(void*, "?_getAllPendingWrites@DBStorage@@IEBA?AV?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UPendingWriteResult@DBStorage@@@std@@@2@@std@@XZ",
    DBStorage* _this, std::map<string, PendingWriteResult>& resultMap, void* a) {
    LOG_START("DBStorage::_getAllPendingWrites");
    auto rtn = original(_this, resultMap, a);
    LOG_END_RTN
        printf_s("DBStorage::_getAllPendingWrites(%p, %p) -> %p\n", _this, &resultMap, rtn);
    for (auto& [key, res] : resultMap) {
        cout << keyToString((string&)key) << " -> " << res << endl;
    }
    return rtn;
}

// DBStorage::_getTelemetryMessage
THook(void*, "?_getTelemetryMessage@DBStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVStatus@leveldb@@@Z",
    DBStorage* _this, string& statusStr, void* dbStatus) {
    LOG_START("DBStorage::_getTelemetryMessage");
    auto rtn = original(_this, statusStr, dbStatus);
    LOG_END_RTN
}

// DBStorage::_handleErrorStatus
THook(void, "?_handleErrorStatus@DBStorage@@IEAAXAEBVStatus@leveldb@@@Z",
    DBStorage* _this, void* dbStatus) {
    LOG_START("DBStorage::_handleErrorStatus");
    original(_this, dbStatus);
    LOG_END
}

// DBStorage::_markAsCorrupted
THook(void, "?_markAsCorrupted@DBStorage@@AEBAXV?$basic_string_span@$$CBD$0?0@gsl@@@Z",
    DBStorage* _this, string_span str_span) {
    LOG_START("DBStorage::_markAsCorrupted");
    original(_this, str_span);
    LOG_END
}
// DBStorage::_mergeIntoWriteCache
THook(void, "?_mergeIntoWriteCache@DBStorage@@IEAAXAEBVLevelStorageWriteBatch@@@Z",
    DBStorage* _this, LevelStorageWriteBatch* batch) {
    LOG_START("DBStorage::_mergeIntoWriteCache");
    original(_this, batch);
    LOG_END
}

// DBStorage::_queueSaveCallback
THook(void, "?_queueSaveCallback@DBStorage@@IEAAX_N@Z",
    DBStorage* _this, bool a1) {
    LOG_START("DBStorage::_queueSaveCallback");
    original(_this, a1);
    LOG_END
}

// DBStorage::_read
THook(void*, "?_read@DBStorage@@IEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    DBStorage* _this, string_span prefix_span, void* func) {
    auto key = prefix_span.toString();
    LOG_START_WITH_KEY("DBStorage::_read");
    auto rtn = original(_this, prefix_span, func);
    LOG_END_RTN
}
// DBStorage::_readPendingWrite
THook(PendingWriteResult*, "?_readPendingWrite@DBStorage@@IEBA?AUPendingWriteResult@1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    DBStorage* _this, PendingWriteResult* res, string& key) {
    LOG_START_WITH_KEY("DBStorage::_readPendingWrite");
    auto rtn = original(_this, res, key);
    LOG_END_RTN
}
// DBStorage::_scheduleNextAutoCompaction
THook(void, "?_scheduleNextAutoCompaction@DBStorage@@AEAAXXZ",
    DBStorage* _this) {
    LOG_START("DBStorage::_scheduleNextAutoCompaction");
    original(_this);
    LOG_END
}
// DBStorage::_suspendAndPerformSaveAction
THook(bool, "?_suspendAndPerformSaveAction@DBStorage@@AEAA_NV?$function@$$A6A?AVTaskResult@@XZ@std@@V?$function@$$A6AXXZ@3@@Z",
    DBStorage* _this, function<void* (void)> func1, function<void(void)>func2) {
    LOG_START("DBStorage::_suspendAndPerformSaveAction")
        auto rtn = original(_this, func1, func2);
    LOG_END_RTN
}

// DBStorage::_suspendAndPerformSaveAction
THook(bool, "?tryRepair@DBStorage@@QEBA_NAEBVPath@Core@@@Z",
    DBStorage* _this, void* path) {
    LOG_START("DBStorage::_suspendAndPerformSaveAction")
        auto rtn = original(_this, path);
    LOG_END_RTN
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
Actor* getActor(Level* lv, ActorUniqueID id) {
    return SymCall("?fetchEntity@Level@@UEBAPEAVActor@@UActorUniqueID@@_N@Z",
        Actor*, Level*, ActorUniqueID, bool)(lv, id, 0);
}
THook(bool, "?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
    Mob* ac, ActorDamageSource* ads, int damage, bool unk1_1, bool unk2_0)
{
    if (false&&ac)
    {
        auto level = offPlayer::getLevel(ac);
        void* auid;
        auto v6 = *VirtualCall<ActorUniqueID*>(ads, 0x40, &auid); // 
        cout << "auid1: " << v6 << endl;
        auto v7 = *VirtualCall<ActorUniqueID*>(ads, 0x68, &auid); // 
        cout << "auid2: " << v7 << endl;
        if (v6&&v7&&v6.id != v7.id) {
            auto act1 = getActor(level, v6);
            auto act2 = getActor(level, v6);
        }
        pair<string, vector<string>> res;
        string name = ac->getNameTag();
        auto& msg = *VirtualCall<pair<string, vector<string>>*>(ads, 0x28, &res, &name , getActor(level, v6));
        cout << "key: " << msg.first << endl;
        for (auto& val : msg.second) {
            cout << "val: " << val << endl;
        }
    }
    return original(ac, ads, damage, unk1_1, unk2_0);
}



// IDA _dynamic_initializer_for__gDamageTypeParam__
enum class DamageCause : int
{
    None = -1,
    Override = 0,
    Contact = 1,
    Attack = 2,
    Projectile = 3,
    Suffocation = 4,
    Fall = 5,
    Fire = 6,
    FireTick = 7,
    Lava = 8,
    Drowning = 9,
    BlockExplosion = 10,
    EntityExplosion = 11,
    Void = 12,
    Suicide = 13,
    Magic = 14,
    Wither = 15,
    Starve = 16,
    Anvil = 17,
    Stalactite = 28,
    Stalagmite = 29,
    Thorns = 18,
    FallingBlock = 19,
    Piston = 20,
    FlyIntoWall = 21,
};
//0x00007ff644bab4b0 {bedrock_server_mod.exe!ActorDamageSource::getDeathMessage(class string, class Actor *)const }
string getDamageMessage(ActorDamageSource* ads) {
    string res;
    pair<string, vector<string>>* unk;
    return SymCall("?getDeathMessage@ActorDamageSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
        string&, ActorDamageSource*, std::pair<string, vector<string>>*, string&)(ads, unk, res);
}

int code = -2;
// ===== onMobHurt =====
THook(bool, "?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
    Mob* ac, ActorDamageSource* ads, int damage, bool unk1_1, bool unk2_0)
{

    if (ac)
    {
        auto level = offPlayer::getLevel(ac);
        DamageCause cause = dAccess<DamageCause>(ads, 8);
        //*((int*)ads + 1) = code++;

        //cout << "Cause: " << (int)cause << endl;
        //auto v6 = *VirtualCall<ActorUniqueID*>(ads, 0x40, &v83); //IDA ActorDamageSource::`vftable'
        //auto src = Raw_GetEntityByUniqueId(v6);
    }
    return original(ac, ads, damage, unk1_1, unk2_0);
}

THook(void*, "?getDeathMessage@ActorDamageSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource* ads, pair<string, vector<string>>& res, string& name, Actor* actor) {
    auto rtn = original(ads, res, name, actor);
    return rtn;
}

THook(void*, "?getDeathMessage@ActorDamageByActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource* ads, pair<string, vector<string>>& res, string& name, Actor* actor) {
    auto rtn = original(ads, res, name, actor);
    return rtn;
}

THook(void*, "?getDeathMessage@ActorDamageByChildActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource* ads, pair<string, vector<string>>& res, string& name, Actor* actor) {
    auto rtn = original(ads, res, name, actor);
    return rtn;
}

THook(void*, "?getDeathMessage@ActorDamageByBlockSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@PEAVActor@@@Z",
    ActorDamageSource* ads, pair<string, vector<string>>& res, string& name, Actor* actor) {
    auto rtn = original(ads, res, name, actor);
    return rtn;
}

/*
*/


//vector<int> vec;
//bool notInAir = false;
//// ===== onAttack =====
//THook(bool, "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
//    Player* _this, Actor* ac, int* damageCause){
//    SymCall("?setNameTagVisible@Actor@@UEAAX_N@Z",
//        void, Actor*, bool)(ac, true);
//    cout << "dAccess<void*>(ac, 472)" << dAccess<void*>(ac, 472) << endl;
//    return original(_this, ac, damageCause);
//    if (vec.empty()) {
//        for(int i=0;i<10000;i++){
//            vec.push_back(i);
//        }
//    }
//    for (auto iter = vec.begin(); iter != vec.end();) {
//        if (dAccess<bool>(_this, *iter) != notInAir) {
//            iter=vec.erase(iter);
//        }
//        else {
//            iter++;
//        }
//    }
//    cout << "not in air: " << notInAir << endl;
//    cout << "size: " << vec.size() << endl;
//    if (vec.size()<10) {
//        for (auto& off : vec) {
//            cout << "off: "<< off << endl;
//        }
//    }
//    notInAir = !notInAir;
//    return original(_this, ac, damageCause);
//}
#include "pch.h"
#include "SymHelper.h"
#include "DBStorageHelper.h"
#include "DBStorage.h"

// DBStorage::addStorageObserver
bool testDBStorage() {
    return true;
    DBStorage* dbs = getDBStorage();
    dbs->addStorageObserver(nullptr);
    string key = "OverWorld";
    string_span ks = { key.length(), (char*)key.c_str() };
    assert(dbs->getCompoundTag(key)->getTagType() == TagType::Compound);
    assert(dbs->hasKey(ks) == true && dbs->hasKey({ 1,"1" }) == false);
    dbs->loadLevelData(*(LevelData*)nullptr);
    dbs->createChunkStorage(nullptr, (StorageVersion*)nullptr);
    dbs->saveLevelData(*(LevelData*)nullptr);
    auto& path = *dbs->getFullPath();
    //dbs->saveData(*(LevelStorageWriteBatch*)nullptr);
    //dbs->saveData(nullptr, nullptr);
    //dbs->deleteData(nullptr);
    //dbs->syncIO(); // stateË¢ÆÁ
    dbs->getStatistics(*(string*)nullptr);
    dbs->clonePlayerData(ks, ks);
    dbs->getState();
    //dbs->startShutdown();
    assert(dbs->isShuttingDown() == false);
    assert(dbs->checkShutdownDone() == false);
    //dbs->loadData(ks, key);
    //dbs->createSnapshot(key); //error
    dbs->releaseSnapshot();
    dbs->compactStorage();
    //dbs->syncAndSuspendStorage(); // stateË¢ÆÁ
    dbs->resumeStorage();
    dbs->setFlushAllowed(false);
    dbs->flushToPermanentStorage();
    dbs->freeCaches();
    dbs->setCompactionCallback(nullptr);
    dbs->setCriticalSyncSaveCallback(nullptr);
    //dbs->corruptLevel(); 
    assert(path.length() > 7 && path.substr(0, 7) == "worlds");

}

enum class OP_DB_HELPER :int
{
	help, //help
    listkey, //listkey [prefix]
	playerids, // [type]
	read, // read key
	write, // write key data
	tofile, // dbtofile key filename
	fromfile, // filetodb key filename
	readchunk,
	writechunk,
};

enum class OP_CHUNK_HELPER :int
{
    count, // count [dim]
    read, // read cx cz dim [type] [cy]
    write, // write cx cz dim type filename [cy]
    del, // del cx cz dim type filename [cy]
    tofile, // tofile filename
    fromfile, // tofile filename
    key, // key cx cz dim [type] [cy]
};
bool oncmd_dbhelper(CommandOrigin const& ori, CommandOutput& outp) {
    cout << getDBStorage()->isShuttingDown() << endl;
    if(!getDBStorage()->isShuttingDown())
        getDBStorage()->startShutdown();
    cout << getDBStorage()->checkShutdownDone() << endl;
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("dbhelper", "start shutdown", 0);
        CmdOverload(dbhelper, oncmd_dbhelper);
        });
    Event::addEventListener([](ServerStartedEV ev) {
        testDBStorage();
        });
}

void entry() {
    regListener();
}
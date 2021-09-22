#include "pch.h"
#include "SymHelper.h"
#include "DBStorageHelper.h"
#include "DBStorage.h"
#include <mc/OffsetHelper.h>
using namespace std;
#define DATA_DIR "F:\\Minecraft\\leveldb_struct"



// DBStorage::addStorageObserver

bool testDBStorage() {
    filesystem::path binDir = filesystem::path(DATA_DIR).append("bin");
    filesystem::path snbtDir = filesystem::path(DATA_DIR).append("snbt");
    filesystem::create_directories(binDir);
    filesystem::create_directories(snbtDir);
    auto dbh = getDBStorage()->getHelper();
    dbh.forEachKeyWithPrefix("", [&dbh, binDir, snbtDir](const string& key, string& bin) {
        try {
            if (!std::regex_match(key, std::regex("[\\w ,\.\-]*")))
                return;
            string fmtKey = keyToString(key, "");
            filesystem::path binPath = filesystem::path(binDir).append(fmtKey + ".bin");
            fstream fo(binPath, ios::out | ios::binary);
            fo.write(bin.c_str(), bin.length());
            fo.flush();
            fo.close();
            auto tags = BinaryNBTToTags(bin);
            if (tags.size() == 1) {
                auto tag = tags[0];
                filesystem::path snbt_path = filesystem::path(snbtDir).append(fmtKey + ".snbt");
                fstream fsnbt(snbt_path, ios::out);
                auto snbt = TagToSNBT(tag);
                fsnbt.write(snbt.c_str(), snbt.length());
                fsnbt.flush();
                fsnbt.close();
            }
            else {
                int index = 0;
                for (auto& tag : tags) {
                    filesystem::path snbt_path = snbtDir;
                    snbt_path.append(fmtKey + "__" + to_string(index) + ".snbt");
                    fstream fsnbt(snbt_path, ios::out);
                    auto snbt = TagToSNBT(tag);
                    fsnbt.write(snbt.c_str(), snbt.length());
                    fsnbt.flush();
                    fsnbt.close();
                    ++index;
                }
            }
        }
        catch (...) {
            cout << "error" << endl;
        }
        });
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
    auto& path = dbs->getFullPath();
    //dbs->saveData(*(LevelStorageWriteBatch*)nullptr);
    //dbs->saveData(nullptr, nullptr);
    //dbs->deleteData(nullptr);
    //dbs->syncIO(); // stateË¢ÆÁ
    dbs->getStatistics(*(string*)nullptr);
    dbs->clonePlayerData(ks, ks);
    //dbs->getState();
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
    auto ip=liteloader::getIP(*offPlayer::getNetworkIdentifier((Player*)ori.getEntity()));
    cout << ip << endl;
    outp.success(ip);
    return true;
    //Player* pl = (Player*)ori.getEntity();
    //auto& pos = pl->getPos();
    //BlockPos bpos = { (int)pos.x, (int)pos.y, (int)pos.z };
    //BlockSource* bs = getBlockSourceByDim(pl->getDimensionId());
    //auto bp = dAccess<void*>(getLevel(), 0x850);
    //BlockLegacy* bl = SymCall("?getBlockLegacy@BlockPalette@@QEBAPEBVBlockLegacy@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    //    BlockLegacy*, void*, const string &)(dAccess<void*>(bp, 88), "minecraft:structure_block");
    //SymCall("?setBlock@BlockSource@@QEAA_NAEBVBlockPos@@AEBVBlock@@HPEBUActorBlockSyncMessage@@@Z",
    //    bool, BlockSource*, BlockPos, Block*, int, void*)
    //    (bs, bpos, (Block*)bl, 0, nullptr);
    //return true;
    testDBStorage();
    return true;
    auto dbh = getDBStorage()->getHelper();
    auto tags = dbh.getCompoundTags("mobevents");
    for (auto& tag : tags) {
        cout << TagToSNBT(tag) << endl;
    }
    dbh.saveTags("mobevents", tags);
    return true;
}

bool oncmd_dbread(CommandOrigin const& ori, CommandOutput& outp, string& prefix) {
    if (prefix.empty()) {
        return false;
    }
    auto dbh = getDBStorage()->getHelper();
    dbh.forEachKeyWithPrefix(prefix, [&dbh](const string& key, string& data) {
        cout << key << " : " << endl;
        auto tags = dbh.getCompoundTags(data);
        for (auto& tag : tags) {
            cout << TagToSNBT(tag) << endl;
        }
        });
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("dbh", "Bds DBStorage Helper", 0);
        CmdOverload(dbh, oncmd_dbhelper);
        MakeCommand("dbr", "Bds DBStorage Read", 0);
        CmdOverload(dbr, oncmd_dbread, "prefix");
        });
    Event::addEventListener([](ServerStartedEV ev) {
        //testDBStorage();
        });
}

void entry() {
    regListener();
}


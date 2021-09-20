#include "pch.h"
#include "SymHelper.h"
#include "BdsDbHelper.h"
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

bool lock = false;

bool oncmd_rpd(CommandOrigin const& ori, CommandOutput& outp, std::string id) {
    Tag* playerTag = getPlayerDataById(id);
    if (!playerTag) {
        cout << "获取玩家数据失败" << endl;
        return false;
    }
    cout << TagToSNBT(playerTag) << endl;
    return true;
}
bool oncmd_rdb(CommandOrigin const& ori, CommandOutput& outp, std::string id) {
    Tag* tag = loadFromDBStorage(id);
    if (!tag) {
        cout << "获取数据失败" << endl;
        return false;
    }
    cout << TagToSNBT(tag) << endl;
    return true;
}
bool oncmd_allIds(CommandOrigin const& ori, CommandOutput& outp) {
    printAllIds();
    return true;
}

vector<Tag*> readTags(string bytes) {
    int offset = 0;
    vector<Tag*> tags;
    while (offset < bytes.length()) {
        auto tag = readFromBinary(bytes, offset);
        if (offset < 4)
            break;
        tags.emplace_back(tag);
    }
    return tags;
}

bool oncmd_test(CommandOrigin const& ori, CommandOutput& outp, int cx, int cy) {
    lock = !lock;
    string hex_key = "player";
    string path_ori = "D:\\bds\\LXL_Plugins\\" + hex_key + ".nbt";
    auto data = loadFromFile(path_ori);
    auto tag = readFromBinary(data);
    string path_data = "D:\\bds\\LXL_Plugins\\" + hex_key + "_data.nbt";
    saveToFile(path_data, data);
    string bin_big = writeToBinary(tag, false);
    string path_big = "D:\\bds\\LXL_Plugins\\" + hex_key + "_big.nbt";
    saveToFile(path_big, bin_big);
    string bin_little = writeToBinary(tag, true);
    string path_little = "D:\\bds\\LXL_Plugins\\" + hex_key + "_little.nbt";
    saveToFile(path_little, bin_little);
    cout << TagToSNBT(tag) << endl;
    return true;
    //vector<void*> areas = SymCall("?getTickingAreas@Dimension@@QEAAAEAVTickingAreaList@@XZ",
    //    vector<void*>&, Dimension*)(getDimensionByDid(0));
    //void* chunk = SymCall("?getChunk@BlockSource@@QEBAPEAVLevelChunk@@HH@Z",
    //    void*, BlockSource*, int, int)(getBlockSourceByDim(0), cx, cy);
    //if (chunk) {
    //    bool a = dAccess<unsigned int>(chunk, 120);
    //    cout << "Chunk a: " << a << endl;
    //    bool fullLoaded = SymCall("?isFullyLoaded@LevelChunk@@QEBA_NXZ",
    //        bool, void*)(chunk);
    //    cout << "fullLoaded: " << fullLoaded << endl;
    //}
    //return true;
    _flushWriteCacheToLevelDB();
    //string bin = loadFromFile(str);
    //Tag* tag = readFromBinary(bin);
    //cout << TagToSNBT(tag) << endl;
    forEachKeyWithPrefix("", [](string& key, string& data) {
        if (std::regex_match(key, std::regex("[\\w ,\.\-]*")))
            //cout << "key: " << key << ", data.length(): " << data.length() << endl;
            int a;
        else {
            auto chunkKey = ChunkKey(key);
            string hex_key = byteToHexStr((byte*)key.c_str(), key.length());
            //cout << "hex_key: " << hex_key << endl;
            //cout << chunkKey.toString() << ", dataLen: " << data.length() << endl;
            if (chunkKey.type == byte('\x30') || chunkKey.type == byte('\x31') || chunkKey.type == byte('\x32')) {
                auto tag = readFromBinary(data);
                string path_data = "D:\\bds\\LXL_Plugins\\" + hex_key + "_data.nbt";
                saveToFile(path_data, data);
                string bin = writeToBinary(tag);
                string path = "D:\\bds\\LXL_Plugins\\" + hex_key + "_big.nbt";
                saveToFile(path, bin);
                string bin2 = writeToBinary(tag, false);
                string path2 = "D:\\bds\\LXL_Plugins\\" + hex_key + "_little.nbt";
                saveToFile(path2, bin2);
                cout << TagToSNBT(tag) << endl;
                if (bin != data.substr(0, bin.length()))
                    throw("Error");
            }
            //if (chunkKey.type == byte('\x2F')) {
            //    auto tag = readFromBinary(data);
            //    //auto str = byteToHexStr((byte*)data.c_str(), data.length(), "\\x");
            //    cout << "hex_key: " << hex_key << endl;
            //    for (auto tag : readTags(data)) {
            //        cout << TagToSNBT(tag) << endl;
            //    }
            //}
        }
        });
    return true;

}
bool oncmd_delall(CommandOrigin const& ori, CommandOutput& outp) {
    _flushWriteCacheToLevelDB();
    vector<ChunkKey> allChunk;
    forEachKeyWithPrefix("", [&allChunk](string& key, string& data) {
        if (!std::regex_match(key, std::regex("[\\w ,\.\-]*"))) {
            deleteDBStorageData(key);
            _flushWriteCacheToLevelDB();
            auto ck = ChunkKey(key);
            auto dim = getBlockSourceByDim(ck.dimid);
            if (!dim)
                return;
            void* chunk = SymCall("?getChunk@BlockSource@@QEBAPEAVLevelChunk@@HH@Z",
                void*, BlockSource*, int, int)(dim, ck.cx, ck.cz);
            if (!chunk)
                return;
            allChunk.emplace_back(ck);
        }
        });
    for (auto& ck : allChunk) {
        auto dim = getBlockSourceByDim(ck.dimid);
        if (!dim)
            continue;
        void* chunk = SymCall("?getChunk@BlockSource@@QEBAPEAVLevelChunk@@HH@Z",
            void*, BlockSource*, int, int)(dim, ck.cx, ck.cz);
        if (!chunk)
            continue;
        void* chunkSource = SymCall("?getChunkSource@Dimension@@QEBAAEAVChunkSource@@XZ",
            void*, Dimension*)(getDimensionByDid(ck.dimid));
        //SymCall("?loadChunk@DBChunkStorage@@UEAAXAEAVLevelChunk@@_N@Z",
        //    void, void*, void*, bool)(chunkSource, chunk, true);
        //SymCall("?setSaved@LevelChunk@@QEAAXXZ",
        //    void, void*)(chunk);
    }
    return true;
}
bool oncmd_del(CommandOrigin const& ori, CommandOutput& outp, int cx, int cz, int dimid) {
    _flushWriteCacheToLevelDB();
    forEachKeyWithPrefix(ChunkKey(cx, cz, dimid).getPosKeyPrefix(), [](string& key, string& data) {
        deleteDBStorageData(key);
        _flushWriteCacheToLevelDB();
        });
    return true;
}

bool oncmd_list(CommandOrigin const& ori, CommandOutput& outp, int cx, int cz, int dimid) {
    _flushWriteCacheToLevelDB();
    ChunkKey ck = ChunkKey(cx, cz, dimid);
    forEachKeyWithPrefix(ck.getPosKeyPrefix(), [ck](string& key, string& data) {
        if (ChunkKey::getDimid(key) != ck.dimid)
            return;
        string hex_key = byteToHexStr((byte*)key.c_str(), key.length());
        cout << "hex_key: " << hex_key << endl;
        auto chunkKey = ChunkKey(key);
        cout << chunkKey.toString() << ", dataLen: " << data.length() << endl;
        int header_size = data.find(string("\x0A\x00\x00\x00"));
        vector<string> snbts;
        int offset = 0;
        while (offset < data.length())
        {
            string snbt = TagToSNBT(readFromBinary(data, offset));
            if (snbt.length() < 3)
                break;
            snbts.emplace_back(snbt);
        }
        auto bin = byteToHexStr((byte*)data.c_str(), data.length(), "\\x");
        string path = "D:\\bds\\LXL_Plugins\\leveldb\\" + hex_key + ".bin";
        saveToFile(path, data);
        for (auto& snbt : snbts) {
            cout << snbt << endl;
        }
        });
    return true;
}
void regCmd()
{
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("rpd", "read player data", 0);
        MakeCommand("rdb", "read database", 0);
        MakeCommand("test", "test write", 0);
        MakeCommand("delall", "delete all", 0);
        MakeCommand("del", "delete Chunk", 0);
        MakeCommand("listc", "delete Chunk", 0);
        CmdOverload(rpd, oncmd_allIds);
        CmdOverload(rpd, oncmd_rpd, "key");
        CmdOverload(rdb, oncmd_rdb, "key");
        CmdOverload(test, oncmd_test, "test", "cy");
        CmdOverload(delall, oncmd_delall);
        CmdOverload(del, oncmd_del, "cx", "cz", "dimid");
        CmdOverload(listc, oncmd_list, "cx", "cz", "dimid");
        });
    Event::addEventListener([](ServerStartedEV ev) {
        loadAllIds();
        });
}

void entry()
{
    regCmd();
    std::cout << "[TestSym] TestSym Loaded." << endl;
}


// Player Ids Logger
THook(void*, "?loadPlayerData@PlayerDataSystem@@YA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVLevelStorage@@AEBUPlayerStorageIds@@_N@Z",
    unique_ptr<Tag>& tagPtr, LevelStorage* ls, string psi[6], bool b) {
    cout << "PlayerDataSystem::loadPlayerData(" << tagPtr << ", " << ls << ", \"" << psi << "\", " << b << ");" << endl;
    void* ret = original(tagPtr, ls, psi, b);
    cout << "psi[0]: " << psi[0] << endl;
    cout << "psi[1]: " << psi[1] << endl;
    cout << "psi[2]: " << psi[2] << endl;
    cout << "psi[3]: " << psi[3] << endl;
    cout << "psi[4]: " << psi[4] << endl;
    cout << "psi[5]: " << psi[5] << endl;
    Tag* tag = tagPtr.get();
    if (tag) {
        auto& pTag = tag->asCompound();
        auto uid = pTag.find("UniqueID");
        if (uid != pTag.end()) {
            std::cout << "UniqueID: " << endl << uid->second.asLong() << std::endl;
        }
        else {
            std::cout << "SNBT: " << endl << TagToSNBT(tag) << std::endl;
        }
    }
    return ret;
}
// DBStorage::loadData(gsl::basic_string_span<char const,-1>,string &)
THook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    LevelStorage* _this, void* key_span[2], string* bin) {
    string key = string((char*)key_span[1], (int)key_span[0]);
    bool ret = original(_this, key_span, bin);
    //if ((int)((uintptr_t*)bin)[2])
    //    cout << TagToSNBT(BinaryNBTToTag((void*)((uintptr_t*)bin)[0], (int)((uintptr_t*)bin)[2])).substr(0, 120) << endl;
    if (!bin->empty())
        cout << TagToSNBT(BinaryNBTToTag((char*)bin->c_str(), bin->length())).substr(0, 120) << endl;
    //cout << "****DBStorage::loadData(" << _this << ", \"" << key << "\", " << key_span << ", " << ");" << endl;
    return ret;
}

//DBStorage::saveData(string const&, string&&)
THook(void*, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@@Z",
    LevelStorage* _this, void* result, string& key, string& bin) {
    // bin 格式和 string 类似
    if (!bin.empty())
        cout << TagToSNBT(BinaryNBTToTag((void*)bin.c_str(), bin.length())).substr(0, 120) << endl;
    //void* fake_result[2]{};
    void* ret = original(_this, result, key, bin);
    //cout << "****DBStorage::saveData(" << _this << ", " << result << ", \"" << key << "\", " << &bin << ");" << endl;

    return ret;
}


//DBStorage::getCompoundTag(string const &)
THook(void*, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@@Z",
    LevelStorage* _this, unique_ptr<Tag>& tagPtr, string const& key) {
    return original(_this, tagPtr, key);
}

//?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z
THook(void*, "?read@NbtIo@@SA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEAVIDataInput@@@Z",
    unique_ptr<Tag>& tagPtr, void** iDataInput[2]) {
    void** tmp;
    tmp = iDataInput[1];
    //if (iDataInput[0] == dlsym("??_7RakDataInput@@6B@")) {
    //    string data = string((char*)tmp[2], (int)tmp[0] / 8);
    //}
    auto rtn = original(tagPtr, iDataInput);
    return rtn;
}

// NbtIo::write(CompoundTag const *,IDataOutput &)
THook(void*, "?write@NbtIo@@SAXPEBVCompoundTag@@AEAVIDataOutput@@@Z",
    Tag* tag, void** iDataOutput[3]) {
    void** tmp;
    tmp = iDataOutput[1];
    string str = TagToSNBT(tag);
    auto rtn = original(tag, iDataOutput);
    return rtn;
}

//Tag::writeNamedTag(string const&, Tag const&, IDataOutput&)
THook(void*, "?writeNamedTag@Tag@@SAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV1@AEAVIDataOutput@@@Z",
    string* key, Tag* tag, void** iDataOutput[3]) {
    void** tmp;
    tmp = iDataOutput[1];
    //cout << "path: " << (char*)iDataOutput[2] << endl;
    //cout << "key: " << *key << endl;
    //cout << TagToSNBT(tag) << endl;
    //string str = TagToSNBT(tag);
    auto rtn = original(key, tag, iDataOutput);
    return rtn;
}

THook(void*, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    void* _this, void** a1, void** a2) {
    string str = string((char*)a1[1], (int)a1[0]);
    auto rtn = original(_this, a1, a2);
    return rtn;
}

THook(bool, "?_hasChunk@DBChunkStorage@@AEAA_NAEBVDBChunkStorageKey@@@Z",
    void* _this, void** dbChunkStorageKey) {
    return true;
    auto rtn = original(_this, dbChunkStorageKey);
    return rtn;
}

clock_t time_start, time_end;
long time_limit = CLOCKS_PER_SEC * 0.01;

THook(bool, "?tickWorld@Player@@UEAAHAEBUTick@@@Z",
    Player* player, size_t* tick) {
    if (lock&&player->getNameTag() == "aa"&& (*tick)^2==0) {    
        return true;
    }
    time_start = clock();
    auto rtn = original(player, tick);
    time_end = clock();
    //cout << time_end - time_start << endl;
    return rtn;
}

/*
typedef std::chrono::high_resolution_clock timer_clock;
#define TIMER_START auto start = timer_clock::now();
#define TIMER_END                                                      \
    auto elapsed = timer_clock::now() - start;                         \
    long long timeReslut =                                             \
        std::chrono::duration_cast<std::chrono::microseconds>(elapsed) \
            .count();

long long chunkTickTime;
size_t last_tick;
// LevelChunk::tick
THook(void, "?tick@LevelChunk@@QEAAXAEAVBlockSource@@AEBUTick@@@Z",
    void* levelChunk, BlockSource* blockSource, size_t* tick) {
    if (*tick != last_tick) {
        cout << chunkTickTime << endl;
        chunkTickTime = 0;
        last_tick = *tick;
    }
    TIMER_START
        original(levelChunk, blockSource, tick);
    TIMER_END
        chunkTickTime += timeReslut;
}

*/



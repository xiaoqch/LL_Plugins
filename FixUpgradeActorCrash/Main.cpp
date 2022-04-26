#include "pch.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/Level.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>

void entry()
{
}

#include <MC/Util.hpp>
#include <MC/DBStorage.hpp>
#include <MC/LevelChunk.hpp>
#include <MC/Dimension.hpp>
#ifdef DEBUG

TInstanceHook(bool, "?initialize@Level@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVLevelSettings@@PEAVLevelData@@AEBVExperiments@@PEBV23@@Z",
              Level, std::string const& a1, class LevelSettings const& a2, class LevelData* a3, class Experiments const& a4, std::string const* a5)
{
    auto rtn = original(this, a1, a2, a3, a4, a5);
    static DBHelpers::Category category = (DBHelpers::Category)4;
    std::string backupDir = fmt::format("{}{:%Y%m%d-%H%M%S}/", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
    bool first = true;
    Global<DBStorage>->forEachKeyWithPrefix("actorprefix", category, [&backupDir,&first](gsl::cstring_span<-1> suffix, gsl::cstring_span<-1> data) {
        if (data.size() > Config::SizeThreshold)
        {
            if (first) {
                std::filesystem::create_directories(std::filesystem::path(backupDir));
                first = false;
            }
            std::string suffixStr = std::string(suffix.data(), suffix.size());
            std::string suffixHex = Util::toHex(suffixStr);
            std::string fullKey = "actorprefix" + suffixStr;
            auto backupFilePath = fmt::format("{}actorprefix-{}.bin", backupDir, suffixHex);
            logger.warn("Remove Data: key: actorprefix-{}, size: {}", suffixHex, data.size());
            logger.warn("backup path: {}", backupFilePath);
            std::string sdata = std::string(data.data(), data.size());
            WriteAllFile(backupFilePath, sdata, true);
            Global<DBStorage>->deleteData(fullKey, category);
        }
    });
    return rtn;
}
#include <MC/DBStorage.hpp>

TInstanceHook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
              DBStorage,
              gsl::string_span<-1> key, std::string& data, DBHelpers::Category category)
{
    auto rtn = original(this, key, data, category);
    if (data.size() > Config::WarnSizeThreshold)
    {
        std::string keyhex = std::string(key.data(), key.size());
        logger.warn("Large Data: Key: {}, Data Size: {}, Category: {}", Util::toHex(keyhex), data.size(), (int)category);
    }
    return rtn;
}

class StringByteInput
{
public:
    void* vftable;
    size_t mIndex;
    size_t mEnd;
    char* data;
};

#endif // DEBUG

std::array<bool,2> needFixs;
std::thread::id firstThreadId;

inline void setNeedFix(bool needFix = true)
{
    needFixs[firstThreadId == std::this_thread::get_id()] = needFix;
}
inline bool isNeedFix()
{
    return needFixs[firstThreadId == std::this_thread::get_id()];
}

TClasslessInstanceHook(std::vector<std::string>&, "?_deserializeChunkActorStorageKeys@DBChunkStorage@@AEAA?AV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@AEAVIDataInput@@@Z",
                       std::vector<std::string>& res, class IDataInput& dataInput)
{
    auto& rtn = original(this, res, dataInput);
    auto data = std::set<std::string>(res.begin(), res.end());
    if (data.size() != res.size())
    {
#ifdef DEBUG
        auto input = (StringByteInput&)dataInput;
        std::string inputData = std::string(input.data, input.mEnd);
#endif // DEBUG
        logger.warn("Fix duplicate loading of entities, keys {} -> {}, please turn debugMode for more detail.", res.size(), data.size());
        res = std::vector<std::string>(data.begin(), data.end());
        setNeedFix(true);
    }
    return rtn;
}

class ChunkKey
{
    ChunkPos cpos;
    int dimid;

public:
    MCAPI ChunkKey(class ChunkPos const&, class AutomaticID<class Dimension, int>);
    MCAPI ChunkKey(class LevelChunk const&);
    MCAPI class gsl::basic_string_span<char const, -1> asSpan() const;
    MCAPI unsigned __int64 hashCode() const;

};

inline std::string& fixActorKeys(class LevelChunk& chunk, std::string& keys)
{
    auto chunkKey = ChunkKey(chunk);
    std::string digKey;
    SymCall("?_getEntityDigestKey@DBChunkStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$basic_string_span@$$CBD$0?0@gsl@@@Z",
            std::string&, void*, std::string&, gsl::cstring_span<-1>)(nullptr, digKey, chunkKey.asSpan());
#ifdef DEBUG
    std::string currentData;
    Global<DBStorage>->loadData(digKey, currentData, (DBHelpers::Category)4);
    if (currentData != keys) {
        __debugbreak();
    }
#endif // DEBUG

    if (keys.size() % 8)
        return keys;
    std::set<std::string> fixedKeySet;
    for (size_t index = 0; index < keys.size(); index += 8) {
        fixedKeySet.insert(keys.substr(index, 8));
    }
    keys.clear();
    keys.reserve(fixedKeySet.size() * 8);
    for (auto& fixedKey : fixedKeySet) {
        keys.append(fixedKey);
    }
    Global<DBStorage>->saveData(digKey, std::string(keys), (DBHelpers::Category)4);
    return keys;
}

TClasslessInstanceHook(void, "?_deserializeIndependentActorStorage@DBChunkStorage@@AEAAXAEAVLevelChunk@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
                       class LevelChunk& chunk, std::string& keys)
{
    static std::thread::id tmp = std::this_thread::get_id();
    if (firstThreadId != tmp) {
        firstThreadId = tmp;
    }
    original(this, chunk, keys);
    if (isNeedFix())
    {
        size_t keyCount = keys.size() / 8;
        auto& cpos = chunk.getPosition();
        logger.debug("fix actor keys bug in dim {} chunk ({}, {})", keyCount, (int)chunk.getDimension().getDimensionId(), cpos.x, cpos.z);
        fixActorKeys(chunk, keys);
        setNeedFix(false);
    }
}

#ifdef DEBUG

TClasslessInstanceHook(void, "?putKey@LevelStorageWriteBatch@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4Category@DBHelpers@@@Z",
                       std::string const& key, std::string const& data, enum DBHelpers::Category category)
{
    if (data.size() > Config::WarnSizeThreshold) {
        logger.warn("saving large data, key: {}, size: {}", Util::toHex(key), data.size());
    }
    original(this, key, data, category);
}

TClasslessInstanceHook(std::string&, "?_getEntityDigestKey@DBChunkStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$basic_string_span@$$CBD$0?0@gsl@@@Z",
                       std::string& res, gsl::cstring_span<-1> a1)
{
    std::string a1s = std::string(a1.data(), a1.size());
    auto& rtn = original(this, res, a1);
    std::string digestData;
    Global<DBStorage>->loadData(rtn, digestData, (DBHelpers::Category)4);
    return rtn;
}

#endif // DEBUG
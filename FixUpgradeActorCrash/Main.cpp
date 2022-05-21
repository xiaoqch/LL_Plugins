#include "pch.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/Level.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>

#include <MC/StringTag.hpp>
#include <MC/Int64Tag.hpp>
#include <MC/EntityStorageKeySystem.hpp>
void entry()
{
    //auto key = EntityStorageKeySystem::generateStorageKey(0xFFFFFF9300000CAB);
    //logger.info(key);
    dlsym_real("FakeSymbol");
}
#include <ServerAPI.h>
inline bool isPendingEntitiesDataBugVersion()
{
    static bool bugVersion = LL::getBdsVersion() == "v1.18.30";
    // 下版本大概率会修，如果mojang修复的话后面的代码会出问题，所以此处要检查版本，如果更新了还没修，那就（跑路吧
    return bugVersion;
}
#include <MC/Util.hpp>
#include <MC/DBStorage.hpp>
#include <MC/LevelChunk.hpp>
#include <MC/Dimension.hpp>

#include <MC/DBStorage.hpp>

inline void removeDuplicatesData(std::string& data)
{
    std::set<std::string> keys;
    std::string newData;
    size_t lastPos = 0;
    for (size_t pos = 0; pos < data.size();)
    {
        try
        {
            lastPos = pos;
            auto tag = CompoundTag::fromBinaryNBT(data, pos);
            if (auto uidTag = tag->getInt64Tag("UniqueID"))
            {
                auto storageKey = EntityStorageKeySystem::generateStorageKey(uidTag->value());
                std::string actorKey = "actorprefix" + storageKey;
                if (keys.find(actorKey) == keys.end())
                {
                    keys.insert(actorKey);
                    newData.append(data.substr(lastPos, pos - lastPos));
                }
            }
        }
        catch (...)
        {
            logger.error("Error in Fix Actor data bug");
        }
    }
    if (!newData.empty()) {
        data.swap(newData);
    }
}

TInstanceHook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
              DBStorage,
              gsl::string_span<-1> key, std::string& data, DBHelpers::Category category)
{
    auto rtn = original(this, key, data, category);
    //if (!isPendingEntitiesDataBugVersion())
    //    return rtn;
    if (category == (DBHelpers::Category)4 && data.size() > 1000000 && key.size() == 19 && key.subspan(0, 11) == "actorprefix")
    {
        //size_t oldSize = data.size();
        //removeDuplicatesData(data); // 防止OOM，真正修复在后面
        //logger.warn("Remove Duplicates Actor in DBStorage::loadData, key {}, size {} -> {}", Util::toHex(std::string(key.data(), key.size())), oldSize, data.size());
        //auto keystr = std::string(key.data(), key.size());
        //saveData(keystr, std::string(data), category);
         logger.warn("Loading Large Actor in DBStorage::loadData, key {}, size {}", Util::toHex(std::string(key.data(), key.size())), data.size());
    }
    return rtn;
}

#ifdef DEBUG

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
    if (!isPendingEntitiesDataBugVersion())
        return rtn;
    auto data = std::set<std::string>(res.begin(), res.end());
    if (data.size() != res.size())
    {
        // 重复key的bug，推测，因为PendingEntitiesData重复了，所以如果这种情况下再增加实体的话会在重复的PendingEntitiesData里面获取下一个key，所以出现重复key
#ifdef DEBUG
        auto input = (StringByteInput&)dataInput;
        std::string inputData = std::string(input.data, input.mEnd);
#endif // DEBUG
        logger.warn("Fix duplicate loading of entities, keys {} -> {}", res.size(), data.size());
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

inline std::string getEntityDigestKey(ChunkKey const& chunkKey)
{
    std::string digKey;
    SymCall("?_getEntityDigestKey@DBChunkStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$basic_string_span@$$CBD$0?0@gsl@@@Z",
            std::string&, void*, std::string&, gsl::cstring_span<-1>)(nullptr, digKey, chunkKey.asSpan());
    return digKey;
}

inline std::string& fixActorDatas(class LevelChunk& chunk, std::string& keys, std::string& pendingEntitiesData)
{
    auto chunkKey = ChunkKey(chunk);
    std::string digKey = getEntityDigestKey(chunkKey);
#ifdef DEBUG
    std::string currentData;
    Global<DBStorage>->loadData(digKey, currentData, (DBHelpers::Category)4);
    if (currentData != keys) {
        //__debugbreak();
    }
#endif // DEBUG

    if (keys.size() % 8)
        return keys;
    size_t actorCount = keys.size() / 8;
    keys.clear();
    std::unordered_map<std::string, std::string> correctDatas;
    for (size_t pos = 0; pos < pendingEntitiesData.size();)
    {
        try
        {
            auto tag = CompoundTag::fromBinaryNBT(pendingEntitiesData, pos);
            if (auto uidTag = tag->getInt64Tag("UniqueID"))
            {
                auto storageKey = EntityStorageKeySystem::generateStorageKey(uidTag->value());
                std::string actorKey = "actorprefix" + storageKey;
                if (correctDatas.find(actorKey) == correctDatas.end())
                {
                    if (auto comps = tag->getCompound("internalComponents"))
                    {
                        if (auto comp = tag->getCompound("EntityStorageKeyComponent"))
                        {
                            comp->putString("StorageKey", EntityStorageKeySystem::generateStorageKey(uidTag->value()));
                        }
                    }
                    correctDatas.emplace(actorKey, tag->toBinaryNBT());
                    keys.append(storageKey);
                    if (correctDatas.size() == actorCount)
                        break;
                }
            }
        }
        catch (...)
        {
            logger.error("Error in Fix Actor data bug");
        }
    }
    pendingEntitiesData.clear();
    for (auto& [key, value] : correctDatas)
    {
        keys.append(key.substr(11));
        pendingEntitiesData.append(value);
        Global<DBStorage>->saveData(key, std::move(value), (DBHelpers::Category)4);
    }
    Global<DBStorage>->saveData(digKey, std::string(keys), (DBHelpers::Category)4);
    pendingEntitiesData.reserve();
    return keys;
}

TClasslessInstanceHook(void, "?_deserializeIndependentActorStorage@DBChunkStorage@@AEAAXAEAVLevelChunk@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
                       class LevelChunk& chunk, std::string& keys)
{
    if (!isPendingEntitiesDataBugVersion())
        return original(this, chunk, keys);

    static std::thread::id tmp = std::this_thread::get_id();
    if (firstThreadId != tmp) {
        firstThreadId = tmp;
    }
    original(this, chunk, keys);
    if (isNeedFix())
    {
        std::string& pendingEntitiesData = dAccess<std::string, 152>(&chunk);
        size_t keyCount = keys.size() / 8;
        auto& cpos = chunk.getPosition();
        logger.warn("fix actor datas bug in dim {} chunk ({}, {})", (int)chunk.getDimension().getDimensionId(), cpos.x, cpos.z);
        // 真正的修复
        fixActorDatas(chunk, keys, pendingEntitiesData);
        setNeedFix(false);
    }
}

TInstanceHook(void, "?serializeEntities@LevelChunk@@QEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_NV?$function@$$A6AXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z@3@22@Z",
              LevelChunk,
              std::string& data,
              bool a2, // discard?
              class std::function<void(std::string const& storageKey)>& a3,
              class std::function<void(std::string const& storageKey)>& a4,
              class std::function<void(std::string const& storageKey)>& a5)
{
    if (!isPendingEntitiesDataBugVersion())
        return original(this, data, a2, a3, a4, a5);
    logger.debug("-->LevelChunk::serializeEntities");

    // pending entities data 是加载进内存但不在tick区块的实体数据，即没反序列化成Actor，
    // 所以即使里面有许多相同UniqueID的实体的数据也不会被BDS发现，这为实体数据碰撞bug提供了基础
    // 这里超过一定量裁剪数据是为了防止这个列表实体重复数据过多（比如超过1GB），导致后面修复另一部分bug时间过长
    std::string& pendingEntitiesData = dAccess<std::string, 152>(this);
    removeDuplicatesData(pendingEntitiesData);

#ifdef FIX_EXTRA
    // 这个修复理论上不是必须的，因为只要经过第一次修复，后面就不会再有重复UinqueID的实体的数据
    std::set<std::string> keys;
#endif // FIX_EXTRA

    std::function<void(std::string const& storageKey)> a5Fixed = [&](std::string const& storageKey) {
        logger.debug("LevelChunk::serializeEntities - a5 - {}", Util::toHex(storageKey));
#ifdef FIX_EXTRA
        if (keys.find(storageKey) != keys.end()) // 这里可能会有重复实体出现
            return data.clear();
        keys.insert(storageKey);
#endif                                       // FIX_EXTRA
        static std::string correctData = ""; // 真正应该保存的实体的数据，静态应该也许大概是非必须的
        correctData = "";
        for (size_t pos = 0; pos < data.size();)
        {
            try
            {
                // 这个 data 是所有 PendingEntitiesData 的数据，所以要找出应该保存的具体实体的数据
                auto tag = CompoundTag::fromBinaryNBT(data, pos);
                if (auto comps = tag->getCompound("internalComponents"))
                {
                    if (auto storageKeyComp = comps->getCompound("EntityStorageKeyComponent"))
                        if (auto str = storageKeyComp->getStringTag("StorageKey"))
                            if (const_cast<StringTag*>(str)->value() == storageKey)
                            {
                                correctData = tag->toBinaryNBT();
                                break;
                            }
                }
                else if (auto uidTag = tag->getInt64Tag("UniqueID"))
                {
                    if (EntityStorageKeySystem::generateStorageKey(uidTag->value()) == storageKey)
                    {
                        correctData = tag->toBinaryNBT();
                        break;
                    }
                }
            }
            catch (...)
            {
                logger.error("Error in Fix Actor data bug");
            }
        }
        if (!correctData.empty())
        {
            auto& cpos = getPosition();
            logger.warn("Fix actor data bug for chunk ({}, {}) in dim {}, storage key: {}, data size: {}",
                        cpos.x, cpos.z, (int)getDimension().getDimensionId(), Util::toHex(storageKey), correctData.size());
            dAccess<std::string*, 8>(&a5) = &correctData;
        }
        a5(storageKey);
        data.clear(); // 在执行a5回调前会每次 append 完整的 PendingEntityData 数据（bug数据产生的地方），所以要清空防止数据增长导致的OOM
    };
    original(this, data, a2, a3, a4, a5Fixed);
    logger.debug("<--LevelChunk::serializeEntities End");
}

#ifdef DEBUG

TClasslessInstanceHook(void, "?putKey@LevelStorageWriteBatch@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4Category@DBHelpers@@@Z",
                       std::string const& key, std::string const& data, enum DBHelpers::Category category)
{
    //if (!isPendingEntitiesDataBugVersion())
    //    return original(this, key, data, category);
    if (data.size() > Config::WarnSizeThreshold) {
        logger.warn("saving large data, key: {}, size: {}", Util::toHex(key), data.size());
        return original(this, key, data, category);

        std::string saveDir = fmt::format("{}Large-{:%Y%m%d-%H%M%S}/", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
        std::filesystem::create_directories(std::filesystem::path(saveDir));
        auto savePath = fmt::format("{}{}.bin", saveDir, Util::toHex(key));
        WriteAllFile(savePath, data, true);
        size_t pos = 0;
        size_t index = 0;
        for (; pos < data.size();) {
            auto savePath = fmt::format("{}{}.nbt", saveDir, ++index);
            auto tag = CompoundTag::fromBinaryNBT(data, pos);
            if (index > 5000)
                continue;
            auto newData = tag->toBinaryNBT();
            WriteAllFile(savePath, newData, true);
        }
        logger.info("data has {} actors");
    }
    original(this, key, data, category);
}

TClasslessInstanceHook(std::string&, "?_getEntityDigestKey@DBChunkStorage@@AEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$basic_string_span@$$CBD$0?0@gsl@@@Z",
                       std::string& res, gsl::cstring_span<-1> a1)
{
    //if (!isPendingEntitiesDataBugVersion())
    //    return original(this, res, a1);

    std::string a1s = std::string(a1.data(), a1.size());
    auto& rtn = original(this, res, a1);
    std::string digestData;
    Global<DBStorage>->loadData(rtn, digestData, (DBHelpers::Category)4);
    return rtn;
    if (digestData.size() / 8 > 200)
        __debugbreak();
    return rtn;
}


TClasslessInstanceHook(void, "?_serializeEntities@DBChunkStorage@@AEAAXAEAVLevelChunk@@AEAVLevelStorageWriteBatch@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z",
                       class LevelChunk& chunk, class LevelStorageWriteBatch& batch, std::string& str, bool discard)
{
    original(this, chunk, batch, str, discard);
    //if (!isPendingEntitiesDataBugVersion())
    //    return;
    auto size = batch.mEntries.size();
    logger.warn("DBChunkStorage::_serializeEntities - dim {} ({}, {}) - {} entries", 
        (int)chunk.getDimension().getDimensionId(), chunk.getPosition().x, chunk.getPosition().z, size);
    auto savingFileDir = fmt::format("{}{}-{:%Y%m%d-%H%M%S}/", PLUGIN_DIR, Util::toHex(std::string(ChunkKey(chunk).asSpan().data(), ChunkKey(chunk).asSpan().size())), fmt::localtime(_time64(nullptr)));

    logger.warn("Saving datas to {}", savingFileDir);
    std::filesystem::create_directories(std::filesystem::path(savingFileDir));
    std::string metaDatas;
    for (auto& [key, entry] : batch.mEntries)
    {
        std::string metaData = fmt::format("key: {:<40}, entry: [size: {:<5}, remove: {:<5}, category: {}]", Util::toHex(key), entry.data ? entry.data->size() : 0, entry.remove, (int)entry.category);
        logger.info(metaData);
        continue;
        metaDatas.append(metaData).append("\n");
        if (!entry.data)
            continue;
        std::string filePath = fmt::format("{}{}.bin", savingFileDir, Util::toHex(key));
        WriteAllFile(filePath, *entry.data, true);
    }
    return;
    std::string filePath = fmt::format("{}meta.txt", savingFileDir);
    WriteAllFile(filePath, metaDatas, false);
    if (false)
        __debugbreak();
}
static_assert(sizeof(LevelStorageWriteBatch) == 48);

#endif // DEBUG

#include "pch.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <PlayerInfoAPI.h>
void entry()
{
}
#include <MC/ListTag.hpp>
#include <MC/IntTag.hpp>
#include <MC/Level.hpp>
#include <MC/DBStorage.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/Util.hpp>
TInstanceHook(bool, "?initialize@Level@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVLevelSettings@@PEAVLevelData@@AEBVExperiments@@PEBV23@@Z",
              Level, std::string const& a1, class LevelSettings const& a2, class LevelData* a3, class Experiments const& a4, std::string const* a5)
{
    auto rtn = original(this, a1, a2, a3, a4, a5);
    //Global<DBStorage>->forEachKeyWithPrefix("", (DBHelpers::Category)0, [](gsl::cstring_span<-1> key, gsl::cstring_span<-1> data) {
    //    std::string fkey = std::string(key.data(), key.size());
    //    if (!Util::isValidUTF8(fkey))
    //        fkey = Util::toHex(fkey);
    //    logger.info("key: {}, size: {}", fkey, data.size());
    //});
    std::vector<std::string> keys = {"Overworld", "Nether", "TheEnd"};
    for (auto& key : keys)
    {
        try
        {
            std::string data;
            if (Global<DBStorage>->hasKey(key, (DBHelpers::Category)0) && Global<DBStorage>->loadData(key, data, (DBHelpers::Category)0))
            {
                if (data.size() < Config::CountThreshold * 512)
                    continue;
                auto tag = CompoundTag::fromBinaryNBT(data);
                auto cmp = tag->getCompoundTag("data");
                if (cmp)
                {
                    auto list = cmp->getListTag("LimboEntities");
                    std::vector<size_t> removeList = {};
                    for (size_t index = 0; index < (list ? list->size() : 0); ++index)
                    {
                        auto t = list->get(static_cast<int>(index))->asCompoundTag();
                        if (auto l = t->getListTag("EntityTagList"))
                        {
                            if (l && l->size() > 500)
                            {
                                auto cxTag = t->getIntTag("ChunkX");
                                int chunkX = cxTag ? cxTag->value() : INT_MIN;
                                auto czTag = t->getIntTag("ChunkZ");
                                int chunkZ = czTag ? czTag->value() : INT_MIN;
                                logger.warn("Chunk ({}, {}) in {} have {} LimboEntities", chunkX, chunkZ, key, l->size());
                                removeList.insert(removeList.begin(), index);
                            }
                        }
                    }
                    for (auto& index : removeList)
                    {
                        logger.warn("remove index {}", index);
                        const_cast<ListTag*>(list)->erase(index);
                    }
                    if (removeList.size() > 0)
                    {
                        auto backupFilePath = fmt::format("{}{}-{:%Y%m%d-%H%M%S}.nbt", PLUGIN_DIR, key, fmt::localtime(_time64(nullptr)));
                        WriteAllFile(backupFilePath, data, true);
                        logger.info("will overload {} data, backup data path: {}", key, backupFilePath);
                        Global<DBStorage>->saveData(key, tag->toBinaryNBT(), (DBHelpers::Category)0);
                    }
                }
            }
        }
        catch (...)
        {
            logger.error("Error in process \"{}\"", key);
        }
    }
    return rtn;
}

TInstanceHook(void, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z", 
    DBStorage, gsl::cstring_span<-1>& prefix, enum DBHelpers::Category category, class std::function<void(gsl::cstring_span<-1>, gsl::cstring_span<-1>)> const& callback)
{
    logger.info("prefix: {}, category: {}", prefix.data(), (int)category);
    return original(this, prefix, category, callback);
}



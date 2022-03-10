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
TInstanceHook(bool, "?initialize@Level@@UEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVLevelSettings@@PEAVLevelData@@AEBVExperiments@@PEBV23@@Z",
              Level, std::string const& a1, class LevelSettings const& a2, class LevelData* a3, class Experiments const& a4, std::string const* a5)
{
    auto rtn = original(this, a1, a2, a3, a4, a5);
    std::vector<std::string> keys = {"Overworld", "Nether", "TheEnd"};
    for (auto& key : keys)
    {
        try
        {
            std::string data;
            if (Global<DBStorage>->hasKey(key, (DBHelpers::Category)0) && Global<DBStorage>->loadData(key, data, (DBHelpers::Category)0))
            {
                if (data.size() < Config::CountThreshold*512)
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
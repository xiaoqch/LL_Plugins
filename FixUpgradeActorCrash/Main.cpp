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
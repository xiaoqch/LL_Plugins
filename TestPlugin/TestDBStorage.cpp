#include "pch.h"
#include "TestDBStorage.h"
#include <MC/DBStorage.hpp>
#include <MC/Level.hpp>
#include <MC/Bedrock.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/StringTag.hpp>
#ifdef ENABLE_TEST_DBSTORAGE

using string_span = gsl::string_span<-1>;
using cstring_span = gsl::cstring_span<-1>;

Logger dbLogger("DBStorage");

struct voids {
    void**** filler[100];
};
#define DBLog(...)\
ASSERT((int)category != 3);\
if ((int)category != 4 && (int)category != 6) /* chunk */ \
    dbLogger.warn(__VA_ARGS__) 

bool isChunkKey(std::string_view key, size_t offset = 0) {
    auto keySize = key.size();
    if (keySize != 9 && keySize != 10 && keySize != 13 && keySize != 14)
        return false;
    for (auto& c : key) {
        if (c <= '\x1f' || c >= '\x7f') {
            return true;
        }
    }
    return false;
}
inline bool isChunkKey(cstring_span const& key, size_t offset = 0) {
    auto keySize = key.size() + offset;
    if (keySize != 9 && keySize != 10 && keySize != 13 && keySize != 14)
        return false;
    for (auto& c : key) {
        if (c <= '\x1f' || c >= '\x7f') {
            return true;
        }
    }
    return false;
}

std::string getKeyString(std::string_view key) {
    if (!isChunkKey(key))
        return key.data();
    char buf[40];
    size_t index = -1;
    auto cmap = "0123456789abcedf";
    for (auto& c : key) {
        if (index > 36)
            return "Error";
        buf[++index] = cmap[((unsigned char)c & '\xf0') >> 4];
        buf[++index] = cmap[(unsigned char)c & '\x0f'];
    }
    if (index > 36)
        return "Error";
    buf[++index] = 0;
    return std::string(buf, index - 1);
}
std::string getKeyString(string_span const& key) {
    std::string result = std::string(key.data(), key.length());
    return getKeyString(std::string_view(result));
}

inline class Player* getPlayer(class mce::UUID const& a0) {
    class Player* (Level:: * rv)(class mce::UUID const&);
    *((void**)&rv) = dlsym_real("?getPlayer@Level@@UEBAPEAVPlayer@@AEBVUUID@mce@@@Z");
    return (Global<Level>->*rv)(std::forward<class mce::UUID const&>(a0));
}
bool TestDBStorage::deletePlayerData(mce::UUID uuid)
{
    auto player = getPlayer(uuid);
    if (player)
        player->kick("");
    auto dbStorage = (DBStorage*)&Global<Level>->getLevelStorage();
    auto tag = dbStorage->getCompoundTag("player_" + uuid.asString(), (DBHelpers::Category)7);
    if (!tag)
        return false;
    for (auto& [key, idTagVariant] : *tag) {
        auto idTag = const_cast<CompoundTagVariant&>(idTagVariant).asStringTag();
        auto& id = idTag->value();
        id = key == "ServerId" ? id : "player_" + id;
        auto res = dbStorage->deleteData(id, (DBHelpers::Category)7);
        //res->addOnComplete([id](Bedrock::Threading::IAsyncResult<void> const& result) {
        //    if (result.getStatus() == 1)
        //        dbLogger.warn("Remove {} Success", id);
        //    else
        //    {
        //        auto code = result.getError();
        //        dbLogger.error("Remove {} Failed, cause: {}", id, code.message());
        //    }
        //    });
    }
    return true;
    auto& serverId = tag->getString("ServerId");
    if (!serverId._Starts_with("player_server"))
        return false;
    auto res2 = dbStorage->deleteData(serverId, (DBHelpers::Category)0);
    return true;
}

std::vector<std::string> RemovePlayerCommand::playerList = {};
void RemovePlayerCommand::execute(CommandOrigin const& origin, CommandOutput& output) const
{
    auto uuid = PlayerInfo::getUUID(mName);
    if (uuid.empty())
        return output.error(fmt::format("Player {} Not Found", mName));
    auto res = TestDBStorage::deletePlayerData(mce::UUID::fromString(uuid));
    if (!res)
        return output.error(fmt::format("Remove Player {} Data Failed", mName));
    return output.success(fmt::format("Remove Player {} Data", mName));
}

void RemovePlayerCommand::setup(CommandRegistry& registry)
{
    return;
    registry.registerCommand("removeplayer", "Operation Agent", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.addSoftEnum("PlayerList", playerList);
    updatePlayerList();
    auto nameParam = makeMandatory<CommandParameterDataType::SOFT_ENUM>(&RemovePlayerCommand::mName, "master", "PlayerList");
    registry.registerOverload<RemovePlayerCommand>("removeplayer", nameParam);
}


void DBTestCommand::execute(CommandOrigin const& origin, CommandOutput& output) const
{
    switch (mOperation)
    {
    case DBTestCommand::Operation::Read: {
        auto tag = Global<DBStorage>->getCompoundTag(mKey, (DBHelpers::Category)0);
        if (tag)
            output.success(tag->toSNBT());
        else
            output.error(fmt::format("读取数据 {} 时发生错误", mKey));
        break;
    }
    case DBTestCommand::Operation::ReadPrefix: {
        size_t count = 0;
        Global<DBStorage>->forEachKeyWithPrefix(mKey, (DBHelpers::Category)0,
            [&output, this, &count](cstring_span keyLeft, cstring_span data) {
                if (count++ % 100000 == 0) // 19056408
                    logger.info("count: {}", count);
                if (!isChunkKey(keyLeft, mKey.size())) {
                    logger.info("{}{} - {}", mKey, keyLeft.data(), data.size());
                    logger.info(CompoundTag::fromBinaryNBT((void*)data.data(), data.size(), true)->toSNBT());
                }
            });
        output.success(fmt::format("总共读取到 {} 个数据", count));
        break;
    }
    case DBTestCommand::Operation::Remove:
        Global<DBStorage>->deleteData(mKey, (DBHelpers::Category)0);
        break;
    case DBTestCommand::Operation::RemovePrefix: {
        size_t count = 0;
        Global<DBStorage>->forEachKeyWithPrefix(mKey, (DBHelpers::Category)0,
            [&output, this, &count](cstring_span keyLeft, cstring_span data) {
                if (count++ % 100000 == 0) // 19056408
                    logger.info("count: {}", count);
                if (!isChunkKey(keyLeft, mKey.size())) {
                    auto key = fmt::format("{}{}", mKey, keyLeft.data());
                    logger.info("Remove: {} - {}", key, data.size());
                    Global<DBStorage>->deleteData(key, (DBHelpers::Category)0);
                }
            });
        output.success(fmt::format("总共删除 {} 个数据", count));
        break;
    }
    case DBTestCommand::Operation::ReadChunk:
        break;
    case DBTestCommand::Operation::RemoveChunk:
        break;
    default:
        break;
    }
}

void DBTestCommand::setup(CommandRegistry& registry)
{
    return;
    registry.registerCommand("dbtest", "Operation Agent", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });

    registry.addEnum<Operation>("DBTest-Action", {
        {"read", Operation::Read},
        {"readprefix", Operation::ReadPrefix},
        {"remove", Operation::Remove},
        {"removeprefix", Operation::RemovePrefix},
        });
    registry.addEnum<Operation>("DBTest-ActionReadChunk", {
        {"readchunk", Operation::ReadChunk},
        {"removechunk", Operation::RemoveChunk},
        });

    auto action = makeMandatory<CommandParameterDataType::ENUM>(&DBTestCommand::mOperation, "action", "DBTest-Action");
    auto actionReadChunk = makeMandatory<CommandParameterDataType::ENUM>(&DBTestCommand::mOperation, "action", "DBTest-ActionReadChunk");

    auto keyParam = makeMandatory(&DBTestCommand::mKey, "key");

    registry.registerOverload<DBTestCommand>("dbtest", action, keyParam);
    registry.registerOverload<DBTestCommand>("dbtest", actionReadChunk, keyParam);
}


TInstanceHook(void, "?_read@DBStorage@@IEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    DBStorage,
    string_span key, DBHelpers::Category category,
    std::function<void(string_span key, string_span value)> const& callback) {
    DBLog("DBStorage::_read({}, {}, callback)", getKeyString(key), (int)category);
    return original(this, key, category, callback);
}

TInstanceHook(DBStorage::PendingWriteResult&, "?_readPendingWrite@DBStorage@@IEBA?AUPendingWriteResult@1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
    DBStorage, DBStorage::PendingWriteResult& result,
    std::string const& key, DBHelpers::Category category) {
    DBLog("DBStorage::_readPendingWrite({}, {})", getKeyString(std::string_view(key)), (int)category);
    return original(this, result, key, category);
}

TInstanceHook(std::shared_ptr<Bedrock::Threading::IAsyncResult<void> >&, "?deleteData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@W4Category@DBHelpers@@@Z",
    DBStorage, std::shared_ptr<Bedrock::Threading::IAsyncResult<void> >& result,
    std::string const& key, DBHelpers::Category category) {
    DBLog("DBStorage::deleteData({}, {})", getKeyString(std::string_view(key)), (int)category);
    return original(this, result, key, category);
}

TInstanceHook(void, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    DBStorage, string_span prefix, DBHelpers::Category category,
    std::function<void(string_span key, string_span value)> const& callback) {
    DBLog("DBStorage::forEachKeyWithPrefix({}, {}, callback)", getKeyString(prefix), (int)category);
    return original(this, prefix, category, callback);
}

TInstanceHook(std::unique_ptr<CompoundTag>&, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@W4Category@DBHelpers@@@Z",
    DBStorage, std::unique_ptr<CompoundTag>& result, std::string const& key, DBHelpers::Category category) {
    DBLog("DBStorage::getCompoundTag({}, {})", getKeyString(std::string_view(key)), (int)category);
    auto& rtn =  original(this, result, key, category);
    dbLogger.info("{}: \n{}", key, rtn->toSNBT());
    return rtn;
}

TInstanceHook(bool, "?hasKey@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@@Z",
    DBStorage, string_span key, DBHelpers::Category category) {
    DBLog("DBStorage::hasKey({}, {})", getKeyString(key), (int)category);
    return original(this, key, category);
}

TInstanceHook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
    DBStorage,
    string_span key, std::string& data, DBHelpers::Category category) {
    auto rtn = original(this, key, data, category);
    DBLog("DBStorage::loadData({}, data: {} bytes, {})", getKeyString(key), data.size(), (int)category);
    return rtn;
}
//TClasslessInstanceHook(class MapItemSavedData*, "?getMapSavedData@Level@@UEAAPEAVMapItemSavedData@@UActorUniqueID@@@Z",
//    struct ActorUniqueID auid) {
//    return nullptr;
//}
//#include <MC/ItemFrameBlockActor.hpp>
//#include <MC/BlockSource.hpp>
//#include <MC/VanillaBlocks.hpp>
//#include <MC/BedrockBlocks.hpp>
//TInstanceHook(void, "?tick@ItemFrameBlockActor@@UEAAXAEAVBlockSource@@@Z",
//    ItemFrameBlockActor, struct BlockSource& bs) {
//    auto& pos = getPosition();
//    Level::setBlock(pos, bs.getDimensionId(), const_cast<Block*>(BedrockBlocks::mAir));
//    return;
//}
TInstanceHook(std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>&, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@W4Category@DBHelpers@@@Z",
    DBStorage, std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>& result,
    std::string const& key, std::string&& data, DBHelpers::Category category) {
    DBLog("DBStorage::saveData({}, data: {} bytes, {})", getKeyString(std::string_view(key)), data.size(), (int)category);
    return original(this, result, key, std::move(data), category);
}

TInstanceHook(std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>&, "?saveData@LevelStorage@@QEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@AEBVCompoundTag@@W4Category@DBHelpers@@@Z",
    LevelStorage, std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>& result,
    std::string const& key, CompoundTag const& tag, DBHelpers::Category category) {
    DBLog("LevelStorage::saveData({}, {}, {})", getKeyString(std::string_view(key)), tag.toString(), (int)category);
    return original(this, result, key, tag, category);
}

//extern LARGE_INTEGER freq_;
//
//extern LARGE_INTEGER begin_time;
//extern LARGE_INTEGER end_time;
//inline double ns_time() {
//    return (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;
//}
//
//#define TestTimeLog(func, ...)\
//QueryPerformanceCounter(&begin_time);\
//func(__VA_ARGS__);\
//QueryPerformanceCounter(&end_time);\
//logger.warn("  {}\t time: {}", #func, ns_time());
//
//#define TestTimeLogRtn(func, ...)\
//QueryPerformanceCounter(&begin_time);\
//auto rtn = func(__VA_ARGS__);\
//QueryPerformanceCounter(&end_time);\
//logger.warn("  {}\t time: {}", #func, ns_time());\
//return rtn;
//
//size_t tick = 0;
//
//THook(void, "?tick@ServerLevel@@UEAAXXZ",
//    void* _this) {
//    if (tick % 3 != 2)
//        return original(_this);
//#define ServerLevel original
//    TestTimeLog(ServerLevel, _this);
//}
//
//THook(bool, "?update@Minecraft@@QEAA_NXZ",
//    void* _this) {
//    if (tick % 3 != 1)
//        return original(_this);
//#define MinecraftUpdate original
//    TestTimeLogRtn(MinecraftUpdate, _this);
//}
//
//THook(void, "?_update@ServerInstance@@AEAAXXZ",
//    void* _this) {
//    ++tick;
//    if (tick % 3 != 0)
//        return original(_this);
//#define ServerInstance original
//    TestTimeLog(ServerInstance, _this);
//}

#include <ScheduleAPI.h>
void TestDBStorage::test()
{
    //Schedule::delay(
    //    []() {
    //        std::string data;
    //        if (Global<DBStorage>->loadData("Overworld", data, (DBHelpers::Category)0))
    //            WriteAllFile("Overworld.nbt", data, true);
    //        dbLogger.warn("Overworld Data Exported");
    //    },
    //    20);
}

#endif // ENABLE_TEST_DBSTORAGE

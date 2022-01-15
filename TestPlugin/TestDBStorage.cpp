#include "pch.h"
#include "TestDBStorage.h"
#include <MC/DBStorage.hpp>
#include <MC/Level.hpp>
#include <MC/Bedrock.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/StringTag.hpp>

Logger dbLogger("DBStorage");

struct voids {
    void**** filler[100];
};
#define DBLog(...)\
ASSERT((int)category != 3);\
if((int)category!=4) /* chunk */ \
    dbLogger.warn(__VA_ARGS__) 
std::string getKeyString(std::string_view key) {
    auto keySize = key.size();
    if (keySize != 9 && keySize != 10 && keySize != 13 && keySize != 14)
        return key.data();
    bool isChunkKey = false;
    for (auto& c : key) {
        if (c <= '\x1f' || c>='\x7f') {
            isChunkKey = true;
            break;
        }
    }
    if (!isChunkKey)
        return key.data();
    char buf[32];
    size_t index = -1;
    auto cmap = "0123456789abcedf";
    for (auto& c : key) {
        buf[++index] = cmap[((unsigned char)c & '\xf0') >> 4];
        buf[++index] = cmap[(unsigned char)c & '\x0f'];
    }
    buf[++index] = 0;
    return std::string(buf, index-1);
}
std::string getKeyString(gsl::string_span<-1> const& key) {
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
    if(!res)
        return output.error(fmt::format("Remove Player {} Data Failed", mName));
    return output.success(fmt::format("Remove Player {} Data", mName));
}

void RemovePlayerCommand::setup(CommandRegistry& registry)
{
    registry.registerCommand("removeplayer", "Operation Agent", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.addSoftEnum("PlayerList", playerList);
    updatePlayerList();
    auto nameParam = makeMandatory<CommandParameterDataType::SOFT_ENUM>(&RemovePlayerCommand::mName, "master", "PlayerList");
    registry.registerOverload<RemovePlayerCommand>("removeplayer", nameParam);
}



TInstanceHook(void, "?_read@DBStorage@@IEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    DBStorage,
    gsl::string_span<-1> key, DBHelpers::Category category,
    std::function<void(gsl::string_span<-1> key, gsl::string_span<-1> value)> const& callback) {
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
    return original(this,result, key, category);
}

TInstanceHook(void, "?forEachKeyWithPrefix@DBStorage@@UEBAXV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@AEBV?$function@$$A6AXV?$basic_string_span@$$CBD$0?0@gsl@@0@Z@std@@@Z",
    DBStorage, gsl::string_span<-1> prefix, DBHelpers::Category category,
    std::function<void(gsl::string_span<-1> key, gsl::string_span<-1> value)> const& callback) {
    DBLog("DBStorage::forEachKeyWithPrefix({}, {}, callback)", getKeyString(prefix), (int)category);
    return original(this, prefix, category, callback);
}

TInstanceHook(std::unique_ptr<CompoundTag>&, "?getCompoundTag@DBStorage@@UEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@W4Category@DBHelpers@@@Z",
    DBStorage, std::unique_ptr<CompoundTag>& result, std::string const& key, DBHelpers::Category category) {
    DBLog("DBStorage::getCompoundTag({}, {})", getKeyString(std::string_view(key)), (int)category);
    return original(this, result, key, category);
}

TInstanceHook(bool, "?hasKey@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@W4Category@DBHelpers@@@Z",
    DBStorage, gsl::string_span<-1> key, DBHelpers::Category category) {
    DBLog("DBStorage::hasKey({}, {})", getKeyString(key), (int)category);
    return original(this, key, category);
}

TInstanceHook(bool, "?loadData@DBStorage@@UEBA_NV?$basic_string_span@$$CBD$0?0@gsl@@AEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4Category@DBHelpers@@@Z",
    DBStorage,
    gsl::string_span<-1> key, std::string& data, DBHelpers::Category category) {
    DBLog("DBStorage::loadData({}, data, {})", getKeyString(key), (int)category);
    return original(this, key, data, category);
}

TInstanceHook(std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>&, "?saveData@DBStorage@@UEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@$$QEAV43@W4Category@DBHelpers@@@Z",
    DBStorage, std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>& result,
    std::string const& key, std::string&& data, DBHelpers::Category category) {
    DBLog("DBStorage::saveData({}, data, {})", getKeyString(std::string_view(key)), (int)category);
    return original(this, result, key, std::move(data), category);
}

TInstanceHook(std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>&, "?saveData@LevelStorage@@QEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@AEBVCompoundTag@@W4Category@DBHelpers@@@Z",
    LevelStorage, std::shared_ptr<Bedrock::Threading::IAsyncResult<void>>& result,
    std::string const& key, CompoundTag const& tag, DBHelpers::Category category) {
    DBLog("LevelStorage::saveData({}, {}, {})", getKeyString(std::string_view(key)), tag.toString(), (int)category);
    return original(this, result, key, tag, category);
}
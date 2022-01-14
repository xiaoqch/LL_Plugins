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

THook(std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>&, "?saveData@LevelStorage@@QEAA?AV?$shared_ptr@V?$IAsyncResult@X@Threading@Bedrock@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@AEBVCompoundTag@@W4Category@DBHelpers@@@Z",
    class LevelStorage* _this, std::shared_ptr<class Bedrock::Threading::IAsyncResult<void>>& res, std::string const& key, class CompoundTag const& tag, enum DBHelpers::Category category) {
    dbLogger.info("LevelStorage::saveData({}, {}, {})", key, tag.toString(), (int)category);
    auto& rtn = original(_this, res, key, tag, category);
    auto a = (voids*)rtn.get();
    logger.info("getStatus: {}", (int)rtn->getStatus());
    rtn->addOnComplete([](Bedrock::Threading::IAsyncResult<void> const& result) {
        logger.info("addOnComplete callback");
        auto a = std::unordered_map<int, int>();
        a.try_emplace(1);
        logger.info("getStatus: {}", (int)result.getStatus());
        });
    return rtn;
}

inline class Player* getPlayer(class mce::UUID const& a0) {
    class Player* (Level:: * rv)(class mce::UUID const&);
    *((void**)&rv) = dlsym("?getPlayer@Level@@UEBAPEAVPlayer@@AEBVUUID@mce@@@Z");
    return (Global<Level>->*rv)(std::forward<class mce::UUID const&>(a0));
}
bool TestDBStorage::deletePlayerData(mce::UUID uuid)
{
    auto player = getPlayer(uuid);
    if (player)
        player->kick("");
    auto dbStorage = (DBStorage*)&Global<Level>->getLevelStorage();
    auto tag = dbStorage->getCompoundTag("player_" + uuid.asString(), (DBHelpers::Category)0);
    if (!tag)
        return false;
    for (auto& [key, idTagVariant] : *tag) {
        auto idTag = const_cast<CompoundTagVariant&>(idTagVariant).asStringTag();
        auto& id = idTag->value();
        id = key == "ServerId" ? id : "player_" + id;
        auto res = dbStorage->deleteData(id, (DBHelpers::Category)0);
        res->addOnComplete([id](Bedrock::Threading::IAsyncResult<void> const& result) {
            if (result.getStatus() == 1)
                logger.warn("Remove {} Success", id);
            else
            {
                auto code = result.getError();
                logger.error("Remove {} Failed, cause: {}", id, code.message());
            }
            });
    }
    return true;
    auto& serverId = tag->getString("ServerId");
    if (!serverId._Starts_with("player_server"))
        return false;
    auto res2 = dbStorage->deleteData(serverId, (DBHelpers::Category)0);
    return res2->getStatus() == 1;
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


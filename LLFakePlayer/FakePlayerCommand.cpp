#include "pch.h"
#include "FakePlayerCommand.h"
#include <MC/DBStorage.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/SimulatedPlayer.hpp>
#include <MC/Dimension.hpp>
#include <MC/CompoundTag.hpp>
#include <PlayerInfoAPI.h>
#include "FakePlayerManager.h"

#define KEY_NO_TARGET "%commands.generic.noTargetMatch"
#define KEY_TOO_MANY_TARGER "%commands.generic.tooManyTargets"

#define AssertUniqueTarger(results)         \
    if (results.empty())                    \
        return output.error(KEY_NO_TARGET); \
    else if (results.count() > 1)           \
        return output.error(KEY_TOO_MANY_TARGER);

using namespace RegisterCommandHelper;
std::vector<std::string> FakePlayerCommand::mList;
//inline BlockPos FakePlayerCommand::getExpectedPosition(CommandOrigin const& origin) const
//{
//    BlockPos bpos;
//    if (commandPos_isSet) {
//        bpos = commandPos.getBlockPos(origin, { 0,0,0 });
//    }
//    else if (origin.getBlockPosition().toVec3().length() < 0.1) {
//        bpos = Global<Level>->getDefaultSpawn();
//    }
//    else {
//        bpos = origin.getBlockPosition();
//    }
//    return bpos;
//}
#include <MC/Scoreboard.hpp>
void FakePlayerCommand::execute(CommandOrigin const& origin, CommandOutput& output) const
{
    auto& manager = FakePlayerManager::getManager();
    bool res = false;
    switch (operation)
    {
        case FakePlayerCommand::Operation::Help:
            output.success(PLUGIN_USAGE);
            break;
        case FakePlayerCommand::Operation::List:
        {
            std::string playerList = "";
            bool first = true;
            for (auto& name : manager.getSortedNames())
            {
                if (!first)
                    playerList += ", ";
                first = false;
                playerList += name;
                output.success();
            }
            if (playerList.empty())
                output.success("No fake player.");
            else
            {
                output.addMessage(fmt::format("List: {}", playerList));
            }
            break;
        }
        case FakePlayerCommand::Operation::Create:
        {
            if (auto fp = manager.create(name))
            {
                output.success(fmt::format("Create fake player {} successfully.", fp->getRealName()));
            }
            else
            {
                output.error(fmt::format("Failed to create fake player {}.", name));
            }
            break;
        }
        case FakePlayerCommand::Operation::Remove:
        {
            res = manager.remove(name);
            if (res)
                output.success("Remove Success");
            else
                output.error("Remove Failed");
            break;
        }
        case FakePlayerCommand::Operation::Login:
            res = manager.login(name);
            if (res)
                output.success("Login Success");
            else
                output.error("Login Failed");
            break;
        case FakePlayerCommand::Operation::Logout:
            res = manager.logout(name);
            if (res)
                output.success("Logout Success");
            else
                output.error("Logout Failed");
            break;
        case FakePlayerCommand::Operation::Import:
            if (name_isSet)
            {
                manager.importData_DDF(name);
            }
            else
            {
                PlayerInfo::forEachInfo([&output](std::string_view name, std::string_view xuid, std::string_view uuid) -> bool {
                    auto nameUUID = JAVA_nameUUIDFromBytes(std::string(name));
                    if (uuid == nameUUID.asString())
                    {
                        output.success(fmt::format("{} - {} - {}", name, xuid, uuid));
                    }
                    return true;
                });
            }
            break;
        case FakePlayerCommand::Operation::GUI:
            output.error("NoImpl");
            break;
        default:
            break;
    }
}
class TestCommand;
constexpr auto FULL_COMMAND_NAME = "llfakeplayer";
void FakePlayerCommand::setup(CommandRegistry& registry)
{

    registry.registerCommand(FULL_COMMAND_NAME, "FakePlayer For LiteLoader", CommandPermissionLevel::GameMasters, {(CommandFlagValue)0}, {(CommandFlagValue)0x80});
    registry.registerAlias(FULL_COMMAND_NAME, "fp");
    registry.addEnum<Operation>("FpCreateAction", {
                                                      {"create", Operation::Create},
                                                  });
    registry.addEnum<Operation>("FpOtherAction", {
                                                     {"remove", Operation::Remove},
                                                     {"login", Operation::Login},
                                                     {"logout", Operation::Logout},
                                                 });
    registry.addEnum<Operation>("ManageAction", {
                                                    {"list", Operation::List},
                                                    {"help", Operation::Help},
                                                    {"gui", Operation::GUI},
                                                });
    registry.addEnum<Operation>("ImportAction", {
                                                    {"import", Operation::Import},
                                                });
    auto actionCreate = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "FpCreateAction");
    auto actionWithName = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "FpOtherAction");
    auto action = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "ManageAction");
    auto actionImport = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "ImportAction");
    actionCreate.addOptions((CommandParameterOption)1);
    actionWithName.addOptions((CommandParameterOption)1);
    action.addOptions((CommandParameterOption)1);

    auto nameSoftEnum = registry.addSoftEnum("playerList", FakePlayerManager::getManager().sortedNames);
    auto nameSoftEnumParam = makeMandatory<CommandParameterDataType::SOFT_ENUM>(&FakePlayerCommand::name, "name", "playerList");
    auto nameParam = makeMandatory(&FakePlayerCommand::name, "name");
    auto nameOptional = makeOptional(&FakePlayerCommand::name, "name", &FakePlayerCommand::name_isSet);
    auto posParam = makeOptional(&FakePlayerCommand::commandPos, "position", &FakePlayerCommand::commandPos_isSet);
    auto dimidParam = makeOptional(&FakePlayerCommand::dimensionId, "dimension", &FakePlayerCommand::dimensionId_isSet);

    //registry.addEnum<Operation>("HelpAction", { {"help", Operation::Help}, });
    //auto actionHelp = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "HelpAction");
    //actionHelp.addOptions((CommandParameterOption)1);
    //registry.registerOverload<TestCommand>("Test", actionHelp);

    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, action);
    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, actionWithName, nameSoftEnumParam);
    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, actionCreate, nameParam);
    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, actionImport, nameOptional);
}

#ifdef PLUGIN_DEV_MODE

// =============== Test ===============
#include <MC/BlockSource.hpp>
#include <MC/LevelChunk.hpp>
bool processCommand(class CommandOrigin const& origin, class CommandOutput& output, Actor* actor, int range)
{
    auto bpos = actor->getBlockPos();
    int chunk_x = bpos.x >> 4;
    int chunk_z = bpos.z >> 4;
    auto max_cx = chunk_x + range;
    auto min_cx = chunk_x - range;
    auto max_cz = chunk_z + range;
    auto min_cz = chunk_z - range;
    auto chunksCount = 0;
    auto needChunksCount = (max_cx - min_cx + 1) * (max_cz - min_cz + 1);

    string loadInfo = "";
    auto& region = actor->getRegion();
    if (!&region)
        return false;

    for (auto cx = min_cx; cx <= max_cx; ++cx)
    {
        loadInfo += " \n";
        for (auto cz = min_cz; cz <= max_cz; ++cz)
        {
            auto chunk = region.getChunk({cx, cz});
            if (cx == chunk_x && cz == chunk_z)
            {
                loadInfo += "X";
            }
            else
            {
                if (chunk)
                {
                    if (chunk->getLastTick().t == Global<Level>->getCurrentServerTick().t)
                    {
                        loadInfo += "#";
                    }
                    else
                    {
                        loadInfo += "O";
                    }
                }
                else
                {
                    loadInfo += "-";
                }
            }
            if (chunk)
                ++chunksCount;
        }
    }
    output.success(fmt::format("Center ChunkPos: ({}, {}), Info: {}", (int)(bpos.x >> 4), (int)(bpos.z >> 4), loadInfo));
    return true;
}

void TickingCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const
{
    Actor* actor;
    if (selector_isSet)
    {
        auto result = selector.results(origin);
        if (result.empty())
        {
            output.error(KEY_NO_TARGET);
            return;
        }
        else if (result.count() > 1)
        {
            output.error(KEY_NO_TARGET);
            return;
        }
        actor = *result.begin();
    }
    else
    {
        if (auto entity = origin.getEntity())
        {
            actor = entity;
        }
        else
        {
            output.error(KEY_NO_TARGET);
            return;
        }
    }
    if (!processCommand(origin, output, actor, range_isSet ? range : 10))
        output.error("Error when executing command \"ticking\"");
}

void TickingCommand::setup(CommandRegistry& registry)
{
    registry.registerCommand("ticking", "Show Ticking chunks", CommandPermissionLevel::Any, {(CommandFlagValue)0}, {(CommandFlagValue)0x80});
    registry.registerOverload<TickingCommand>("ticking",
                                              makeOptional(&TickingCommand::selector, "target", &TickingCommand::selector_isSet),
                                              makeOptional(&TickingCommand::range, "range", &TickingCommand::range_isSet));
    registry.registerOverload<TickingCommand>("ticking",
                                              makeMandatory(&TickingCommand::range, "range", &TickingCommand::range_isSet));
}
#endif // PLUGIN_DEV_MODE
#include "pch.h"
#include "FakePlayerCommand.h"
#include <MC/ServerNetworkHandler.hpp>
#include <MC/SimulatedPlayer.hpp>
#include <MC/Dimension.hpp>
#include <MC/CompoundTag.hpp>
using namespace RegisterCommandHelper;
std::vector<std::string> FakePlayerCommand::mList;
inline BlockPos FakePlayerCommand::getExpectedPosition(CommandOrigin const& origin) const
{
    BlockPos bpos;
    if (commandPos_isSet) {
        bpos = commandPos.getBlockPos(origin, { 0,0,0 });
    }
    else if (origin.getBlockPosition().toVec3().length() < 0.1) {
        bpos = Global<Level>->getDefaultSpawn();
    }
    else {
        bpos = origin.getBlockPosition();
    }
    return bpos;
}

SimulatedPlayer* FakePlayerCommand::createSimulatedPlayer(CommandOrigin const& origin, CommandOutput& output) const
{
    static int SimulatedPlayerSubId = 0;
    auto bpos = getExpectedPosition(origin);
    auto oriDim = origin.getDimension();
    int oriDimid = oriDim ? (int)oriDim->getDimensionId() : 0;
    auto dimid = dimensionId_isSet ? dimensionId : oriDimid;
    if (!Global<Level>->getDimension(dimid))
        Global<Level>->createDimension(dimid);
    auto sp = SimulatedPlayer::create(name, bpos, dimid, *Global<ServerNetworkHandler>);

    if (sp) {
        mList.push_back(sp->getNameTag());
        output.success(fmt::format("Create fake player {} success.", sp->getNameTag()));
        return sp;
    }
    else {
        output.error(fmt::format("Create fake player {} failed.", name));
        return nullptr;
    }
}

#include <MC/Scoreboard.hpp>
void FakePlayerCommand::execute(CommandOrigin const& origin, CommandOutput& output) const
{
    switch (operation)
    {
    case FakePlayerCommand::Operation::Help:
        output.success(PLUGIN_USAGE);
        break;
    case FakePlayerCommand::Operation::List:
    {
        std::string playerList = "";
        bool first = true;
        for (auto& pl : Level::getAllPlayers()) {
            if (!pl->isSimulatedPlayer())
                continue;
            if (!first)
                playerList += ", ";
            first = false;
            playerList += pl->getNameTag();
            output.success();
        }
        if (playerList.empty())
            output.error("Not any simulated player.");
        else {
            output.addMessage(fmt::format("List: {}", playerList));
        }
        break;
    }
    case FakePlayerCommand::Operation::Create:
        createSimulatedPlayer(origin, output);
        break;
    case FakePlayerCommand::Operation::Remove:
    {
        auto pl = Level::getPlayer(name);
        if (!pl || !pl->isSimulatedPlayer()) {
            output.error("Player Not Found");
            break;
        }
        ((SimulatedPlayer*)pl)->simulateDisconnect();
        output.success("Remove Success");
        break;
    }
    case FakePlayerCommand::Operation::Login:
        break;
    case FakePlayerCommand::Operation::Logout:
        break;
    case FakePlayerCommand::Operation::GUI:
        break;
    default:
        break;
    }
}
constexpr auto FULL_COMMAND_NAME = "llfakeplayer";
void FakePlayerCommand::setup(CommandRegistry& registry)
{

    registry.registerCommand(FULL_COMMAND_NAME, "FakePlayer For LiteLoader", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
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
    auto opWithNamePosition = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "FpCreateAction");

    auto opWithName = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "FpOtherAction");
    auto op = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "action", "ManageAction");
    opWithNamePosition.addOptions((CommandParameterOption)1);
    opWithName.addOptions((CommandParameterOption)1);
    op.addOptions((CommandParameterOption)1);
    auto nameParam = makeMandatory(&FakePlayerCommand::name, "name");
    auto posParam = makeOptional(&FakePlayerCommand::commandPos, "position", &FakePlayerCommand::commandPos_isSet);
    auto dimidParam = makeOptional(&FakePlayerCommand::dimensionId, "dimension", &FakePlayerCommand::dimensionId_isSet);

    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, opWithName, nameParam);
    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, opWithNamePosition, nameParam, posParam, dimidParam);
    registry.registerOverload<FakePlayerCommand>(FULL_COMMAND_NAME, op);
}

#if PLUGIN_VERSION_IS_BETA

// =============== Test ===============
#include <MC/BlockSource.hpp>
#include <MC/LevelChunk.hpp>
bool processCommand(class CommandOrigin const& origin, class CommandOutput& output, Actor* actor) {
    auto bpos = actor->getBlockPos();
    int chunk_x = bpos.x >> 4;
    int chunk_z = bpos.z >> 4;
    int range = 10;
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

    for (auto cx = min_cx; cx <= max_cx; ++cx) {
        loadInfo += " \n";
        for (auto cz = min_cz; cz <= max_cz; ++cz) {
            auto chunk = region.getChunk({ cx, cz });
            if (cx == chunk_x && cz == chunk_z) {
                loadInfo += "X";
            }
            else {
                if (chunk) {
                    if (chunk->getLastTick().t == Global<Level>->getCurrentServerTick().t) {
                        loadInfo += "#";
                    }
                    else {
                        loadInfo += "O";
                    }
                }
                else {
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

void TickingCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const {
    Actor* actor;
    if (selector_isSet) {
        auto result = selector.results(origin);
        if (result.empty()) {
            output.error("%no.target");
            return;
        }
        else if (result.count() > 1) {
            output.error("%no.target");
            return;
        }
        actor = *result.begin();
    }
    else {
        if (auto entity = origin.getEntity()) {
            actor = entity;
        }
        else {
            output.error("%no.target");
            return;
        }
    }
    if (!processCommand(origin, output, actor))
        output.error("Error when executing command \"ticking\"");
}

void TickingCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("ticking", "Show Ticking chunk", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.registerOverload<TickingCommand>("ticking",
        makeOptional(&TickingCommand::selector, "target", &TickingCommand::selector_isSet));
}
#endif // PLUGIN_VERSION_IS_BETA
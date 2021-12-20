#include "pch.h"
#include "FakePlayerCommand.h"
#include <MC/ServerNetworkHandler.hpp>
#include <MC/SimulatedPlayer.hpp>
#include <MC/Dimension.hpp>

using namespace RegisterCommandHelper;
std::vector<std::string> FakePlayerCommand::mList;
inline BlockPos FakePlayerCommand::getPositionFromCommand(CommandOrigin const& origin) const
{
    BlockPos bpos;
    if (commandPos_isSet)
    {
        bpos = commandPos.getBlockPos(origin, { 0,0,0 });
    }
    else {
        bpos = origin.getBlockPosition();
    }
    return bpos;
}

SimulatedPlayer* FakePlayerCommand::createSimulatedPlayer(CommandOrigin const& origin, CommandOutput& output) const
{
    static int SimulatedPlayerSubId = 0;
    auto bpos = getPositionFromCommand(origin);
    auto oriDim = origin.getDimension();
    int oriDimid = oriDim ? (int)oriDim->getDimensionId() : 0;
    auto dimid = dimensionId_isSet ? dimensionId : oriDimid;
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

void FakePlayerCommand::execute(CommandOrigin const& origin, CommandOutput& output) const
{
    switch (operation)
    {
    case FakePlayerCommand::Operation::Help:
        break;
    case FakePlayerCommand::Operation::List:
        break;
    case FakePlayerCommand::Operation::Create:
        createSimulatedPlayer(origin, output);
        break;
    case FakePlayerCommand::Operation::Remove:
        break;
    case FakePlayerCommand::Operation::Login:
        break;
    case FakePlayerCommand::Operation::Logout:
        break;
    default:
        break;
    }
}
constexpr auto FULL_COMMAND_NAME = "llfakeplayer";
void FakePlayerCommand::setup(CommandRegistry& registry)
{
    
    registry.registerCommand(FULL_COMMAND_NAME, "FakePlayer For LiteLoader", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.registerAlias(FULL_COMMAND_NAME, "llfp");
    registry.addEnum<Operation>("Operation", {
        {"create", Operation::Create},
        });
    auto op = makeMandatory<CommandParameterDataType::ENUM>(&FakePlayerCommand::operation, "operation", "Operation");
    auto nameParam = makeMandatory(&FakePlayerCommand::name, "name");
    auto posParam = makeOptional(&FakePlayerCommand::commandPos, "position", &FakePlayerCommand::commandPos_isSet);
    auto dimidParam = makeOptional(&FakePlayerCommand::dimensionId, "dimension", &FakePlayerCommand::dimensionId_isSet);
    registry.registerOverload< FakePlayerCommand>(FULL_COMMAND_NAME, op, nameParam, posParam, dimidParam);
}

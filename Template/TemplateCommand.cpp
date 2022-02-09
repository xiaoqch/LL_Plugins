#include "pch.h"
#include "ActorDebugCommand.h"

using namespace RegisterCommandHelper;

void ActorDebugCommand::execute(class CommandOrigin const& ori, class CommandOutput& outp) const {
    if (mOperation_isSet) {
        switch (mOperation)
        {
        default:
            break;
        }
    }
    else {

    }
}

void ActorDebugCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("template", "Command Template", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });

    registry.addEnum<Operation>("Template_Action", {/* ... */});
    auto action = makeMandatory<CommandParameterDataType::ENUM>(
        &ActorDebugCommand::mOperation, "action", "Template_Action", &ActorDebugCommand::mOperation_isSet);

    registry.registerOverload<ActorDebugCommand>("template");
    registry.registerOverload<ActorDebugCommand>("template", action);
}
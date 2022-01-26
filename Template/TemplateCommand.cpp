#include "pch.h"
#include "TemplateCommand.h"

using namespace RegisterCommandHelper;

void TemplateCommand::execute(class CommandOrigin const& ori, class CommandOutput& outp) const {
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

void TemplateCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("template", "Command Template", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });

    registry.addEnum<Operation>("Template_Action", {/* ... */});
    auto action = makeMandatory<CommandParameterDataType::ENUM>(
        &TemplateCommand::mOperation, "action", "Template_Action", &TemplateCommand::mOperation_isSet);

    registry.registerOverload<TemplateCommand>("template");
    registry.registerOverload<TemplateCommand>("template", action);
}
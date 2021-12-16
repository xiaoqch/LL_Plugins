#include "pch.h"
#include "TemplateCommand.h"

using namespace RegisterCommandHelper;

void TemplateCommand::execute(class CommandOrigin const& ori, class CommandOutput& outp) const {
    outp.success(fmt::format("param: {}", param));
}

void TemplateCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("template", "Command Template", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.registerOverload<TemplateCommand>("template", makeMandatory(&TemplateCommand::param, "param"));
}
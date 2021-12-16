#include "pch.h"
#include "TemplateCommand.h"
#include <EventAPI.h>

void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        TemplateCommand::setup(*ev.mCommandRegistry);
        return true;
        });
}
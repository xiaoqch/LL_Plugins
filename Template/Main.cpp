#include "pch.h"
#include "ActorDebugCommand.h"
#include <EventAPI.h>

void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        ActorDebugCommand::setup(*ev.mCommandRegistry);
        return true;
        });
}
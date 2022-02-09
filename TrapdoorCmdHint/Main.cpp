#include "pch.h"
#include "TrapdoorCommands.h"
#include <EventAPI.h>

void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        registryCommands(*ev.mCommandRegistry);
        return true;
        });
}
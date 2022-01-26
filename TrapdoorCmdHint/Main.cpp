#include "pch.h"
#include "TrapdoorCommand.h"
#include <EventAPI.h>

void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) {
        registryCommand(*ev.mCommandRegistry);
        return true;
        });
}
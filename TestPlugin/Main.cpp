#include "pch.h"
#include "TestRegRecipe.h"
#include <EventAPI.h>
#include "TestDBStorage.h"
void entry() {
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev)->bool {
        testRegRecipe();
        return true;
        });
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent const& ev)->bool {
        RemovePlayerCommand::setup(*ev.mCommandRegistry);
        return true;
        });
}
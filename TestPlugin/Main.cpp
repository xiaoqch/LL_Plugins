#include "pch.h"
#include "TestRegRecipe.h"
#include <EventAPI.h>
void entry() {
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev)->bool {
        testRegRecipe();
        return true;
        });
}
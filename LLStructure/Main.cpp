#include "pch.h"
#include "LLStructureCommand.h"
void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent const& ev) {
        LLStructureCommand::setup(*ev.mCommandRegistry);
        return true;
        });
    //Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev) {
    //    SymCall()
    //    return true;
    //    });
}
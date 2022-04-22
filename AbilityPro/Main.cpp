#include "pch.h"
#include "AbilityProCommand.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <PlayerInfoAPI.h>
void entry()
{
    Event::RegCmdEvent::subscribe(
        [](Event::RegCmdEvent ev) {
            AbilityProCommand::setup(*ev.mCommandRegistry);
            return true;
        });
}

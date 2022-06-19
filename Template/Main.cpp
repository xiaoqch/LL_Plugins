#include "pch.h"
#include "TemplateCommand.h"
#include <EventAPI.h>
#include <MC/ServerPlayer.hpp>
#include <MC/ServerNetworkHandler.hpp>
#include <MC/Level.hpp>
#include <PlayerInfoAPI.h>
#include <ScheduleAPI.h>

void entry()
{
    Event::RegCmdEvent::subscribe_ref([](Event::RegCmdEvent& ev) {
        TemplateCommand::setup(*ev.mCommandRegistry);
        return true;
    });
}



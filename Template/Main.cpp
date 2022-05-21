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
    Event::PlayerJumpEvent::subscribe_ref([](Event::PlayerJumpEvent& ev) {
        return true;
        });
}


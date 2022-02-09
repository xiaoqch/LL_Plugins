#include "pch.h"
#include <EventAPI.h>
#include "FakePlayerManager.h"
#include "FakePlayerCommand.h"

void* fakeSimulatedPlayerVftbl[445];
void modifyVftbl()
{
    void** vftbl_simulated = (void**)dlsym_real("??_7SimulatedPlayer@@6B@");
    void** vftbl_server = (void**)dlsym_real("??_7ServerPlayer@@6B@");
    memcpy(fakeSimulatedPlayerVftbl, vftbl_server, sizeof(fakeSimulatedPlayerVftbl));
#define RestoreVFunc(index) fakeSimulatedPlayerVftbl[index] = vftbl_simulated[index]
    RestoreVFunc(14);
    RestoreVFunc(292);
    RestoreVFunc(10);
    //RestoreVFunc(339);
    //RestoreVFunc(438);
    RestoreVFunc(439);
    RestoreVFunc(440);
    RestoreVFunc(443);
#undef RestoreVFunc
}

#include <MC/Block.hpp>
#include <MC/NetworkIdentifier.hpp>
void entry()
{
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) -> bool {
        FakePlayerCommand::setup(*ev.mCommandRegistry);
#ifdef PLUGIN_DEV_MODE
        TickingCommand::setup(*ev.mCommandRegistry);
#endif // PLUGIN_DEV_MODE
        return true;
    });
    // ========== Test ==========
#ifdef PLUGIN_DEV_MODE
    auto listener = Event::PlayerJoinEvent::subscribe([](Event::PlayerJoinEvent const& ev) -> bool {
        DEBUGW(ev.mPlayer->getNetworkIdentifier()->toString());
        return true;
    });
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent ev) -> bool {
        //modifyVftbl();
        //FakePlayerManager::getManager();
        return true;
    });
#endif // PLUGIN_DEV_MODE
}
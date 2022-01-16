#include "pch.h"
#include <EventAPI.h>
#include "FakePlayerManager.h"
#include "FakePlayerCommand.h"

void* fakeSimulatedPlayerVftbl[445];
void modifyVftbl() {
    void** vftbl_simulated = (void**)dlsym_real("??_7SimulatedPlayer@@6B@");
    void** vftbl_server = (void**)dlsym_real("??_7ServerPlayer@@6B@");
    memcpy(fakeSimulatedPlayerVftbl, vftbl_server, sizeof(fakeSimulatedPlayerVftbl));
#define restoreVFunc(index) fakeSimulatedPlayerVftbl[index] = vftbl_simulated[index]
    restoreVFunc(14);
    restoreVFunc(10);
    restoreVFunc(292);
    //restoreVFunc(339);
    //restoreVFunc(438);
    restoreVFunc(439);
    restoreVFunc(440);
    restoreVFunc(443);
}

#include <MC/Block.hpp>
#include <MC/NetworkIdentifier.hpp>
void entry() {
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev)->bool {
        FakePlayerCommand::setup(*ev.mCommandRegistry);
#if PLUGIN_VERSION_IS_BETA
        TickingCommand::setup(*ev.mCommandRegistry);
#endif // PLUGIN_VERSION_IS_BETA
        return true;
        });
    // ========== Test ==========
#if PLUGIN_VERSION_IS_BETA
    auto listener = Event::PlayerJoinEvent::subscribe([](Event::PlayerJoinEvent const& ev)->bool {
        DEBUGW(ev.mPlayer->getNetworkIdentifier()->toString());
        return true;
        });
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent ev)->bool {
        //modifyVftbl();
        //FakePlayerManager::getManager();
        return true;
        });
#endif // PLUGIN_VERSION_IS_BETA
}
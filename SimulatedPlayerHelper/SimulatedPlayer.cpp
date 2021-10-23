#include "pch.h"
#include "SimulatedPlayer.h"

bool isSimulatedPlayer(Actor* actor) {
    return *(void**)actor == dlsym("??_7SimulatedPlayer@@6B@");
}

THook(void, "?die@ServerPlayer@@UEAAXAEBVActorDamageSource@@@Z",
    ServerPlayer* _this, ActorDamageSource* ads) {
    original(_this, ads);
    if (isSimulatedPlayer(_this)) {
        SymCall("?respawn@Player@@UEAAXXZ", void, ServerPlayer*)(_this);
        if(_this->getDimensionId())
            ((SimulatedPlayer*)_this)->changeDimension(0, false);
    }
}
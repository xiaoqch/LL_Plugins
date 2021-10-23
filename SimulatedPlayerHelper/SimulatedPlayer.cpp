#include "pch.h"
#include "SimulatedPlayer.h"

bool isSimulatedPlayer(Actor* actor) {
    return *(void**)actor == dlsym("??_7SimulatedPlayer@@6B@");
}

THook(void, "?die@ServerPlayer@@UEAAXAEBVActorDamageSource@@@Z",
    ServerPlayer* _this, ActorDamageSource* ads) {
    if (isSimulatedPlayer(_this)) {
        auto sp = ((SimulatedPlayer*)_this);
        WPlayer(*sp).teleport({ 0,0,0 }, 0);
        original(_this, ads);
        return sp->respawn();
    }
    original(_this, ads);
}

//THook(void, "?applyTarget@TeleportCommand@@SAXAEAVActor@@VTeleportTarget@@@Z",
//    ServerPlayer* _this, ActorDamageSource* ads) {
//    original(_this, ads);
//    if (isSimulatedPlayer(_this)) {
//        auto sp = ((SimulatedPlayer*)_this);
//        sp->respawn();
//        sp->resetPos(true);
//    }
//}

//THook(void, "?respawn@Player@@UEAAXXZ",
//    Player* _this) {
//    original(_this);
//    if (isSimulatedPlayer(_this)) {
//        if(_this->getDimensionId())
//            ((SimulatedPlayer*)_this)->changeDimension(0, false);
//    }
//}
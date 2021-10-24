#include "pch.h"
#include "SymHelper.h"

Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self) {
    original(self);
    mc = (Minecraft*)self;
}

Player* getPlayerByAUID(ActorUniqueID auid) {
    return SymCall("?getPlayer@Level@@UEBAPEAVPlayer@@UActorUniqueID@@@Z",
        Player*, Level*, ActorUniqueID)(mc->getLevel(), auid);
}

Player* getPlayerByAUID(long long auid) {
    return getPlayerByAUID(ActorUniqueID(auid));
}

Actor* getActorByAUID(ActorUniqueID auid) {
    return SymCall("?fetchEntity@Level@@UEBAPEAVActor@@UActorUniqueID@@_N@Z",
        Actor*, Level*, ActorUniqueID, bool)(mc->getLevel(), auid, true);
}
Actor* getActorByAUID(long long auid) {
    return getActorByAUID(ActorUniqueID(auid));
}

Mob* getMobByAUID(ActorUniqueID auid) {
    return SymCall("?getMob@Level@@UEBAPEAVMob@@UActorUniqueID@@@Z",
        Mob*, Level*, ActorUniqueID, bool)(mc->getLevel(), auid, true);
}
Mob* getMobByAUID(long long auid) {
    return getMobByAUID(ActorUniqueID(auid));
}

bool isPlayer(Actor* actor) {
    return *(void**)actor == dlsym("??_7ServerPlayer@@6B@");
}
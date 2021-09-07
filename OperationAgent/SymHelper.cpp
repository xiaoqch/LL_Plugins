#include "pch.h"
#include "SymHelper.h"

Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self) {
  original(self);
  mc = (Minecraft*)self;
}

BlockSource* getBlockSourceByDim(int dimid) {
  auto dim = (int*)SymCall(
      "?getDimension@Level@@UEBAPEAVDimension@@V?$AutomaticID@VDimension@@H@@@Z",
      uintptr_t, void*, int)(mc->getLevel(), dimid);
  return dAccess<BlockSource*>(dim, 96);
}

void setOwner(Actor* actor, ActorUniqueID auid) {
  SymCall("?setOwner@Actor@@UEAAXUActorUniqueID@@@Z", void*, Actor*,
          ActorUniqueID)(actor, auid);
}
void setOwner(Actor* actor, long long auid) {
    setOwner(actor, ActorUniqueID(auid));
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
    if (!actor)
        return false;
    auto vtbl = dlsym("??_7ServerPlayer@@6B@");
    return *(void**)actor == vtbl;
}

bool isSleeping(Player* player) {
    return *((bool*)player + 7648); //Player::isSleeping
}
bool isSleeping(Mob* mob) {//Mob::isSleeping
    return SymCall("?getStatusFlag@Actor@@QEBA_NW4ActorFlags@@@Z",
        bool, Actor*, int64_t)(mob, 75i64);
}

void sendPlayerText(Player* player, std::string str) {
    WPlayer(*player).sendText(str, TextType::RAW);
}

std::string getActorName(Actor* actor) {
    if (actor == nullptr) {
        return "";
    }
    string name;
    return SymCall("?getActorName@CommandUtils@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVActor@@@Z",
        std::string&, std::string*, Actor* actor)(&name, actor);
}
std::string getActorDescription(Actor* actor) {
    if (actor == nullptr) {
        std::cerr << "getActorDescription 传入空指针" << std::endl;
        return "";
    }
    auto auid = std::to_string(actor->getUniqueID().id);
    return getActorName(actor) + "(" + auid + ")";
}
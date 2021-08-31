#include "pch.h"
#include "mc/Actor.h"
#include "mc/BlockSource.h"
#include "mc/LevelChunk.h"

BlockSource* getBlockSourceByDim(int dimid);

void setOwner(Actor* actor, long long auid);
void setOwner(Actor* actor, ActorUniqueID auid);

Player* getPlayerByAUID(long long auid);
Player* getPlayerByAUID(ActorUniqueID auid);

Actor* getActorByAUID(long long auid);
Actor* getActorByAUID(ActorUniqueID auid);

Mob* getMobByAUID(long long auid);
Mob* getMobByAUID(ActorUniqueID auid);

bool isPlayer(Actor* actor);
void sendPlayerText(Player* player, std::string str);

std::string getActorName(Actor* actor);
std::string getActorDescription(Actor* actor);

bool isSleeping(Player* player);
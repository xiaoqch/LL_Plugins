#pragma once
#include <api/scheduler/scheduler.h>

extern Minecraft* mc;

inline ServerNetworkHandler* getServerNetworkHandler() {
    return mc->getServerNetworkHandler();
};

inline Level* getLevel() {
    return mc->getLevel();
};

inline void setTimeOut(function<void()> func, tick_t denyTick) {
    auto task = DelayedTask(std::move(func), (float)denyTick / 20.0f);
    auto taskId = Handler::schedule(std::move(task));
}

Player* getPlayerByAUID(ActorUniqueID auid);

bool isPlayer(Actor* actor);
#pragma once

extern Minecraft* mc;

inline ServerNetworkHandler* getServerNetworkHandler() {
    return mc->getServerNetworkHandler();
};


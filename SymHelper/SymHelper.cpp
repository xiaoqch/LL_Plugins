#include "pch.h"
#include "SymHelper.h"


//======= Basic Function =======

Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self)
{
    original(self);
    mc = (Minecraft*)self;
}

Level* getLevel() {
    return mc->getLevel();
};
ServerNetworkHandler* getServerNetworkHandler() {
    return mc->getServerNetworkHandler();
};
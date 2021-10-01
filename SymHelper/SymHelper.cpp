#include "pch.h"


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
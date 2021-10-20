#include "pch.h"
#include "SymHelper.h"

Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self) {
    original(self);
    mc = (Minecraft*)self;
}

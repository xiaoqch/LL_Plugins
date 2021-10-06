#include "pch.h"
#include "SymHelper.h"

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

class Recipes* getRecipes() {
    return SymCall("?getRecipes@Level@@UEBAAEAVRecipes@@XZ",
        Recipes*, Level*)(getLevel());
}
#include "pch.h"
#include "ItemHelper.h"
#include <mc/Command.h>
#include "RecipeHelper.h"


Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self)
{
    original(self);
    mc = (Minecraft*)self;
}

class Recipes* getRecipes() {
    return SymCall("?getRecipes@Level@@UEBAAEAVRecipes@@XZ",
        Recipes*, Level*)(mc->getLevel());
}
Level* getLevel() {
    return mc->getLevel();
}
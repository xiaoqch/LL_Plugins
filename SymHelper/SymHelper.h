#pragma once
#include <mc/Level.h>

#define LOG_VAR(var) std::cout << #var" :\t" << var << std::endl;

Level* getLevel();
ServerNetworkHandler* getServerNetworkHandler();
class NetworkHandler* getNetworkHandler();
class Recipes* getRecipes();
#pragma once

template <typename T>
struct WeakPtr {
	T** ptr;
};

template <typename T>
struct SharedPtr {
	T** ptr;
};

Level* getLevel();
class Recipes* getRecipes();


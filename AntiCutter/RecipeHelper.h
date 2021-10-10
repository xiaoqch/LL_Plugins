#pragma once


class Recipes;
class Recipe;
class ShapelessRecipe;
class RecipeIngredient;
class ItemDescriptor;
class Recipes* getRecipes();

inline ShapelessRecipe* getCutterRecipeFor(ItemInstance& item) {
    auto htag = HashedString("stonecutter");
    auto recipe = SymCall("?getRecipeFor@Recipes@@QEBAPEAVRecipe@@AEBVItemInstance@@AEBVHashedString@@@Z",
        Recipe*, Recipes*, ItemInstance&, HashedString&)(getRecipes(), item, htag);
    return (ShapelessRecipe*)recipe;
}

inline RecipeIngredient* getIngredientForCutter(ShapelessRecipe* recipe) {
    return SymCall("?getIngredient@ShapelessRecipe@@UEBAAEBVRecipeIngredient@@HH@Z",
        RecipeIngredient*, ShapelessRecipe*, int, int)(recipe, 0, 0);
}

inline size_t getIngredientCount(RecipeIngredient* ingredient) {
    return SymCall("?getStackSize@ItemDescriptorCount@@QEBAFXZ", size_t, RecipeIngredient*)(ingredient);
}

inline ItemDescriptor* getDescriptor(RecipeIngredient* ingredient) {
    return (ItemDescriptor*)ingredient;
}

inline vector<ItemInstance> getRecipeOutput(ShapelessRecipe* recipe) {
    if (!recipe)
        return {};
    return dAccess<vector<ItemInstance>>(recipe, 216);
}

inline bool outputMatch(ShapelessRecipe* recipe, ItemInstance* item) {
    auto recipeOutputs = getRecipeOutput(recipe);
    auto& recipeOutput = recipeOutputs.at(0);
    auto recipeCount = getItemCount((ItemStackBase*)&recipeOutput);
    auto itemCount = getItemCount((ItemStackBase*)item);
    return recipeCount == itemCount;
}
inline bool ingredientMatch(ShapelessRecipe* recipe, ItemStack* item) {
    auto ingredient = getIngredientForCutter(recipe);
    auto expectItem = getDescriptor(ingredient);
    char tmp[80] = {};
    auto inputItem = getDescriptor(item, (ItemDescriptor*)tmp);
    auto result = SymCall("?itemsMatch@Recipe@@UEBA_NAEBVItemDescriptor@@0@Z",
        bool, Recipe*, const ItemDescriptor*, const ItemDescriptor*)((Recipe*)recipe, inputItem, expectItem);
    if (!result)
        return result;
    auto expectCount = getIngredientCount(ingredient);
    auto count = getItemCount(item);
    return count >= expectCount;
}
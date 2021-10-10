#include "pch.h"
#include "SymHelper.h"
#include <wangheader/SortItemInstanceIdAux.hpp>
#include "RecipeHelper.h"

//#include <wangheader/TextureUVCoordinateSet.hpp>

using namespace std;
//PotionBrewing
Recipes::Type buildRecipesType(string const& name, char c, int aux, unsigned short count) {
    Recipes::Type type = {};
    Item* item = ItemRegistry::lookupByName(name);
    if (!item)
        throw("Item " + name + " Not Exists");
    type.ingredient = SymCall("??0ItemDescriptorCount@@QEAA@AEBVItem@@HG@Z",
        ItemDescriptorCount&, ItemDescriptorCount&, Item*, int, unsigned int)(type.ingredient, item, aux, count);
    assert(type.ingredient.descriptor.aux == aux);
    assert(type.ingredient.count == count);
    type.c = c;
    return type;
}


struct voids {
    void****** v[1000];
};

void testRexipes(Recipes* recipes) {
    auto b = (voids*)recipes;
    map<HashedString, std::map<string, std::shared_ptr<Recipe>>> tag_identifier_recipe =
        dAccess<map<HashedString, std::map<string, std::shared_ptr<Recipe>>>>(recipes, 16);
    int total_size_of_tag_identifier_recipe = 0;
    for (auto& recipe : tag_identifier_recipe) {
        total_size_of_tag_identifier_recipe += recipe.second.size();
    }
    map<Recipes::FurnaceRecipeKey const, ItemInstance>& furnace_recipes =
        dAccess<map<Recipes::FurnaceRecipeKey const, ItemInstance>>(recipes, 32);
    for (auto recipe = furnace_recipes.begin(); recipe != furnace_recipes.end();) {
        if (recipe->first.id == -365) {
            recipe = furnace_recipes.erase(recipe);
        }
        else {
            ++recipe;
        }
    }
    map<ItemInstance, unordered_map<string, Recipe*>> item_identifier_recipe =
        dAccess<map<ItemInstance, unordered_map<string, Recipe*>>>(recipes, 56);
    int total_size_of_item_identifier_recipe = 0;
    for (auto& recipe : item_identifier_recipe) {
        total_size_of_item_identifier_recipe += recipe.second.size();
    }
    unordered_map<TypedServerNetId, Recipe*> unk4 =
        dAccess<unordered_map<TypedServerNetId, Recipe*>>(recipes, 72);
    unordered_set<string> unkset = dAccess<unordered_set<string>>(recipes, 136);
    Recipe& recipe = *unk4.begin()->second;
    auto& id = recipe.unk40;
    auto s = id.begin()->first;
    auto s2 = id.begin()->second;
    auto& getid = recipe.getId();
    HashedString hstr = HashedString("crafting_table");
    for (auto& recipes : recipes->recipes) {
        if (recipes.first.getString() == "crafting_table") {
            auto b = recipes.second.find("minecraft:iron_block");
            if (b != recipes.second.end()) {
                string str = b->second->getIngredient(0, 0)->descriptor.getSerializedNameAndAux();
                cout << str << endl;
            }
        }
    }

    return;
}

void dynReg() {
    auto recipes = getRecipes();
    //testRexipes(recipes);

    auto itemIns = *newItem("minecraft:command_block", 1);
    //setItemName(itemIns, "自定义铁块");
    vector<ItemInstance> outputItems;
    outputItems.push_back(itemIns);

    vector<string> shapeMatrix;
    shapeMatrix.push_back("AAA");
    shapeMatrix.push_back("A A");
    shapeMatrix.push_back("AAA");

    vector<HashedString> craftingTags;
    craftingTags.push_back("crafting_table");

    vector<Recipes::Type> types;

    auto type = buildRecipesType("minecraft:iron_ingot", 'A', 1, 0x7fff);
    string identifier = "custom::custom_test";

    types.push_back(type);
    int priority = 2;
    registerCreativeItem(itemIns);
    recipes->addShapedRecipe(identifier, outputItems, shapeMatrix, types, craftingTags, priority, nullptr);
}


#include "pch.h"
#include "TestRegRecipe.h"
#include <MC/Level.hpp>
#include <MC/ItemStack.hpp>
#include <MC/ItemInstance.hpp>
#include <MC/HashedString.hpp>
#include <MC/Recipes.hpp>
static_assert(offsetof(RecipeIngredient, count) == 72);
//static_assert(offsetof(RecipeIngredient, pad74) == 74);
static_assert(sizeof(RecipeIngredient) == 80);
static_assert(sizeof(ItemDescriptor) == 72);
static_assert(offsetof(Recipes::Type, label) == 96);
static_assert(sizeof(Recipes::Type) == 104);

void testRegRecipe()
{
    auto& recipes = Global<Level>->getRecipes();
    //testRexipes(recipes);
    auto tmpItem = ItemStack::create("minecraft:command_block", 1);
    auto itemIns = ItemInstance(*tmpItem);
    delete tmpItem;
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
    types.emplace_back("minecraft:iron_ingot", 'A', 0x7fff, 1);
    logger.info(types[0].toDebugString());
    string identifier = "custom::custom_test";

    int priority = 2;
    //registerCreativeItem(itemIns);
    recipes.addShapedRecipe(identifier, outputItems, shapeMatrix, types, craftingTags, priority, nullptr);
}
//struct voids {
//    void**** filler[100];
//};
//THook(void, "?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
//    Recipes* _this,
//    std::string identifier,
//    std::vector<class ItemInstance> const& outputItems,
//    std::vector<std::string> const& shapeMatrix,
//    std::vector<class Recipes::Type> const& types,
//    std::vector<class HashedString> const& craftingTags,
//    int priority,
//    class std::function<std::unique_ptr<class ShapedRecipe>(std::string, int, int, std::vector<class RecipeIngredient> const&, std::vector<class ItemInstance> const&, class HashedString)> callback) {
//    auto a = (voids*)&types[0];
//    logger.info("\nidentifier: {}\noutputItems: {}\nshapeMatrix: {}\ntypes: {}\ncraftingTags: {}\npriority: {}\ncallback: {}",
//        identifier, outputItems[0].toDebugString(), shapeMatrix.size(), types[0].toDebugString(), craftingTags[0].getString(), priority, (void*)&callback);
//    return original(_this, identifier, outputItems, shapeMatrix, types, craftingTags, priority, callback);
//}
#include "pch.h"
#include <mc/OffsetHelper.h>
#include <mc/Item.h>
#include <unordered_set>
#include "SymHelper.h"
#include <seh_exception/seh_exception.hpp>
#include <nbt-from-lxl/NBT.h>

bool loadFirst = true;
using namespace std;


class SemVersion {
    unsigned short major{}, minor{}, patch{}; // 0, 2, 4
    std::string    s8, s40, s72;              // 8, 40, 72
    bool           b104{}, valid{}, b106{};   // 104, 105, 106
};

class ItemInstance {
    void* filler[17];
};
class ShapedRecipe {
    void* filler[256 / 8 + 1];
};

struct ItemDescriptor {
    void* weakptr_item;
    void* unk8;
    void* unk16;
    Block* block;
    int16_t aux;
    byte unk34;
    byte unk35; //need _resolveImpl
    char unk36[4];
    string* unk40;
    void* unk48;
    void* unk56;
    int64_t unk64;//block 15,
};
struct ItemDescriptorCount {
    ItemDescriptor descriptor;
    unsigned short count;
};
typedef ItemDescriptorCount RecipeIngredient;
class ShapelessRecipe;
typedef function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> AddShapedRecipeCallback_t;
class Recipes {
public:
    struct FurnaceRecipeKey {
        short aux;
        short id;
        int unk;
        HashedString tag;
    };
    struct Type {
        void* suffix[2];
        RecipeIngredient ingredient;
        char type;
    };
    void addShapedRecipe(string, vector<ItemInstance> const&, vector<string> const&, vector<Recipes::Type> const&, vector<HashedString> const&, int, AddShapedRecipeCallback_t) {};
    void addShapedRecipe(string, ItemInstance const&, string const&, string const&, string const&, vector<Recipes::Type> const&, vector<HashedString> const&, int, AddShapedRecipeCallback_t) {};
    void addShapedRecipe(string, ItemInstance const&, string const&, string const&, vector<Recipes::Type> const&, vector<HashedString> const&, int, AddShapedRecipeCallback_t) {};
    void addShapedRecipe(string, ItemInstance const&, string const&, vector<Recipes::Type> const&, vector<HashedString> const&, int, AddShapedRecipeCallback_t) {};
    void addShapedRecipe(string, ItemInstance const&, vector<string> const&, vector<Recipes::Type> const&, vector<HashedString> const&, int, AddShapedRecipeCallback_t) {};
    void addShapelessRecipe(string, ItemInstance const&, vector<Recipes::Type> const&, vector<HashedString> const&, int, function<unique_ptr<ShapelessRecipe>(string, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)>) {};
    void addShulkerBoxRecipe(string&, ItemInstance const&, vector<Recipes::Type> const&, vector<HashedString> const&) {};

};

struct strSpan {
    size_t size;
    char const* str;
};

ItemStack* Raw_NewItem()
{
    try
    {
        ItemStack* a = (ItemStack*) new char[272];
        ItemStack* item = SymCall("??0ItemStack@@QEAA@XZ", ItemStack*, ItemStack*)(a);
        return item;
    }
    catch (...)
    {
        return nullptr;
    }
}

ItemStack* Raw_NewItem(Tag* tag)
{
    ItemStack* item = Raw_NewItem();
    if (!item)
        return nullptr;
    tag->setItem(item);

    return item;
}
ItemStack* Raw_NewItem(std::string type, int count)
{
    Tag* nbt = Tag::createTag(TagType::Compound);
    nbt->putByte("WasPickedUp", 0);
    nbt->putShort("Damage", 0);
    nbt->putString("Name", type);
    nbt->putByte("Count", count);

    return Raw_NewItem(nbt);
}

bool JrParse(void* jr, string str, void* jv) {
    return SymCall("?parse@Reader@Json@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVValue@2@_N@Z",
        bool, void*, string&, void*, bool)(jr, str, jv, true);
}
string toStyledString(void* jv) {
    string str;
    return SymCall("?toStyledString@Value@Json@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        string&, void*, string&)(jv, str);
}
SemVersion semVersionFromString(string str) {
    SemVersion sv;
    SymCall("?fromString@SemVersion@@SA?AW4MatchType@1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV1@W4ParseOption@1@@Z",
        SemVersion&, string&, SemVersion&, bool)(str, sv, false);
    return sv;
}


//Recipes::loadRecipe(std::pair<string ,Json::Value> const &,SemVersion const &)
THook(bool, "?loadRecipe@Recipes@@QEAA_NAEBU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VValue@Json@@@std@@AEBVSemVersion@@@Z",
    Recipes* _this, std::pair <string, void* [2]> a1, SemVersion& sv) {
    if (!loadFirst)
        return original(_this, a1, sv);
    loadFirst = false;
    auto rtn = original(_this, a1, sv);

    // only first;
    auto recipe = std::pair <string, void* [2]>();
    recipe.first = "recipe_shaped";
    void* jr[24] = {};
    auto pres = JrParse(jr,
        //"{\"description\": {\"identifier\": \"minecraft:command_block\"},\"tags\": [\"crafting_table\"],\"pattern\": [\"AAA\",\"A A\",\"AAA\"],\"key\": {\"A\": {\"item\": \"iron_ignot\"}},\"result\": {\"item\": \"command_block\" , },\"priority\": 2}",
        "{\"description\": {\"identifier\": \"minecraft:custom_command_block\"},\"tags\": [\"crafting_table\"],\"pattern\": [\"AAA\",\"A A\",\"AAA\"],\"key\": {\"A\": {\"item\": \"iron_ingot\"}},\"result\": {\"item\": \"command_block\",\"lore\": \"string\"},\"priority\": 2}",
        recipe.second);
    auto ver = semVersionFromString("1.16");

    auto res = original(_this, recipe, ver);
    return rtn;
}
ItemInstance _itemInstanceFromIngredient(RecipeIngredient const* ingredient) {
    ItemInstance item;
    return SymCall("?_itemInstanceFromIngredient@Recipes@@AEBA?AVItemInstance@@AEBVRecipeIngredient@@@Z",
        ItemInstance&, Recipes*, ItemInstance&, RecipeIngredient const*)(nullptr, item, ingredient);
}

string itemInsToString(ItemInstance const& item) {
    string str;
    SymCall("?toString@ItemStackBase@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        string&, ItemInstance const&, string&)(item, str);
    return str;
}
void setItemInsName(ItemInstance const& item, string name) {
    SymCall("?setCustomName@ItemStackBase@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        void, ItemInstance const&, string&)(item, name);
}

struct UUID {
    uint64_t a, b;
};

ShapedRecipe newShapedRecipe(string& identifier, int row, int column, vector<RecipeIngredient> const& ings, vector<ItemInstance> const& outputItems, HashedString& craftingTags, int priority) {
    ShapedRecipe recipe = {};
    UUID voidUUID = { 0,0 };
    strSpan idspan = { identifier.length(), identifier.c_str() };
    // 	bedrock_server_mod.exe!ShapedRecipe::ShapedRecipe(class gsl::basic_string_span<char const ,-1>,int,int,class std::vector<class RecipeIngredient> const &,class std::vector<class ItemInstance> const &,class HashedString,int,class mce::UUID const *)
    return SymCall("??0ShapedRecipe@@QEAA@V?$basic_string_span@$$CBD$0?0@gsl@@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@4@VHashedString@@HPEBVUUID@mce@@@Z",
        ShapedRecipe&, ShapedRecipe const& _this, strSpan idspan, int row, int column, vector<RecipeIngredient> const& ings,
        vector<ItemInstance>const& outputItems, HashedString craftingTags, int priority, UUID & voidUUID)(
            recipe, idspan, row, column, ings, outputItems, craftingTags, priority, voidUUID
            );
}
//ShapedRecipe::ShapedRecipe(gsl::basic_string_span<char const,-1>,int,int,std::vector<RecipeIngredient> const &,std::vector<ItemInstance> const &,HashedString,int,mce::UUID const *)
THook(ShapedRecipe*, "??0ShapedRecipe@@QEAA@V?$basic_string_span@$$CBD$0?0@gsl@@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@4@VHashedString@@HPEBVUUID@mce@@@Z",
    ShapedRecipe* _this, strSpan identifier, int row, int column, vector<RecipeIngredient>& ings, vector<ItemInstance>& items, HashedString craftingTags, int priority, UUID const* voidUUID) {
    auto rtn = original(_this, identifier, row, column, ings, items, craftingTags, priority, voidUUID);
    return _this;
}

THook(void, "?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
    Recipes* _this, string identifier, vector<ItemInstance>* outputItems, vector<string> const& shapeMatrix,
    vector<Recipes::Type> const* types, vector<HashedString> const* craftingTags, int priority,
    function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance>&, HashedString)> func) {
    assert(craftingTags->size() == 1);
    auto& a = outputItems->at(0);
    assert(outputItems->size() == 1);
    uint64_t unk = dAccess<uint64_t>(&types->at(0), 10 * 8);
    //auto biptr = dAccess<void*>(&types->at(0), 2*8);
    size_t s = sizeof(RecipeIngredient);
    class BlockItem;
    auto bi = SymCall("?get@?$WeakPtr@VBlockLegacy@@@@QEBAPEAVBlockLegacy@@XZ",
        BlockItem*, void*)((void**)&types->at(0) + 2);

    string str;
    try {
        //if(bi&&count<44)
        //    SymCall("?buildDescriptionName@Item@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemStackBase@@@Z",
        //        string&, BlockItem*, string&)(bi, str);
    }
    catch (seh_exception& e) {

    }
    catch (...) {

    }
    Block* bl = dAccess<Block*>(&types->at(0), 5 * 8);
    if (bl)
        string blstr = offBlock::getFullName(bl);
    //cout << itemInsToString(outputItems->at(0)) << endl;

    if (identifier == "minecraft:custom_command_block")
        setItemInsName(outputItems->at(0), "AAAAA");
    auto& working_block = craftingTags->at(0).getString();

    ////AddShapedRecipeCallback_t* func
    //auto fakeFunc = [&func, priority](string identifier, int row, int column, vector<RecipeIngredient> const& ingredients, vector<ItemInstance>& outputItems, HashedString craftingTags) -> unique_ptr<ShapedRecipe> {
    //    cout << itemInsToString(outputItems.at(0)) << endl;
    //    if (!func) {
    //        for (auto& ing : ingredients) {
    //            int count = dAccess<unsigned short>(&ing, 72);
    //            string name;
    //            SymCall("?getSerializedNameAndAux@ItemDescriptor@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
    //                string&, RecipeIngredient const&, string&)(ing, name);
    //            cout << "\t" << name << ": " << count << endl;
    //        }
    //        //if(*(void**)&ingredients.at(0)!=nullptr)
    //        //outputItems.push_back(_itemInstanceFromIngredient(&ingredients.at(0)));
    //        auto recipe = newShapedRecipe(identifier, row, column, ingredients, outputItems, craftingTags, priority);
    //        return make_unique<ShapedRecipe>(recipe);
    //    }
    //    else {
    //        return func(identifier, row, column, ingredients, outputItems, craftingTags);
    //    }
    //};
    return original(_this, identifier, outputItems, shapeMatrix, types, craftingTags, priority, func);

}

BlockLegacy* getBlockLegacy(string const& name) {
    auto btli = SymCall("?getBlockTypeLegacyIdFromName@VanillaBlockConversion@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        int, string const&)(name);
    class BlockType* bt = (BlockType*)new char[1];
    bt = SymCall("?getBlockTypeFromLegacyId@VanillaBlockConversion@@YA?AV?$WeakPtr@VBlockLegacy@@@@I@Z",
        BlockType*, BlockType*, int)(bt, btli);

    BlockLegacy* bl = SymCall("?get@?$WeakPtr@VBlockLegacy@@@@QEBAPEAVBlockLegacy@@XZ",
        BlockLegacy*, BlockType*)(bt);
    return bl;
}

Recipes::Type newRecipesType(string const& name, char t, int count, int aux) {
    Recipes::Type type = {};
    BlockLegacy* bl = getBlockLegacy(name);
    type.ingredient.descriptor = SymCall("??0ItemDescriptor@@QEAA@AEBVBlockLegacy@@@Z",
        ItemDescriptor&, ItemDescriptor&, BlockLegacy*)(type.ingredient.descriptor, bl);
    type.ingredient.descriptor.aux = aux;
    type.ingredient.count = count;
    type.type = t;
    return type;
}
ItemInstance& newItemIns(ItemInstance& itemIns, string const& name, int count = 1, int aux = 0) {
    //GetInteractionPositionForBlockNode::parseFacingNameFromString
    itemIns = *(ItemInstance*)Raw_NewItem(name, count);
    return itemIns;
}
class Recipe;//160 HashedKey
class SortItemInstanceIdAux {
public:
    bool operator()(ItemInstance const& left, ItemInstance const& right) {
        return SymCall("??RSortItemInstanceIdAux@@QEBA_NAEBVItemInstance@@0@Z",
            bool, ItemInstance const&, ItemInstance const&)(left, right);
    }
};

//enum TypedServerNetId<RecipeNetIdTag, unsigned int, 0>{};
typedef unsigned int TypedServerNetId;
void dynReg() {
    auto recipes = SymCall("?getRecipes@Level@@UEBAAEAVRecipes@@XZ",
        Recipes*, Level*)(getLevel());
    map<HashedString, std::map<string, std::shared_ptr<Recipe>>> tag_identifier_recipe =
        dAccess<map<HashedString, std::map<string, std::shared_ptr<Recipe>>>>(recipes, 16);
    int total_size_of_tag_identifier_recipe = 0;
    for (auto& recipe : tag_identifier_recipe) {
        total_size_of_tag_identifier_recipe += recipe.second.size();
    }
    map<Recipes::FurnaceRecipeKey const, ItemInstance>& furnace_recipes =
        dAccess<map<Recipes::FurnaceRecipeKey const, ItemInstance>>(recipes, 32);
    for (auto recipe = furnace_recipes.begin(); recipe != furnace_recipes.end();) {
        auto output = itemInsToString(recipe->second);
        cout << output << endl;
        if (recipe->first.id == -365) {
            recipe = furnace_recipes.erase(recipe);

            cout << "Remove: " << output << endl;
        }
        else {
            ++recipe;
        }
    }
    map<ItemInstance, unordered_map<string, Recipe*>, SortItemInstanceIdAux>        item_identifier_recipe =
        dAccess<map<ItemInstance, unordered_map<string, Recipe*>, SortItemInstanceIdAux>>(recipes, 56);
    int total_size_of_item_identifier_recipe = 0;
    for (auto& recipe : item_identifier_recipe) {
        total_size_of_item_identifier_recipe += recipe.second.size();
    }
    unordered_map<TypedServerNetId, Recipe*> unk4 =
        dAccess<unordered_map<TypedServerNetId, Recipe*>>(recipes, 72);
    unordered_set<string> unkset = dAccess<unordered_set<string>>(recipes, 136);
    std::_Hash_vec<std::allocator<std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<enum FilterSubject const, string>>>>>>
        unk95;
    vector<ItemInstance> outputItems;;
    ItemInstance itemIns = {};
    newItemIns(itemIns, "minecraft:iron_ingot", 1, 0);
    setItemInsName(itemIns, "自定义铁块");
    outputItems.push_back(itemIns);
    vector<string> shapeMatrix;
    shapeMatrix.push_back("A A");
    shapeMatrix.push_back(" A ");
    shapeMatrix.push_back("A A");
    vector<HashedString> craftingTags;
    craftingTags.push_back("crafting_table");
    vector<Recipes::Type> types;
    auto type = newRecipesType("command_block", 'A', 1, 0x7fff);


    types.push_back(type);
    SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
        void, Recipes * _this, string identifier, vector<ItemInstance> const& outputItems, vector<string> const& shapeMatrix,
        vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        AddShapedRecipeCallback_t func)(
            recipes, "custom:dynamic_register", outputItems, shapeMatrix, types, craftingTags, 2, nullptr);
    cout << itemInsToString(itemIns) << endl;;
}

//THook(void , "?onConnectionClosed@NetworkHandler@@EEAAXAEBVNetworkIdentifier@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z",
//    NetworkHandler* nh, NetworkIdentifier const* nid, string const& str, bool b) {
//    string ip;
//    ip = SymCall("?getAddress@NetworkIdentifier@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
//        string&, NetworkIdentifier const*, string&)(nid, ip);
//    
//    original(nh, nid, str, b);
//}


THook(Item*, "?useTimeDepleted@SpyglassItem@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class FoodItemComponentLegacy* _this, ItemStack* item, Player* player, Level* level) {
    cout << "SpyglassItem" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}

THook(Item*, "?useTimeDepleted@SuspiciousStewItem@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class FoodItemComponentLegacy* _this, ItemStack* item, Player* player, Level* level) {
    cout << "SuspiciousStewItem" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}
THook(Item*, "?useTimeDepleted@ComponentItem@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class FoodItemComponentLegacy* _this, ItemStack* item, Player* player, Level* level) {
    cout << "ComponentItem" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}

THook(Item*, "?useTimeDepleted@PotionItem@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class PotionItem* _this, ItemStack* item, Player* player, Level* level) {
    cout << "PotionItem" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}
THook(Item*, "?useTimeDepleted@Item@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class FoodItemComponentLegacy* _this, ItemStack* item, Player* player, Level* level) {
    cout << "Item" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}
THook(Item*, "?useTimeDepleted@ItemStack@@QEAA?AW4ItemUseMethod@@PEAVLevel@@PEAVPlayer@@@Z",
    ItemStack* _this, Level* level,  Player* player) {
    auto v5 = dAccess<void**, 8>(_this);
    auto v6 = *v5;
    if (v5 && (v6 = *v5) != 0) {
        cout << "a" << endl;
    }
    cout << "ItemStack" << endl;
    auto rtn = original(_this, level, player);

    return rtn;
}


THook(Item*, "?useTimeDepleted@FoodItemComponent@@UEAAPEBVItem@@AEAVItemStack@@AEAVPlayer@@AEAVLevel@@@Z",
    class FoodItemComponent* _this, ItemStack* item, Player* player, Level* level) {
    cout << "FoodItemComponent" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}

THook(Item*, "?useTimeDepleted@MedicineItem@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class FoodItemComponent* _this, ItemStack* item, Level* level, Player* player) {
    cout << "MedicineItem" << endl;
    auto rtn = original(_this, item, level, player);

    return rtn;
}

THook(Item*, "?useTimeDepleted@BucketItem@@UEBA?AW4ItemUseMethod@@AEAVItemStack@@PEAVLevel@@PEAVPlayer@@@Z",
    class FoodItemComponent* _this, ItemStack* item, Level* level, Player* player) {
    cout << "BucketItem" << endl;
    auto rtn = original(_this, item, level, player);

    return rtn;
}
THook(Item*, "?useTimeDepleted@FoodItemComponentLegacy@@UEAAPEBVItem@@AEAVItemStack@@AEAVPlayer@@AEAVLevel@@@Z",
    class FoodItemComponent* _this, ItemStack* item, Player* player, Level* level) {
    cout << "FoodItemComponentLegacy" << endl;
    auto rtn = original(_this, item, player, level);

    return rtn;
}
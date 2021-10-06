#include "pch.h"
#include "RecipeHelper.h"
#include "SymHelper.h"
#include <unordered_set>
#include <wangheader/SortItemInstanceIdAux.hpp>
#include <mc/Item.h>
#include <mc/OffsetHelper.h>
//#include <wangheader/BlockReducer.hpp>

using namespace std;

class UUID {
public:
    std::uint64_t a = 0, b = 0;
};

class SemVersion {
    unsigned short major{}, minor{}, patch{}; // 0, 2, 4
    std::string    s8, s40, s72;              // 8, 40, 72
    bool           b104{}, valid{}, b106{};   // 104, 105, 106
};

typedef unsigned int TypedServerNetId;

class ItemInstance : ItemStackBase {};

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
    size_t __cdecl operator()(const ItemDescriptor* item)
    {
        return SymCall("??4ItemDescriptor@@QEAAX$$QEAV0@@Z",
            size_t, const ItemDescriptor*, const ItemDescriptor*)(this, item);
    }
    bool __cdecl operator==(const ItemDescriptor* item)
    {
        return SymCall("??8ItemDescriptor@@QEBA_NAEBV0@@Z",
            bool, const ItemDescriptor*, const ItemDescriptor*)(this, item);
    }
    string getSerializedNameAndAux() {
        string name;
        return SymCall("?getSerializedNameAndAux@ItemDescriptor@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
            string&, ItemDescriptor*, string&)(this, name);
    }
};
struct ItemDescriptorCount {
    ItemDescriptor descriptor;
    unsigned short count;
};
typedef ItemDescriptorCount RecipeIngredient;
class ShapelessRecipe;

class Recipe {
public:
    //void* vbtl;
    string RecipeId; // 8
    unordered_map<ItemDescriptor, int> unk40; //40, Unknown hasher
    UUID MyId; // 104
    int width; // 120
    int height; // 124
    int Priority; // 128
    int unk132; // 132
    vector<RecipeIngredient> MyIngredients; //136
    HashedString Tag; //160
    /*
        [0]	    0x00007ff777c50100 {bedrock_server_mod.exe!ShapedRecipe::`vector deleting destructor'(unsigned int)}	void *
		[1]	    0x00007ff77777a440 {bedrock_server_mod.exe!ShapedRecipe::assemble(class CraftingContainer &)const }	void *
		[2]	    0x00007ff777c6e310 {bedrock_server_mod.exe!ShapedRecipe::getCraftingSize(void)const }	void *
		[3]	    0x00007ff777c6e7b0 {bedrock_server_mod.exe!ShapedRecipe::getIngredient(int,int)const }	void *
		[4]	    0x00007ff77777a440 {bedrock_server_mod.exe!ShapedRecipe::assemble(class CraftingContainer &)const }	void *
		[5]	    0x00007ff776d61cd0 {bedrock_server_mod.exe!std::_Func_impl_no_alloc<<lambda_995a056c8a5cc3e83f32a8a5337a6e7a>,bool,Bedrock::JSONObject::ValueWrapper &>::_Do_call(void)}	void *
		[6]	    0x00007ff777c767f0 {bedrock_server_mod.exe!ShapedRecipe::matches(class CraftingContainer &,class Level &)const }	void *
		[7]	    0x00007ff777c77c50 {bedrock_server_mod.exe!ShapedRecipe::size(void)const }	void *
		[8]	    0x00007ff77721b8e0 {bedrock_server_mod.exe!MobSpawnRules::getHerdListMutable(void)}	void *
		[9]	    0x00007ff777186680 {bedrock_server_mod.exe!BlockVolumeTarget::getContext(void)}	void *
		[10]	0x00007ff776d61cd0 {bedrock_server_mod.exe!std::_Func_impl_no_alloc<<lambda_995a056c8a5cc3e83f32a8a5337a6e7a>,bool,Bedrock::JSONObject::ValueWrapper &>::_Do_call(void)}	void *
		[11]	0x00007ff777c714f0 {bedrock_server_mod.exe!Recipe::itemValidForRecipe(class ItemDescriptor const &,class ItemStack const &)const }	void *
		[12]	0x00007ff777c716a0 {bedrock_server_mod.exe!Recipe::itemsMatch(class ItemDescriptor const &,int,int,class CompoundTag const *)const }	void *
		[13]	0x00007ff777c71600 {bedrock_server_mod.exe!Recipe::itemsMatch(class ItemDescriptor const &,class ItemDescriptor const &,class CompoundTag const *)const }	void *
		[14]	0x00007ff777c71590 {bedrock_server_mod.exe!Recipe::itemsMatch(class ItemDescriptor const &,class ItemDescriptor const &)const }	void *
		[15]	0x00007ff777c73730 {bedrock_server_mod.exe!ShapedRecipe::loadResultList(class BlockPalette const &)const }	void *
    */
    virtual ~Recipe();
    virtual class std::vector<class ItemInstance, class std::allocator<class ItemInstance> > const& assemble(class CraftingContainer&);
    virtual int getCraftingSize(void);
    virtual RecipeIngredient* getIngredient(int, int)const;
    virtual void unk_vfn_4();
    virtual void unk_vfn_5();
    virtual bool matches(class CraftingContainer&, class Level&);
    virtual int size(void);
    virtual class mce::UUID const& getId(void);
    virtual void unk_vfn_9();
    virtual void unk_vfn_10();
    virtual bool itemValidForRecipe(class ItemDescriptor const&, class ItemStack const&);
    virtual bool itemsMatch(class ItemDescriptor const&, int, int, class CompoundTag const*);
    virtual bool itemsMatch(class ItemDescriptor const&, class ItemDescriptor const&, class CompoundTag const*);
    virtual bool itemsMatch(class ItemDescriptor const&, class ItemDescriptor const&);
    virtual void* loadResultList(class BlockPalette const&)const;
};//160


class ShapedRecipe :Recipe {
    void* filler[256 / 8 + 1 - sizeof(Recipe) / 8];
    
};

class BlockReducer {
    std::unordered_map<int, std::vector <ItemStack>> items;

    virtual ~BlockReducer();
    virtual void registerBlock(class ItemStack const&, class std::vector<class ItemStack, class std::allocator<class ItemStack> >&&);

};

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

    void* ResourcePackManager;
    BlockReducer* reducer;
    map<HashedString, std::map<string, std::shared_ptr<Recipe>>> recipes; // 16
    map<Recipes::FurnaceRecipeKey const, ItemInstance> furnaceRecipes; // 32
    bool initializing;// 48
    map<ItemInstance, unordered_map<string, Recipe*>, SortItemInstanceIdAux> recipesByOutput; //56
    unordered_map<TypedServerNetId, Recipe*> unk72; // 72
    unordered_set<string> identifiers; // 136

    void addShapedRecipe(string identifier, vector<ItemInstance> const& outputItems, vector<string> const& shapeMatrix, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, vector<ItemInstance> const& outputItems, vector<string> const& shapeMatrix,
            vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func)(
                this, identifier, outputItems, shapeMatrix, types, craftingTags, priority, func);
    };
    void addShapedRecipe(string identifier, ItemInstance const& outputItem, string const& row1, string const& row2, string const& row3, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV23@22AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, string const& row1, string const& row2, string const& row3, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func)(
                this, identifier, outputItem, row1, row2, row3, types, craftingTags, priority, func);
    };
    void addShapedRecipe(string identifier, ItemInstance const& outputItem, string const& row1, string const& row2, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV23@2AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, string const& row1, string const& row2, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func)(
                this, identifier, outputItem, row1, row2, types, craftingTags, priority, func);
    };
    void addShapedRecipe(string identifier, ItemInstance const& outputItem, string const& row1, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV23@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, string const& row1, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func)(
                this, identifier, outputItem, row1, types, craftingTags, priority, func);
    };
    void addShapedRecipe(string identifier, ItemInstance const& outputItem, vector<string> const& shapeMatrix, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes* _this, string identifier, ItemInstance const& outputItem, vector<string> const& shapeMatrix, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTag, int priority,
            function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func)(
                this, identifier, outputItem, shapeMatrix, types, craftingTags, priority, func);
    };
    void addShapelessRecipe(string identifier, ItemInstance const& outputItem, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
        function<unique_ptr<ShapelessRecipe>(string, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            function<unique_ptr<ShapelessRecipe>(string, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> func)(
                this, identifier, outputItem, types, craftingTags, priority, func);
    };
    void addShulkerBoxRecipe(string& identifier, ItemInstance const& outputItem, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags) {
        SymCall("?addShapelessRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapelessRecipe@@U?$default_delete@VShapelessRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@AEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string & identifier, ItemInstance const& outputItem, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags)(
                this, identifier, outputItem, types, craftingTags);
    };

};

struct strSpan {
    size_t size;
    char const* str;
};


Recipes::Type newRecipesType(string const& name, char t, int count, int aux) {
    Recipes::Type type = {};
    BlockLegacy* bl = {};// = getBlockLegacy(name);
    type.ingredient.descriptor = SymCall("??0ItemDescriptor@@QEAA@AEBVBlockLegacy@@@Z",
        ItemDescriptor&, ItemDescriptor&, BlockLegacy*)(type.ingredient.descriptor, bl);
    type.ingredient.descriptor.aux = aux;
    type.ingredient.count = count;
    type.type = t;
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
    map<ItemInstance, unordered_map<string, Recipe*>, SortItemInstanceIdAux>        item_identifier_recipe =
        dAccess<map<ItemInstance, unordered_map<string, Recipe*>, SortItemInstanceIdAux>>(recipes, 56);
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
}

void dynReg() {
    auto recipes = getRecipes();
    testRexipes(recipes);

    HashedString hstr = HashedString("crafting_table");
    for (auto& recipes : recipes->recipes) {
        if (recipes.first.getString() == "crafting_table") {
            auto b = recipes.second.find("minecraft:iron_block");
            if (b != recipes.second.end()){
                string str = b->second->getIngredient(0, 0)->descriptor.getSerializedNameAndAux();
                cout << str << endl;
            }
        }
    }
    
    return;
    ItemInstance itemIns = {};
    //newItemIns(itemIns, "minecraft:iron_ingot", 1, 0);
    //setItemInsName(itemIns, "×Ô¶¨ÒåÌú¿é");
    vector<ItemInstance> outputItems;
    outputItems.push_back(itemIns);

    vector<string> shapeMatrix;
    shapeMatrix.push_back("A A");
    shapeMatrix.push_back(" A ");
    shapeMatrix.push_back("A A");

    vector<HashedString> craftingTags;
    craftingTags.push_back("crafting_table");
    vector<Recipes::Type> types;

    auto type = newRecipesType("command_block", 'A', 1, 0x7fff);
    string identifier = "custom::custom_test";

    types.push_back(type);
    int priority = 2;
    recipes->addShapedRecipe(identifier, outputItems, shapeMatrix, types, craftingTags, priority, nullptr);
    //auto desc = r->MyIngredients.at(0).descriptor;
    //cout << desc.getSerializedNameAndAux() << endl;
}

class FakeValue;
//{
//    void** v;
//    char type;
//};

string seriJson(void* json) {
    string str;
    return SymCall("?serialize@JsonHelpers@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z",
        string&, string&, void*)(str, json);
}

void* parseJson(void* json, string& str) {
    SymCall("?parseJson@JsonHelpers@@YA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVValue@Json@@@Z",
        bool, string&, void*)(str, json);
    return json;
}
//FakeValue& parseJson(string& str) {
//    SymCall("?parseJson@JsonHelpers@@YA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAVValue@Json@@@Z",
//        bool, string&, void*)(str, json);
//    return json;
//}

////Recipes::loadRecipe(std::pair<string ,Json::Value> const &,SemVersion const &)
//THook(bool, "?loadRecipe@Recipes@@QEAA_NAEBU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VValue@Json@@@std@@AEBVSemVersion@@@Z",
//    Recipes* _this, std::pair<string, void*[2]> a1, SemVersion& sv) {
//    auto rtn = original(_this, a1, sv);
//    if (a1.first == "recipe_material_reduction") {
//        return false;
//    }
//    return rtn;
//}


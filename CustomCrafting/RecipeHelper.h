#pragma once
#include <unordered_set>
#include "ItemHelper.h"

typedef ItemDescriptorCount RecipeIngredient;

typedef unsigned int TypedServerNetId;

//#define AddShapedRecipeCallback_t function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)>
//#define AddShaplessRecipeCallback_t function<unique_ptr<ShapelessRecipe>(string, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)>

class UUID {
public:
    std::uint64_t a = 0, b = 0;
};

class SemVersion {
    unsigned short major{}, minor{}, patch{}; // 0, 2, 4
    std::string    s8, s40, s72;              // 8, 40, 72
    bool           b104{}, valid{}, b106{};   // 104, 105, 106
};

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
    virtual class std::vector<ItemInstance> const& assemble(class CraftingContainer&);
    virtual int getCraftingSize(void);
    virtual RecipeIngredient* getIngredient(int, int)const;
    virtual void unk_vfn_4();
    virtual void unk_vfn_5();
    virtual bool matches(CraftingContainer&, class Level&);
    virtual int size(void);
    virtual class mce::UUID const& getId(void);
    virtual void unk_vfn_9();
    virtual void unk_vfn_10();
    virtual bool itemValidForRecipe(ItemDescriptor const&, ItemStack const&);
    virtual bool itemsMatch(ItemDescriptor const&, int, int, class CompoundTag const*);
    virtual bool itemsMatch(ItemDescriptor const&, ItemDescriptor const&, CompoundTag const*);
    virtual bool itemsMatch(ItemDescriptor const&, ItemDescriptor const&);
    virtual void* loadResultList(class BlockPalette const&)const;
};//160

class ShapedRecipe :Recipe {
    void* filler[256 / 8 + 1 - sizeof(Recipe) / 8];

};//264

class ShapelessRecipe : Recipe {
    //void* filler[0x108/8 - sizeof(Recipe) / 8];
    char unk160[208 - 160];// 160
    byte unk208 = byte(1); // 208
    char unk209[7];
    vector<ItemInstance> items; // 216
    void* unk240[3] = { 0,0,0 }; //240
    //pair<enum BlockActorType, const string> 
}; //0x264

class BlockReducer {
    std::unordered_map<int, std::vector <ItemStack>> items;

    virtual ~BlockReducer();
    virtual void registerBlock(class ItemStack const&, class std::vector<class ItemStack, class std::allocator<class ItemStack> >&&);

};

typedef function<unique_ptr<ShapedRecipe>(string, int, int, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> AddShapedRecipeCallback_t;
typedef function<unique_ptr<ShapelessRecipe>(string, vector<RecipeIngredient> const&, vector<ItemInstance> const&, HashedString)> AddShaplessRecipeCallback_t;

class Recipes {
public:
    // 熔炉原料结构
    struct FurnaceRecipeKey {
        short aux;
        short id;
        int unk;
        HashedString tag; // 熔炉类型标签
    };

    // 其他合成原料结构
    struct Type {
        Item* item;
        Block* block;
        RecipeIngredient ingredient;
        char c;
    };

    void* ResourcePackManager;
    BlockReducer* reducer; //材料分解器
    // map<tags , map<identifier, recipe>>
    map<HashedString, map<string, std::shared_ptr<Recipe>>> recipes; // 16
    map<Recipes::FurnaceRecipeKey const, ItemInstance> furnaceRecipes; // 32
    bool initializing;// 48
    // map<output, unorder_map<identifier, recipe>
    map<ItemInstance, unordered_map<string, Recipe*>> recipesByOutput; //56
    unordered_map<TypedServerNetId, Recipe*> unk72; // 72
    unordered_set<string> identifiers; // 136

    /// <summary>
    /// 添加新有形状合成表
    /// </summary>
    /// <param name="identifier">合成表id</param>
    /// <param name="outputItems">合成表输出物品</param>
    /// <param name="shapeMatrix">合成表形状定义</param>
    /// <param name="types">合成表输入定义</param>
    /// <param name="craftingTags">工作台标签</param>
    /// <param name="priority">权重？</param>
    /// <param name="func">未知回调</param>
    void addShapedRecipe(
        string identifier,
        vector<ItemInstance> const& outputItems,
        vector<string> const& shapeMatrix,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags,
        int priority,
        AddShapedRecipeCallback_t func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, vector<ItemInstance> const& outputItems, vector<string> const& shapeMatrix,
            vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            AddShapedRecipeCallback_t func)(
                this, identifier, outputItems, shapeMatrix, types, craftingTags, priority, func);
    };

    void addShapedRecipe(string identifier,
        ItemInstance const& outputItem,
        string const& row1,
        string const& row2,
        string const& row3,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags,
        int priority,
        AddShapedRecipeCallback_t func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV23@22AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, string const& row1, string const& row2, string const& row3, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            AddShapedRecipeCallback_t func)(
                this, identifier, outputItem, row1, row2, row3, types, craftingTags, priority, func);
    };

    void addShapedRecipe(string identifier,
        ItemInstance const& outputItem,
        string const& row1,
        string const& row2,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags,
        int priority,
        AddShapedRecipeCallback_t func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV23@2AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, string const& row1, string const& row2, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            AddShapedRecipeCallback_t func)(
                this, identifier, outputItem, row1, row2, types, craftingTags, priority, func);
    };

    void addShapedRecipe(string identifier,
        ItemInstance const& outputItem,
        string const& row1,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags,
        int priority,
        AddShapedRecipeCallback_t func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV23@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, string const& row1, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            AddShapedRecipeCallback_t func)(
                this, identifier, outputItem, row1, types, craftingTags, priority, func);
    };

    void addShapedRecipe(string identifier,
        ItemInstance const& outputItem,
        vector<string> const& shapeMatrix,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags,
        int priority,
        AddShapedRecipeCallback_t func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem, vector<string> const& shapeMatrix, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTag, int priority,
            AddShapedRecipeCallback_t func)(
                this, identifier, outputItem, shapeMatrix, types, craftingTags, priority, func);
    };

    /// <summary>
    /// 添加无形状合成
    /// </summary>
    /// <param name="identifier">合成id</param>
    /// <param name="outputItem">合成输入物品</param>
    /// <param name="types">合成输入物品</param>
    /// <param name="craftingTags">工作台类型</param>
    /// <param name="priority">权重</param>
    /// <param name="func">未知回调</param>
    void addShapelessRecipe(string identifier,
        ItemInstance const& outputItem,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags,
        int priority,
        AddShaplessRecipeCallback_t func) {
        SymCall("?addShapedRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapedRecipe@@U?$default_delete@VShapedRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@HHAEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string identifier, ItemInstance const& outputItem,
            vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags, int priority,
            AddShaplessRecipeCallback_t func)(
                this, identifier, outputItem, types, craftingTags, priority, func);
    };

    void addShulkerBoxRecipe(string& identifier,
        ItemInstance const& outputItem,
        vector<Recipes::Type> const& types,
        vector<HashedString> const& craftingTags) {
        SymCall("?addShapelessRecipe@Recipes@@QEAAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItemInstance@@AEBV?$vector@VType@Recipes@@V?$allocator@VType@Recipes@@@std@@@3@AEBV?$vector@VHashedString@@V?$allocator@VHashedString@@@std@@@3@HV?$function@$$A6A?AV?$unique_ptr@VShapelessRecipe@@U?$default_delete@VShapelessRecipe@@@std@@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@AEBV?$vector@VRecipeIngredient@@V?$allocator@VRecipeIngredient@@@std@@@2@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@2@VHashedString@@@Z@3@@Z",
            void, Recipes * _this, string & identifier, ItemInstance const& outputItem, vector<Recipes::Type> const& types, vector<HashedString> const& craftingTags)(
                this, identifier, outputItem, types, craftingTags);
    };

    inline Recipe* getRecipeFor(ItemInstance& item, HashedString& tag) {
        return SymCall("?getRecipeFor@Recipes@@QEBAPEAVRecipe@@AEBVItemInstance@@AEBVHashedString@@@Z",
            Recipe*, Recipes*, ItemInstance&, HashedString&)(this, item, tag);
    }
};

void dynReg();
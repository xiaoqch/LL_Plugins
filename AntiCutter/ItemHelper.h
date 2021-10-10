#pragma once
#pragma once
#include <mc/Item.h>
#include <mc/Command.h>

using namespace std;

class ItemInstance : ItemStackBase {};

struct ItemDescriptor {
    void* weakptr_item;
    void* unk8;
    void* unk16;
    Block* block;
    int16_t aux;
    byte unk34; //vaild?
    byte unk35; //need _resolveImpl
    char unk36[4];
    string* unk40;
    void* unk48;
    void* unk56;
    int64_t unk64;//block 15,
    //size_t __cdecl operator()(const ItemDescriptor* item)
    //{
    //    return SymCall("??4ItemDescriptor@@QEAAX$$QEAV0@@Z",
    //        size_t, const ItemDescriptor*, const ItemDescriptor*)(this, item);
    //}
    //bool __cdecl operator==(const ItemDescriptor* item)
    //{
    //    return SymCall("??8ItemDescriptor@@QEBA_NAEBV0@@Z",
    //        bool, const ItemDescriptor*, const ItemDescriptor*)(this, item);
    //}
    inline string getSerializedNameAndAux() {
        string name;
        return SymCall("?getSerializedNameAndAux@ItemDescriptor@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
            string&, ItemDescriptor*, string&)(this, name);
    }
};
struct ItemDescriptorCount {
    ItemDescriptor descriptor;
    unsigned short count;
};

class ItemRegistry {
public:
    static HashedString& getNameFromLegacyID(unsigned short id) {
        HashedString hanme = HashedString("");
        return SymCall("?getNameFromLegacyID@ItemRegistry@@SA?AVHashedString@@F@Z",
            HashedString&, HashedString&, unsigned short)(hanme, id);
    };

    static Item* lookupByName(int64_t& id, unsigned int& aux, string const& name) {
        Item** item;
        auto res = SymCall("?lookupByName@ItemRegistry@@SA?AV?$WeakPtr@VItem@@@@AEAH0AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            Item**&, Item**&, int64_t&, unsigned int&, string const&)(item, id, aux, name);
        if (res && *res)
            return *res;
        return nullptr;
    };
    static Item* lookupByName(unsigned int& aux, string const& name) {
        int64_t id;
        return lookupByName(id, aux, name);
    };
    static Item* lookupByName(string const& name) {
        unsigned int aux;
        return lookupByName(aux, name);
    };
    static Item* lookupByName(HashedString const& name) {
        unsigned int aux;
        return lookupByName(aux, name.getString());
    };
    static Item* lookupByNameNoAlias(string const& nameNoAlias) {
        Item** item;
        auto res = SymCall("?lookupByNameNoAlias@ItemRegistry@@SA?AV?$WeakPtr@VItem@@@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
            Item**&, Item**&, string const&)(item, nameNoAlias);
        if (res && *res)
            return *res;
        return nullptr;
    };
    static Item* lookupByNameNoAlias(HashedString const& nameNoAlias) {
        return lookupByNameNoAlias(nameNoAlias.getString());
    };
};

inline string itemInsToString(ItemInstance const& item) {
    string str;
    SymCall("?toString@ItemStackBase@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        string&, ItemInstance const&, string&)(item, str);
    return str;
}

inline string itemStackToString(ItemStack const& item) {
    string str;
    SymCall("?toString@ItemStack@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
        string&, ItemStack const&, string&)(item, str);
    return str;
}

inline ItemDescriptor* getDescriptor(ItemStackBase* item, ItemDescriptor* descriptor) {
    SymCall("?getDescriptor@ItemStackBase@@QEBA?AVItemDescriptor@@XZ",
        ItemDescriptor*, ItemStackBase*, ItemDescriptor*)(item, (ItemDescriptor*)descriptor);
    return (ItemDescriptor*)descriptor;
}

inline unsigned char getItemCount(ItemStackBase* item) {
    return dAccess<char>(item, 34); // ItemStackBase::init
}
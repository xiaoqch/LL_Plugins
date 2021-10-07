#pragma once
#include <mc/Item.h>
#include <wangheader/SortItemInstanceIdAux.hpp>

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

//namespace ItemRegistry {
//    HashedString& getNameFromLegacyID(unsigned short id) {
//        HashedString hanme = HashedString("");
//        return SymCall("?getNameFromLegacyID@ItemRegistry@@SA?AVHashedString@@F@Z",
//            HashedString&, HashedString&, unsigned short)(hanme, id);
//    };
//
//    Item* lookupByName(int64_t& id, unsigned int& aux, string const& name) {
//        Item* item;
//        SymCall("?lookupByName@ItemRegistry@@SA?AV?$WeakPtr@VItem@@@@AEAH0AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
//            Item**, Item**, int64_t&, unsigned int&, string const&)(&item, id, aux, name);
//        return item;
//    };
//    Item* lookupByName(unsigned int& aux, string const& name) {
//        int64_t id;
//        return lookupByName(id, aux, name);
//    };
//    Item* lookupByName(HashedString const& name) {
//        unsigned int aux;
//        return lookupByName(aux, name.getString());
//    };
//    Item* lookupByNameNoAlias(string const& nameNoAlias) {
//        Item* item;
//        SymCall("?lookupByNameNoAlias@ItemRegistry@@SA?AV?$WeakPtr@VItem@@@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
//            Item**, Item**, string const&)(&item, nameNoAlias);
//        return item;
//    };
//    Item* lookupByNameNoAlias(HashedString const& nameNoAlias) {
//        return lookupByNameNoAlias(nameNoAlias.getString());
//    };
//    /*
//    lookupByName(int &,int &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &)	.text	00007FF725EB9130	000000A9	00000038	00000010	R	.	.	.	.	.	.	.
//    lookupByName(int &,std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &)	.text	00007FF725EB91E0	00000FC5	00000238	00000020	R	.	.	.	.	B	T	.
//    lookupByName(HashedString const &)	.text	00007FF725EBA1B0	00000053	00000038	00000000	R	.	.	.	.	.	T	.
//    lookupByNameNoAlias(std::basic_string<char,std::char_traits<char>,std::allocator<char>> const &)	.text	00007FF725EBA210	00000DC3	000001D8	00000018	R	.	.	.	.	B	T	.
//    lookupByNameNoAlias(HashedString const &)	.text	00007FF725EBAFE0	00000025	00000028	00000000	R	.	.	.	.	.	T	.
//    */
//}

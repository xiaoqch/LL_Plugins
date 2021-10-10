#include "pch.h"
#include "SymHelper.h"
#include "ItemHelper.h"
#include <set>

ItemInstance* newItem() {
    ItemInstance* a = (ItemInstance*) new char[136];
    ItemInstance* item = SymCall("??0ItemInstance@@QEAA@XZ", ItemInstance*, ItemInstance*)(a);
    return item;
}

ItemInstance* newItem(Tag* tag) {
    auto item = newItem();
    return SymCall("?fromTag@ItemInstance@@SA?AV1@AEBVCompoundTag@@@Z",
        ItemInstance*, ItemInstance*, Tag*)(item, tag);
}

ItemInstance* newItem(string const& name, int count) {
    int64_t id;
    unsigned int aux;
    auto item = ItemRegistry::lookupByName(id, aux, name);
    if (!item)
        return nullptr;
    cout << dAccess<string>(item, 208) << endl;
    ItemInstance itemIns{};
    return SymCall("??0ItemInstance@@QEAA@AEBVItem@@HH@Z",
        ItemInstance*, ItemInstance*, Item*, int, unsigned int)(&itemIns, item, count, aux);
}

ItemInstance* newItem(string const& name) {
    return newItem(name, 1);
}

void setItemName(ItemInstance& item, string const& name) {
    SymCall("?setCustomName@ItemStackBase@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
        void, ItemInstance const&, string const&)(item, name);
}

class CreativeItemRegistry* getCreativeItemRegistry() {
    auto regptr = (unique_ptr<CreativeItemRegistry>*)dlsym("?mCurrentRegistry@CreativeItemRegistry@@0V?$unique_ptr@VCreativeItemRegistry@@U?$default_delete@VCreativeItemRegistry@@@std@@@std@@A");
    return regptr->get();
}

unique_ptr<std::set<short>>* getServerItemsUsedInCreativeItems() {
    return (unique_ptr<std::set<short>>*)dlsym("?mServerItemsUsedInCreativeItems@Item@@0V?$unique_ptr@V?$set@FU?$less@F@std@@V?$allocator@F@2@@std@@U?$default_delete@V?$set@FU?$less@F@std@@V?$allocator@F@2@@std@@@2@@std@@A");
}
void updateNetIdMap() {
    auto reg = getCreativeItemRegistry();
    SymCall("?updateNetIdMap@CreativeItemRegistry@@QEAAXXZ",
        void, CreativeItemRegistry*)(reg);
}

void registerCreativeItem(ItemInstance& item) {
    //Item::startCreativeItemDefinitions(v5, v6);
    //Item::mActiveCreativeItemCategory
    //Item::mActiveCreativeGroupInfo = 0i64
    //Item::beginCreativeGroup(name, block, 0i64)
    //Item::addCreativeItem(v19)
    //Item::endCreativeGroup()
    //Item::addLooseCreativeItems(v5, v1192);
    //Item::endCreativeItemDefinitions(v5);
    SymCall("?addCreativeItem@Item@@SAXAEBVItemInstance@@@Z", void, ItemInstance&)(item);
    updateNetIdMap();
}

THook(Item**, "?lookupByName@ItemRegistry@@SA?AV?$WeakPtr@VItem@@@@AEAH0AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    Item** item, unsigned int& id, int& aux, string const& name) {
    auto rtn = original(item, id, aux, name);
    return rtn;
}
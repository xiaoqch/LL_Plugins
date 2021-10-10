#include "pch.h"
#include <mc/Item.h>
#include "TempEnum.h"
#include "CraftingLogger.h"

#define LOG_VAR(var) std::cout << #var" :\t" << var << std::endl;

using namespace std;

class SparseContainer;
void iterContainer(SparseContainer* ctn) {
    size_t size = SymCall("?getContainerSize@SparseContainer@@UEBAHXZ",
        size_t, SparseContainer*)(ctn);
    for (size_t slot = 0; slot < size; ++slot) {
        auto item = SymCall("?getItem@SparseContainer@@UEBAAEBVItemStack@@H@Z", 
            ItemStack*, SparseContainer*, size_t)(ctn, slot);
        auto isNull = SymCall("?isNull@ItemStackBase@@QEBA_NXZ",
            bool, ItemStackBase*)(item);
        if (!isNull) {
            string itemString;
            SymCall("?toString@ItemStack@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
                string&, ItemStack*, string&)(item, itemString);
            LOG_VAR(itemString)
        }
    }
}

THook(ItemStackNetResult, "?handleCraftAction@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* irc) {
    auto irh = dAccess<ItemStackRequestActionHandler*>(irch, 8);

    auto actionType = dAccess<ItemStackRequestActionType>(irc, 8);
    string actionTypeName;
    actionTypeName = SymCall("?getActionTypeName@ItemStackRequestAction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ItemStackRequestActionType@@@Z",
        string&, string&, ItemStackRequestActionType)(actionTypeName, actionType);

    LOG_VAR(actionTypeName);

    auto ctn = SymCall("?_getOrInitSparseContainer@ItemStackRequestActionHandler@@QEAAPEAVSparseContainer@@W4ContainerEnumName@@@Z",
        SparseContainer*, ItemStackRequestActionHandler*, ContainerEnumName)(irh, ContainerEnumName::creativeOutputItems);
    iterContainer(ctn);
    auto player = dAccess<Player*>(irch, 2 * 8);
    auto& outputItems = dAccess<vector<ItemInstance>>(irc, 72);
    auto rtn = original(irch, irc);

    return rtn;
}
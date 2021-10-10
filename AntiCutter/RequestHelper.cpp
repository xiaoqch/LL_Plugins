#include "pch.h"
#include "ContainerHelper.h"
#include "ItemHelper.h"
#include "RequestHelper.h"

ItemStackRequestActionHandler* getHandlerFromCraftHandler(ItemStackRequestActionCraftHandler* irch) {
    return dAccess<ItemStackRequestActionHandler*>(irch, 8);
}

SparseContainer* getOrInitSparseContainer(ItemStackRequestActionHandler* irh, ContainerEnumName type) {
    return SymCall("?_getOrInitSparseContainer@ItemStackRequestActionHandler@@QEAAPEAVSparseContainer@@W4ContainerEnumName@@@Z",
        SparseContainer*, ItemStackRequestActionHandler*, ContainerEnumName)(irh, type);
}

SparseContainer* getOrInitSparseContainer(ItemStackRequestActionCraftHandler* irch, ContainerEnumName type) {
    ItemStackRequestActionHandler* irh = getHandlerFromCraftHandler(irch);
    return getOrInitSparseContainer(irh, type);
}

ContainerScreenContext* getScreenContext(ItemStackRequestActionHandler* handler) {
    if (!handler)
        return nullptr;
    return SymCall("?getScreenContext@ItemStackRequestActionHandler@@QEBAAEBVContainerScreenContext@@XZ",
        ContainerScreenContext*, ItemStackRequestActionHandler*)(handler);
}

ContainerType getRequestContainerType(ItemStackRequestActionHandler* handler) {
    if (!handler)
        return ContainerType::NONE;
    auto screen = getScreenContext(handler);
    if (!screen)
        return ContainerType::NONE;
    auto containerType = getScreenContainerType(screen);
    return containerType;
}



ItemStack* getResultItem(ItemStackRequestActionHandler* irh) {
    return dAccess<ItemStack*>(irh, 5 * 8);
}

ItemStack* getResultItem(ItemStackRequestActionCraftHandler* irch) {
    if (!irch)
        return nullptr;
    ItemStackRequestActionHandler* irh = getHandlerFromCraftHandler(irch);
    return dAccess<ItemStack*>(irh, 5 * 8);
}

vector<ItemInstance>& getResultItems(ItemStackRequestActionCraftResults* ircr) {
    return dAccess<vector<ItemInstance>>(ircr, 72); // **********
}
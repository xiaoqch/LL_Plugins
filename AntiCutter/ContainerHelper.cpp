#include "pch.h"
#include "ContainerHelper.h"

ItemStack* getItemFromSparseContainer(SparseContainer* ctn, ContainerOffset offset) {
    if (!ctn)
        return nullptr;
    //int size = VirtualCall<int>(ctn, 0x70);
    auto size = SymCall("?getContainerSize@SparseContainer@@UEBAHXZ",
        size_t, SparseContainer*)(ctn);
    if ((int)offset >= size) {
        return nullptr;
    }
    //ItemStack* item = VirtualCall<ItemStack*>(ctn, 40, offset);
    auto item = SymCall("?getItem@SparseContainer@@UEBAAEBVItemStack@@H@Z",
        ItemStack*, SparseContainer*, ContainerOffset)(ctn, offset);
    return item;
}

ContainerType getScreenContainerType(ContainerScreenContext* context) {
    // ContainerScreenContext::getScreenContainerType
    return dAccess<ContainerType>(context, 8);
}
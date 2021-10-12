#include "pch.h"
#include <mc/Item.h>
#include "TempEnum.h"
#include "CraftingLogger.h"


#define LOG_VAR(var) std::cout << #var" :\t" << var << std::endl;

string const space = "                                                     ";

#define LOG_START(name) \
string fun_name=name;\
if(level<0) level=0;\
cout<<space.substr(0, 2*level++)<<fun_name<<":"<<endl;

#define LOG(var)\
cout<<space.substr(0, 2*level)<< #var" :\t" << var << std::endl;

#define LOG_END \
--level;

#define LOG_END_RTN \
if(rtn!=ItemStackNetResult::Success)\
cout<<space.substr(0, 2*--level)<<"return"<<":"<<(int)rtn<<endl;\
else --level;\
return rtn;

#define LOG_PREFIX cout<<space.substr(0, 2*level);

using namespace std;

size_t level=0;


struct voids {
    void***** v[1000];
};

void iterContainer(SparseContainer* ctn) {
    if (!ctn)
        return;
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
            LOG_PREFIX
            cout << "Slot: " << slot << ", Item: " << itemString << endl;
        }
    }
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
    auto containerType = dAccess<ContainerType>(screen, 8);
    return containerType;
}


void iterContainer(ItemStackRequestActionCraftHandler* irch) {
    auto ctn = irch->_getOrInitSparseContainer(ContainerEnumName::creativeOutputItems);
    iterContainer(ctn);
    auto& ctx = irch->handler->getScreenContext();
    LOG((int)ctx.ctnType);
    LOG((int)ctx.type);
    LOG(ctx.player->getNameTag());
    auto v = (voids*)&ctx;
}

//THook(ItemStackNetResult, "?handleCraftResults@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftResults_DEPRECATEDASKTYLAING@@@Z",
//    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* irc) {
//    auto irh = dAccess<ItemStackRequestActionHandler*>(irch, 8);
//
//    auto actionType = dAccess<ItemStackRequestActionType>(irc, 8);
//    string actionTypeName;
//    actionTypeName = SymCall("?getActionTypeName@ItemStackRequestAction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ItemStackRequestActionType@@@Z",
//        string&, string&, ItemStackRequestActionType)(actionTypeName, actionType);
//    LOG_VAR(actionTypeName);
//
//    auto screenType = getRequestContainerType(irh);
//    string screenTypeName = SymCall("?getContainerTypeName@Container@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContainerType@@@Z",
//        string&, ContainerType)(screenType);
//
//    LOG_VAR(screenTypeName);
//
//    auto ctn = SymCall("?_getOrInitSparseContainer@ItemStackRequestActionHandler@@QEAAPEAVSparseContainer@@W4ContainerEnumName@@@Z",
//        SparseContainer*, ItemStackRequestActionHandler*, ContainerEnumName)(irh, ContainerEnumName::creativeOutputItems);
//
//    iterContainer(ctn);
//
//    auto rtn = original(irch, irc);
//
//    iterContainer(ctn);
//
//    return rtn;
//}

THook(ItemStackNetResult, "?handleCraftAction@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* irc) {
    LOG_START("handleCraftAction")

        auto rtn = original(irch, irc);

        auto actionType = dAccess<ItemStackRequestActionType>(irc, 8);
        string actionTypeName;
        actionTypeName = SymCall("?getActionTypeName@ItemStackRequestAction@@SA?BV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ItemStackRequestActionType@@@Z",
        string&, string&, ItemStackRequestActionType)(actionTypeName, actionType);
        LOG(actionTypeName);

        auto irh = dAccess<ItemStackRequestActionHandler*>(irch, 8);
        auto screenType = getRequestContainerType(irh);
        string screenTypeName = SymCall("?getContainerTypeName@Container@@SAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@W4ContainerType@@@Z",
            string&, ContainerType)(screenType);
        LOG(screenTypeName);

        iterContainer(irch);

    LOG_END_RTN
}

//THook(ItemStackNetResult, "?preHandleAction@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@W4ItemStackRequestActionType@@@Z",
//    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionType actionType) {
//    LOG_START("preHandleAction")
//
//        auto rtn = original(irch, actionType);
//
//    LOG_END_RTN
//}

THook(ItemStackNetResult, "?handleCreate@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCreate@@@Z",
    ItemStackRequestActionCraftHandler* irch, class ItemStackRequestActionCreate* a1) {
    LOG_START("handleCreate")

    auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?handleCraftResults@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftResults_DEPRECATEDASKTYLAING@@@Z",
    ItemStackRequestActionCraftHandler* irch, class ItemStackRequestActionCraftResults* a1) {
    LOG_START("handleCraftResults")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?handleConsume@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionConsume@@@Z",
    ItemStackRequestActionCraftHandler* irch, class ItemStackRequestActionConsume* a1) {
    LOG_START("handleConsume")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_setCreatedItemOutputSlot@ItemStackRequestActionCraftHandler@@AEAA?AW4ItemStackNetResult@@E@Z",
    ItemStackRequestActionCraftHandler* irch, unsigned char slot) {
    LOG_START("_setCreatedItemOutputSlot")

        auto rtn = original(irch, slot);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?postRequest@ItemStackRequestActionCraftHandler@@QEAAX_N@Z",
    ItemStackRequestActionCraftHandler* irch, bool a1) {
    LOG_START("postRequest")

        auto rtn = original(irch, a1);

    LOG_END;
    cout << endl;
    return rtn;
}

THook(ItemStackNetResult, "?endRequest@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@W42@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackNetResult a1) {
    LOG_START("endRequest")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_initCraftResults@ItemStackRequestActionCraftHandler@@QEAA?AW4ItemStackNetResult@@AEBV?$vector@VItemInstance@@V?$allocator@VItemInstance@@@std@@@std@@E@Z",
    ItemStackRequestActionCraftHandler* irch, vector<ItemInstance> const& a1, unsigned char a2) {
    LOG_START("_initCraftResults")

        auto rtn = original(irch, a1, a2);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_handleCraftAction@CraftHandlerMap@@MEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* a1) {
    LOG_START("CraftHandlerMap")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_handleCraftAction@CraftHandlerTrade@@MEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* a1) {
    LOG_START("CraftHandlerTrade")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_handleCraftAction@CraftHandlerEnchant@@MEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* a1) {
    LOG_START("CraftHandlerEnchant")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_handleCraftAction@CraftHandlerCrafting@@MEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* a1) {
    LOG_START("CraftHandlerCrafting")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_handleCraftAction@CraftHandlerAnvil@@MEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* a1) {
    LOG_START("CraftHandlerAnvil")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?_handleCraftAction@CraftHandleNonImplemented_DEPRECATEDASKTYLAING@@MEAA?AW4ItemStackNetResult@@AEBVItemStackRequestActionCraftBase@@@Z",
    ItemStackRequestActionCraftHandler* irch, ItemStackRequestActionCraftBase* a1) {
    LOG_START("CraftHandleNonImplemented_DEPRECATEDASKTYLAING")

        auto rtn = original(irch, a1);

    LOG_END_RTN
}

THook(ItemStackNetResult, "?handleConsumedItem@CraftHandlerBase@@UEAA?AW4ItemStackNetResult@@W4ContainerEnumName@@EAEBVItemStack@@@Z",
    ItemStackRequestActionCraftHandler* irch, void* a1, void* a2, void* a3) {
    LOG_START("CraftHandlerBase::handleConsumedItem")

        auto rtn = original(irch, a1, a2, a3);

    LOG_END_RTN
}

//THook(bool, "?_tryPullInItemsFromAboveContainer@Hopper@@IEAA_NAEAVBlockSource@@AEAVContainer@@AEBVVec3@@@Z",
//    void* _this, BlockSource* bs, void* container, Vec3* pos) {
//
//    bool isMinecart = dAccess<bool>(_this, 5);
//    auto v = (voids*)_this;
//    if (isMinecart) {
//
//    }
//    else {
//        auto ba = dAccess<BlockActor*>(_this, -424);
//    }
//    auto rtn = original(_this, bs, container, pos);
//
//    return rtn;
//}
#pragma once
#include <wangheader/ItemStackRequestActionHandler.hpp>

class ItemInstance : ItemStackBase {};
class ItemStackRequestActionCraftBase;
class CraftHandlerBase;
class ItemStackNetManagerServer;

class ContainerScreenContext;
class SparseContainer;

class ItemStackRequestActionHandler {
    struct ScreenData;
public:
    //struct PlayerLegacyRequestSlotIdAssignment;
    Player* player;
    ItemStackNetManagerServer* manager;
    void********* filler[29-2];
    SparseContainer* _getOrInitSparseContainer(ContainerEnumName name) {
        return SymCall("?_getOrInitSparseContainer@ItemStackRequestActionHandler@@QEAAPEAVSparseContainer@@W4ContainerEnumName@@@Z",
            SparseContainer*, ItemStackRequestActionHandler*, ContainerEnumName)(this, name);
    }
    ContainerScreenContext const& getScreenContext() {
        return SymCall("?getScreenContext@ItemStackRequestActionHandler@@QEBAAEBVContainerScreenContext@@XZ",
            ContainerScreenContext&, ItemStackRequestActionHandler*)(this);
    };
    //ItemStackRequestActionHandler::ScreenData* _tryGetCurrentScreenData(void) {
    //}
};

class ItemStackRequestActionCraftHandler {
public:
    ItemStackRequestActionHandler* handler;
    Player* player;
    CraftHandlerBase* ch;
    SparseContainer* ctn;
    std::vector<ItemInstance> items;

    virtual ~ItemStackRequestActionCraftHandler();
};


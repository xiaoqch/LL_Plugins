#pragma once


class ItemInstance : ItemStackBase {};
class ItemStackRequestActionCraftBase;
class CraftHandlerBase;
class ItemStackNetManagerServer;

class ContainerScreenContext {
public:
    Player* player;
    ContainerType type;
    void* uidOrPos[2];
    char ctnType;
    bool  operator== (enum ContainerType);
    ContainerScreenContext(void);
    ContainerScreenContext(class Player&, enum ContainerType, class BlockPos const&);
    ContainerScreenContext(class Player&, enum ContainerType, struct ActorUniqueID const&);
    Player* getPlayer(void) {
        return dAccess<Player*>(this, 0);
    }
    ContainerType getScreenContainerType(void){
        return SymCall("?tryGetActor@ContainerScreenContext@@QEBAPEAVActor@@XZ",
            ContainerType, ContainerScreenContext*)(this);
    }
    Actor* tryGetActor(void){
        return SymCall("?tryGetActor@ContainerScreenContext@@QEBAPEAVActor@@XZ",
            Actor*, ContainerScreenContext*)(this);
    }
    BlockActor* tryGetBlockActor(void) {
        return SymCall("?tryGetActor@ContainerScreenContext@@QEBAPEAVActor@@XZ",
            BlockActor*, ContainerScreenContext*)(this);
    };
};
class SparseContainer;

class ItemStackRequestActionHandler {
    struct ScreenData;
public:
    //struct PlayerLegacyRequestSlotIdAssignment;
    Player* player;
    ItemStackNetManagerServer* manager;
    void********* filler[29-2];
    inline SparseContainer* _getOrInitSparseContainer(ContainerEnumName name) {
        return SymCall("?_getOrInitSparseContainer@ItemStackRequestActionHandler@@QEAAPEAVSparseContainer@@W4ContainerEnumName@@@Z",
            SparseContainer*, ItemStackRequestActionHandler*, ContainerEnumName)(this, name);
    }
    inline ContainerScreenContext const& getScreenContext() {
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

    inline SparseContainer* _getOrInitSparseContainer(ContainerEnumName name) {
        return handler->_getOrInitSparseContainer(name);
    }
};


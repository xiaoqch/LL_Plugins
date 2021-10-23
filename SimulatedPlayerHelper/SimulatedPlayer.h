#pragma once
#include "SymHelper.h"
#include <mc/Player.h>

class SimulatedPlayer : public ServerPlayer {
public:
    SimulatedPlayer(const SimulatedPlayer&) = delete;
    SimulatedPlayer& operator=(const SimulatedPlayer&) = delete;
    SimulatedPlayer() = delete;

    inline static SimulatedPlayer* create(string const& name, BlockPos const& bpos, int dimid, ServerNetworkHandler* snh) {
        return SymCall("?create@SimulatedPlayer@@SAPEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlockPos@@V?$AutomaticID@VDimension@@H@@AEAVServerNetworkHandler@@@Z",
            SimulatedPlayer*, string const&, BlockPos const&, int, ServerNetworkHandler*)(name, bpos, dimid, snh);
    }
    inline void aiStep() {
        return SymCall("?aiStep@SimulatedPlayer@@UEAAXXZ", void, SimulatedPlayer*)(this);
    }
    inline const struct PlayerMovementSettings* getMovementSettings() {
        return SymCall("?getMovementSettings@SimulatedPlayer@@UEBAAEBUPlayerMovementSettings@@XZ", PlayerMovementSettings*, SimulatedPlayer*)(this);
    }
    inline void initializeComponents() {
        return SymCall("?initializeComponents@SimulatedPlayer@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
            void, SimulatedPlayer*)(this);
    }
    inline bool simulateAttack(Actor* ac) {
        return SymCall("?simulateAttack@SimulatedPlayer@@QEAA_NAEAVActor@@@Z", bool, SimulatedPlayer*, Actor*)(this, ac);
    }
    inline bool simulateAttack() {
        return SymCall("?simulateAttack@SimulatedPlayer@@QEAA_NXZ", bool, SimulatedPlayer*)(this);
    }
    inline bool simulateDestroyBlock(BlockPos const& bpos, unsigned char direction) {
        return SymCall("?simulateDestroyBlock@SimulatedPlayer@@QEAA_NAEBVBlockPos@@E@Z", bool, SimulatedPlayer*, BlockPos const&, unsigned char)(this, bpos, direction);
    }
    inline void simulateDisconnect() {
        return SymCall("?simulateDisconnect@SimulatedPlayer@@QEAAXXZ", void, SimulatedPlayer*)(this);
    }
    inline bool simulateInteract(Actor* ac) {
        return SymCall("?simulateInteract@SimulatedPlayer@@QEAA_NAEAVActor@@@Z", bool, SimulatedPlayer*, Actor*)(this, ac);
    }
    inline bool simulateInteract(BlockPos const& bpos, unsigned char direction) {
        return SymCall("?simulateInteract@SimulatedPlayer@@QEAA_NAEBVBlockPos@@E@Z", bool, SimulatedPlayer*, BlockPos const&, unsigned char)(this, bpos, direction);
    }
    inline bool simulateInteract() {
        return SymCall("?simulateInteract@SimulatedPlayer@@QEAA_NXZ", bool, SimulatedPlayer*)(this);
    }
    inline bool simulateJump() {
        return SymCall("?simulateJump@SimulatedPlayer@@QEAA_NXZ", bool, SimulatedPlayer*)(this);
    }
    inline void simulateLocalMove(Vec3 const& pos, float speed) {
        return SymCall("?simulateLocalMove@SimulatedPlayer@@QEAAXAEBVVec3@@M@Z", void, SimulatedPlayer*, Vec3 const&, float)(this, pos, speed);
    }
    inline void simulateLookAt(Actor* ac) {
        return SymCall("?simulateLookAt@SimulatedPlayer@@QEAAXAEAVActor@@@Z", void, SimulatedPlayer*, Actor*)(this, ac);
    }
    inline void simulateLookAt(BlockPos const& bpos) {
        return SymCall("?simulateLookAt@SimulatedPlayer@@QEAAXAEBVBlockPos@@@Z", void, SimulatedPlayer*, BlockPos const&)(this, bpos);
    }
    inline void simulateLookAt(Vec3 const& pos) {
        return SymCall("?simulateLookAt@SimulatedPlayer@@QEAAXAEBVVec3@@@Z", void, SimulatedPlayer*, Vec3 const&)(this, pos);
    }
    inline void* simulateNavigateToEntity(Actor* ac, float speed) {
        return SymCall("?simulateNavigateToEntity@SimulatedPlayer@@QEAA?AUScriptNavigationResult@@AEAVActor@@M@Z", void*, SimulatedPlayer*, Actor*, float)(this, ac, speed);
    }
    inline void* simulateMoveToLocation(Vec3 const& pos, float speed) {
        return SymCall("?simulateNavigateToLocation@SimulatedPlayer@@QEAA?AUScriptNavigationResult@@AEBVVec3@@M@Z", void*, SimulatedPlayer*, Vec3 const&, float)(this, pos, speed);
    }
    inline void simulateNavigateToLocations(std::vector<Vec3>** pos, float speed) {
        return SymCall("?simulateNavigateToLocations@SimulatedPlayer@@QEAAX$$QEAV?$vector@VVec3@@V?$allocator@VVec3@@@std@@@std@@M@Z", void, SimulatedPlayer*, std::vector<Vec3>**, float)(this, pos, speed);
    }
    inline ItemStack* simulateSelectSlot(int slot) {
        return SymCall("?simulateSelectSlot@SimulatedPlayer@@QEAAAEBVItemStack@@H@Z", ItemStack*, SimulatedPlayer*, int)(this, slot);
    }
    inline void simulateSetBodyRotation(float rotation) {
        return SymCall("?simulateSetBodyRotation@SimulatedPlayer@@QEAAXM@Z", void, SimulatedPlayer*, int)(this, rotation);
    }
    inline void simulateStopDestroyingBlock() {
        return SymCall("?simulateStopDestroyingBlock@SimulatedPlayer@@QEAAXXZ", void, SimulatedPlayer*)(this);
    }
    inline void simulateStopInteracting() {
        return SymCall("?simulateStopInteracting@SimulatedPlayer@@QEAAXXZ", void, SimulatedPlayer*)(this);
    }
    inline void simulateStopMoving() {
        return SymCall("?simulateStopMoving@SimulatedPlayer@@QEAAXXZ", void, SimulatedPlayer*)(this);
    }
    inline void simulateStopUsingItem() {
        return SymCall("?simulateStopUsingItem@SimulatedPlayer@@QEAAXXZ", void, SimulatedPlayer*)(this);
    }
    inline bool simulateUseItem(ItemStack* item) {
        return SymCall("?simulateUseItem@SimulatedPlayer@@QEAA_NAEAVItemStack@@@Z", bool, SimulatedPlayer*, ItemStack*)(this, item);
    }
    inline bool simulateUseItemInSlot(int slot) {
        return SymCall("?simulateUseItemInSlot@SimulatedPlayer@@QEAA_NH@Z", bool, SimulatedPlayer*, int)(this, slot);
    }
    inline bool simulateUseItemInSlotOnBlock(int slot, BlockPos const& bpos, uchar direction, Vec3 const& faceLocation) {
        return SymCall("?simulateUseItemInSlotOnBlock@SimulatedPlayer@@QEAA_NHAEBVBlockPos@@EAEBVVec3@@@Z", bool, SimulatedPlayer*, int, BlockPos const&, uchar, Vec3 const&)(this, slot, bpos, direction, faceLocation);
    }
    inline bool simulateUseItemOnBlock(ItemStack* item, BlockPos const& bpos, uchar direction, Vec3 const& faceLocation) {
        return SymCall("?simulateUseItemOnBlock@SimulatedPlayer@@QEAA_NAEAVItemStack@@AEBVBlockPos@@EAEBVVec3@@@Z", bool, SimulatedPlayer*, ItemStack*, BlockPos const&, uchar, Vec3 const&)(this, item, bpos, direction, faceLocation);
    }
    inline void simulateWorldMove(Vec3 const& pos, float speed) {
        return SymCall("?simulateWorldMove@SimulatedPlayer@@QEAAXAEBVVec3@@M@Z", void, SimulatedPlayer*, Vec3 const&, float)(this, pos, speed);
    }
    inline static SimulatedPlayer* tryGetFromEntity(struct EntityContext* a1, bool a2) {
        return SymCall("?tryGetFromEntity@SimulatedPlayer@@SAPEAV1@AEAVEntityContext@@_N@Z", SimulatedPlayer*, EntityContext*, bool)(a1, a2);
    }


    inline void teleportTo(Vec3 const& pos, bool shouldStopRiding, int cause, int sourceEntityType) {
        SymCall("?teleportTo@Player@@UEAAXAEBVVec3@@_NHH@Z", void, SimulatedPlayer*, Vec3 const&, bool, int, int)(this, pos, shouldStopRiding, cause, sourceEntityType);
    }
    inline void changeDimension(unsigned int dimid, bool usePortal) {
        SymCall("?changeDimension@ServerPlayer@@UEAAXV?$AutomaticID@VDimension@@H@@_N@Z", void, ServerPlayer*, unsigned int, bool)(this, dimid, usePortal);
    }
    inline void resetPos(bool clearMore) {
        SymCall("?resetPos@Player@@UEAAX_N@Z", void, Player*)(this);
    }
    inline void respawn() {
        SymCall("?respawn@Player@@UEAAXXZ", void, ServerPlayer*)(this);
    }
    inline void reloadHardcode() {
        SymCall("?reloadHardcoded@Player@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z", void, ServerPlayer*)(this);
    }
    inline int getExpectedSpawnDimensionId() {
        return SymCall("?getExpectedSpawnDimensionId@Player@@QEBA?AV?$AutomaticID@VDimension@@H@@XZ", int&, ServerPlayer*)(this);
    }
    inline BlockPos const* getExpectedSpawnPosition() {
        return SymCall("?getExpectedSpawnPosition@Player@@QEBAAEBVBlockPos@@XZ", BlockPos const*, ServerPlayer*)(this);
    }
    inline void clearRespawnPosition() {
        SymCall("?clearRespawnPosition@Player@@QEAAXXZ", void, ServerPlayer*)(this);
    }
    inline void updateSpawnChunkView() {
        SymCall("?updateSpawnChunkView@Player@@QEAAXXZ", void, ServerPlayer*)(this);
    }
};

bool isSimulatedPlayer(Actor* actor);

class SimulatedPlayerHelper
{
public:
    SimulatedPlayer* sp;
    inline SimulatedPlayerHelper(SimulatedPlayer* sp) {
        this->sp = sp;
    };
    inline static SimulatedPlayer* createSP(string const& name, BlockPos const& bpos, int dimid) {
        auto snh = getServerNetworkHandler();
        auto sp = SimulatedPlayer::create(name, bpos, 0, snh);
        sp->clearRespawnPosition();
        if (dimid)
            WPlayer(*sp).teleport({ bpos.x + 0.5f,bpos.y + 0.0f,bpos.z + 0.5f }, dimid);
        return sp;
    };
    inline static SimulatedPlayer* createSP(string const& name) {
        int dimid = 0;
        auto& pos = SymCall("?getDefaultSpawn@Level@@UEBAAEBVBlockPos@@XZ", const BlockPos&, Level*)(getLevel());
        return createSP(name, pos, dimid);
    }
    inline static SimulatedPlayer* createSP(string const& name, Vec3 const& pos, int dimid) {
        return createSP(name, ((Vec3)pos).toBlockPos(), dimid);;
    };
    inline static SimulatedPlayer* createSP(string const& name, float x, float y, float z, int dimid) {
        Vec3 pos = { x, y, z };
        return createSP(name, pos, dimid);
    }
    inline static SimulatedPlayer* createSP(string const& name, int x, int y, int z, int dimid) {
        BlockPos pos = { x, y, z };
        return createSP(name, pos, dimid);
    }
    inline void remove() {
        sp->simulateDisconnect();
    }
    inline bool attack() {
        return sp->simulateAttack();
    }
    inline bool useItem() {
        return sp->simulateUseItemInSlot(0);
    }
};


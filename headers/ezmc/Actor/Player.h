#pragma once

#include <vector>

#include <loader/Loader.h>

#include "../Command/CommandPermissionLevel.h"
#include "../Container/EnderChestContainer.h"
#include "../Container/PlayerInventory.h"
#include "../Core/AutomaticID.h"
#include "../Core/ExtendedCertificate.h"
#include "../Core/VanillaDimensions.h"
#include "../Math/BlockPos.h"
#include "../Math/Vec3.h"
#include "../dll.h"
#include "Actor.h"
#include "Mob.h"

class Packet;
class ServerPlayer;
class NetworkIdentifier;
class Dimension;
enum class StructureFeatureType;
enum class AbilitiesIndex;
enum class BedSleepingResult;
enum class GameType;
enum class CooldownType;
enum class ClientPlayMode;
enum class MovementEventType;
enum class PlayerUISlot;

class Player : public Mob {
public:
    class PlayerSpawnPoint {
    public:
        inline static BlockPos            InvalidSpawnPos = BlockPos::MIN;
        BlockPos                          spawn_block = InvalidSpawnPos, spawn_pos = InvalidSpawnPos;
        AutomaticID<class Dimension, int> dim = VanillaDimensions::Undefined;

        inline PlayerSpawnPoint()        = default;
        inline PlayerSpawnPoint& operator=(PlayerSpawnPoint&&) = default;
        inline bool              hasSpawnPoint() const {
            return spawn_block != BlockPos::MIN && dim != VanillaDimensions::Undefined;
        }
        inline void invalidate() {
            *this = {};
        }
        inline bool isValid() const {
            return dim != VanillaDimensions::Undefined;
        }
        inline void setSpawnPoint(BlockPos spawn_block, AutomaticID<class Dimension, int> dim, BlockPos spawn_pos) {
            this->spawn_block = spawn_block;
            this->spawn_pos   = spawn_pos;
            this->dim         = dim;
        }
        inline void setSpawnPoint(BlockPos spawn_block, AutomaticID<class Dimension, int> dim) {
            setSpawnPoint(spawn_block, dim, spawn_block);
        }
    };

    enum class PlayerPermissionLevel { Visitor,
                                       Member,
                                       Operator,
                                       Custom };

    inline ServerPlayer* asServerPlayer() const noexcept {
        return const_cast<ServerPlayer*>(reinterpret_cast<ServerPlayer const*>(this));
    }

    virtual void                               prepareRegion(class ChunkSource&);
    virtual void                               destroyRegion(void);
    virtual void                               suspendRegion(void);
    virtual void                               _fireWillChangeDimension(void);
    virtual void                               _fireDimensionChanged(void);
    virtual void                               changeDimensionWithCredits(class AutomaticID<class Dimension, int>);
    virtual int                                tickWorld(struct Tick const&);
    virtual void                               frameUpdate(class FrameUpdateContextBase&);
    virtual std::vector<class ChunkPos> const& getTickingOffsets(void) const;
    virtual void                               moveView(void);
    virtual void                               setName(std::string const&);
    virtual void                               checkMovementStats(class Vec3 const&);
    virtual class StructureFeature*            getCurrentStructureFeature() const;
    virtual bool                               isAutoJumpEnabled() const;
    virtual void                               respawn(void);
    virtual void                               resetRot();
    virtual void                               resetPos(bool);
    virtual bool                               isInTrialMode();
    virtual bool                               hasResource(int);
    virtual void                               completeUsingItem(void);
    virtual void                               setPermissions(enum CommandPermissionLevel);
    virtual void                               startDestroying(void);
    virtual void                               stopDestroying(void);
    virtual void                               openPortfolio();
    virtual void                               openBook(int, bool, int, BlockActor*);
    virtual void                               openTrading(struct ActorUniqueID const&, bool);
    virtual bool                               canOpenContainerScreen(void);
    virtual void                               openChalkboard(class ChalkboardBlockActor*, bool);
    virtual void                               openNpcInteractScreen(Actor&);
    virtual void                               openInventory(void);
    virtual void                               displayChatMessage(std::string const&, std::string const&);
    virtual void                               displayClientMessage(std::string const&);
    virtual void                               displayTextObjectMessage(class TextObjectRoot const&);
    virtual void                               displayTextObjectWhisperMessage(class TextObjectRoot const&, std::string const&, std::string const&);
    virtual void                               displayWhisperMessage(std::string const&, std::string const&, std::string const&, std::string const&);
    virtual enum BedSleepingResult             startSleepInBed(class BlockPos const&);
    virtual void                               stopSleepInBed(bool, bool);
    virtual bool                               canStartSleepInBed(void);
    virtual int                                getSleepTimer(void) const;
    virtual int                                getPreviousTickSleepTimer(void) const;
    virtual void                               openSign(BlockPos const&);
    virtual void                               playEmote(std::string const&);
    virtual bool                               isHostingPlayer(void) const;
    virtual bool                               isLoading(void) const;
    virtual bool                               isPlayerInitialized(void) const;
    virtual void                               stopLoading();
    virtual void                               registerTrackedBoss(struct ActorUniqueID);
    virtual void                               unRegisterTrackedBoss(struct ActorUniqueID);
    virtual void                               setPlayerGameType(enum GameType);
    virtual void                               initHUDContainerManager(void);
    virtual void                               _crit(class Actor&);
    virtual class IMinecraftEventing*          getEventing(void) const;
    virtual unsigned char                      getUserId();
    virtual void                               sendEventPacket(class EventPacket&) const;
    virtual void                               addExperience(int);
    virtual void                               addLevels(int);
    virtual void                               setContainerData(class IContainerManager&, int, int);
    virtual void                               slotChanged(class IContainerManager&, class Container&, int, class ItemStack const&, class ItemStack const&, bool);
    virtual void                               inventoryChanged(class Container&, int, class ItemStack const&, class ItemStack const&, bool);
    virtual void                               refreshContainer(class IContainerManager&);
    virtual void                               deleteContainerManager(void);
    virtual void                               setFieldOfViewModifier(float);
    virtual bool                               is2DPositionRelevant(class AutomaticID<class Dimension, int>, class BlockPos const&);
    virtual bool                               isEntityRelevant(class Actor const&);
    virtual bool                               isTeacher(void) const;
    virtual void                               onSuspension(void);
    virtual void                               onLinkedSlotsChanged(void);
    virtual void                               startCooldown(class Item const*);
    virtual int                                getItemCooldownLeft(std::string const&) const;
    virtual bool                               isItemInCooldown(std::string const&) const;
    virtual void                               sendInventoryTransaction(class InventoryTransaction const&) const;
    virtual void                               sendComplexInventoryTransaction(std::unique_ptr<class ComplexInventoryTransaction>) const;
    virtual void                               sendNetworkPacket(Packet&) const;
    virtual class PlayerEventCoordinator&      getPlayerEventCoordinator(void);
    virtual class MoveInputHandler*            getMoveInputHandler();
    virtual enum InputMode                     getInputMode(void) const;
    virtual enum ClientPlayMode                getPlayMode(void) const;
    virtual void                               reportMovementTelemetry(enum MovementEventType);
    virtual void                               onMovePlayerPacketNormal(class Vec3 const&, class Vec2 const&, float);

    MCAPI virtual ~Player(void);

    MCAPI static void                                  _aiStep(struct IPlayerMovementProxy&);
    MCAPI static void                                  _jumpFromGround(struct IPlayerMovementProxy&);
    MCAPI static void                                  _travel(struct IPlayerMovementProxy&, float, float, float);
    MCAPI void                                         broadcastPlayerSpawnedMobEvent(enum ActorType, enum MobSpawnMethod);
    MCAPI bool                                         canBeSeenOnMap(void) const;
    MCAPI bool                                         canDestroy(class Block const&) const;
    MCAPI bool                                         canUseAbility(enum AbilitiesIndex) const;
    MCAPI bool                                         canUseOperatorBlocks(void) const;
    MCAPI void                                         causeFoodExhaustion(float);
    MCAPI bool                                         checkNeedAutoJump(float, float);
    MCAPI void                                         clearRespawnPosition(void);
    MCAPI void                                         eat(class ItemStack const&);
    MCAPI void                                         eat(int, float);
    MCAPI bool                                         equippedArmorItemCanBeMoved(class ItemStack const&) const;
    MCAPI void                                         fireDimensionChangedEvent(class AutomaticID<class Dimension, int>);
    MCAPI bool                                         forceAllowEating(void) const;
    MCAPI class Agent*                                 getAgent(void) const;
    MCAPI struct ActorUniqueID                         getAgentID(void) const;
    MCAPI class Agent*                                 getAgentIfAllowed(bool, struct ActorUniqueID) const;
    MCAPI class BlockPos const&                        getBedPosition(void) const;
    MCAPI __int64                                      getBlockedUsingDamagedShieldTimeStamp(void) const;
    MCAPI __int64                                      getBlockedUsingShieldTimeStamp(void) const;
    MCAPI __int64                                      getBlockingStartTimeStamp(void) const;
    MCAPI class Vec3                                   getCapePos(float);
    MCAPI class Certificate const*                     getCertificate(void) const;
    MCAPI class NetworkIdentifier const&               getClientId(void) const;
    MCAPI unsigned char                                getClientSubId(void) const;
    MCAPI class std::weak_ptr<class IContainerManager> getContainerManager(void);
    MCAPI class ItemStack const&                       getCurrentActiveShield(void) const;
    MCAPI float                                        getDestroyProgress(class Block const&) const;
    MCAPI float                                        getDestroySpeed(class Block const&) const;
    MCAPI int                                          getDirection(void) const;
    MCAPI int                                          getEnchantmentSeed(void) const;
    MCAPI class AutomaticID<class Dimension, int>      getExpectedSpawnDimensionId(void) const;
    MCAPI class BlockPos const&                        getExpectedSpawnPosition(void) const;
    MCAPI std::string            getInteractText(void) const;
    MCAPI class Container&       getInventory(void);
    MCAPI class ItemStack const& getItemInUse(void) const;
    MCAPI std::string                          getItemInteractText(class Item const&) const;
    MCAPI class ItemStackNetManagerBase const* getItemStackNetManager(void) const;
    MCAPI class ItemStackNetManagerBase*       getItemStackNetManager(void);
    MCAPI float                                getLuck(void);
    MCAPI int                                  getMapIndex(void);
    MCAPI void                                 getNewEnchantmentSeed(void);
    MCAPI enum BuildPlatform                   getPlatform(void) const;
    MCAPI std::string const&         getPlatformOnlineId(void) const;
    MCAPI enum GameType              getPlayerGameType(void) const;
    MCAPI int                        getPlayerIndex(void) const;
    MCAPI int                        getPlayerLevel(void) const;
    MCAPI enum PlayerPermissionLevel getPlayerPermissionLevel(void) const;
    MCAPI std::string const&                                                                         getPlayerSessionId(void) const;
    MCAPI class ItemStack const&                                                                     getPlayerUIItem(enum PlayerUISlot);
    MCAPI class BlockPos const&                                                                      getRespawnAnchorPosition(void) const;
    MCAPI class ItemStack const&                                                                     getSelectedItem(void) const;
    MCAPI int                                                                                        getSelectedItemSlot(void) const;
    MCAPI class SerializedSkin const&                                                                getSkin(void) const;
    MCAPI class SerializedSkin&                                                                      getSkin(void);
    MCAPI float                                                                                      getSleepRotation(void) const;
    MCAPI class AutomaticID<class Dimension, int>                                                    getSpawnDimension(void) const;
    MCAPI class BlockPos const&                                                                      getSpawnPosition(void) const;
    MCAPI class PlayerInventory&                                                                     getSupplies(void);
    MCAPI class PlayerInventory const&                                                               getSupplies(void) const;
    MCAPI class std::vector<struct ActorUniqueID, class std::allocator<struct ActorUniqueID>> const& getTrackedBosses(void);
    MCAPI enum GameType                                                                              getUnmappedPlayerGameType(void);
    MCAPI bool                                                                                       getUsedPotion(void);
    MCAPI int                                                                                        getXpNeededForNextLevel(void) const;
    MCAPI static void                                                                                goDownInWater(struct IActorMovementProxy&);
    MCAPI void                                                                                       handleJumpEffects(void);
    MCAPI bool                                                                                       hasBedPosition(void) const;
    MCAPI bool                                                                                       hasOpenContainer(void) const;
    MCAPI bool                                                                                       hasOpenContainerOfContainerType(enum ContainerType) const;
    MCAPI bool                                                                                       hasOwnedChunkSource(void) const;
    MCAPI bool                                                                                       hasResource(class ItemDescriptor const&);
    MCAPI bool                                                                                       hasRespawnAnchorPosition(void) const;
    MCAPI bool                                                                                       hasRespawnPosition(void) const;
    MCAPI bool                                                                                       interact(class Actor&, class Vec3 const&);
    MCAPI bool                                                                                       isBouncing(void) const;
    MCAPI bool                                                                                       isForcedRespawn(void) const;
    MCAPI bool                                                                                       isHiddenFrom(class Mob&) const;
    MCAPI bool                                                                                       isHungry(void) const;
    MCAPI bool                                                                                       isHurt(void);
    MCAPI bool                                                                                       isInCreativeMode(void) const;
    MCAPI bool                                                                                       isInRaid(void) const;
    MCAPI bool                                                                                       isRespawningFromTheEnd(void) const;
    MCAPI bool                                                                                       isSleepingLongEnough(void) const;
    MCAPI bool                                                                                       isSpawned(void) const;
    MCAPI bool                                                                                       isSurvival(void) const;
    MCAPI bool                                                                                       isUsingItem(void) const;
    MCAPI void                                                                                       moveSpawnView(class Vec3 const&, class AutomaticID<class Dimension, int>);
    MCAPI void                                                                                       recheckSpawnPosition(void);
    MCAPI void                                                                                       releaseUsingItem(void);
    MCAPI void                                                                                       resetPlayerLevel(void);
    MCAPI void                                                                                       resetToDefaultGameMode(void);
    MCAPI void                                                                                       setAgent(class Agent*);
    MCAPI void                                                                                       setAllPlayersSleeping(void);
    MCAPI void                                                                                       setBedRespawnPosition(class BlockPos const&);
    MCAPI void                                                                                       setBlockRespawnUntilClientMessage(bool);
    MCAPI void                                                                                       setChunkRadius(unsigned int);
    MCAPI void                                                                                       setContainerManager(std::shared_ptr<class IContainerManager>);
    MCAPI void                                                                                       setCursorSelectedItem(class ItemStack const&);
    MCAPI void                                                                                       setCursorSelectedItemGroup(class ItemGroup const&);
    MCAPI void                                                                                       setEnchantmentSeed(int);
    MCAPI void                                                                                       setHasSeenCredits(bool);
    MCAPI void                                                                                       setMapIndex(int);
    MCAPI void                                                                                       setPlatformOnlineId(std::string const&);
    MCAPI void                                                                                       setPlayerIndex(int);
    MCAPI void                                                                                       setPlayerUIItem(enum PlayerUISlot, class ItemStack const&);
    MCAPI bool                                                                                       setRespawnPosition(class BlockPos const&, class AutomaticID<class Dimension, int>);
    MCAPI void                                                                                       setRespawnPositionCandidate(void);
    MCAPI void                                                                                       setSelectedItem(class ItemStack const&);
    MCAPI void                                                                                       setSpawnBlockRespawnPosition(class BlockPos const&, class AutomaticID<class Dimension, int>);
    MCAPI void                                                                                       setUsedPotion(bool);
    MCAPI bool                                                                                       shouldShowCredits(void) const;
    MCAPI void                                                                                       spawnExperienceOrb(class Vec3 const&, int);
    MCAPI void                                                                                       startGliding(void);
    MCAPI void                                                                                       startUsingItem(class ItemStack const&, int);
    MCAPI void                                                                                       stopGliding(void);
    MCAPI void                                                                                       stopUsingItem(void);
    MCAPI bool                                                                                       take(class Actor&, int, int);
    MCAPI void                                                                                       updateInventoryTransactions(void);
    MCAPI void                                                                                       updateSkin(class SerializedSkin const&, int);
    MCAPI void                                                                                       updateSpawnChunkView(void);
    MCAPI void                                                                                       updateTrackedBosses(void);
    MCAPI void                                                                                       useSelectedItem(enum ItemUseMethod, bool);

    //BUILD_ACCESS_COMPAT(PlayerInventory&, Inventory);
    //BUILD_ACCESS_COMPAT(class EnderChestContainer*, EnderChestContainer);
    //BUILD_ACCESS_COMPAT(class Certificate&, Certificate);
    //BUILD_ACCESS_COMPAT(class NetworkIdentifier const&, NetworkIdentifier);
    //BUILD_ACCESS_COMPAT(std::string&, DeviceId);
    //BUILD_ACCESS_COMPAT(std::string&, ClientPlatformId);
    //BUILD_ACCESS_COMPAT(std::string&, PlatformOfflineId);
    //BUILD_ACCESS_COMPAT(std::string&, ClientPlatformOnlineId);
    //BASEAPI void kick();
};

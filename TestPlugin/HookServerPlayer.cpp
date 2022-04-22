#include "pch.h"
#include <MC/ServerPlayer.hpp>


#ifdef HOOK_CLASS_ServerPlayer
// child_types : 1
// parent_types : 3
// private : 6
TInstanceHook(void, "?_logCDEvent@ServerPlayer@@AEAAXW4CrashDumpLogStringID@@000@Z",
              ServerPlayer, enum CrashDumpLogStringID a0, enum CrashDumpLogStringID a1, enum CrashDumpLogStringID a2, enum CrashDumpLogStringID a3)
{
    logger.info("ServerPlayer({})::_logCDEvent", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(enum ContainerID, "?_nextContainerCounter@ServerPlayer@@AEAA?AW4ContainerID@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::_nextContainerCounter", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_removeNearbyEntities@ServerPlayer@@AEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::_removeNearbyEntities", getName());
    original(this);
}

TInstanceHook(void, "?_scanForNearbyActors@ServerPlayer@@AEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::_scanForNearbyActors", getName());
    original(this);
}

#include <MC/IContainerManager.hpp>
TInstanceHook(void, "?_setContainerManager@ServerPlayer@@AEAAXV?$shared_ptr@VIContainerManager@@@std@@@Z",
              ServerPlayer, class std::shared_ptr<class IContainerManager> a0)
{
    logger.info("ServerPlayer({})::_setContainerManager", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_updateNearbyActors@ServerPlayer@@AEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::_updateNearbyActors", getName());
    original(this);
}

// public : 19
#include <MC/Certificate.hpp>
TInstanceHook(class ServerPlayer&, "??0ServerPlayer@@QEAA@AEAVLevel@@AEAVPacketSender@@AEAVNetworkHandler@@AEAVActiveTransfersManager@Server@ClientBlobCache@@W4GameType@@AEBVNetworkIdentifier@@EV?$function@$$A6AXAEAVServerPlayer@@@Z@std@@VUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@std@@H_NAEAVEntityContext@@@Z",
              ServerPlayer, class Level& a0, class PacketSender& a1, class NetworkHandler& a2, class ClientBlobCache::Server::ActiveTransfersManager& a3, enum GameType a4, class NetworkIdentifier const& a5, unsigned char a6, class std::function<void(class ServerPlayer&)> a7, class mce::UUID a8, std::string const& a9, class std::unique_ptr<class Certificate, struct std::default_delete<class Certificate>> a10, int a11, bool a12, class EntityContext& a13)
{
    logger.info("ServerPlayer::ServerPlayer");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6), std::forward<decltype(a7)>(a7), std::forward<decltype(a8)>(a8), std::forward<decltype(a9)>(a9), std::forward<decltype(a10)>(a10), std::forward<decltype(a11)>(a11), std::forward<decltype(a12)>(a12), std::forward<decltype(a13)>(a13));
    return rtn;
}

TInstanceHook(void, "?checkCheating@ServerPlayer@@QEAAXAEBVVec3@@@Z",
              ServerPlayer, class Vec3 const& a0)
{
    logger.info("ServerPlayer({})::checkCheating", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?disconnect@ServerPlayer@@QEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::disconnect", getName());
    original(this);
}

TInstanceHook(void, "?doDeleteContainerManager@ServerPlayer@@QEAAX_N@Z",
              ServerPlayer, bool a0)
{
    logger.info("ServerPlayer({})::doDeleteContainerManager", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

// there are 2 functions with the same rva

// ?getItemStackNetManager@Player@@QEAAPEAVItemStackNetManagerBase@@XZ
// ?getItemStackNetManager@Player@@QEBAPEBVItemStackNetManagerBase@@XZ

// TInstanceHook(class ItemStackNetManagerServer&, "?getItemStackNetManagerServer@ServerPlayer@@QEAAAEAVItemStackNetManagerServer@@XZ",
//     ServerPlayer){
//     logger.info("ServerPlayer({})::getItemStackNetManagerServer", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class ServerMoveInputHandler*, "?getServerMoveInputHandler@ServerPlayer@@QEAAPEAVServerMoveInputHandler@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::getServerMoveInputHandler", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?handleActorPickRequestOnServer@ServerPlayer@@QEAAXAEAVActor@@_N1@Z",
              ServerPlayer, class Actor& a0, bool a1, bool a2)
{
    logger.info("ServerPlayer({})::handleActorPickRequestOnServer", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?handleBlockPickRequestOnServer@ServerPlayer@@QEAAXAEBVBlockPos@@_N@Z",
              ServerPlayer, class BlockPos const& a0, bool a1)
{
    logger.info("ServerPlayer({})::handleBlockPickRequestOnServer", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(enum ContainerID, "?openUnmanagedContainer@ServerPlayer@@QEAA?AW4ContainerID@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::openUnmanagedContainer", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?postLoad@ServerPlayer@@QEAAX_N@Z",
              ServerPlayer, bool a0)
{
    logger.info("ServerPlayer({})::postLoad", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?selectItem@ServerPlayer@@QEAAXAEBVItemStack@@@Z",
              ServerPlayer, class ItemStack const& a0)
{
    logger.info("ServerPlayer({})::selectItem", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?sendMobEffectPackets@ServerPlayer@@QEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::sendMobEffectPackets", getName());
    original(this);
}

TInstanceHook(void, "?setClientChunkRadius@ServerPlayer@@QEAAXI@Z",
              ServerPlayer, unsigned int a0)
{
    logger.info("ServerPlayer({})::setClientChunkRadius", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setInputMode@ServerPlayer@@QEAAXAEBW4InputMode@@@Z",
              ServerPlayer, enum InputMode const& a0)
{
    logger.info("ServerPlayer({})::setInputMode", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setLocalPlayerAsInitialized@ServerPlayer@@QEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::setLocalPlayerAsInitialized", getName());
    original(this);
}

TInstanceHook(void, "?setPlayMode@ServerPlayer@@QEAAXAEBW4ClientPlayMode@@@Z",
              ServerPlayer, enum ClientPlayMode const& a0)
{
    logger.info("ServerPlayer({})::setPlayMode", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPlayerInput@ServerPlayer@@QEAAXMM_N0@Z",
              ServerPlayer, float a0, float a1, bool a2, bool a3)
{
    logger.info("ServerPlayer({})::setPlayerInput", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?setSyncTimeIfClientServerPositionMatches@ServerPlayer@@QEAAXAEBVVec3@@@Z",
              ServerPlayer, class Vec3 const& a0)
{
    logger.info("ServerPlayer({})::setSyncTimeIfClientServerPositionMatches", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?triggerRespawnFromCompletingTheEnd@ServerPlayer@@QEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::triggerRespawnFromCompletingTheEnd", getName());
    original(this);
}

// public.static : 1
THook(class ServerPlayer*, "?tryGetFromEntity@ServerPlayer@@SAPEAV1@AEAVEntityContext@@_N@Z",
      class EntityContext& a0, bool a1)
{
    logger.info("ServerPlayer::tryGetFromEntity");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// virtual : 444
TInstanceHook(void, "?initializeComponents@ServerPlayer@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              ServerPlayer, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("ServerPlayer({})::initializeComponents", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_serverInitItemStackIds@ServerPlayer@@EEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::_serverInitItemStackIds", getName());
    original(this);
}

TInstanceHook(void, "?normalTick@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::normalTick", getName());
    original(this);
}

TInstanceHook(bool, "?isValidTarget@ServerPlayer@@UEBA_NPEAVActor@@@Z",
              ServerPlayer, class Actor* a0)
{
    logger.info("ServerPlayer({})::isValidTarget", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?handleEntityEvent@ServerPlayer@@UEAAXW4ActorEvent@@H@Z",
              ServerPlayer, enum ActorEvent a0, int a1)
{
    logger.info("ServerPlayer({})::handleEntityEvent", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setArmor@ServerPlayer@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z",
              ServerPlayer, enum ArmorSlot a0, class ItemStack const& a1)
{
    logger.info("ServerPlayer({})::setArmor", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setOffhandSlot@ServerPlayer@@UEAAXAEBVItemStack@@@Z",
              ServerPlayer, class ItemStack const& a0)
{
    logger.info("ServerPlayer({})::setOffhandSlot", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?load@ServerPlayer@@UEAA_NAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              ServerPlayer, class CompoundTag const& a0, class DataLoadHelper& a1)
{
    logger.info("ServerPlayer({})::load", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?canChangeDimensions@ServerPlayer@@UEBA_NXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::canChangeDimensions", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?changeDimension@ServerPlayer@@UEAAXV?$AutomaticID@VDimension@@H@@_N@Z",
              ServerPlayer, class AutomaticID<class Dimension, int> a0, bool a1)
{
    logger.info("ServerPlayer({})::changeDimension", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(struct ActorUniqueID&, "?getControllingPlayer@ServerPlayer@@UEBA?AUActorUniqueID@@XZ",
              ServerPlayer, struct ActorUniqueID& ret)
{
    logger.info("ServerPlayer({})::getControllingPlayer", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?checkFallDamage@ServerPlayer@@UEAAXM_N@Z",
              ServerPlayer, float a0, bool a1)
{
    logger.info("ServerPlayer({})::checkFallDamage", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?handleFallDistanceOnServer@ServerPlayer@@UEAAXMM_N@Z",
              ServerPlayer, float a0, float a1, bool a2)
{
    logger.info("ServerPlayer({})::handleFallDistanceOnServer", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?onEffectAdded@ServerPlayer@@MEAAXAEAVMobEffectInstance@@@Z",
              ServerPlayer, class MobEffectInstance& a0)
{
    logger.info("ServerPlayer({})::onEffectAdded", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?onEffectUpdated@ServerPlayer@@MEAAXAEAVMobEffectInstance@@@Z",
              ServerPlayer, class MobEffectInstance& a0)
{
    logger.info("ServerPlayer({})::onEffectUpdated", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?onEffectRemoved@ServerPlayer@@MEAAXAEAVMobEffectInstance@@@Z",
              ServerPlayer, class MobEffectInstance& a0)
{
    logger.info("ServerPlayer({})::onEffectRemoved", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?die@ServerPlayer@@UEAAXAEBVActorDamageSource@@@Z",
              ServerPlayer, class ActorDamageSource const& a0)
{
    logger.info("ServerPlayer({})::die", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?knockback@ServerPlayer@@UEAAXPEAVActor@@HMMMMM@Z",
              ServerPlayer, class Actor* a0, int a1, float a2, float a3, float a4, float a5, float a6)
{
    logger.info("ServerPlayer({})::knockback", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6));
}

TInstanceHook(void, "?aiStep@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::aiStep", getName());
    original(this);
}

TInstanceHook(void, "?hurtArmorSlots@ServerPlayer@@UEAAXAEBVActorDamageSource@@HAEBV?$bitset@$03@std@@@Z",
              ServerPlayer, class ActorDamageSource const& a0, int a1, class std::bitset<4> const& a2)
{
    logger.info("ServerPlayer({})::hurtArmorSlots", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?setDamagedArmor@ServerPlayer@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z",
              ServerPlayer, enum ArmorSlot a0, class ItemStack const& a1)
{
    logger.info("ServerPlayer({})::setDamagedArmor", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?sendArmorDamage@ServerPlayer@@UEAAXAEBV?$bitset@$03@std@@@Z",
              ServerPlayer, class std::bitset<4> const& a0)
{
    logger.info("ServerPlayer({})::sendArmorDamage", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?sendArmor@ServerPlayer@@UEAAXAEBV?$bitset@$03@std@@@Z",
              ServerPlayer, class std::bitset<4> const& a0)
{
    logger.info("ServerPlayer({})::sendArmor", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?clearVanishEnchantedItemsOnDeath@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::clearVanishEnchantedItemsOnDeath", getName());
    original(this);
}

TInstanceHook(void, "?sendInventory@ServerPlayer@@UEAAX_N@Z",
              ServerPlayer, bool a0)
{
    logger.info("ServerPlayer({})::sendInventory", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?prepareRegion@ServerPlayer@@UEAAXAEAVChunkSource@@@Z",
              ServerPlayer, class ChunkSource& a0)
{
    logger.info("ServerPlayer({})::prepareRegion", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?destroyRegion@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::destroyRegion", getName());
    original(this);
}

TInstanceHook(void, "?suspendRegion@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::suspendRegion", getName());
    original(this);
}

TInstanceHook(void, "?resendAllChunks@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::resendAllChunks", getName());
    original(this);
}

TInstanceHook(void, "?changeDimensionWithCredits@ServerPlayer@@UEAAXV?$AutomaticID@VDimension@@H@@@Z",
              ServerPlayer, class AutomaticID<class Dimension, int> a0)
{
    logger.info("ServerPlayer({})::changeDimensionWithCredits", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?tickWorld@ServerPlayer@@UEAAXAEBUTick@@@Z",
              ServerPlayer, struct Tick const& a0)
{
    logger.info("ServerPlayer({})::tickWorld", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?checkMovementStats@ServerPlayer@@UEAAXAEBVVec3@@@Z",
              ServerPlayer, class Vec3 const& a0)
{
    logger.info("ServerPlayer({})::checkMovementStats", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPermissions@ServerPlayer@@UEAAXW4CommandPermissionLevel@@@Z",
              ServerPlayer, enum CommandPermissionLevel a0)
{
    logger.info("ServerPlayer({})::setPermissions", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?openTrading@ServerPlayer@@UEAAXAEBUActorUniqueID@@_N@Z",
              ServerPlayer, struct ActorUniqueID const& a0, bool a1)
{
    logger.info("ServerPlayer({})::openTrading", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?openInventory@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::openInventory", getName());
    original(this);
}

TInstanceHook(void, "?displayTextObjectMessage@ServerPlayer@@UEAAXAEBVTextObjectRoot@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z",
              ServerPlayer, class TextObjectRoot const& a0, std::string const& a1, std::string const& a2)
{
    logger.info("ServerPlayer({})::displayTextObjectMessage", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?displayTextObjectWhisperMessage@ServerPlayer@@UEAAXAEBVResolvedTextObject@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z",
              ServerPlayer, class ResolvedTextObject const& a0, std::string const& a1, std::string const& a2)
{
    logger.info("ServerPlayer({})::displayTextObjectWhisperMessage", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?displayWhisperMessage@ServerPlayer@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@000@Z",
              ServerPlayer, std::string const& a0, std::string const& a1, std::string const& a2, std::string const& a3)
{
    logger.info("ServerPlayer({})::displayWhisperMessage", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?stopSleepInBed@ServerPlayer@@UEAAX_N0@Z",
              ServerPlayer, bool a0, bool a1)
{
    logger.info("ServerPlayer({})::stopSleepInBed", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(bool, "?isHostingPlayer@ServerPlayer@@UEBA_NXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::isHostingPlayer", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isLoading@ServerPlayer@@UEBA_NXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::isLoading", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPlayerInitialized@ServerPlayer@@UEBA_NXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::isPlayerInitialized", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setPlayerGameType@ServerPlayer@@UEAAXW4GameType@@@Z",
              ServerPlayer, enum GameType a0)
{
    logger.info("ServerPlayer({})::setPlayerGameType", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setContainerData@ServerPlayer@@UEAAXAEAVIContainerManager@@HH@Z",
              ServerPlayer, class IContainerManager& a0, int a1, int a2)
{
    logger.info("ServerPlayer({})::setContainerData", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?slotChanged@ServerPlayer@@UEAAXAEAVIContainerManager@@AEAVContainer@@HAEBVItemStack@@2_N@Z",
              ServerPlayer, class IContainerManager& a0, class Container& a1, int a2, class ItemStack const& a3, class ItemStack const& a4, bool a5)
{
    logger.info("ServerPlayer({})::slotChanged", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5));
}

TInstanceHook(void, "?refreshContainer@ServerPlayer@@UEAAXAEAVIContainerManager@@@Z",
              ServerPlayer, class IContainerManager& a0)
{
    logger.info("ServerPlayer({})::refreshContainer", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?is2DPositionRelevant@ServerPlayer@@UEAA_NV?$AutomaticID@VDimension@@H@@AEBVBlockPos@@@Z",
              ServerPlayer, class AutomaticID<class Dimension, int> a0, class BlockPos const& a1)
{
    logger.info("ServerPlayer({})::is2DPositionRelevant", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?isActorRelevant@ServerPlayer@@UEAA_NAEBVActor@@@Z",
              ServerPlayer, class Actor const& a0)
{
    logger.info("ServerPlayer({})::isActorRelevant", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isTeacher@ServerPlayer@@UEBA_NXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::isTeacher", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?onSuspension@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::onSuspension", getName());
    original(this);
}

TInstanceHook(void, "?onLinkedSlotsChanged@ServerPlayer@@UEAAXXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::onLinkedSlotsChanged", getName());
    original(this);
}

TInstanceHook(void, "?sendInventoryTransaction@ServerPlayer@@UEBAXAEBVInventoryTransaction@@@Z",
              ServerPlayer, class InventoryTransaction const& a0)
{
    logger.info("ServerPlayer({})::sendInventoryTransaction", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

#include <MC/ComplexInventoryTransaction.hpp>
TInstanceHook(void, "?sendComplexInventoryTransaction@ServerPlayer@@UEBAXV?$unique_ptr@VComplexInventoryTransaction@@U?$default_delete@VComplexInventoryTransaction@@@std@@@std@@@Z",
              ServerPlayer, class std::unique_ptr<class ComplexInventoryTransaction, struct std::default_delete<class ComplexInventoryTransaction>> a0)
{
    logger.info("ServerPlayer({})::sendComplexInventoryTransaction", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?sendNetworkPacket@ServerPlayer@@UEBAXAEAVPacket@@@Z",
              ServerPlayer, class Packet& a0)
{
    logger.info("ServerPlayer({})::sendNetworkPacket", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class PlayerEventCoordinator&, "?getPlayerEventCoordinator@ServerPlayer@@UEAAAEAVPlayerEventCoordinator@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::getPlayerEventCoordinator", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class MoveInputHandler*, "?getMoveInputHandler@ServerPlayer@@UEAAPEAVMoveInputHandler@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::getMoveInputHandler", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum InputMode, "?getInputMode@ServerPlayer@@UEBA?AW4InputMode@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::getInputMode", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum ClientPlayMode, "?getPlayMode@ServerPlayer@@UEBA?AW4ClientPlayMode@@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::getPlayMode", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?reportMovementTelemetry@ServerPlayer@@UEAAXW4MovementEventType@@@Z",
              ServerPlayer, enum MovementEventType a0)
{
    logger.info("ServerPlayer({})::reportMovementTelemetry", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?_getSpawnChunkLimit@ServerPlayer@@MEBAHXZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::_getSpawnChunkLimit", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_updateChunkPublisherView@ServerPlayer@@MEAAXAEBVVec3@@M@Z",
              ServerPlayer, class Vec3 const& a0, float a1)
{
    logger.info("ServerPlayer({})::_updateChunkPublisherView", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// virtual.unordered : 4
// there are 1606 functions with the same rva

// ??$basic_vtable@C@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@D@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@E@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@F@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@G@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@H@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@I@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@M@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@N@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$VariantCRef@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBlockMaterialInstance@@@cereal@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$char_traits@D@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@VHashedString@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@PEBVItem@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@UStateNameProxy@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UTypedObjectHandle@Scripting@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UVariantCRef@cereal@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z

// TInstanceHook(void, "?frameUpdate@ServerPlayer@@UEAAXAEAVFrameUpdateContextBase@@@Z",
//     ServerPlayer, class FrameUpdateContextBase& a0){
//     logger.info("ServerPlayer({})::frameUpdate", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

// there are 1606 functions with the same rva

// ??$basic_vtable@C@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@D@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@E@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@F@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@G@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@H@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@I@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@M@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@N@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$VariantCRef@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UBlockMaterialInstance@@@cereal@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$_Wrap_alloc@V?$allocator@I@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$char_traits@D@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$hash@VHashedString@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@PEBVItem@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@UStateNameProxy@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UTypedObjectHandle@Scripting@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z
// ??$basic_vtable@U?$meta_class_template_tag@UVariantCRef@cereal@@@entt@@@meta_any@entt@@CAXW4operation@01@AEBV?$basic_any@$0BA@$07@1@PEAX@Z

// TInstanceHook(void, "?openPortfolio@ServerPlayer@@UEAAXXZ",
//     ServerPlayer){
//     logger.info("ServerPlayer({})::openPortfolio", getName());
//     original(this);
// }

TInstanceHook(class ServerPlayer&, "??1ServerPlayer@@UEAA@XZ",
              ServerPlayer)
{
    logger.info("ServerPlayer({})::~ServerPlayer", getName());
    auto& rtn = original(this);
    return rtn;
}

// there are 3 functions with the same rva

// ?openNpcInteractScreen@Player@@UEAAXV?$shared_ptr@UINpcDialogueData@@@std@@@Z
// ?requeueTask@InternalTaskGroup@@UEAAXV?$shared_ptr@VBackgroundTaskBase@@@std@@_N@Z
// ?taskRegister@InternalTaskGroup@@UEAAXV?$shared_ptr@VBackgroundTaskBase@@@std@@@Z

// #include <MC/INpcDialogueData.hpp>
// TInstanceHook(void, "?openNpcInteractScreen@ServerPlayer@@UEAAXV?$shared_ptr@UINpcDialogueData@@@std@@@Z",
//     ServerPlayer, class std::shared_ptr<struct INpcDialogueData> a0){
//     logger.info("ServerPlayer({})::openNpcInteractScreen", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

// vtbl_entry : 1

#endif // HOOK_CLASS_ServerPlayer

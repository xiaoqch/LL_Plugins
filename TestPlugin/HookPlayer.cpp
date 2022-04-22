#include "pch.h"
#include <MC/Player.hpp>


#ifdef HOOK_CLASS_Player
// child_types : 2
// parent_types : 2
// private : 8
TInstanceHook(void, "?_addLevels@Player@@AEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::_addLevels", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?_blockUsingShield@Player@@AEAA_NAEBVActorDamageSource@@M@Z",
              Player, class ActorDamageSource const& a0, float a1)
{
    logger.info("Player({})::_blockUsingShield", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?_ensureSafeSpawnPosition@Player@@AEAAXAEAVVec3@@@Z",
              Player, class Vec3& a0)
{
    logger.info("Player({})::_ensureSafeSpawnPosition", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?_findFallbackSpawnPosition@Player@@AEAA_NAEAVVec3@@V?$vector@V?$not_null@PEAVBlockSource@@@gsl@@V?$allocator@V?$not_null@PEAVBlockSource@@@gsl@@@std@@@std@@I@Z",
              Player, class Vec3& a0, class std::vector<class gsl::not_null<class BlockSource*>, class std::allocator<class gsl::not_null<class BlockSource*>>> a1, unsigned int a2)
{
    logger.info("Player({})::_findFallbackSpawnPosition", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(void, "?_handleCarriedItemInteractText@Player@@AEAAXXZ",
              Player)
{
    logger.info("Player({})::_handleCarriedItemInteractText", getName());
    original(this);
}

TInstanceHook(bool, "?_isChunkSourceLoaded@Player@@AEBA_NAEBVVec3@@AEBVBlockSource@@@Z",
              Player, class Vec3 const& a0, class BlockSource const& a1)
{
    logger.info("Player({})::_isChunkSourceLoaded", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?_registerElytraLoopSound@Player@@AEAAXXZ",
              Player)
{
    logger.info("Player({})::_registerElytraLoopSound", getName());
    original(this);
}

TInstanceHook(void, "?_sendShieldUpdatePacket@Player@@AEAAXAEBVShieldItem@@AEBVItemStack@@1W4ContainerID@@H@Z",
              Player, class ShieldItem const& a0, class ItemStack const& a1, class ItemStack const& a2, enum ContainerID a3, int a4)
{
    logger.info("Player({})::_sendShieldUpdatePacket", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4));
}

// protected : 8
TInstanceHook(bool, "?_checkAndFixSpawnPosition@Player@@IEBA_NAEAVVec3@@V?$vector@V?$not_null@PEAVBlockSource@@@gsl@@V?$allocator@V?$not_null@PEAVBlockSource@@@gsl@@@std@@@std@@_N2222@Z",
              Player, class Vec3& a0, class std::vector<class gsl::not_null<class BlockSource*>, class std::allocator<class gsl::not_null<class BlockSource*>>> a1, bool a2, bool a3, bool a4, bool a5, bool a6)
{
    logger.info("Player({})::_checkAndFixSpawnPosition", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6));
    return rtn;
}

TInstanceHook(void, "?_chooseSpawnArea@Player@@IEAAXXZ",
              Player)
{
    logger.info("Player({})::_chooseSpawnArea", getName());
    original(this);
}

TInstanceHook(bool, "?_chooseSpawnPositionWithinArea@Player@@IEAA_NXZ",
              Player)
{
    logger.info("Player({})::_chooseSpawnPositionWithinArea", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_registerPlayerAttributes@Player@@IEAAXXZ",
              Player)
{
    logger.info("Player({})::_registerPlayerAttributes", getName());
    original(this);
}

TInstanceHook(void, "?_updateInteraction@Player@@IEAAXXZ",
              Player)
{
    logger.info("Player({})::_updateInteraction", getName());
    original(this);
}

TInstanceHook(bool, "?_validateSpawnPositionAvailability@Player@@IEBA_NAEBVVec3@@PEAVBlockSource@@QEBV2@@Z",
              Player, class Vec3 const& a0, class BlockSource* a1, class Vec3 const* a2)
{
    logger.info("Player({})::_validateSpawnPositionAvailability", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(bool, "?checkBed@Player@@IEAA_NPEAVBlockSource@@QEBVVec3@@@Z",
              Player, class BlockSource* a0, class Vec3 const* a1)
{
    logger.info("Player({})::checkBed", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?checkSpawnBlock@Player@@IEBA_NAEBVBlockSource@@@Z",
              Player, class BlockSource const& a0)
{
    logger.info("Player({})::checkSpawnBlock", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

// public : 120
// there are 2 functions with the same rva

// ?getItemStackNetManager@Player@@QEBAPEBVItemStackNetManagerBase@@XZ
// ?getItemStackNetManagerServer@ServerPlayer@@QEAAAEAVItemStackNetManagerServer@@XZ

// TInstanceHook(class ItemStackNetManagerBase*, "?getItemStackNetManager@Player@@QEAAPEAVItemStackNetManagerBase@@XZ",
//     Player){
//     logger.info("Player({})::getItemStackNetManager", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 2 functions with the same rva

// ?getItemStackNetManager@Player@@QEAAPEAVItemStackNetManagerBase@@XZ
// ?getItemStackNetManagerServer@ServerPlayer@@QEAAAEAVItemStackNetManagerServer@@XZ

// TInstanceHook(class ItemStackNetManagerBase const*, "?getItemStackNetManager@Player@@QEBAPEBVItemStackNetManagerBase@@XZ",
//     Player){
//     logger.info("Player({})::getItemStackNetManager", getName());
//     auto rtn = original(this);
//     return rtn;
// }

#include <MC/Certificate.hpp>
TInstanceHook(class Player&, "??0Player@@QEAA@AEAVLevel@@AEAVPacketSender@@W4GameType@@AEBVNetworkIdentifier@@EVUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$unique_ptr@VCertificate@@U?$default_delete@VCertificate@@@std@@@8@AEAVEntityContext@@55@Z",
              Player, class Level& a0, class PacketSender& a1, enum GameType a2, class NetworkIdentifier const& a3, unsigned char a4, class mce::UUID a5, std::string const& a6, class std::unique_ptr<class Certificate, struct std::default_delete<class Certificate>> a7, class EntityContext& a8, std::string const& a9, std::string const& a10)
{
    logger.info("Player::Player");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6), std::forward<decltype(a7)>(a7), std::forward<decltype(a8)>(a8), std::forward<decltype(a9)>(a9), std::forward<decltype(a10)>(a10));
    return rtn;
}

TInstanceHook(void, "?broadcastPlayerSpawnedMobEvent@Player@@QEAAXW4ActorType@@W4MobSpawnMethod@@@Z",
              Player, enum ActorType a0, enum MobSpawnMethod a1)
{
    logger.info("Player({})::broadcastPlayerSpawnedMobEvent", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(bool, "?canBeSeenOnMap@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::canBeSeenOnMap", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canDestroy@Player@@QEBA_NAEBVBlock@@@Z",
              Player, class Block const& a0)
{
    logger.info("Player({})::canDestroy", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canUseAbility@Player@@QEBA_NW4AbilitiesIndex@@@Z",
              Player, enum AbilitiesIndex a0)
{
    logger.info("Player({})::canUseAbility", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canUseOperatorBlocks@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::canUseOperatorBlocks", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?causeFoodExhaustion@Player@@QEAAXM@Z",
              Player, float a0)
{
    logger.info("Player({})::causeFoodExhaustion", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?clearRespawnPosition@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::clearRespawnPosition", getName());
    original(this);
}

TInstanceHook(void, "?eat@Player@@QEAAXAEBVItemStack@@@Z",
              Player, class ItemStack const& a0)
{
    logger.info("Player({})::eat", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?eat@Player@@QEAAXHM@Z",
              Player, int a0, float a1)
{
    logger.info("Player({})::eat", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(bool, "?equippedArmorItemCanBeMoved@Player@@QEBA_NAEBVItemStack@@@Z",
              Player, class ItemStack const& a0)
{
    logger.info("Player({})::equippedArmorItemCanBeMoved", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?fireDimensionChangedEvent@Player@@QEAAXV?$AutomaticID@VDimension@@H@@@Z",
              Player, class AutomaticID<class Dimension, int> a0)
{
    logger.info("Player({})::fireDimensionChangedEvent", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?forceAllowEating@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::forceAllowEating", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Agent*, "?getAgent@Player@@QEBAPEAVAgent@@XZ",
              Player)
{
    logger.info("Player({})::getAgent", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorUniqueID&, "?getAgentID@Player@@QEBA?AUActorUniqueID@@XZ",
              Player, struct ActorUniqueID& ret)
{
    logger.info("Player({})::getAgentID", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class Agent*, "?getAgentIfAllowed@Player@@QEBAPEAVAgent@@_NUActorUniqueID@@@Z",
              Player, bool a0, struct ActorUniqueID a1)
{
    logger.info("Player({})::getAgentIfAllowed", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// there are 1 functions with the same rva

// ?getBedPosition@Player@@QEBAAEBVBlockPos@@XZ

// TInstanceHook(class BlockPos const&, "?getRespawnAnchorPosition@Player@@QEBAAEBVBlockPos@@XZ",
//     Player){
//     logger.info("Player({})::getRespawnAnchorPosition", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getRespawnAnchorPosition@Player@@QEBAAEBVBlockPos@@XZ

// TInstanceHook(class BlockPos const&, "?getBedPosition@Player@@QEBAAEBVBlockPos@@XZ",
//     Player){
//     logger.info("Player({})::getBedPosition", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(__int64&, "?getBlockedUsingDamagedShieldTimeStamp@Player@@QEBA_JXZ",
              Player, __int64& ret)
{
    logger.info("Player({})::getBlockedUsingDamagedShieldTimeStamp", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(__int64&, "?getBlockedUsingShieldTimeStamp@Player@@QEBA_JXZ",
              Player, __int64& ret)
{
    logger.info("Player({})::getBlockedUsingShieldTimeStamp", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(__int64&, "?getBlockingStartTimeStamp@Player@@QEBA_JXZ",
              Player, __int64& ret)
{
    logger.info("Player({})::getBlockingStartTimeStamp", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class Vec3&, "?getCapePos@Player@@QEAA?AVVec3@@M@Z",
              Player, class Vec3& ret, float a0)
{
    logger.info("Player({})::getCapePos", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

// there are 1 functions with the same rva

// ?getCarriedItem@Player@@UEBAAEBVItemStack@@XZ

// TInstanceHook(class ItemStack const&, "?getSelectedItem@Player@@QEBAAEBVItemStack@@XZ",
//     Player){
//     logger.info("Player({})::getSelectedItem", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

#include <MC/IContainerManager.hpp>
TInstanceHook(std::weak_ptr<class IContainerManager>&, "?getContainerManager@Player@@QEAA?AV?$weak_ptr@VIContainerManager@@@std@@XZ",
              Player, std::weak_ptr<class IContainerManager>& ret)
{
    logger.info("Player({})::getContainerManager", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getCurrentActiveShield@Player@@QEBAAEBVItemStack@@XZ",
              Player)
{
    logger.info("Player({})::getCurrentActiveShield", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getDestroyProgress@Player@@QEBAMAEBVBlock@@@Z",
              Player, class Block const& a0)
{
    logger.info("Player({})::getDestroyProgress", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getDestroySpeed@Player@@QEBAMAEBVBlock@@@Z",
              Player, class Block const& a0)
{
    logger.info("Player({})::getDestroySpeed", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getDirection@Player@@QEBAHXZ",
              Player)
{
    logger.info("Player({})::getDirection", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getEnchantmentSeed@Player@@QEBAHXZ",
              Player)
{
    logger.info("Player({})::getEnchantmentSeed", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void* /*class AutomaticID<class Dimension, int>&*/, "?getExpectedSpawnDimensionId@Player@@QEBA?AV?$AutomaticID@VDimension@@H@@XZ",
              Player, class AutomaticID<class Dimension, int>& ret)
{
    logger.info("Player({})::getExpectedSpawnDimensionId", getName());
    auto rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class BlockPos const&, "?getExpectedSpawnPosition@Player@@QEBAAEBVBlockPos@@XZ",
              Player)
{
    logger.info("Player({})::getExpectedSpawnPosition", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(std::string&, "?getInteractText@Player@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Player, std::string& ret)
{
    logger.info("Player({})::getInteractText", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class Container&, "?getInventory@Player@@QEAAAEAVContainer@@XZ",
              Player)
{
    logger.info("Player({})::getInventory", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getItemInUse@Player@@QEBAAEBVItemStack@@XZ",
              Player)
{
    logger.info("Player({})::getItemInUse", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(std::string&, "?getItemInteractText@Player@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVItem@@@Z",
              Player, std::string& ret, class Item const& a0)
{
    logger.info("Player({})::getItemInteractText", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getLuck@Player@@QEAAMXZ",
              Player)
{
    logger.info("Player({})::getLuck", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getMapIndex@Player@@QEAAHXZ",
              Player)
{
    logger.info("Player({})::getMapIndex", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?getNewEnchantmentSeed@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::getNewEnchantmentSeed", getName());
    original(this);
}

TInstanceHook(class AABB&, "?getPickupArea@Player@@QEBA?AVAABB@@XZ",
              Player, class AABB& ret)
{
    logger.info("Player({})::getPickupArea", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(enum BuildPlatform, "?getPlatform@Player@@QEBA?AW4BuildPlatform@@XZ",
              Player)
{
    logger.info("Player({})::getPlatform", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::string const&, "?getPlatformOnlineId@Player@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Player)
{
    logger.info("Player({})::getPlatformOnlineId", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(enum GameType, "?getPlayerGameType@Player@@QEBA?AW4GameType@@XZ",
              Player)
{
    logger.info("Player({})::getPlayerGameType", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getPlayerIndex@Player@@QEBAHXZ",
              Player)
{
    logger.info("Player({})::getPlayerIndex", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getPlayerLevel@Player@@QEBAHXZ",
              Player)
{
    logger.info("Player({})::getPlayerLevel", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum PlayerPermissionLevel, "?getPlayerPermissionLevel@Player@@QEBA?AW4PlayerPermissionLevel@@XZ",
              Player)
{
    logger.info("Player({})::getPlayerPermissionLevel", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::string const&, "?getPlayerSessionId@Player@@QEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Player)
{
    logger.info("Player({})::getPlayerSessionId", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getPlayerUIItem@Player@@QEAAAEBVItemStack@@W4PlayerUISlot@@@Z",
              Player, enum PlayerUISlot a0)
{
    logger.info("Player({})::getPlayerUIItem", getName());
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getSelectedItemSlot@Player@@QEBAHXZ",
              Player)
{
    logger.info("Player({})::getSelectedItemSlot", getName());
    auto rtn = original(this);
    return rtn;
}

// there are 2 functions with the same rva

// ?getImmersiveReaderString@Level@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// ?getSkin@Player@@QEBAAEBVSerializedSkin@@XZ

// TInstanceHook(class SerializedSkin&, "?getSkin@Player@@QEAAAEAVSerializedSkin@@XZ",
//     Player){
//     logger.info("Player({})::getSkin", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 2 functions with the same rva

// ?getImmersiveReaderString@Level@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
// ?getSkin@Player@@QEAAAEAVSerializedSkin@@XZ

// TInstanceHook(class SerializedSkin const&, "?getSkin@Player@@QEBAAEBVSerializedSkin@@XZ",
//     Player){
//     logger.info("Player({})::getSkin", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(float, "?getSleepRotation@Player@@QEBAMXZ",
              Player)
{
    logger.info("Player({})::getSleepRotation", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void* /*class AutomaticID<class Dimension, int>&*/, "?getSpawnDimension@Player@@QEBA?AV?$AutomaticID@VDimension@@H@@XZ",
              Player, class AutomaticID<class Dimension, int>& ret)
{
    logger.info("Player({})::getSpawnDimension", getName());
    auto rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class BlockPos const&, "?getSpawnPosition@Player@@QEBAAEBVBlockPos@@XZ",
              Player)
{
    logger.info("Player({})::getSpawnPosition", getName());
    auto& rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getSupplies@Player@@QEBAAEBVPlayerInventory@@XZ

// TInstanceHook(class PlayerInventory&, "?getSupplies@Player@@QEAAAEAVPlayerInventory@@XZ",
//     Player){
//     logger.info("Player({})::getSupplies", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getSupplies@Player@@QEAAAEAVPlayerInventory@@XZ

// TInstanceHook(class PlayerInventory const&, "?getSupplies@Player@@QEBAAEBVPlayerInventory@@XZ",
//     Player){
//     logger.info("Player({})::getSupplies", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(std::vector<struct ActorUniqueID> const&, "?getTrackedBosses@Player@@QEAAAEBV?$vector@UActorUniqueID@@V?$allocator@UActorUniqueID@@@std@@@std@@XZ",
              Player)
{
    logger.info("Player({})::getTrackedBosses", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(enum GameType, "?getUnmappedPlayerGameType@Player@@QEBA?AW4GameType@@XZ",
              Player)
{
    logger.info("Player({})::getUnmappedPlayerGameType", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?getUsedPotion@Player@@QEAA_NXZ",
              Player)
{
    logger.info("Player({})::getUsedPotion", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getXpNeededForNextLevel@Player@@QEBAHXZ",
              Player)
{
    logger.info("Player({})::getXpNeededForNextLevel", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasBedPosition@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::hasBedPosition", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasOpenContainer@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::hasOpenContainer", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasOpenContainerOfContainerType@Player@@QEBA_NW4ContainerType@@@Z",
              Player, enum ContainerType a0)
{
    logger.info("Player({})::hasOpenContainerOfContainerType", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasOwnedChunkSource@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::hasOwnedChunkSource", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasResource@Player@@QEAA_NAEBVItemDescriptor@@@Z",
              Player, class ItemDescriptor const& a0)
{
    logger.info("Player({})::hasResource", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasRespawnAnchorPosition@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::hasRespawnAnchorPosition", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasRespawnPosition@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::hasRespawnPosition", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?interact@Player@@QEAA_NAEAVActor@@AEBVVec3@@@Z",
              Player, class Actor& a0, class Vec3 const& a1)
{
    logger.info("Player({})::interact", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?isBouncing@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isBouncing", getName());
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?isCreative@Player@@UEBA_NXZ

// TInstanceHook(bool, "?isInCreativeMode@Player@@QEBA_NXZ",
//     Player){
//     logger.info("Player({})::isInCreativeMode", getName());
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(bool, "?isForcedRespawn@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isForcedRespawn", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isHiddenFrom@Player@@QEBA_NAEAVMob@@@Z",
              Player, class Mob& a0)
{
    logger.info("Player({})::isHiddenFrom", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isHungry@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isHungry", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isHurt@Player@@QEAA_NXZ",
              Player)
{
    logger.info("Player({})::isHurt", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInRaid@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isInRaid", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isRespawningFromTheEnd@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isRespawningFromTheEnd", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSleepingLongEnough@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isSleepingLongEnough", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSpawned@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isSpawned", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSurvival@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isSurvival", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isUsingItem@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::isUsingItem", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?moveSpawnView@Player@@QEAAXAEBVVec3@@V?$AutomaticID@VDimension@@H@@@Z",
              Player, class Vec3 const& a0, class AutomaticID<class Dimension, int> a1)
{
    logger.info("Player({})::moveSpawnView", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?recheckSpawnPosition@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::recheckSpawnPosition", getName());
    original(this);
}

TInstanceHook(void, "?releaseUsingItem@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::releaseUsingItem", getName());
    original(this);
}

// there are 1 functions with the same rva

// ?replaceCurrentItem@@YAXAEAVPlayer@@AEAVItemStack@@@Z

// TInstanceHook(void, "?setSelectedItem@Player@@QEAAXAEBVItemStack@@@Z",
//     Player, class ItemStack const& a0){
//     logger.info("Player({})::setSelectedItem", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?resetPlayerLevel@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::resetPlayerLevel", getName());
    original(this);
}

TInstanceHook(void, "?resetToDefaultGameMode@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::resetToDefaultGameMode", getName());
    original(this);
}

TInstanceHook(void, "?setAgent@Player@@QEAAXPEAVAgent@@@Z",
              Player, class Agent* a0)
{
    logger.info("Player({})::setAgent", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setAllPlayersSleeping@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::setAllPlayersSleeping", getName());
    original(this);
}

TInstanceHook(void, "?setBedRespawnPosition@Player@@QEAAXAEBVBlockPos@@@Z",
              Player, class BlockPos const& a0)
{
    logger.info("Player({})::setBedRespawnPosition", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setBlockRespawnUntilClientMessage@Player@@QEAAX_N@Z",
              Player, bool a0)
{
    logger.info("Player({})::setBlockRespawnUntilClientMessage", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setChunkRadius@Player@@QEAAXI@Z",
              Player, unsigned int a0)
{
    logger.info("Player({})::setChunkRadius", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

#include <MC/IContainerManager.hpp>
TInstanceHook(void, "?setContainerManager@Player@@QEAAXV?$shared_ptr@VIContainerManager@@@std@@@Z",
              Player, class std::shared_ptr<class IContainerManager> a0)
{
    logger.info("Player({})::setContainerManager", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCursorSelectedItem@Player@@QEAAXAEBVItemStack@@@Z",
              Player, class ItemStack const& a0)
{
    logger.info("Player({})::setCursorSelectedItem", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCursorSelectedItemGroup@Player@@QEAAXAEBVItemGroup@@@Z",
              Player, class ItemGroup const& a0)
{
    logger.info("Player({})::setCursorSelectedItemGroup", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setEnchantmentSeed@Player@@QEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::setEnchantmentSeed", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setHasSeenCredits@Player@@QEAAX_N@Z",
              Player, bool a0)
{
    logger.info("Player({})::setHasSeenCredits", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setMapIndex@Player@@QEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::setMapIndex", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPlatformOnlineId@Player@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Player, std::string const& a0)
{
    logger.info("Player({})::setPlatformOnlineId", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPlayerIndex@Player@@QEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::setPlayerIndex", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPlayerUIItem@Player@@QEAAXW4PlayerUISlot@@AEBVItemStack@@@Z",
              Player, enum PlayerUISlot a0, class ItemStack const& a1)
{
    logger.info("Player({})::setPlayerUIItem", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setRespawnPosition@Player@@QEAAXAEBVBlockPos@@V?$AutomaticID@VDimension@@H@@@Z",
              Player, class BlockPos const& a0, class AutomaticID<class Dimension, int> a1)
{
    logger.info("Player({})::setRespawnPosition", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setRespawnPositionCandidate@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::setRespawnPositionCandidate", getName());
    original(this);
}

TInstanceHook(void, "?setRespawnReady@Player@@QEAAXAEBVVec3@@@Z",
              Player, class Vec3 const& a0)
{
    logger.info("Player({})::setRespawnReady", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class ItemStack const&, "?setSelectedSlot@Player@@QEAAAEBVItemStack@@H@Z",
              Player, int a0)
{
    logger.info("Player({})::setSelectedSlot", getName());
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?setSpawnBlockRespawnPosition@Player@@QEAAXAEBVBlockPos@@V?$AutomaticID@VDimension@@H@@@Z",
              Player, class BlockPos const& a0, class AutomaticID<class Dimension, int> a1)
{
    logger.info("Player({})::setSpawnBlockRespawnPosition", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setUsedPotion@Player@@QEAAX_N@Z",
              Player, bool a0)
{
    logger.info("Player({})::setUsedPotion", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?shouldShowCredits@Player@@QEBA_NXZ",
              Player)
{
    logger.info("Player({})::shouldShowCredits", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?spawnExperienceOrb@Player@@QEAAXAEBVVec3@@H@Z",
              Player, class Vec3 const& a0, int a1)
{
    logger.info("Player({})::spawnExperienceOrb", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?startCooldown@Player@@QEAAXAEBVHashedString@@H_N@Z",
              Player, class HashedString const& a0, int a1, bool a2)
{
    logger.info("Player({})::startCooldown", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?startGliding@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::startGliding", getName());
    original(this);
}

TInstanceHook(void, "?startUsingItem@Player@@QEAAXAEBVItemStack@@H@Z",
              Player, class ItemStack const& a0, int a1)
{
    logger.info("Player({})::startUsingItem", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?stopGliding@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::stopGliding", getName());
    original(this);
}

TInstanceHook(void, "?stopUsingItem@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::stopUsingItem", getName());
    original(this);
}

TInstanceHook(bool, "?take@Player@@QEAA_NAEAVActor@@HH@Z",
              Player, class Actor& a0, int a1, int a2)
{
    logger.info("Player({})::take", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(void, "?updateInventoryTransactions@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::updateInventoryTransactions", getName());
    original(this);
}

TInstanceHook(void, "?updateSkin@Player@@QEAAXAEBVSerializedSkin@@H@Z",
              Player, class SerializedSkin const& a0, int a1)
{
    logger.info("Player({})::updateSkin", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?updateSpawnChunkView@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::updateSpawnChunkView", getName());
    original(this);
}

TInstanceHook(void, "?updateTrackedBosses@Player@@QEAAXXZ",
              Player)
{
    logger.info("Player({})::updateTrackedBosses", getName());
    original(this);
}

TInstanceHook(void, "?useSelectedItem@Player@@QEAAXW4ItemUseMethod@@_N@Z",
              Player, enum ItemUseMethod a0, bool a1)
{
    logger.info("Player({})::useSelectedItem", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// public.static : 43
THook(void, "?_aiStep@Player@@SAXAEAUIPlayerMovementProxy@@@Z",
      struct IPlayerMovementProxy& a0)
{
    logger.info("Player::_aiStep");
    original(std::forward<decltype(a0)>(a0));
}

THook(void, "?_jumpFromGround@Player@@SAXAEAUIPlayerMovementProxy@@@Z",
      struct IPlayerMovementProxy& a0)
{
    logger.info("Player::_jumpFromGround");
    original(std::forward<decltype(a0)>(a0));
}

THook(void, "?_travel@Player@@SAXAEAUIPlayerMovementProxy@@MMM@Z",
      struct IPlayerMovementProxy& a0, float a1, float a2, float a3)
{
    logger.info("Player::_travel");
    original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

THook(bool, "?canJump@Player@@SA_NAEAUIPlayerMovementProxy@@@Z",
      struct IPlayerMovementProxy& a0)
{
    logger.info("Player::canJump");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?checkAndFixSpawnPosition@Player@@SA_NAEAVVec3@@V?$vector@V?$not_null@PEAVBlockSource@@@gsl@@V?$allocator@V?$not_null@PEAVBlockSource@@@gsl@@@std@@@std@@VAABB@@_N33333F@Z",
      class Vec3& a0, class std::vector<class gsl::not_null<class BlockSource*>, class std::allocator<class gsl::not_null<class BlockSource*>>> a1, class AABB a2, bool a3, bool a4, bool a5, bool a6, bool a7, bool a8, short a9)
{
    logger.info("Player::checkAndFixSpawnPosition");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6), std::forward<decltype(a7)>(a7), std::forward<decltype(a8)>(a8), std::forward<decltype(a9)>(a9));
    return rtn;
}

THook(bool, "?checkNeedAutoJump@Player@@SA_NPEAUIPlayerMovementProxy@@MM@Z",
      struct IPlayerMovementProxy* a0, float a1, float a2)
{
    logger.info("Player::checkNeedAutoJump");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(void, "?goDownInWater@Player@@SAXAEAUIActorMovementProxy@@@Z",
      struct IActorMovementProxy& a0)
{
    logger.info("Player::goDownInWater");
    original(std::forward<decltype(a0)>(a0));
}

THook(void, "?handleJumpEffects@Player@@SAXAEAUIPlayerMovementProxy@@@Z",
      struct IPlayerMovementProxy& a0)
{
    logger.info("Player::handleJumpEffects");
    original(std::forward<decltype(a0)>(a0));
}

THook(class Player*, "?tryGetFromComponent@Player@@SAPEAV1@AEBV?$FlagComponent@UPlayerComponentFlag@@@@AEAVActorOwnerComponent@@_N@Z",
      class FlagComponent<struct PlayerComponentFlag> const& a0, class ActorOwnerComponent& a1, bool a2)
{
    logger.info("Player::tryGetFromComponent");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(class Player*, "?tryGetFromEntity@Player@@SAPEAV1@AEAVEntityContext@@_N@Z",
      class EntityContext& a0, bool a1)
{
    logger.info("Player::tryGetFromEntity");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

//THook(class Player*, "?tryGetFromEntity@Player@@SAPEAV1@V?$StackRefResultT@UEntityRefTraits@@@@_N@Z",
//      class StackRefResultT<struct EntityRefTraits> a0, bool a1)
//{
//    logger.info("Player::tryGetFromEntity");
//    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
//    return rtn;
//}

THook(float const&, "?DEFAULT_PLAYER_HEIGHT_OFFSET@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DEFAULT_PLAYER_HEIGHT_OFFSET");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_GLIDING_CAMERA_OFFSET@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_GLIDING_CAMERA_OFFSET");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SWIMMING_CAMERA_OFFSET@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SWIMMING_CAMERA_OFFSET");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SLEEPING_CAMERA_OFFSET@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SLEEPING_CAMERA_OFFSET");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SNEAK_OFFSET@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SNEAK_OFFSET");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_UP_SWIM_SPEED@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_UP_SWIM_SPEED");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_DOWN_SWIM_SPEED@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_DOWN_SWIM_SPEED");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SWIM_FLY_MULTI@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SWIM_FLY_MULTI");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SWIM_BREACH_ANGLE@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SWIM_BREACH_ANGLE");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SWIM_ENTER_THRESHOLD@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SWIM_ENTER_THRESHOLD");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_BB_WIDTH@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DEFAULT_BB_WIDTH");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_BB_HEIGHT@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DEFAULT_BB_HEIGHT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DISTANCE_TO_TRAVELLED_EVENT@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DISTANCE_TO_TRAVELLED_EVENT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DISTANCE_TO_TRANSFORM_EVENT@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DISTANCE_TO_TRANSFORM_EVENT");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?GLIDE_STOP_DELAY@Player@@2HB",
      int const& ret)
{
    logger.info("Player::GLIDE_STOP_DELAY");
    auto& rtn = original(ret);
    return rtn;
}

THook(unsigned int const&, "?SPAWN_CHUNK_RADIUS@Player@@2IB",
      unsigned int const& ret)
{
    logger.info("Player::SPAWN_CHUNK_RADIUS");
    auto& rtn = original(ret);
    return rtn;
}

THook(unsigned int const&, "?SPAWN_CHUNK_LARGE_JUMP@Player@@2IB",
      unsigned int const& ret)
{
    logger.info("Player::SPAWN_CHUNK_LARGE_JUMP");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_ALIVE_HEIGHT@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_ALIVE_HEIGHT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_ALIVE_WIDTH@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_ALIVE_WIDTH");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_DEAD_HEIGHT@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_DEAD_HEIGHT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_DEAD_WIDTH@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_DEAD_WIDTH");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SLEEPING_HEIGHT@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SLEEPING_HEIGHT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?PLAYER_SLEEPING_WIDTH@Player@@2MB",
      float const& ret)
{
    logger.info("Player::PLAYER_SLEEPING_WIDTH");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_WALK_SPEED@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DEFAULT_WALK_SPEED");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_FLY_SPEED@Player@@2MB",
      float const& ret)
{
    logger.info("Player::DEFAULT_FLY_SPEED");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?MAX_ITEM_USE_DURATION@Player@@2HB",
      int const& ret)
{
    logger.info("Player::MAX_ITEM_USE_DURATION");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?ITEM_USE_INTERVAL_DURATION@Player@@2HB",
      int const& ret)
{
    logger.info("Player::ITEM_USE_INTERVAL_DURATION");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Attribute const&, "?HUNGER@Player@@2VAttribute@@B",
      class Attribute const& ret)
{
    logger.info("Player::HUNGER");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Attribute const&, "?SATURATION@Player@@2VAttribute@@B",
      class Attribute const& ret)
{
    logger.info("Player::SATURATION");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Attribute const&, "?EXHAUSTION@Player@@2VAttribute@@B",
      class Attribute const& ret)
{
    logger.info("Player::EXHAUSTION");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Attribute const&, "?LEVEL@Player@@2VAttribute@@B",
      class Attribute const& ret)
{
    logger.info("Player::LEVEL");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Attribute const&, "?EXPERIENCE@Player@@2VAttribute@@B",
      class Attribute const& ret)
{
    logger.info("Player::EXPERIENCE");
    auto& rtn = original(ret);
    return rtn;
}

// virtual : 442
TInstanceHook(void, "?reloadHardcoded@Player@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              Player, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Player({})::reloadHardcoded", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?initializeComponents@Player@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              Player, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Player({})::initializeComponents", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?remove@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::remove", getName());
    original(this);
}

TInstanceHook(class Vec3&, "?getAttachPos@Player@@UEBA?AVVec3@@W4ActorLocation@@M@Z",
              Player, class Vec3& ret, enum ActorLocation a0, float a1)
{
    logger.info("Player({})::getAttachPos", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?move@Player@@UEAAXAEBVVec3@@@Z",
              Player, class Vec3 const& a0)
{
    logger.info("Player({})::move", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?move@Player@@UEBAXAEAUIActorMovementProxy@@AEBVVec3@@@Z",
              Player, struct IActorMovementProxy& a0, class Vec3 const& a1)
{
    logger.info("Player({})::move", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?teleportTo@Player@@UEAAXAEBVVec3@@_NHH@Z",
              Player, class Vec3 const& a0, bool a1, int a2, int a3)
{
    logger.info("Player({})::teleportTo", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

#include <MC/AddActorBasePacket.hpp>
TInstanceHook(std::unique_ptr<class AddActorBasePacket>&, "?tryCreateAddActorPacket@Player@@UEAA?AV?$unique_ptr@VAddActorBasePacket@@U?$default_delete@VAddActorBasePacket@@@std@@@std@@XZ",
              Player, std::unique_ptr<class AddActorBasePacket>& ret)
{
    logger.info("Player({})::tryCreateAddActorPacket", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?normalTick@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::normalTick", getName());
    original(this);
}

TInstanceHook(void, "?vehicleTick@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::vehicleTick", getName());
    original(this);
}

TInstanceHook(float, "?getRidingHeight@Player@@UEAAMXZ",
              Player)
{
    logger.info("Player({})::getRidingHeight", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::string&, "?getFormattedNameTag@Player@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Player, std::string& ret)
{
    logger.info("Player({})::getFormattedNameTag", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(float, "?getCameraOffset@Player@@UEBAMXZ",
              Player)
{
    logger.info("Player({})::getCameraOffset", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isImmobile@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::isImmobile", getName());
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?chunkHasConvertedDataTag@LevelChunk@@QEBA_NXZ

// TInstanceHook(bool, "?isSleeping@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isSleeping", getName());
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(void, "?setSleeping@Player@@UEAAX_N@Z",
              Player, bool a0)
{
    logger.info("Player({})::setSleeping", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isBlocking@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::isBlocking", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isDamageBlocked@Player@@UEBA_NAEBVActorDamageSource@@@Z",
              Player, class ActorDamageSource const& a0)
{
    logger.info("Player({})::isDamageBlocked", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
              Player, class Actor& a0, enum ActorDamageCause const& a1)
{
    logger.info("Player({})::attack", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?adjustDamageAmount@Player@@UEBAXAEAH@Z",
              Player, int& a0)
{
    logger.info("Player({})::adjustDamageAmount", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isJumping@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::isJumping", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInvulnerableTo@Player@@UEBA_NAEBVActorDamageSource@@@Z",
              Player, class ActorDamageSource const& a0)
{
    logger.info("Player({})::isInvulnerableTo", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?actuallyHurt@Player@@UEAAXHAEBVActorDamageSource@@_N@Z",
              Player, int a0, class ActorDamageSource const& a1, bool a2)
{
    logger.info("Player({})::actuallyHurt", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?onBounceStarted@Player@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z",
              Player, class BlockPos const& a0, class Block const& a1)
{
    logger.info("Player({})::onBounceStarted", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?feed@Player@@UEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::feed", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?handleEntityEvent@Player@@UEAAXW4ActorEvent@@H@Z",
              Player, enum ActorEvent a0, int a1)
{
    logger.info("Player({})::handleEntityEvent", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(class HashedString const&, "?getActorRendererId@Player@@UEBAAEBVHashedString@@XZ",
              Player)
{
    logger.info("Player({})::getActorRendererId", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?awardKillScore@Player@@UEAAXAEAVActor@@H@Z",
              Player, class Actor& a0, int a1)
{
    logger.info("Player({})::awardKillScore", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setArmor@Player@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z",
              Player, enum ArmorSlot a0, class ItemStack const& a1)
{
    logger.info("Player({})::setArmor", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// there are 1 functions with the same rva

// ?getSelectedItem@Player@@QEBAAEBVItemStack@@XZ

// TInstanceHook(class ItemStack const&, "?getCarriedItem@Player@@UEBAAEBVItemStack@@XZ",
//     Player){
//     logger.info("Player({})::getCarriedItem", getName());
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(void, "?setCarriedItem@Player@@UEAAXAEBVItemStack@@@Z",
              Player, class ItemStack const& a0)
{
    logger.info("Player({})::setCarriedItem", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setOffhandSlot@Player@@UEAAXAEBVItemStack@@@Z",
              Player, class ItemStack const& a0)
{
    logger.info("Player({})::setOffhandSlot", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class ItemStack const&, "?getEquippedTotem@Player@@UEBAAEBVItemStack@@XZ",
              Player)
{
    logger.info("Player({})::getEquippedTotem", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?consumeTotem@Player@@UEAA_NXZ",
              Player)
{
    logger.info("Player({})::consumeTotem", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum ActorType, "?getEntityTypeId@Player@@UEBA?AW4ActorType@@XZ",
              Player)
{
    logger.info("Player({})::getEntityTypeId", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canFreeze@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::canFreeze", getName());
    auto rtn = original(this);
    return rtn;
}

// there are 6 functions with the same rva

// ?getContainerOffset@LoomDyeContainerValidation@@UEBAHAEBVContainerScreenContext@@@Z
// ?getContainerSize@CauldronBlockActor@@UEBAHXZ
// ?getCooldownTime@IceBombItem@@UEBAHXZ
// ?getId@SetTimePacket@@UEBA?AW4MinecraftPacketIds@@XZ
// ?getTickDelay@WeightedPressurePlateBlock@@UEBAHXZ
// ?size@BannerAddPatternRecipe@@UEBAHXZ

// TInstanceHook(int, "?getPortalCooldown@Player@@UEBAHXZ",
//     Player){
//     logger.info("Player({})::getPortalCooldown", getName());
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(int, "?getPortalWaitTime@Player@@UEBAHXZ",
              Player)
{
    logger.info("Player({})::getPortalWaitTime", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?onSynchedDataUpdate@Player@@UEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::onSynchedDataUpdate", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?canAddPassenger@Player@@UEBA_NAEAVActor@@@Z",
              Player, class Actor& a0)
{
    logger.info("Player({})::canAddPassenger", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?startSwimming@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::startSwimming", getName());
    original(this);
}

TInstanceHook(void, "?stopSwimming@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::stopSwimming", getName());
    original(this);
}

TInstanceHook(enum CommandPermissionLevel, "?getCommandPermissionLevel@Player@@UEBA?AW4CommandPermissionLevel@@XZ",
              Player)
{
    logger.info("Player({})::getCommandPermissionLevel", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class AnimationComponent&, "?getAnimationComponent@Player@@UEAAAEAVAnimationComponent@@XZ",
              Player)
{
    logger.info("Player({})::getAnimationComponent", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?useItem@Player@@UEAAXAEAVItemStackBase@@W4ItemUseMethod@@_N@Z",
              Player, class ItemStackBase& a0, enum ItemUseMethod a1, bool a2)
{
    logger.info("Player({})::useItem", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(float, "?getMapDecorationRotation@Player@@UEBAMXZ",
              Player)
{
    logger.info("Player({})::getMapDecorationRotation", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isWorldBuilder@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::isWorldBuilder", getName());
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?isInCreativeMode@Player@@QEBA_NXZ

// TInstanceHook(bool, "?isCreative@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isCreative", getName());
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(bool, "?isAdventure@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::isAdventure", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?add@Player@@UEAA_NAEAVItemStack@@@Z",
              Player, class ItemStack& a0)
{
    logger.info("Player({})::add", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?drop@Player@@UEAA_NAEBVItemStack@@_N@Z",
              Player, class ItemStack const& a0, bool a1)
{
    logger.info("Player({})::drop", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?setSize@Player@@UEAAXMM@Z",
              Player, float a0, float a1)
{
    logger.info("Player({})::setSize", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?startSpinAttack@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::startSpinAttack", getName());
    original(this);
}

TInstanceHook(void, "?stopSpinAttack@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::stopSpinAttack", getName());
    original(this);
}

TInstanceHook(void, "?die@Player@@UEAAXAEBVActorDamageSource@@@Z",
              Player, class ActorDamageSource const& a0)
{
    logger.info("Player({})::die", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?shouldDropDeathLoot@Player@@UEBA_NXZ",
              Player)
{
    logger.info("Player({})::shouldDropDeathLoot", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?_hurt@Player@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
              Player, class ActorDamageSource const& a0, int a1, bool a2, bool a3)
{
    logger.info("Player({})::_hurt", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(void, "?readAdditionalSaveData@Player@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              Player, class CompoundTag const& a0, class DataLoadHelper& a1)
{
    logger.info("Player({})::readAdditionalSaveData", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?addAdditionalSaveData@Player@@MEAAXAEAVCompoundTag@@@Z",
              Player, class CompoundTag& a0)
{
    logger.info("Player({})::addAdditionalSaveData", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_onSizeUpdated@Player@@EEAAXXZ",
              Player)
{
    logger.info("Player({})::_onSizeUpdated", getName());
    original(this);
}

TInstanceHook(float, "?getSpeed@Player@@UEBAMXZ",
              Player)
{
    logger.info("Player({})::getSpeed", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setSpeed@Player@@UEAAXM@Z",
              Player, float a0)
{
    logger.info("Player({})::setSpeed", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?travel@Player@@UEAAXMMM@Z",
              Player, float a0, float a1, float a2)
{
    logger.info("Player({})::travel", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?travel@Player@@UEBAXAEAUIMobMovementProxy@@MMM@Z",
              Player, struct IMobMovementProxy& a0, float a1, float a2, float a3)
{
    logger.info("Player({})::travel", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?aiStep@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::aiStep", getName());
    original(this);
}

TInstanceHook(void, "?aiStep@Player@@UEBAXAEAUIMobMovementProxy@@@Z",
              Player, struct IMobMovementProxy& a0)
{
    logger.info("Player({})::aiStep", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?getItemUseDuration@Player@@UEBAHXZ",
              Player)
{
    logger.info("Player({})::getItemUseDuration", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getItemUseStartupProgress@Player@@UEBAMXZ",
              Player)
{
    logger.info("Player({})::getItemUseStartupProgress", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getItemUseIntervalProgress@Player@@UEBAMXZ",
              Player)
{
    logger.info("Player({})::getItemUseIntervalProgress", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::vector<class ItemStack const*>&, "?getAllHand@Player@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ",
              Player, std::vector<class ItemStack const*>& ret)
{
    logger.info("Player({})::getAllHand", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(std::vector<class ItemStack const*>&, "?getAllEquipment@Player@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ",
              Player, std::vector<class ItemStack const*>& ret)
{
    logger.info("Player({})::getAllEquipment", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?dropEquipmentOnDeath@Player@@UEAAXAEBVActorDamageSource@@H@Z",
              Player, class ActorDamageSource const& a0, int a1)
{
    logger.info("Player({})::dropEquipmentOnDeath", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?dropEquipmentOnDeath@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::dropEquipmentOnDeath", getName());
    original(this);
}

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

// TInstanceHook(void, "?clearVanishEnchantedItemsOnDeath@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::clearVanishEnchantedItemsOnDeath", getName());
//     original(this);
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

// TInstanceHook(void, "?sendInventory@Player@@UEAAX_N@Z",
//     Player, bool a0){
//     logger.info("Player({})::sendInventory", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

#include <MC/BodyControl.hpp>
TInstanceHook(std::unique_ptr<class BodyControl>&, "?initBodyControl@Player@@EEAA?AV?$unique_ptr@VBodyControl@@U?$default_delete@VBodyControl@@@std@@@std@@XZ",
              Player, std::unique_ptr<class BodyControl>& ret)
{
    logger.info("Player({})::initBodyControl", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?jumpFromGround@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::jumpFromGround", getName());
    original(this);
}

TInstanceHook(void, "?jumpFromGround@Player@@UEBAXAEAUIMobMovementProxy@@@Z",
              Player, struct IMobMovementProxy& a0)
{
    logger.info("Player({})::jumpFromGround", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?updateGliding@Player@@MEAAXXZ",
              Player)
{
    logger.info("Player({})::updateGliding", getName());
    original(this);
}

TInstanceHook(void, "?prepareRegion@Player@@UEAAXAEAVChunkSource@@@Z",
              Player, class ChunkSource& a0)
{
    logger.info("Player({})::prepareRegion", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?destroyRegion@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::destroyRegion", getName());
    original(this);
}

TInstanceHook(void, "?suspendRegion@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::suspendRegion", getName());
    original(this);
}

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

// TInstanceHook(void, "?resendAllChunks@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::resendAllChunks", getName());
//     original(this);
// }

TInstanceHook(void, "?_fireWillChangeDimension@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::_fireWillChangeDimension", getName());
    original(this);
}

TInstanceHook(void, "?_fireDimensionChanged@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::_fireDimensionChanged", getName());
    original(this);
}

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

// TInstanceHook(void, "?changeDimensionWithCredits@Player@@UEAAXV?$AutomaticID@VDimension@@H@@@Z",
//     Player, class AutomaticID<class Dimension, int> a0){
//     logger.info("Player({})::changeDimensionWithCredits", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?tickWorld@Player@@UEAAXAEBUTick@@@Z",
              Player, struct Tick const& a0)
{
    logger.info("Player({})::tickWorld", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(std::vector<class ChunkPos> const&, "?getTickingOffsets@Player@@UEBAAEBV?$vector@VChunkPos@@V?$allocator@VChunkPos@@@std@@@std@@XZ",
              Player)
{
    logger.info("Player({})::getTickingOffsets", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?moveView@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::moveView", getName());
    original(this);
}

TInstanceHook(void, "?setName@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Player, std::string const& a0)
{
    logger.info("Player({})::setName", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

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

// TInstanceHook(void, "?checkMovementStats@Player@@UEAAXAEBVVec3@@@Z",
//     Player, class Vec3 const& a0){
//     logger.info("Player({})::checkMovementStats", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?respawn@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::respawn", getName());
    original(this);
}

TInstanceHook(void, "?resetPos@Player@@UEAAX_N@Z",
              Player, bool a0)
{
    logger.info("Player({})::resetPos", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?hasResource@Player@@UEAA_NH@Z",
              Player, int a0)
{
    logger.info("Player({})::hasResource", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?completeUsingItem@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::completeUsingItem", getName());
    original(this);
}

TInstanceHook(void, "?setPermissions@Player@@UEAAXW4CommandPermissionLevel@@@Z",
              Player, enum CommandPermissionLevel a0)
{
    logger.info("Player({})::setPermissions", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?startDestroying@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::startDestroying", getName());
    original(this);
}

TInstanceHook(void, "?stopDestroying@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::stopDestroying", getName());
    original(this);
}

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

// TInstanceHook(void, "?openTrading@Player@@UEAAXAEBUActorUniqueID@@_N@Z",
//     Player, struct ActorUniqueID const& a0, bool a1){
//     logger.info("Player({})::openTrading", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
// }

TInstanceHook(bool, "?canOpenContainerScreen@Player@@UEAA_NXZ",
              Player)
{
    logger.info("Player({})::canOpenContainerScreen", getName());
    auto rtn = original(this);
    return rtn;
}

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

// TInstanceHook(void, "?openInventory@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::openInventory", getName());
//     original(this);
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

// TInstanceHook(void, "?displayTextObjectMessage@Player@@UEAAXAEBVTextObjectRoot@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z",
//     Player, class TextObjectRoot const& a0, std::string const& a1, std::string const& a2){
//     logger.info("Player({})::displayTextObjectMessage", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
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

// TInstanceHook(void, "?displayTextObjectWhisperMessage@Player@@UEAAXAEBVResolvedTextObject@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1@Z",
//     Player, class ResolvedTextObject const& a0, std::string const& a1, std::string const& a2){
//     logger.info("Player({})::displayTextObjectWhisperMessage", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
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

// TInstanceHook(void, "?displayWhisperMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@000@Z",
//     Player, std::string const& a0, std::string const& a1, std::string const& a2, std::string const& a3){
//     logger.info("Player({})::displayWhisperMessage", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
// }

TInstanceHook(enum BedSleepingResult, "?startSleepInBed@Player@@UEAA?AW4BedSleepingResult@@AEBVBlockPos@@@Z",
              Player, class BlockPos const& a0)
{
    logger.info("Player({})::startSleepInBed", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?stopSleepInBed@Player@@UEAAX_N0@Z",
              Player, bool a0, bool a1)
{
    logger.info("Player({})::stopSleepInBed", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(bool, "?canStartSleepInBed@Player@@UEAA_NXZ",
              Player)
{
    logger.info("Player({})::canStartSleepInBed", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getSleepTimer@Player@@UEBAHXZ",
              Player)
{
    logger.info("Player({})::getSleepTimer", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getPreviousTickSleepTimer@Player@@UEBAHXZ",
              Player)
{
    logger.info("Player({})::getPreviousTickSleepTimer", getName());
    auto rtn = original(this);
    return rtn;
}

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?isHostingPlayer@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isHostingPlayer", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?isLoading@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isLoading", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?isPlayerInitialized@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isPlayerInitialized", getName());
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(void, "?registerTrackedBoss@Player@@UEAAXUActorUniqueID@@@Z",
              Player, struct ActorUniqueID a0)
{
    logger.info("Player({})::registerTrackedBoss", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?unRegisterTrackedBoss@Player@@UEAAXUActorUniqueID@@@Z",
              Player, struct ActorUniqueID a0)
{
    logger.info("Player({})::unRegisterTrackedBoss", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPlayerGameType@Player@@UEAAXW4GameType@@@Z",
              Player, enum GameType a0)
{
    logger.info("Player({})::setPlayerGameType", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?initHUDContainerManager@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::initHUDContainerManager", getName());
    original(this);
}

TInstanceHook(void, "?_crit@Player@@UEAAXAEAVActor@@@Z",
              Player, class Actor& a0)
{
    logger.info("Player({})::_crit", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class IMinecraftEventing*, "?getEventing@Player@@UEBAPEAVIMinecraftEventing@@XZ",
              Player)
{
    logger.info("Player({})::getEventing", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?sendEventPacket@Player@@UEBAXAEAVEventPacket@@@Z",
              Player, class EventPacket& a0)
{
    logger.info("Player({})::sendEventPacket", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?addExperience@Player@@UEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::addExperience", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?addLevels@Player@@UEAAXH@Z",
              Player, int a0)
{
    logger.info("Player({})::addLevels", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?inventoryChanged@Player@@UEAAXAEAVContainer@@HAEBVItemStack@@1_N@Z",
              Player, class Container& a0, int a1, class ItemStack const& a2, class ItemStack const& a3, bool a4)
{
    logger.info("Player({})::inventoryChanged", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4));
}

TInstanceHook(void, "?deleteContainerManager@Player@@UEAAXXZ",
              Player)
{
    logger.info("Player({})::deleteContainerManager", getName());
    original(this);
}

TInstanceHook(void, "?setFieldOfViewModifier@Player@@UEAAXM@Z",
              Player, float a0)
{
    logger.info("Player({})::setFieldOfViewModifier", getName());
    original(this, std::forward<decltype(a0)>(a0));
}

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?is2DPositionRelevant@Player@@UEAA_NV?$AutomaticID@VDimension@@H@@AEBVBlockPos@@@Z",
//     Player, class AutomaticID<class Dimension, int> a0, class BlockPos const& a1){
//     logger.info("Player({})::is2DPositionRelevant", getName());
//     auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
//     return rtn;
// }

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?isActorRelevant@Player@@UEAA_NAEBVActor@@@Z",
//     Player, class Actor const& a0){
//     logger.info("Player({})::isActorRelevant", getName());
//     auto rtn = original(this, std::forward<decltype(a0)>(a0));
//     return rtn;
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

// TInstanceHook(void, "?onSuspension@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::onSuspension", getName());
//     original(this);
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

// TInstanceHook(void, "?onLinkedSlotsChanged@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::onLinkedSlotsChanged", getName());
//     original(this);
// }

TInstanceHook(void, "?startCooldown@Player@@UEAAXPEBVItem@@_N@Z",
              Player, class Item const* a0, bool a1)
{
    logger.info("Player({})::startCooldown", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(int, "?getItemCooldownLeft@Player@@UEBAHAEBVHashedString@@@Z",
              Player, class HashedString const& a0)
{
    logger.info("Player({})::getItemCooldownLeft", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getItemCooldownLeft@Player@@UEBAH_K@Z",
              Player, unsigned __int64 a0)
{
    logger.info("Player({})::getItemCooldownLeft", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getMaxItemCooldownLeft@Player@@UEBAHXZ",
              Player)
{
    logger.info("Player({})::getMaxItemCooldownLeft", getName());
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isItemInCooldown@Player@@UEBA_NAEBVHashedString@@@Z",
              Player, class HashedString const& a0)
{
    logger.info("Player({})::isItemInCooldown", getName());
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

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

// TInstanceHook(void, "?sendNetworkPacket@Player@@UEBAXAEAVPacket@@@Z",
//     Player, class Packet& a0){
//     logger.info("Player({})::sendNetworkPacket", getName());
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

// TInstanceHook(void, "?reportMovementTelemetry@Player@@UEAAXW4MovementEventType@@@Z",
//     Player, enum MovementEventType a0){
//     logger.info("Player({})::reportMovementTelemetry", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(std::string&, "?getXuid@Player@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Player, std::string& ret)
{
    logger.info("Player({})::getXuid", getName());
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(struct PlayerMovementSettings const&, "?getMovementSettings@Player@@UEBAAEBUPlayerMovementSettings@@XZ",
              Player)
{
    logger.info("Player({})::getMovementSettings", getName());
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?onMovePlayerPacketNormal@Player@@MEAAXAEBVVec3@@AEBVVec2@@M@Z",
              Player, class Vec3 const& a0, class Vec2 const& a1, float a2)
{
    logger.info("Player({})::onMovePlayerPacketNormal", getName());
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

#include <MC/ChunkViewSource.hpp>
TInstanceHook(std::shared_ptr<class ChunkViewSource>&, "?_createChunkSource@Player@@MEAA?AV?$shared_ptr@VChunkViewSource@@@std@@AEAVChunkSource@@@Z",
              Player, std::shared_ptr<class ChunkViewSource>& ret, class ChunkSource& a0)
{
    logger.info("Player({})::_createChunkSource", getName());
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

// virtual.unordered : 23
// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(enum StructureFeatureType, "?getCurrentStructureFeature@Player@@UEBA?AW4StructureFeatureType@@XZ",
//     Player){
//     logger.info("Player({})::getCurrentStructureFeature", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?isInTrialMode@Player@@UEAA_NXZ",
//     Player){
//     logger.info("Player({})::isInTrialMode", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?useNewAi@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::useNewAi", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?isSimulated@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isSimulated", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1382 functions with the same rva

// ??$parse@PEBUActorDefinitionIdentifier@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVBlock@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@PEBVMobEffect@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@V?$AutomaticID@VDimension@@H@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VCommandItem@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@VExecuteChainedSubcommand@NewExecuteCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@AllowListCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@CodeBuilderCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@DialogueCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@MusicCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@ScoreboardCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4Action@TagCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActionType@ResourceUriCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4ActorDamageCause@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AddAreaType@TickingAreaCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AnimationMode@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AreaType@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4AvailableCommandPermissionPresets@PermissionCommand@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z
// ??$parse@W4BlockSlot@@@CommandRegistry@@AEBA_NPEAXAEBUParseToken@0@AEBVCommandOrigin@@HAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@4@@Z

// TInstanceHook(bool, "?isLocalPlayer@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isLocalPlayer", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 614 functions with the same rva

// ?GetBytesPerSecondLimitByCongestionControl@CCRakNetSlidingWindow@RakNet@@QEBA_KXZ
// ?_DLMallocDirectMMap@RakNet@@YAPEAX_K@Z
// ?_DLMallocMMap@RakNet@@YAPEAX_K@Z
// ?_DLMallocMUnmap@RakNet@@YAHPEAX_K@Z
// ?_Get_deleter@_Ref_count_base@std@@UEBAPEAXAEBVtype_info@@@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_04126ab3841162f070846e248505fe78>@@XAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VVanillaTreeFeature@@@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VVanillaTreeFeature@@@FeatureLoading@@@JsonUtil@@VBlockDescriptor@@@JsonUtil@@AEBVBlockDescriptor@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VVanillaTreeFeature@@@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VVanillaTreeFeature@@@FeatureLoading@@@JsonUtil@@VBlockDescriptor@@@JsonUtil@@AEBVBlockDescriptor@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0430d35d81f82ec0e2d64769f36d2a04>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VDefinition@JumpToBlockGoal@@@JsonUtil@@H@JsonUtil@@AEBH@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VDefinition@JumpToBlockGoal@@@JsonUtil@@H@JsonUtil@@AEBH@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0441a0580b72ce35182bb5568e08ddad>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VDefinition@AvoidBlockGoal@@@JsonUtil@@H@JsonUtil@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VDefinition@AvoidBlockGoal@@@JsonUtil@@H@JsonUtil@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_055ccfb14d6a5ecee049eee4ce9e2f92>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VExploreOutskirtsDefinition@@@JsonUtil@@H@JsonUtil@@AEBH@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VExploreOutskirtsDefinition@@@JsonUtil@@H@JsonUtil@@AEBH@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_059dafa7f727168828c9772a0a6a0861>@@W4EventResult@@V?$not_null@PEAVPlayerEventListener@@@gsl@@@std@@EEAAPEAV?$_Func_base@W4EventResult@@V?$not_null@PEAVPlayerEventListener@@@gsl@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_07102330a583f220c63db5031da4ebff>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VNearestAttackableTargetDefinition@@@JsonUtil@@H@JsonUtil@@AEBH@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VNearestAttackableTargetDefinition@@@JsonUtil@@H@JsonUtil@@AEBH@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_07ec980eef44cc591cd294c9346b931d>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VRangedAttackDefinition@@@JsonUtil@@M@JsonUtil@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VRangedAttackDefinition@@@JsonUtil@@M@JsonUtil@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_08e01a5f67d647a919dd40f16a254eca>@@XAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VVanillaTreeFeature@@@FeatureLoading@@@JsonUtil@@VSimpleTreeCanopy@@@JsonUtil@@VSimpleTreeCanopy@@@JsonUtil@@W4GrowthDirection@AttachableDecoration@TreeHelper@@@JsonUtil@@AEBW4GrowthDirection@AttachableDecoration@TreeHelper@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VVanillaTreeFeature@@@FeatureLoading@@@JsonUtil@@VSimpleTreeCanopy@@@JsonUtil@@VSimpleTreeCanopy@@@JsonUtil@@W4GrowthDirection@AttachableDecoration@TreeHelper@@@JsonUtil@@AEBW4GrowthDirection@AttachableDecoration@TreeHelper@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0975e96ad24b541d385d35dc68df53d2>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VDropItemForDefinition@@@JsonUtil@@H@JsonUtil@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VDropItemForDefinition@@@JsonUtil@@H@JsonUtil@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0999754f132fb405fbd76d303bb0b020>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VStompAttackDefinition@@@JsonUtil@@H@JsonUtil@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VStompAttackDefinition@@@JsonUtil@@H@JsonUtil@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0b4de70124f0f162c6319d2925b3b929>@@XAEAVCompoundTag@@AEAVEntityContext@@AEAVIWorldRegistriesProvider@@@std@@EEAAPEAV?$_Func_base@XAEAVCompoundTag@@AEAVEntityContext@@AEAVIWorldRegistriesProvider@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0c720ee6282a929c5f7301f37100dcee>@@XAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$BiomeDecorationAttributes@UListedFeatures@@@@@JsonUtil@@UBiomeDecorationFeature@@@JsonUtil@@UCoordinateRange@ScatterParams@@@JsonUtil@@@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$BiomeDecorationAttributes@UListedFeatures@@@@@JsonUtil@@UBiomeDecorationFeature@@@JsonUtil@@UCoordinateRange@ScatterParams@@@JsonUtil@@@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0d6acf1a93d9008c909c8de9d3caf398>@@X$$V@std@@EEAAPEAV?$_Func_base@X$$V@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0d941e7eab87ed2925aade43347ee895>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VSlimeKeepOnJumpingDefinition@@@JsonUtil@@H@JsonUtil@@AEBH@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VSlimeKeepOnJumpingDefinition@@@JsonUtil@@H@JsonUtil@@AEBH@2@PEAX@Z
// ?_Move@?$_Func_impl_no_alloc@V<lambda_0f1f12bcc6e712e0a637daa4118f707b>@@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VControlledByPlayerDefinition@@@JsonUtil@@M@JsonUtil@@AEBM@std@@EEAAPEAV?$_Func_base@XAEAV?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@VControlledByPlayerDefinition@@@JsonUtil@@M@JsonUtil@@AEBM@2@PEAX@Z

// TInstanceHook(unsigned int, "?getUserId@Player@@UEBAIXZ",
//     Player){
//     logger.info("Player({})::getUserId", getName());
//     auto rtn = original(this);
//     return rtn;
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

// TInstanceHook(void, "?displayChatMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z",
//     Player, std::string const& a0, std::string const& a1){
//     logger.info("Player({})::displayChatMessage", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
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

// TInstanceHook(void, "?openChalkboard@Player@@UEAAXAEAVChalkboardBlockActor@@_N@Z",
//     Player, class ChalkboardBlockActor& a0, bool a1){
//     logger.info("Player({})::openChalkboard", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
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

// TInstanceHook(void, "?openBook@Player@@UEAAXH_NHPEAVBlockActor@@@Z",
//     Player, int a0, bool a1, int a2, class BlockActor* a3){
//     logger.info("Player({})::openBook", getName());
//     original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
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

// TInstanceHook(void, "?displayClientMessage@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
//     Player, std::string const& a0){
//     logger.info("Player({})::displayClientMessage", getName());
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

// TInstanceHook(void, "?openSign@Player@@UEAAXAEBVBlockPos@@@Z",
//     Player, class BlockPos const& a0){
//     logger.info("Player({})::openSign", getName());
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

// TInstanceHook(void, "?_serverInitItemStackIds@Player@@MEAAXXZ",
//     Player){
//     logger.info("Player({})::_serverInitItemStackIds", getName());
//     original(this);
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

// TInstanceHook(void, "?playEmote@Player@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
//     Player, std::string const& a0){
//     logger.info("Player({})::playEmote", getName());
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

// TInstanceHook(void, "?openPortfolio@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::openPortfolio", getName());
//     original(this);
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

// TInstanceHook(void, "?resetRot@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::resetRot", getName());
//     original(this);
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

// TInstanceHook(void, "?stopLoading@Player@@UEAAXXZ",
//     Player){
//     logger.info("Player({})::stopLoading", getName());
//     original(this);
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?isPlayer@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isPlayer", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?isCreativeModeAllowed@Player@@UEAA_NXZ",
//     Player){
//     logger.info("Player({})::isCreativeModeAllowed", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?isAutoJumpEnabled@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::isAutoJumpEnabled", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?isShootable@Player@@UEAA_NXZ",
//     Player){
//     logger.info("Player({})::isShootable", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_allowAscendingScaffolding@Mob@@MEBA_NXZ
// ?_calculatePlacePos@DeprecatedSlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@Item@@EEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_calculatePlacePos@SlabBlockItem@@UEBA_NAEAVItemStackBase@@AEAVActor@@AEAEAEAVBlockPos@@@Z
// ?_checkAgainstEventAllowlist@AggregationEventListener@Events@Social@@MEBA_NAEBVEvent@23@@Z
// ?_handleUnknownMember@FilterGroup@@MEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVValue@Json@@@Z
// ?_isListenerReadyForEvents@AggregationEventListener@Events@Social@@MEBA_NXZ
// ?_isValidEnchantmentTypeForCategory@Enchant@@EEBA_NW4Type@1@@Z
// ?_makeFlySound@Parrot@@MEBA_NXZ
// ?_needsPostProcessing@PoolElementStructurePiece@@MEAA_NAEAVBlockSource@@@Z
// ?_playerCanUpdate@BlockActor@@MEBA_NAEBVPlayer@@@Z
// ?_read@?$ItemStackRequestActionDataless@$08@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_read@ItemStackRequestActionCraftNonImplemented_DEPRECATEDASKTYLAING@@MEAA_NAEAVReadOnlyBinaryStream@@@Z
// ?_registerSystemObjects@ScriptEngine@@MEAA_NAEBVScriptObjectHandle@ScriptApi@@@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@U?$pair@PEAVBiome@@I@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@V?$vector@U?$pair@PEAVBiome@@I@std@@V?$allocator@U?$pair@PEAVBiome@@I@std@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVBiome@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@U?$pair@V?$reference_wrapper@VBiome@@@std@@V?$reference_wrapper@VIWorldRegistriesProvider@@@2@@std@@@JsonUtil@@PEAVBiome@@@2@_N@Z
// ?_validate@?$JsonSchemaTypedNode@PEAVStructureTemplate@@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAV1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UFeatureRootParseContext@FeatureLoading@@@JsonUtil@@U?$ConcreteFeatureHolder@VStructureTemplateFeature@@@FeatureLoading@@@JsonUtil@@PEAVStructureTemplate@@@2@_N@Z

// TInstanceHook(bool, "?getAlwaysShowNameTag@Player@@UEBA_NXZ",
//     Player){
//     logger.info("Player({})::getAlwaysShowNameTag", getName());
//     auto rtn = original(this);
//     return rtn;
// }

// there are 3 functions with the same rva

// ?openNpcInteractScreen@ServerPlayer@@UEAAXV?$shared_ptr@UINpcDialogueData@@@std@@@Z
// ?requeueTask@InternalTaskGroup@@UEAAXV?$shared_ptr@VBackgroundTaskBase@@@std@@_N@Z
// ?taskRegister@InternalTaskGroup@@UEAAXV?$shared_ptr@VBackgroundTaskBase@@@std@@@Z

// #include <MC/INpcDialogueData.hpp>
// TInstanceHook(void, "?openNpcInteractScreen@Player@@UEAAXV?$shared_ptr@UINpcDialogueData@@@std@@@Z",
//     Player, class std::shared_ptr<struct INpcDialogueData> a0){
//     logger.info("Player({})::openNpcInteractScreen", getName());
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(class Player&, "??1Player@@UEAA@XZ",
              Player)
{
    logger.info("Player({})::~Player", getName());
    auto& rtn = original(this);
    return rtn;
}

// vtbl_entry : 1

#endif // HOOK_CLASS_Player

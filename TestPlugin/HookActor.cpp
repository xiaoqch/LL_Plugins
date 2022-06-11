#include "pch.h"
#include <MC/Actor.hpp>


#ifdef HOOK_CLASS_Actor
// child_types : 109
// private : 14
TInstanceHook(void, "?_addActorComponents@Actor@@AEAAXXZ",
              Actor)
{
    logger.info("Actor::_addActorComponents");
    original(this);
}

TInstanceHook(void, "?_initAliasProperties@Actor@@AEAAXXZ",
              Actor)
{
    logger.info("Actor::_initAliasProperties");
    original(this);
}

TInstanceHook(void, "?_initializeLeashRopeSystem@Actor@@AEAAXPEAV1@@Z",
              Actor, class Actor* a0)
{
    logger.info("Actor::_initializeLeashRopeSystem");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?_isItemStackNetManagerEnabled@Actor@@AEBA_NXZ",
              Actor)
{
    logger.info("Actor::_isItemStackNetManagerEnabled");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_managePassengers@Actor@@AEAAXAEAVBlockSource@@@Z",
              Actor, class BlockSource& a0)
{
    logger.info("Actor::_managePassengers");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_moveHitboxTo@Actor@@AEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::_moveHitboxTo");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_sendLinkPacket@Actor@@AEBAXAEBUActorLink@@@Z",
              Actor, struct ActorLink const& a0)
{
    logger.info("Actor::_sendLinkPacket");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_serializeComponents@Actor@@AEAAXAEAVCompoundTag@@@Z",
              Actor, class CompoundTag& a0)
{
    logger.info("Actor::_serializeComponents");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_setupServerAnimationComponent@Actor@@AEAAXXZ",
              Actor)
{
    logger.info("Actor::_setupServerAnimationComponent");
    original(this);
}

TInstanceHook(void, "?_spawnTreasureHuntingParticles@Actor@@AEAAXXZ",
              Actor)
{
    logger.info("Actor::_spawnTreasureHuntingParticles");
    original(this);
}

TInstanceHook(bool, "?_tryPlaceAt@Actor@@AEAA_NAEBVVec3@@AEBVAABB@@@Z",
              Actor, class Vec3 const& a0, class AABB const& a1)
{
    logger.info("Actor::_tryPlaceAt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?_tryPlantWitherRose@Actor@@AEAAXXZ",
              Actor)
{
    logger.info("Actor::_tryPlantWitherRose");
    original(this);
}

TInstanceHook(void, "?_updateComposition@Actor@@AEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::_updateComposition");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_updateOwnerChunk@Actor@@AEAAXXZ",
              Actor)
{
    logger.info("Actor::_updateOwnerChunk");
    original(this);
}

// private.static : 4
// there are 1 functions with the same rva

// ?_containsSneakCollisionShapes@?$DirectActorProxyImpl@UIActorMovementProxy@@@@UEAA_NAEBVAABB@@@Z

// THook(bool, "?_containsSneakCollisionShapes@Actor@@CA_NAEAUIActorMovementProxy@@AEBVAABB@@@Z",
//     struct IActorMovementProxy& a0, class AABB const& a1){
//     logger.info("Actor::_containsSneakCollisionShapes");
//     auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
//     return rtn;
// }

THook(int const&, "?DAMAGE_NEARBY_MOBS_DURATION@Actor@@0HB",
      int const& ret)
{
    logger.info("Actor::DAMAGE_NEARBY_MOBS_DURATION");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_MAX_DISTANCE_OPTIMIZATION@Actor@@0MB",
      float const& ret)
{
    logger.info("Actor::DEFAULT_MAX_DISTANCE_OPTIMIZATION");
    auto& rtn = original(ret);
    return rtn;
}

THook(unsigned __int64 const&, "?DEFAULT_MAX_TICK_DELAY_OPTIMIZATION@Actor@@0_KB",
      unsigned __int64 const& ret)
{
    logger.info("Actor::DEFAULT_MAX_TICK_DELAY_OPTIMIZATION");
    auto& rtn = original(ret);
    return rtn;
}

// protected : 15
TInstanceHook(void, "?_assignActorMovementProxy@Actor@@IEAAXV?$not_null@V?$shared_ptr@UIActorMovementProxy@@@std@@@gsl@@@Z",
              Actor, class gsl::not_null<class std::shared_ptr<struct IActorMovementProxy>> a0)
{
    logger.info("Actor::_assignActorMovementProxy");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?_damageSensorComponentHurt@Actor@@IEAA_NAEAHHAEBVActorDamageSource@@@Z",
              Actor, int& a0, int a1, class ActorDamageSource const& a2)
{
    logger.info("Actor::_damageSensorComponentHurt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(class ItemActor const*, "?_drop@Actor@@IEAAPEBVItemActor@@AEBVItemStack@@_N@Z",
              Actor, class ItemStack const& a0, bool a1)
{
    logger.info("Actor::_drop");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// there are 2 functions with the same rva

// ?getAABBShape@Actor@@QEBAAEBVAABBShape@@XZ
// ?getFlatWorldGeneratorOptions@LevelData@@QEBAAEBVValue@Json@@XZ

// TInstanceHook(class AABBShape&, "?_getAABBShapeNonConst@Actor@@IEAAAEAVAABBShape@@XZ",
//     Actor){
//     logger.info("Actor::_getAABBShapeNonConst");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(bool, "?_isHeadInWater@Actor@@IEBA_NXZ",
              Actor)
{
    logger.info("Actor::_isHeadInWater");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_playMovementSound@Actor@@IEAAX_N@Z",
              Actor, bool a0)
{
    //logger.info("Actor::_playMovementSound");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_refreshAABB@Actor@@IEAAXXZ",
              Actor)
{
    logger.info("Actor::_refreshAABB");
    original(this);
}

// there are 1 functions with the same rva

// ?setAABBDim@Actor@@QEAAXAEBVVec2@@@Z

// TInstanceHook(void, "?_setAABBDim@Actor@@IEAAXAEBVVec2@@@Z",
//     Actor, class Vec2 const& a0){
//     logger.info("Actor::_setAABBDim");
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?_setArmorContainer@Actor@@IEAAXV?$unique_ptr@VSimpleContainer@@U?$default_delete@VSimpleContainer@@@std@@@std@@@Z",
              Actor, class std::unique_ptr<class SimpleContainer, struct std::default_delete<class SimpleContainer>>& a0)
{
    logger.info("Actor::_setArmorContainer");
    original(this, std::forward<decltype(a0)>(a0));
}

#include <MC/SimpleContainer.hpp>
TInstanceHook(void, "?_setHandContainer@Actor@@IEAAXV?$unique_ptr@VSimpleContainer@@U?$default_delete@VSimpleContainer@@@std@@@std@@@Z",
              Actor, class std::unique_ptr<class SimpleContainer, struct std::default_delete<class SimpleContainer>> a0)
{
    logger.info("Actor::_setHandContainer");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_setHeightOffset@Actor@@IEAAXM@Z",
              Actor, float a0)
{
    logger.info("Actor::_setHeightOffset");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_setNetherPortalData@Actor@@IEAAXV?$AutomaticID@VDimension@@H@@0H@Z",
              Actor, class AutomaticID<class Dimension, int> a0, class AutomaticID<class Dimension, int> a1, int a2)
{
    logger.info("Actor::_setNetherPortalData");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

// there are 1 functions with the same rva

// ?setPosDirectLegacy@Actor@@QEAAXAEBVVec3@@@Z

// TInstanceHook(void, "?_setPos@Actor@@IEAAXAEBVVec3@@@Z",
//     Actor, class Vec3 const& a0){
//     logger.info("Actor::_setPos");
//     original(this, std::forward<decltype(a0)>(a0));
// }

// there are 1 functions with the same rva

// ?setPosPrev@Actor@@QEAAXAEBVVec3@@@Z

// TInstanceHook(void, "?_setPosPrev@Actor@@IEAAXAEBVVec3@@@Z",
//     Actor, class Vec3 const& a0){
//     logger.info("Actor::_setPosPrev");
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?enableAutoSendPosRot@Actor@@IEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::enableAutoSendPosRot");
    original(this, std::forward<decltype(a0)>(a0));
}

// protected.static : 3
THook(bool, "?_isImmersedInWater@Actor@@KA_NAEBVStateVector@@AEBVBlockSource@@AEBVAABBShape@@@Z",
      class StateVector const& a0, class BlockSource const& a1, class AABBShape const& a2)
{
    logger.info("Actor::_isImmersedInWater");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(class Block const&, "?getBlockWhenClimbing@Actor@@KAAEBVBlock@@AEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    //logger.info("Actor::getBlockWhenClimbing");
    auto& rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(int const&, "?PLAYER_HURT_EXPERIENCE_TIME@Actor@@1HB",
      int const& ret)
{
    logger.info("Actor::PLAYER_HURT_EXPERIENCE_TIME");
    auto& rtn = original(ret);
    return rtn;
}

// public : 346
// there are 6 functions with the same rva

// ?displaysOnScreenTextureAnimation@MobEffectInstance@@QEBA_NXZ
// ?getClientSubId@ConnectionRequest@@QEBAEXZ
// ?getIsWorldBuilder@ActorDamageByActorSource@@UEBA_NXZ
// ?getPackType@InPackagePackSource@@UEBA?AW4PackType@@XZ
// ?isEnabled@ContentLog@@QEBA_NXZ
// ?isListening@Debugger@QuickJS@Scripting@@UEBA_NXZ

// TInstanceHook(enum Actor::InitializationMethod, "?getInitializationMethod@Actor@@QEAA?AW4InitializationMethod@1@XZ",
//     Actor){
//     logger.info("Actor::getInitializationMethod");
//     auto rtn = original(this);
//     return rtn;
// }

// there are 2 functions with the same rva

// ?getPackSourceFactory@ResourcePackRepository@@UEAAAEAVPackSourceFactory@@XZ
// ?getSpatialNetworkData@Actor@@QEBAAEBVSpatialActorNetworkData@@XZ

// TInstanceHook(class SpatialActorNetworkData&, "?getSpatialNetworkData@Actor@@QEAAAEAVSpatialActorNetworkData@@XZ",
//     Actor){
//     logger.info("Actor::getSpatialNetworkData");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 2 functions with the same rva

// ?getPackSourceFactory@ResourcePackRepository@@UEAAAEAVPackSourceFactory@@XZ
// ?getSpatialNetworkData@Actor@@QEAAAEAVSpatialActorNetworkData@@XZ

// TInstanceHook(class SpatialActorNetworkData const&, "?getSpatialNetworkData@Actor@@QEBAAEBVSpatialActorNetworkData@@XZ",
//     Actor){
//     logger.info("Actor::getSpatialNetworkData");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class Actor&, "??0Actor@@QEAA@AEAVILevel@@AEAVEntityContext@@@Z",
              Actor, class ILevel& a0, class EntityContext& a1)
{
    logger.info("Actor::Actor");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(class Actor&, "??0Actor@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@AEAVEntityContext@@@Z",
              Actor, class ActorDefinitionGroup* a0, struct ActorDefinitionIdentifier const& a1, class EntityContext& a2)
{
    logger.info("Actor::Actor");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(bool, "??8Actor@@QEAA_NAEAV0@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::operator==");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

// there are 2 functions with the same rva

// ?_getAABBShapeNonConst@Actor@@IEAAAEAVAABBShape@@XZ
// ?getFlatWorldGeneratorOptions@LevelData@@QEBAAEBVValue@Json@@XZ

// TInstanceHook(class AABBShape const&, "?getAABBShape@Actor@@QEBAAEBVAABBShape@@XZ",
//     Actor){
//     logger.info("Actor::getAABBShape");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class Vec3&, "?_randomHeartPos@Actor@@QEAA?AVVec3@@XZ",
              Actor, class Vec3& ret)
{
    logger.info("Actor::_randomHeartPos");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?_sendDirtyActorData@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::_sendDirtyActorData");
    original(this);
}

// there are 1 functions with the same rva

// ?_setAABBDim@Actor@@IEAAXAEBVVec2@@@Z

// TInstanceHook(void, "?setAABBDim@Actor@@QEAAXAEBVVec2@@@Z",
//     Actor, class Vec2 const& a0){
//     logger.info("Actor::setAABBDim");
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?_setActorTypeId@Actor@@QEAAXW4ActorType@@@Z",
              Actor, enum ActorType a0)
{
    logger.info("Actor::_setActorTypeId");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_setLevelPtr@Actor@@QEAAXPEAVLevel@@@Z",
              Actor, class Level* a0)
{
    logger.info("Actor::_setLevelPtr");
    original(this, std::forward<decltype(a0)>(a0));
}

// there are 1 functions with the same rva

// ?_setPos@Actor@@IEAAXAEBVVec3@@@Z

// TInstanceHook(void, "?setPosDirectLegacy@Actor@@QEAAXAEBVVec3@@@Z",
//     Actor, class Vec3 const& a0){
//     logger.info("Actor::setPosDirectLegacy");
//     original(this, std::forward<decltype(a0)>(a0));
// }

// there are 1 functions with the same rva

// ?_setPosPrev@Actor@@IEAAXAEBVVec3@@@Z

// TInstanceHook(void, "?setPosPrev@Actor@@QEAAXAEBVVec3@@@Z",
//     Actor, class Vec3 const& a0){
//     logger.info("Actor::setPosPrev");
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?addDefinitionGroup@Actor@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::addDefinitionGroup");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?addEffect@Actor@@QEAAXAEBVMobEffectInstance@@@Z",
              Actor, class MobEffectInstance const& a0)
{
    logger.info("Actor::addEffect");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?addTag@Actor@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::addTag");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?buildDebugGroupInfo@Actor@@QEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string& a0)
{
    logger.info("Actor::buildDebugGroupInfo");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class Vec3&, "?buildForward@Actor@@QEBA?AVVec3@@XZ",
              Actor, class Vec3& ret)
{
    logger.info("Actor::buildForward");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?burn@Actor@@QEAAXH_N@Z",
              Actor, int a0, bool a1)
{
    logger.info("Actor::burn");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?cacheComponentData@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::cacheComponentData");
    original(this);
}

TInstanceHook(class Vec3&, "?calcCenterPos@Actor@@QEBA?AVVec3@@XZ",
              Actor, class Vec3& ret)
{
    logger.info("Actor::calcCenterPos");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?calculateAttackDamage@Actor@@QEAAHAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::calculateAttackDamage");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canAscendCurrentBlockByJumping@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::canAscendCurrentBlockByJumping");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canBeginOrContinueClimbingLadder@Actor@@QEBA_NXZ",
              Actor)
{
    //logger.info("Actor::canBeginOrContinueClimbingLadder");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canCurrentlySwim@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::canCurrentlySwim");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canDescendBlockBelowByCrouching@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::canDescendBlockBelowByCrouching");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canFly@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::canFly");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canMate@Actor@@QEBA_NAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::canMate");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?celebrateHunt@Actor@@QEAAXH_N@Z",
              Actor, int a0, bool a1)
{
    logger.info("Actor::celebrateHunt");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?clearFishingHookID@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::clearFishingHookID");
    original(this);
}

TInstanceHook(void, "?consumeItem@Actor@@QEAAXAEAVItemActor@@H@Z",
              Actor, class ItemActor& a0, int a1)
{
    logger.info("Actor::consumeItem");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(class UpdateEquipPacket&, "?createUpdateEquipPacket@Actor@@QEAA?AVUpdateEquipPacket@@H@Z",
              Actor, class UpdateEquipPacket& ret, int a0)
{
    logger.info("Actor::createUpdateEquipPacket");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class UpdateTradePacket&, "?createUpdateTradePacket@Actor@@QEAA?AVUpdateTradePacket@@H@Z",
              Actor, class UpdateTradePacket& ret, int a0)
{
    logger.info("Actor::createUpdateTradePacket");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?deregisterTagsFromLevelCache@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::deregisterTagsFromLevelCache");
    original(this);
}

TInstanceHook(float, "?distanceSqrToBlockPosCenter@Actor@@QEBAMAEBVBlockPos@@@Z",
              Actor, class BlockPos const& a0)
{
    logger.info("Actor::distanceSqrToBlockPosCenter");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?distanceTo@Actor@@QEBAMAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::distanceTo");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?distanceTo@Actor@@QEBAMAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::distanceTo");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?distanceToSqr@Actor@@QEBAMAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::distanceToSqr");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?distanceToSqr@Actor@@QEBAMAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::distanceToSqr");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?dropLeash@Actor@@QEAAX_N0@Z",
              Actor, bool a0, bool a1)
{
    logger.info("Actor::dropLeash");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?dropTowards@Actor@@QEAAXAEBVItemStack@@VVec3@@@Z",
              Actor, class ItemStack const& a0, class Vec3 a1)
{
    logger.info("Actor::dropTowards");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(bool, "?executeEvent@Actor@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVVariantParameterList@@@Z",
              Actor, std::string const& a0, class VariantParameterList const& a1)
{
    logger.info("Actor::executeEvent");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?exitVehicle@Actor@@QEAAXAEBV1@P6A?AV?$optional@VVec3@@@std@@AEBUVehicleDirections@VehicleUtils@@V?$function@$$A6A_NAEBVVec3@@0@Z@3@@Z@Z",
              Actor, class Actor const& a0, class std::optional<class Vec3> (*a1)(struct VehicleUtils::VehicleDirections const&, class std::function<bool(class Vec3 const&, class Vec3 const&)>))
{
    logger.info("Actor::exitVehicle");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(class FishingHook*, "?fetchFishingHook@Actor@@QEAAPEAVFishingHook@@XZ",
              Actor)
{
    logger.info("Actor::fetchFishingHook");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::vector<struct DistanceSortedActor>&, "?fetchNearbyActorsSorted@Actor@@QEAA?AV?$vector@UDistanceSortedActor@@V?$allocator@UDistanceSortedActor@@@std@@@std@@AEBVVec3@@W4ActorType@@@Z",
              Actor, std::vector<struct DistanceSortedActor>& ret, class Vec3 const& a0, enum ActorType a1)
{
    logger.info("Actor::fetchNearbyActorsSorted");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?forEachLeashedActor@Actor@@QEAAXV?$function@$$A6AXV?$not_null@PEAVActor@@@gsl@@@Z@std@@@Z",
              Actor, class std::function<void(class gsl::not_null<class Actor*>)> a0)
{
    logger.info("Actor::forEachLeashedActor");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?getActiveEffectCount@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getActiveEffectCount");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorDefinitionIdentifier const&, "?getActorIdentifier@Actor@@QEBAAEBUActorDefinitionIdentifier@@XZ",
              Actor)
{
    logger.info("Actor::getActorIdentifier");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(std::vector<class MobEffectInstance> const&, "?getAllEffects@Actor@@QEBAAEBV?$vector@VMobEffectInstance@@V?$allocator@VMobEffectInstance@@@std@@@std@@XZ",
              Actor)
{
    logger.info("Actor::getAllEffects");
    auto& rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getArmorContainer@Actor@@QEBAAEBVSimpleContainer@@XZ

// TInstanceHook(class SimpleContainer&, "?getArmorContainer@Actor@@QEAAAEAVSimpleContainer@@XZ",
//     Actor){
//     logger.info("Actor::getArmorContainer");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getArmorContainer@Actor@@QEAAAEAVSimpleContainer@@XZ

// TInstanceHook(class SimpleContainer const&, "?getArmorContainer@Actor@@QEBAAEBVSimpleContainer@@XZ",
//     Actor){
//     logger.info("Actor::getArmorContainer");
//     auto& rtn = original(this);
//     return rtn;
// }

#include <MC/BaseAttributeMap.hpp>
TInstanceHook(gsl::not_null<class BaseAttributeMap*>&, "?getAttributes@Actor@@QEAA?AV?$not_null@PEAVBaseAttributeMap@@@gsl@@XZ",
              Actor, gsl::not_null<class BaseAttributeMap*>& ret)
{
    logger.info("Actor::getAttributes");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class BlockPos&, "?getBlockPosCurrentlyStandingOn@Actor@@QEBA?AVBlockPos@@PEAV1@@Z",
              Actor, class BlockPos& ret, class Actor* a0)
{
    logger.info("Actor::getBlockPosCurrentlyStandingOn");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class BlockPos&, "?getBlockTarget@Actor@@QEBA?AVBlockPos@@XZ",
              Actor, class BlockPos& ret)
{
    logger.info("Actor::getBlockTarget");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(bool, "?getCanPickupItems@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::getCanPickupItems");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getCarriedItemInSlotPreferredBy@Actor@@QEBAAEBVItemStack@@AEBV2@@Z",
              Actor, class ItemStack const& a0)
{
    logger.info("Actor::getCarriedItemInSlotPreferredBy");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?getChainedDamageEffects@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::getChainedDamageEffects");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?getCollidableMobNear@Actor@@QEAA_NXZ",
              Actor)
{
    logger.info("Actor::getCollidableMobNear");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum PaletteColor, "?getColor2@Actor@@QEBA?AW4PaletteColor@@XZ",
              Actor)
{
    logger.info("Actor::getColor2");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum PaletteColor, "?getColor@Actor@@QEBA?AW4PaletteColor@@XZ",
              Actor)
{
    logger.info("Actor::getColor");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getControllingSeat@Actor@@QEAAHXZ",
              Actor)
{
    logger.info("Actor::getControllingSeat");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getCurrentSwimAmount@Actor@@QEBAMXZ",
              Actor)
{
    logger.info("Actor::getCurrentSwimAmount");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?getDamageNearbyMobs@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::getDamageNearbyMobs");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class ActorDefinitionDiffList*, "?getDiffList@Actor@@QEAAPEAVActorDefinitionDiffList@@XZ",
              Actor)
{
    logger.info("Actor::getDiffList");
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getDimensionConst@Actor@@QEBAAEBVDimension@@XZ

// TInstanceHook(class Dimension&, "?getDimension@Actor@@QEBAAEAVDimension@@XZ",
//     Actor){
//     logger.info("Actor::getDimension");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getDimension@Actor@@QEBAAEAVDimension@@XZ

// TInstanceHook(class Dimension const&, "?getDimensionConst@Actor@@QEBAAEBVDimension@@XZ",
//     Actor){
//     logger.info("Actor::getDimensionConst");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class EconomyTradeableComponent*, "?getEconomyTradeableComponent@Actor@@QEBAPEAVEconomyTradeableComponent@@XZ",
              Actor)
{
    logger.info("Actor::getEconomyTradeableComponent");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class MobEffectInstance const*, "?getEffect@Actor@@QEBAPEBVMobEffectInstance@@AEBVMobEffect@@@Z",
              Actor, class MobEffect const& a0)
{
    //logger.info("Actor::getEffect");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

// there are 1 functions with the same rva

// ?getEntityData@Actor@@QEBAAEBVSynchedActorData@@XZ

// TInstanceHook(class SynchedActorData&, "?getEntityData@Actor@@QEAAAEAVSynchedActorData@@XZ",
//     Actor){
//     logger.info("Actor::getEntityData");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getEntityData@Actor@@QEAAAEAVSynchedActorData@@XZ

// TInstanceHook(class SynchedActorData const&, "?getEntityData@Actor@@QEBAAEBVSynchedActorData@@XZ",
//     Actor){
//     logger.info("Actor::getEntityData");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class ActorTerrainInterlockData&, "?getEntityTerrainInterlockData@Actor@@QEAAAEAVActorTerrainInterlockData@@XZ",
              Actor)
{
    logger.info("Actor::getEntityTerrainInterlockData");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(enum EquipmentSlot, "?getEquipmentSlotForItem@Actor@@QEBA?AW4EquipmentSlot@@AEBVItemStack@@@Z",
              Actor, class ItemStack const& a0)
{
    logger.info("Actor::getEquipmentSlotForItem");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?getFirstAvailableSeatPos@Actor@@QEBA_NAEAV1@AEAVVec3@@@Z",
              Actor, class Actor& a0, class Vec3& a1)
{
    logger.info("Actor::getFirstAvailableSeatPos");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(class Actor*, "?getFirstPassenger@Actor@@QEBAPEAV1@XZ",
              Actor)
{
    logger.info("Actor::getFirstPassenger");
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getHandContainer@Actor@@QEBAAEBVSimpleContainer@@XZ

// TInstanceHook(class SimpleContainer&, "?getHandContainer@Actor@@QEAAAEAVSimpleContainer@@XZ",
//     Actor){
//     logger.info("Actor::getHandContainer");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getHandContainer@Actor@@QEAAAEAVSimpleContainer@@XZ

// TInstanceHook(class SimpleContainer const&, "?getHandContainer@Actor@@QEBAAEBVSimpleContainer@@XZ",
//     Actor){
//     logger.info("Actor::getHandContainer");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(int, "?getHealth@Actor@@QEBAHXZ",
              Actor)
{
    //logger.info("Actor::getHealth");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getHurtDir@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getHurtDir");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getHurtTime@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getHurtTime");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Vec3&, "?getInterpolatedPosition@Actor@@QEBA?AVVec3@@M@Z",
              Actor, class Vec3& ret, float a0)
{
    logger.info("Actor::getInterpolatedPosition");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class Vec2&, "?getInterpolatedRotation@Actor@@QEBA?AVVec2@@M@Z",
              Actor, class Vec2& ret, float a0)
{
    logger.info("Actor::getInterpolatedRotation");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getJumpDuration@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getJumpDuration");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getLastHurtByMobTime@Actor@@QEAAHXZ",
              Actor)
{
    logger.info("Actor::getLastHurtByMobTime");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getLastHurtByMobTimestamp@Actor@@QEAAHXZ",
              Actor)
{
    logger.info("Actor::getLastHurtByMobTimestamp");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum ActorDamageCause, "?getLastHurtCause@Actor@@QEBA?AW4ActorDamageCause@@XZ",
              Actor)
{
    logger.info("Actor::getLastHurtCause");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getLastHurtDamage@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getLastHurtDamage");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getLastHurtMobTimestamp@Actor@@QEAAHXZ",
              Actor)
{
    logger.info("Actor::getLastHurtMobTimestamp");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(unsigned __int64&, "?getLastHurtTimestamp@Actor@@QEBA_KXZ",
              Actor, unsigned __int64& ret)
{
    logger.info("Actor::getLastHurtTimestamp");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(struct ActorUniqueID&, "?getLeashHolder@Actor@@QEBA?AUActorUniqueID@@XZ",
              Actor, struct ActorUniqueID& ret)
{
    logger.info("Actor::getLeashHolder");
    auto& rtn = original(this, ret);
    return rtn;
}

// there are 1 functions with the same rva

// ?getLevel@Actor@@QEAAAEAVLevel@@XZ

// TInstanceHook(class Level const&, "?getLevel@Actor@@QEBAAEBVLevel@@XZ",
//     Actor){
//     logger.info("Actor::getLevel");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getLevel@Actor@@QEBAAEBVLevel@@XZ

// TInstanceHook(class Level&, "?getLevel@Actor@@QEAAAEAVLevel@@XZ",
//     Actor){
//     logger.info("Actor::getLevel");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(int, "?getLimitedLifetimeTicks@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getLimitedLifetimeTicks");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::vector<struct ActorLink>&, "?getLinks@Actor@@QEBA?AV?$vector@UActorLink@@V?$allocator@UActorLink@@@std@@@std@@XZ",
              Actor, std::vector<struct ActorLink>& ret)
{
    logger.info("Actor::getLinks");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getMarkVariant@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getMarkVariant");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getMaxHealth@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getMaxHealth");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class MolangVariableMap&, "?getMolangVariables@Actor@@QEAAAEAVMolangVariableMap@@XZ",
              Actor)
{
    logger.info("Actor::getMolangVariables");
    auto& rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getMovementProxy@Actor@@QEBA?AV?$not_null@V?$shared_ptr@$$CBUIActorMovementProxy@@@std@@@gsl@@XZ

// TInstanceHook(gsl::not_null<class std::shared_ptr<struct IActorMovementProxy> >&, "?getMovementProxy@Actor@@QEAA?AV?$not_null@V?$shared_ptr@UIActorMovementProxy@@@std@@@gsl@@XZ",
//     Actor, gsl::not_null<class std::shared_ptr<struct IActorMovementProxy> >& ret){
//     logger.info("Actor::getMovementProxy");
//     auto& rtn = original(this, ret);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getMovementProxy@Actor@@QEAA?AV?$not_null@V?$shared_ptr@UIActorMovementProxy@@@std@@@gsl@@XZ

// TInstanceHook(gsl::not_null<class std::shared_ptr<struct IActorMovementProxy const> >&, "?getMovementProxy@Actor@@QEBA?AV?$not_null@V?$shared_ptr@$$CBUIActorMovementProxy@@@std@@@gsl@@XZ",
//     Actor, gsl::not_null<class std::shared_ptr<struct IActorMovementProxy const> >& ret){
//     logger.info("Actor::getMovementProxy");
//     auto& rtn = original(this, ret);
//     return rtn;
// }

TInstanceHook(class ItemStack const&, "?getOffhandSlot@Actor@@QEBAAEBVItemStack@@XZ",
              Actor)
{
    //logger.info("Actor::getOffhandSlot");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class Mob*, "?getOwner@Actor@@QEBAPEAVMob@@XZ",
              Actor)
{
    logger.info("Actor::getOwner");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorUniqueID const&, "?getOwnerId@Actor@@QEBA?BUActorUniqueID@@XZ",
              Actor, struct ActorUniqueID const& ret)
{
    logger.info("Actor::getOwnerId");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getPassengerIndex@Actor@@QEBAHAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::getPassengerIndex");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

#include <MC/CompoundTag.hpp>
TInstanceHook(std::unique_ptr<class CompoundTag>&, "?getPersistingTradeOffers@Actor@@QEAA?AV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@XZ",
              Actor, std::unique_ptr<class CompoundTag>& ret)
{
    logger.info("Actor::getPersistingTradeOffers");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getPersistingTradeRiches@Actor@@QEAAHXZ",
              Actor)
{
    logger.info("Actor::getPersistingTradeRiches");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Player*, "?getPlayerOwner@Actor@@QEBAPEAVPlayer@@XZ",
              Actor)
{
    logger.info("Actor::getPlayerOwner");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum PortalAxis, "?getPortalEntranceAxis@Actor@@QEBA?AW4PortalAxis@@XZ",
              Actor)
{
    logger.info("Actor::getPortalEntranceAxis");
    auto rtn = original(this);
    return rtn;
}

// there are 2 functions with the same rva

// ?getPos@Actor@@UEBAAEBVVec3@@XZ
// ?getStateVector@Actor@@QEBAAEBVStateVector@@XZ

// TInstanceHook(class StateVector&, "?getStateVectorNonConst@Actor@@QEAAAEAVStateVector@@XZ",
//     Actor){
//     logger.info("Actor::getStateVectorNonConst");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 2 functions with the same rva

// ?getPos@Actor@@UEBAAEBVVec3@@XZ
// ?getStateVectorNonConst@Actor@@QEAAAEAVStateVector@@XZ

// TInstanceHook(class StateVector const&, "?getStateVector@Actor@@QEBAAEBVStateVector@@XZ",
//     Actor){
//     logger.info("Actor::getStateVector");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(float, "?getRadius@Actor@@QEBAMXZ",
              Actor)
{
    logger.info("Actor::getRadius");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Random&, "?getRandom@Actor@@QEBAAEAVRandom@@XZ",
              Actor)
{
    logger.info("Actor::getRandom");
    auto& rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getRegion@Actor@@QEBAAEAVBlockSource@@XZ

// TInstanceHook(class BlockSource const&, "?getRegionConst@Actor@@QEBAAEBVBlockSource@@XZ",
//     Actor){
//     logger.info("Actor::getRegionConst");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getRegionConst@Actor@@QEBAAEBVBlockSource@@XZ

// TInstanceHook(class BlockSource&, "?getRegion@Actor@@QEBAAEAVBlockSource@@XZ",
//     Actor){
//     logger.info("Actor::getRegion");
//     auto& rtn = original(this);
//     return rtn;
// }

// there are 1 functions with the same rva

// ?getRenderParams@RenderParams@@SAAEAV1@AEAVActor@@@Z

// TInstanceHook(class RenderParams&, "?getRenderParams@Actor@@QEAAAEAVRenderParams@@XZ",
//     Actor){
//     logger.info("Actor::getRenderParams");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class Vec2&, "?getRotation@Actor@@QEBA?AVVec2@@XZ",
              Actor, class Vec2& ret)
{
    logger.info("Actor::getRotation");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class ActorRuntimeID&, "?getRuntimeID@Actor@@QEBA?AVActorRuntimeID@@XZ",
              Actor, class ActorRuntimeID& ret)
{
    logger.info("Actor::getRuntimeID");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getShakeTime@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getShakeTime");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getSkinID@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getSkinID");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getSpeedInMetersPerSecond@Actor@@QEBAMXZ",
              Actor)
{
    logger.info("Actor::getSpeedInMetersPerSecond");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?getStatusFlag@Actor@@QEBA_NW4ActorFlags@@@Z",
              Actor, enum ActorFlags a0)
{
    //logger.info("Actor::getStatusFlag");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getStrength@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getStrength");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getStrengthMax@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getStrengthMax");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getStructuralIntegrity@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getStructuralIntegrity");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getSwimAmount@Actor@@QEBAMM@Z",
              Actor, float a0)
{
    logger.info("Actor::getSwimAmount");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void* /*class gsl::span<std::string, -1> const&*/, "?getTags@Actor@@QEBA?BV?$span@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0?0@gsl@@XZ",
              Actor, class gsl::span<std::string, -1> const& ret)
{
    logger.info("Actor::getTags");
    auto rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class Actor*, "?getTarget@Actor@@QEBAPEAV1@XZ",
              Actor)
{
    logger.info("Actor::getTarget");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorUniqueID&, "?getTargetId@Actor@@QEAA?AUActorUniqueID@@XZ",
              Actor, struct ActorUniqueID& ret)
{
    logger.info("Actor::getTargetId");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class ITickingArea*, "?getTickingArea@Actor@@QEAAPEAVITickingArea@@XZ",
              Actor)
{
    logger.info("Actor::getTickingArea");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?getTradeInterest@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::getTradeInterest");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class MerchantRecipeList*, "?getTradeOffers@Actor@@QEAAPEAVMerchantRecipeList@@XZ",
              Actor)
{
    logger.info("Actor::getTradeOffers");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Player*, "?getTradingPlayer@Actor@@QEBAPEAVPlayer@@XZ",
              Actor)
{
    logger.info("Actor::getTradingPlayer");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorUniqueID const&, "?getUniqueID@Actor@@QEBAAEBUActorUniqueID@@XZ",
              Actor)
{
    logger.info("Actor::getUniqueID");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getVariant@Actor@@QEBAHXZ",
              Actor)
{
    logger.info("Actor::getVariant");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Actor*, "?getVehicle@Actor@@QEBAPEAV1@XZ",
              Actor)
{
    logger.info("Actor::getVehicle");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Actor*, "?getVehicleRoot@Actor@@QEBAPEAV1@XZ",
              Actor)
{
    logger.info("Actor::getVehicleRoot");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class ActorRuntimeID&, "?getVehicleRuntimeID@Actor@@QEBA?AVActorRuntimeID@@XZ",
              Actor, class ActorRuntimeID& ret)
{
    logger.info("Actor::getVehicleRuntimeID");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(float, "?getVerticalSpeedInMetersPerSecond@Actor@@QEBAMXZ",
              Actor)
{
    logger.info("Actor::getVerticalSpeedInMetersPerSecond");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Vec3&, "?getViewVector@Actor@@QEBA?AVVec3@@M@Z",
              Actor, class Vec3& ret, float a0)
{
    logger.info("Actor::getViewVector");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasAnyEffects@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasAnyEffects");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasAnyVisibleEffects@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasAnyVisibleEffects");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasBeenHurtByMobInLastTicks@Actor@@QEBA_NH@Z",
              Actor, int a0)
{
    logger.info("Actor::hasBeenHurtByMobInLastTicks");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasCategory@Actor@@QEBA_NW4ActorCategory@@@Z",
              Actor, enum ActorCategory a0)
{
    logger.info("Actor::hasCategory");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasDefinitionGroup@Actor@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::hasDefinitionGroup");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasDimension@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasDimension");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasEffect@Actor@@QEBA_NAEBVMobEffect@@@Z",
              Actor, class MobEffect const& a0)
{
    //logger.info("Actor::hasEffect");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasFamily@Actor@@QEBA_NAEBVHashedString@@@Z",
              Actor, class HashedString const& a0)
{
    logger.info("Actor::hasFamily");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasFishingHook@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasFishingHook");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasLevel@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasLevel");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasPassenger@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasPassenger");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasPersistingTrade@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasPersistingTrade");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasPlayerPassenger@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasPlayerPassenger");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasPriorityAmmunition@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasPriorityAmmunition");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasRuntimeID@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasRuntimeID");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasSaddle@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasSaddle");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasTag@Actor@@QEBA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::hasTag");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasTags@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasTags");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasTeleported@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasTeleported");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasTickingArea@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasTickingArea");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasTotemEquipped@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasTotemEquipped");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasType@Actor@@QEBA_NW4ActorType@@@Z",
              Actor, enum ActorType a0)
{
    logger.info("Actor::hasType");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?hasUniqueID@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasUniqueID");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?healEffects@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::healEffects");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?hurt@Actor@@QEAA_NAEBVActorDamageSource@@H_N1@Z",
              Actor, class ActorDamageSource const& a0, int a1, bool a2, bool a3)
{
    logger.info("Actor::hurt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(bool, "?inDownwardFlowingLiquid@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::inDownwardFlowingLiquid");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?initActorProperties@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::initActorProperties");
    original(this);
}

TInstanceHook(void, "?initParams@Actor@@QEAAXAEAVVariantParameterList@@@Z",
              Actor, class VariantParameterList& a0)
{
    logger.info("Actor::initParams");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isActorLocationInMaterial@Actor@@QEBA_NW4ActorLocation@@W4MaterialType@@@Z",
              Actor, enum ActorLocation a0, enum MaterialType a1)
{
    logger.info("Actor::isActorLocationInMaterial");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?isAngry@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isAngry");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isAutonomous@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isAutonomous");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isBaby@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isBaby");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isBreakingObstruction@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isBreakingObstruction");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isBribed@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isBribed");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isCharged@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isCharged");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isChested@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isChested");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isClimbing@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isClimbing");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isControlledByLocalInstance@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isControlledByLocalInstance");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isDoorBreaker@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isDoorBreaker");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isDoorOpener@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isDoorOpener");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isGlobal@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isGlobal");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isIgnited@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isIgnited");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isImmersedInWater@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isImmersedInWater");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInClouds@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInClouds");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInContactWithWater@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInContactWithWater");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInLove@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInLove");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInPrecipitation@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInPrecipitation");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInRain@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInRain");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInScaffolding@Actor@@QEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isInScaffolding");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInSnow@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInSnow");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInThunderstorm@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInThunderstorm");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInWaterOrRain@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInWaterOrRain");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInWorld@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInWorld");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInsideBorderBlock@Actor@@QEBA_NM@Z",
              Actor, float a0)
{
    logger.info("Actor::isInsideBorderBlock");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isInsidePortal@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInsidePortal");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isLayingDown@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isLayingDown");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isLeashed@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isLeashed");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isMovedToLimbo@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isMovedToLimbo");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isMoving@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isMoving");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isOrphan@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isOrphan");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isOutOfControl@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isOutOfControl");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isOverScaffolding@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isOverScaffolding");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPacified@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isPacified");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPassenger@Actor@@QEBA_NAEBUActorUniqueID@@@Z",
              Actor, struct ActorUniqueID const& a0)
{
    logger.info("Actor::isPassenger");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isPassenger@Actor@@QEBA_NAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::isPassenger");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isPersistent@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isPersistent");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPlayingDead@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isPlayingDead");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPowered@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isPowered");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isRegionValid@Actor@@QEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isRegionValid");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isRemoved@Actor@@QEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isRemoved");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isResting@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isResting");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isRiding@Actor@@QEBA_NPEAV1@@Z",
              Actor, class Actor* a0)
{
    //logger.info("Actor::isRiding");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isRiding@Actor@@QEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isRiding");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSafeToSleepNear@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isSafeToSleepNear");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSheared@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isSheared");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSitting@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isSitting");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSneaking@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isSneaking");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isStackable@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isStackable");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isStanding@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isStanding");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSwimmer@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isSwimmer");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSwimming@Actor@@QEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isSwimming");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isTame@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isTame");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isTickingEntity@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isTickingEntity");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isTouchingDamageBlock@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isTouchingDamageBlock");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isTrading@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isTrading");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isTrusting@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isTrusting");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isType@Actor@@QEBA_NW4ActorType@@@Z",
              Actor, enum ActorType a0)
{
    logger.info("Actor::isType");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isUseNewTradeScreen@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isUseNewTradeScreen");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isWASDControlled@Actor@@QEAA_NXZ",
              Actor)
{
    logger.info("Actor::isWASDControlled");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isWalker@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::isWalker");
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?lerpMotion@Actor@@UEAAXAEBVVec3@@@Z

// TInstanceHook(void, "?setVelocity@Actor@@QEAAXAEBVVec3@@@Z",
//     Actor, class Vec3 const& a0){
//     logger.info("Actor::setVelocity");
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?lerpTo@Actor@@QEAAXAEBVVec3@@AEBVVec2@@H@Z",
              Actor, class Vec3 const& a0, class Vec2 const& a1, int a2)
{
    logger.info("Actor::lerpTo");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?lerpTo@Actor@@QEAAXAEBVVec3@@AEBVVec2@@MH@Z",
              Actor, class Vec3 const& a0, class Vec2 const& a1, float a2, int a3)
{
    logger.info("Actor::lerpTo");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?lerpToRotation@Actor@@QEAAXAEBVVec2@@H@Z",
              Actor, class Vec2 const& a0, int a1)
{
    logger.info("Actor::lerpToRotation");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?loadEntityFlags@Actor@@QEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              Actor, class CompoundTag const& a0, class DataLoadHelper& a1)
{
    logger.info("Actor::loadEntityFlags");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(struct ActorUniqueID const&, "?lovePartnerId@Actor@@QEBAAEBUActorUniqueID@@XZ",
              Actor)
{
    logger.info("Actor::lovePartnerId");
    auto& rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?setUniqueID@Actor@@QEAAXUActorUniqueID@@@Z

// TInstanceHook(void, "?migrateUniqueID@Actor@@QEAAXUActorUniqueID@@@Z",
//     Actor, struct ActorUniqueID a0){
//     logger.info("Actor::migrateUniqueID");
//     original(this, std::forward<decltype(a0)>(a0));
// }

// there are 1 functions with the same rva

// ?migrateUniqueID@Actor@@QEAAXUActorUniqueID@@@Z

// TInstanceHook(void, "?setUniqueID@Actor@@QEAAXUActorUniqueID@@@Z",
//     Actor, struct ActorUniqueID a0){
//     logger.info("Actor::setUniqueID");
//     original(this, std::forward<decltype(a0)>(a0));
// }

TInstanceHook(void, "?moveBBs@Actor@@QEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::moveBBs");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?moveRelative@Actor@@QEAAXMMMM@Z",
              Actor, float a0, float a1, float a2, float a3)
{
    //logger.info("Actor::moveRelative");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?moveTo@Actor@@QEAAXAEBVVec3@@AEBVVec2@@@Z",
              Actor, class Vec3 const& a0, class Vec2 const& a1)
{
    logger.info("Actor::moveTo");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?onAffectedByWaterBottle@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::onAffectedByWaterBottle");
    original(this);
}

TInstanceHook(bool, "?onClimbableBlock@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::onClimbableBlock");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?onHoverableBlock@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::onHoverableBlock");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?onOnewayCollision@Actor@@QEAAXAEBVAABB@@@Z",
              Actor, class AABB const& a0)
{
    logger.info("Actor::onOnewayCollision");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?pickUpItem@Actor@@QEAAXAEAVItemActor@@H@Z",
              Actor, class ItemActor& a0, int a1)
{
    logger.info("Actor::pickUpItem");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?playSound@Actor@@QEAAXW4LevelSoundEvent@@AEBVVec3@@AEBVBlock@@@Z",
              Actor, enum LevelSoundEvent a0, class Vec3 const& a1, class Block const& a2)
{
    logger.info("Actor::playSound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?playSound@Actor@@QEAAXW4LevelSoundEvent@@AEBVVec3@@H@Z",
              Actor, enum LevelSoundEvent a0, class Vec3 const& a1, int a2)
{
    logger.info("Actor::playSound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?positionAllPassengers@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::positionAllPassengers");
    original(this);
}

TInstanceHook(bool, "?pullInEntity@Actor@@QEAA_NAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::pullInEntity");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

//TInstanceHook(void, "?pushBackActionEventToActionQueue@Actor@@QEAAXVActionEvent@@@Z",
//              Actor, class ActionEvent a0)
//{
//    logger.info("Actor::pushBackActionEventToActionQueue");
//    original(this, std::forward<decltype(a0)>(a0));
//}

TInstanceHook(void, "?refreshComponents@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::refreshComponents");
    original(this);
}

TInstanceHook(void, "?reload@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::reload");
    original(this);
}

TInstanceHook(void, "?reloadProperties@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::reloadProperties");
    original(this);
}

TInstanceHook(void, "?removeAllEffects@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::removeAllEffects");
    original(this);
}

TInstanceHook(void, "?removeAllPassengers@Actor@@QEAAX_N0@Z",
              Actor, bool a0, bool a1)
{
    logger.info("Actor::removeAllPassengers");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?removeEffect@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::removeEffect");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?removeEffectParticles@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::removeEffectParticles");
    original(this);
}

TInstanceHook(void, "?removePersistingTrade@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::removePersistingTrade");
    original(this);
}

TInstanceHook(bool, "?removeTag@Actor@@QEAA_NAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::removeTag");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?resetClientAnimations@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::resetClientAnimations");
    original(this);
}

TInstanceHook(void, "?resetRegion@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::resetRegion");
    original(this);
}

TInstanceHook(void, "?saveEntityFlags@Actor@@QEAAXAEAVCompoundTag@@@Z",
              Actor, class CompoundTag& a0)
{
    logger.info("Actor::saveEntityFlags");
    original(this, std::forward<decltype(a0)>(a0));
}

#include <MC/ListTag.hpp>
TInstanceHook(std::unique_ptr<class ListTag>&, "?saveLinks@Actor@@QEBA?AV?$unique_ptr@VListTag@@U?$default_delete@VListTag@@@std@@@std@@XZ",
              Actor, std::unique_ptr<class ListTag>& ret)
{
    logger.info("Actor::saveLinks");
    auto& rtn = original(this, ret);
    return rtn;
}

#include <MC/CompoundTag.hpp>
TInstanceHook(void, "?savePersistingTrade@Actor@@QEAAXV?$unique_ptr@VCompoundTag@@U?$default_delete@VCompoundTag@@@std@@@std@@H@Z",
              Actor, class std::unique_ptr<class CompoundTag, struct std::default_delete<class CompoundTag>> a0, int a1)
{
    logger.info("Actor::savePersistingTrade");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?sendActorDefinitionEventTriggered@Actor@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::sendActorDefinitionEventTriggered");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?sendMotionToServer@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::sendMotionToServer");
    original(this);
}

TInstanceHook(void, "?serializationSetHealth@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::serializationSetHealth");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setAABB@Actor@@QEAAXAEBVAABB@@@Z",
              Actor, class AABB const& a0)
{
    logger.info("Actor::setAABB");
    original(this, std::forward<decltype(a0)>(a0));
}
void test()
{
    logger.info("This is test");
}

#include <MC/HashedString.hpp>
TInstanceHook(void, "?setActorRendererId@Actor@@QEAAXVHashedString@@@Z",
              Actor, class HashedString a0)
{
    test();
    logger.info("Actor::setActorRendererId");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setAutonomous@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setAutonomous");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setBaseDefinition@Actor@@QEAAXAEBUActorDefinitionIdentifier@@_N1@Z",
              Actor, struct ActorDefinitionIdentifier const& a0, bool a1, bool a2)
{
    logger.info("Actor::setBaseDefinition");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?setBlockTarget@Actor@@QEAAXAEBVBlockPos@@@Z",
              Actor, class BlockPos const& a0)
{
    logger.info("Actor::setBlockTarget");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setBreakingObstruction@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setBreakingObstruction");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCanClimb@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setCanClimb");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCanFly@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setCanFly");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setChainedDamageEffects@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setChainedDamageEffects");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCharged@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setCharged");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setClimbing@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setClimbing");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCollidableMob@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setCollidableMob");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setCollidableMobNear@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setCollidableMobNear");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setColor2@Actor@@QEAAXW4PaletteColor@@@Z",
              Actor, enum PaletteColor a0)
{
    logger.info("Actor::setColor2");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setColor@Actor@@QEAAXW4PaletteColor@@@Z",
              Actor, enum PaletteColor a0)
{
    logger.info("Actor::setColor");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setControllingSeat@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setControllingSeat");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setDancing@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setDancing");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setDoorBreaker@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setDoorBreaker");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setDoorOpener@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setDoorOpener");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setEnchanted@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setEnchanted");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setFishingHookID@Actor@@QEAAXUActorUniqueID@@@Z",
              Actor, struct ActorUniqueID a0)
{
    logger.info("Actor::setFishingHookID");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setGlobal@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setGlobal");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setHurtDir@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setHurtDir");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setHurtTime@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setHurtTime");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setInLove@Actor@@QEAAXPEAV1@@Z",
              Actor, class Actor* a0)
{
    logger.info("Actor::setInLove");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setInterpolation@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setInterpolation");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setInvisible@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setInvisible");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setJumpDuration@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setJumpDuration");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setLastHitBB@Actor@@QEAAXAEBVVec3@@0@Z",
              Actor, class Vec3 const& a0, class Vec3 const& a1)
{
    logger.info("Actor::setLastHitBB");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setLayingDown@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setLayingDown");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setLeashHolder@Actor@@QEAAXUActorUniqueID@@@Z",
              Actor, struct ActorUniqueID a0)
{
    logger.info("Actor::setLeashHolder");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setLimitedLifetimeTicks@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setLimitedLifetimeTicks");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setMarkVariant@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setMarkVariant");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setMovedToLimbo@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setMovedToLimbo");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setMoving@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setMoving");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPersistent@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::setPersistent");
    original(this);
}

TInstanceHook(void, "?setPreviousPosRot@Actor@@QEAAXAEBVVec3@@AEBVVec2@@@Z",
              Actor, class Vec3 const& a0, class Vec2 const& a1)
{
    logger.info("Actor::setPreviousPosRot");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setRegion@Actor@@QEAAXAEAVBlockSource@@@Z",
              Actor, class BlockSource& a0)
{
    logger.info("Actor::setRegion");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setResting@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setResting");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setRuntimeID@Actor@@QEAAXVActorRuntimeID@@@Z",
              Actor, class ActorRuntimeID a0)
{
    logger.info("Actor::setRuntimeID");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSaddle@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setSaddle");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setScared@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setScared");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSeatDescription@Actor@@QEAAXAEBVVec3@@AEBUSeatDescription@@@Z",
              Actor, class Vec3 const& a0, struct SeatDescription const& a1)
{
    logger.info("Actor::setSeatDescription");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?setShakeTime@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setShakeTime");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSkinID@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setSkinID");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?setStatusFlag@Actor@@QEAA_NW4ActorFlags@@_N@Z",
              Actor, enum ActorFlags a0, bool a1)
{
    logger.info("Actor::setStatusFlag");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?setStrength@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setStrength");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setStrengthMax@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setStrengthMax");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setStructuralIntegrity@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setStructuralIntegrity");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setStunned@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setStunned");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSwimmer@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setSwimmer");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setTempted@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setTempted");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setTradeInterest@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setTradeInterest");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setTradingPlayer@Actor@@QEAAXPEAVPlayer@@@Z",
              Actor, class Player* a0)
{
    logger.info("Actor::setTradingPlayer");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setVariant@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::setVariant");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setWASDControlled@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setWASDControlled");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setWalker@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setWalker");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?shouldOrphan@Actor@@QEAA_NAEAVBlockSource@@@Z",
              Actor, class BlockSource& a0)
{
    logger.info("Actor::shouldOrphan");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?shouldUpdateEffects@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::shouldUpdateEffects");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?spawnBalloonPopParticles@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::spawnBalloonPopParticles");
    original(this);
}

TInstanceHook(void, "?spawnDeathParticles@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::spawnDeathParticles");
    original(this);
}

TInstanceHook(void, "?spawnDustParticles@Actor@@QEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::spawnDustParticles");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?spawnEatParticles@Actor@@QEAAXAEBVItemStack@@H@Z",
              Actor, class ItemStack const& a0, int a1)
{
    logger.info("Actor::spawnEatParticles");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?spawnTamingParticles@Actor@@QEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::spawnTamingParticles");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?teleportPassengersTo@Actor@@QEAAXAEBVVec3@@HH@Z",
              Actor, class Vec3 const& a0, int a1, int a2)
{
    logger.info("Actor::teleportPassengersTo");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?testForEntityStacking@Actor@@QEAAXAEAVBlockSource@@AEBVAABB@@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@@Z",
              Actor, class BlockSource& a0, class AABB const& a1, class std::vector<class AABB, class std::allocator<class AABB>>& a2)
{
    logger.info("Actor::testForEntityStacking");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(bool, "?tick@Actor@@QEAA_NAEAVBlockSource@@@Z",
              Actor, class BlockSource& a0)
{
    logger.info("Actor::tick");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?tickBlockDamage@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::tickBlockDamage");
    original(this);
}

TInstanceHook(void, "?transferTickingArea@Actor@@QEAAXAEAVDimension@@@Z",
              Actor, class Dimension& a0)
{
    logger.info("Actor::transferTickingArea");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(std::vector<class ItemDescriptor> const*, "?tryGetEquippableSlotAllowedItems@Actor@@QEBAPEBV?$vector@VItemDescriptor@@V?$allocator@VItemDescriptor@@@std@@@std@@H@Z",
              Actor, int a0)
{
    logger.info("Actor::tryGetEquippableSlotAllowedItems");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?tryMoveChunks@Actor@@QEAA_NXZ",
              Actor)
{
    logger.info("Actor::tryMoveChunks");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?updateAnimationComponentOnServer@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::updateAnimationComponentOnServer");
    original(this);
}

TInstanceHook(void, "?updateBBFromDefinition@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::updateBBFromDefinition");
    original(this);
}

TInstanceHook(void, "?updateDescription@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::updateDescription");
    original(this);
}

TInstanceHook(void, "?updateInvisibilityStatus@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::updateInvisibilityStatus");
    original(this);
}

TInstanceHook(void, "?updateMolangVariables@Actor@@QEAAXAEAVRenderParams@@@Z",
              Actor, class RenderParams& a0)
{
    logger.info("Actor::updateMolangVariables");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?updateTickingData@Actor@@QEAAXXZ",
              Actor)
{
    logger.info("Actor::updateTickingData");
    original(this);
}

TInstanceHook(bool, "?useSaddle@Actor@@QEAA_NAEAVItemStackBase@@PEAVPlayer@@@Z",
              Actor, class ItemStackBase& a0, class Player* a1)
{
    logger.info("Actor::useSaddle");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?wasLastHitByPlayer@Actor@@QEAA_NXZ",
              Actor)
{
    logger.info("Actor::wasLastHitByPlayer");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?wasLoadedFromNBTThisFrame@Actor@@QEBA_NXZ",
              Actor)
{
    logger.info("Actor::wasLoadedFromNBTThisFrame");
    auto rtn = original(this);
    return rtn;
}

// public.static : 35
THook(void, "?_move@Actor@@SAXAEAUIActorMovementProxy@@AEBVVec3@@@Z",
      struct IActorMovementProxy& a0, class Vec3 const& a1)
{
    logger.info("Actor::_move");
    original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

THook(class Vec3&, "?buildForward@Actor@@SA?AVVec3@@AEBUIActorMovementProxy@@@Z",
      class Vec3& ret, struct IActorMovementProxy const& a0)
{
    logger.info("Actor::buildForward");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?canBeginOrContinueClimbingLadder@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Actor::canBeginOrContinueClimbingLadder");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(void, "?checkEntityOnewayCollision@Actor@@SAXAEAVBlockSource@@AEBVBlockPos@@@Z",
      class BlockSource& a0, class BlockPos const& a1)
{
    logger.info("Actor::checkEntityOnewayCollision");
    original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

THook(class BlockPos&, "?getBlockPosCurrentlyStandingOn@Actor@@SA?AVBlockPos@@AEBUIActorMovementProxy@@PEAU3@@Z",
      class BlockPos& ret, struct IActorMovementProxy const& a0, struct IActorMovementProxy* a1)
{
    logger.info("Actor::getBlockPosCurrentlyStandingOn");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(class Vec2&, "?getInterpolatedRotation@Actor@@SA?AVVec2@@AEBV2@0M@Z",
      class Vec2& ret, class Vec2 const& a0, class Vec2 const& a1, float a2)
{
    logger.info("Actor::getInterpolatedRotation");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(class AABB&, "?getLiquidAABB@Actor@@SA?AVAABB@@AEBUIActorMovementProxy@@W4MaterialType@@@Z",
      class AABB& ret, struct IActorMovementProxy const& a0, enum MaterialType a1)
{
    //logger.info("Actor::getLiquidAABB");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(float, "?getLiquidFlowStrength@Actor@@SAMW4MaterialType@@@Z",
      enum MaterialType a0)
{
    logger.info("Actor::getLiquidFlowStrength");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?getStatusFlag@Actor@@SA_NAEBVSynchedActorData@@W4ActorFlags@@@Z",
      class SynchedActorData const& a0, enum ActorFlags a1)
{
    logger.info("Actor::getStatusFlag");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(class Vec3&, "?getViewVector@Actor@@SA?AVVec3@@AEBUIActorMovementProxy@@M@Z",
      class Vec3& ret, struct IActorMovementProxy const& a0, float a1)
{
    logger.info("Actor::getViewVector");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(class Vec3&, "?getViewVector@Actor@@SA?AVVec3@@AEBVVec2@@0M@Z",
      class Vec3& ret, class Vec2 const& a0, class Vec2 const& a1, float a2)
{
    logger.info("Actor::getViewVector");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(bool, "?hasSubBBIn@Actor@@SA_NAEBUIActorMovementProxy@@W4MaterialType@@@Z",
      struct IActorMovementProxy const& a0, enum MaterialType a1)
{
    //logger.info("Actor::hasSubBBIn");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(bool, "?isFree@Actor@@SA_NAEAUIActorMovementProxy@@AEBVVec3@@M@Z",
      struct IActorMovementProxy& a0, class Vec3 const& a1, float a2)
{
    logger.info("Actor::isFree");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(bool, "?isImmersedInWater@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Actor::isImmersedInWater");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?isImmobile@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    //logger.info("Actor::isImmobile");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?isInScaffolding@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Actor::isInScaffolding");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?isSitting@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Actor::isSitting");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?isStanding@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Actor::isStanding");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(void, "?moveRelative@Actor@@SAXAEAUIActorMovementProxy@@MMMM@Z",
      struct IActorMovementProxy& a0, float a1, float a2, float a3, float a4)
{
    logger.info("Actor::moveRelative");
    original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4));
}

THook(bool, "?onClimbableBlock@Actor@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Actor::onClimbableBlock");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?setStatusFlag@Actor@@SA_NAEAVSynchedActorData@@W4ActorFlags@@_N@Z",
      class SynchedActorData& a0, enum ActorFlags a1, bool a2)
{
    logger.info("Actor::setStatusFlag");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

THook(void, "?testForCollidableMobs@Actor@@SAXAEBUIActorMovementProxy@@AEAVBlockSource@@AEBVAABB@@AEAV?$vector@VAABB@@V?$allocator@VAABB@@@std@@@std@@@Z",
      struct IActorMovementProxy const& a0, class BlockSource& a1, class AABB const& a2, class std::vector<class AABB, class std::allocator<class AABB>>& a3)
{
    logger.info("Actor::testForCollidableMobs");
    original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

// there are 1 functions with the same rva

// ?tryGetFromComponent@Actor@@SAPEBV1@AEBVActorOwnerComponent@@_N@Z

// THook(class Actor*, "?tryGetFromComponent@Actor@@SAPEAV1@AEAVActorOwnerComponent@@_N@Z",
//     class ActorOwnerComponent& a0, bool a1){
//     logger.info("Actor::tryGetFromComponent");
//     auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
//     return rtn;
// }

// there are 1 functions with the same rva

// ?tryGetFromComponent@Actor@@SAPEAV1@AEAVActorOwnerComponent@@_N@Z

// THook(class Actor const*, "?tryGetFromComponent@Actor@@SAPEBV1@AEBVActorOwnerComponent@@_N@Z",
//     class ActorOwnerComponent const& a0, bool a1){
//     logger.info("Actor::tryGetFromComponent");
//     auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
//     return rtn;
// }

THook(class Actor*, "?tryGetFromEntity@Actor@@SAPEAV1@AEAVEntityContext@@_N@Z",
      class EntityContext& a0, bool a1)
{
    //logger.info("Actor::tryGetFromEntity");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

//THook(class Actor*, "?tryGetFromEntity@Actor@@SAPEAV1@V?$StackRefResultT@UEntityRefTraits@@@@_N@Z",
//      class StackRefResultT<struct EntityRefTraits> a0, bool a1)
//{
//    logger.info("Actor::tryGetFromEntity");
//    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
//    return rtn;
//}

THook(int const&, "?TOTAL_AIR_SUPPLY@Actor@@2HB",
      int const& ret)
{
    logger.info("Actor::TOTAL_AIR_SUPPLY");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_AMBIENT_SOUND_INTERVAL@Actor@@2MB",
      float const& ret)
{
    logger.info("Actor::DEFAULT_AMBIENT_SOUND_INTERVAL");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_AMBIENT_SOUND_INTERVAL_RANGE@Actor@@2MB",
      float const& ret)
{
    logger.info("Actor::DEFAULT_AMBIENT_SOUND_INTERVAL_RANGE");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?MAX_BYTE_CHARGE_AMOUNT@Actor@@2HB",
      int const& ret)
{
    logger.info("Actor::MAX_BYTE_CHARGE_AMOUNT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?WATER_FLOW_STRENGTH_MULTIPLIER@Actor@@2MB",
      float const& ret)
{
    logger.info("Actor::WATER_FLOW_STRENGTH_MULTIPLIER");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?LAVA_FLOW_STRENGTH_MULTIPLIER@Actor@@2MB",
      float const& ret)
{
    logger.info("Actor::LAVA_FLOW_STRENGTH_MULTIPLIER");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Vec3 const&, "?LAVA_AABB_SHRINK_AMOUNT@Actor@@2VVec3@@B",
      class Vec3 const& ret)
{
    logger.info("Actor::LAVA_AABB_SHRINK_AMOUNT");
    auto& rtn = original(ret);
    return rtn;
}

THook(class Vec3 const&, "?WATER_AABB_SHRINK_AMOUNT@Actor@@2VVec3@@B",
      class Vec3 const& ret)
{
    logger.info("Actor::WATER_AABB_SHRINK_AMOUNT");
    auto& rtn = original(ret);
    return rtn;
}

THook(std::string const&, "?RIDING_TAG@Actor@@2V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@B",
      std::string const& ret)
{
    logger.info("Actor::RIDING_TAG");
    auto& rtn = original(ret);
    return rtn;
}

// virtual : 274
TInstanceHook(bool, "?hasComponent@Actor@@UEBA_NAEBVHashedString@@@Z",
              Actor, class HashedString const& a0)
{
    logger.info("Actor::hasComponent");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class Mob*, "?getLastHurtByMob@Actor@@UEAAPEAVMob@@XZ",
              Actor)
{
    logger.info("Actor::getLastHurtByMob");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setLastHurtByMob@Actor@@UEAAXPEAVMob@@@Z",
              Actor, class Mob* a0)
{
    logger.info("Actor::setLastHurtByMob");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class Player*, "?getLastHurtByPlayer@Actor@@UEAAPEAVPlayer@@XZ",
              Actor)
{
    logger.info("Actor::getLastHurtByPlayer");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setLastHurtByPlayer@Actor@@UEAAXPEAVPlayer@@@Z",
              Actor, class Player* a0)
{
    logger.info("Actor::setLastHurtByPlayer");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class Mob*, "?getLastHurtMob@Actor@@UEAAPEAVMob@@XZ",
              Actor)
{
    logger.info("Actor::getLastHurtMob");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setLastHurtMob@Actor@@UEAAXPEAV1@@Z",
              Actor, class Actor* a0)
{
    logger.info("Actor::setLastHurtMob");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?outOfWorld@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::outOfWorld");
    original(this);
}

TInstanceHook(void, "?reloadHardcodedClient@Actor@@MEAAXW4InitializationMethod@1@AEBVVariantParameterList@@@Z",
              Actor, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Actor::reloadHardcodedClient");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?initializeComponents@Actor@@MEAAXW4InitializationMethod@1@AEBVVariantParameterList@@@Z",
              Actor, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Actor::initializeComponents");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?reloadComponents@Actor@@MEAAXW4InitializationMethod@1@AEBVVariantParameterList@@@Z",
              Actor, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Actor::reloadComponents");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_serverInitItemStackIds@Actor@@MEAAXXZ",
              Actor)
{
    logger.info("Actor::_serverInitItemStackIds");
    original(this);
}

TInstanceHook(void, "?_doInitialMove@Actor@@MEAAXXZ",
              Actor)
{
    logger.info("Actor::_doInitialMove");
    original(this);
}

TInstanceHook(void, "?reset@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::reset");
    original(this);
}

TInstanceHook(int, "?getOnDeathExperience@Actor@@UEAAHXZ",
              Actor)
{
    logger.info("Actor::getOnDeathExperience");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum ActorType, "?getOwnerEntityType@Actor@@UEAA?AW4ActorType@@XZ",
              Actor)
{
    logger.info("Actor::getOwnerEntityType");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?remove@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::remove");
    original(this);
}

TInstanceHook(void, "?setPos@Actor@@UEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::setPos");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(struct PredictedMovementValues const&, "?getPredictedMovementValues@Actor@@UEBAAEBUPredictedMovementValues@@XZ",
              Actor)
{
    logger.info("Actor::getPredictedMovementValues");
    auto& rtn = original(this);
    return rtn;
}

// there are 2 functions with the same rva

// ?getStateVector@Actor@@QEBAAEBVStateVector@@XZ
// ?getStateVectorNonConst@Actor@@QEAAAEAVStateVector@@XZ

// TInstanceHook(class Vec3 const&, "?getPos@Actor@@UEBAAEBVVec3@@XZ",
//     Actor){
//     logger.info("Actor::getPos");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(class Vec3 const&, "?getPosOld@Actor@@UEBAAEBVVec3@@XZ",
              Actor)
{
    logger.info("Actor::getPosOld");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class Vec3 const&, "?getPosExtrapolated@Actor@@UEBA?BVVec3@@M@Z",
              Actor, class Vec3 const& ret, float a0)
{
    logger.info("Actor::getPosExtrapolated");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class Vec3&, "?getAttachPos@Actor@@UEBA?AVVec3@@W4ActorLocation@@M@Z",
              Actor, class Vec3& ret, enum ActorLocation a0, float a1)
{
    //logger.info("Actor::getAttachPos");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(class Vec3&, "?getFiringPos@Actor@@UEBA?AVVec3@@XZ",
              Actor, class Vec3& ret)
{
    logger.info("Actor::getFiringPos");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?setRot@Actor@@UEAAXAEBVVec2@@@Z",
              Actor, class Vec2 const& a0)
{
    logger.info("Actor::setRot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?move@Actor@@UEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::move");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?move@Actor@@UEBAXAEAUIActorMovementProxy@@AEBVVec3@@@Z",
              Actor, struct IActorMovementProxy& a0, class Vec3 const& a1)
{
    logger.info("Actor::move");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(class Vec3&, "?getInterpolatedRidingPosition@Actor@@UEBA?AVVec3@@M@Z",
              Actor, class Vec3& ret, float a0)
{
    //logger.info("Actor::getInterpolatedRidingPosition");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getInterpolatedBodyRot@Actor@@UEBAMM@Z",
              Actor, float a0)
{
    logger.info("Actor::getInterpolatedBodyRot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getYawSpeedInDegreesPerSecond@Actor@@UEBAMXZ",
              Actor)
{
    logger.info("Actor::getYawSpeedInDegreesPerSecond");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getInterpolatedWalkAnimSpeed@Actor@@UEBAMM@Z",
              Actor, float a0)
{
    logger.info("Actor::getInterpolatedWalkAnimSpeed");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

// there are 7 functions with the same rva

// ?getLastDelta@DirectPlayerMovementProxy@@UEBA?AVVec3@@XZ
// ?getLastPos@DirectPlayerMovementProxy@@UEBA?AVVec3@@XZ
// ?getWorldPosition@ClientAutomationCommandOrigin@@UEBA?AVVec3@@XZ
// ?getWorldPosition@PrecompiledCommandOrigin@@UEBA?AVVec3@@XZ
// ?getWorldPosition@ScriptCommandOrigin@@UEBA?AVVec3@@XZ
// ?getWorldPosition@ScriptingCommandOrigin@@UEBA?AVVec3@@XZ
// ?getWorldPosition@ServerCommandOrigin@@UEBA?AVVec3@@XZ

// TInstanceHook(class Vec3&, "?getInterpolatedRidingOffset@Actor@@UEBA?AVVec3@@M@Z",
//     Actor, class Vec3& ret, float a0){
//     logger.info("Actor::getInterpolatedRidingOffset");
//     auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
//     return rtn;
// }

TInstanceHook(void, "?checkBlockCollisions@Actor@@UEAAXAEBVAABB@@V?$function@$$A6AXAEAVBlockSource@@AEBVBlock@@AEBVBlockPos@@AEAVActor@@@Z@std@@@Z",
              Actor, class AABB const& a0, class std::function<void(class BlockSource&, class Block const&, class BlockPos const&, class Actor&)> a1)
{
    logger.info("Actor::checkBlockCollisions");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?updateEntityInside@Actor@@UEAAXAEBVAABB@@@Z",
              Actor, class AABB const& a0)
{
    logger.info("Actor::updateEntityInside");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?updateEntityInside@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::updateEntityInside");
    original(this);
}

TInstanceHook(bool, "?isFireImmune@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isFireImmune");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?blockedByShield@Actor@@UEAAXAEBVActorDamageSource@@AEAV1@@Z",
              Actor, class ActorDamageSource const& a0, class Actor& a1)
{
    logger.info("Actor::blockedByShield");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?teleportTo@Actor@@UEAAXAEBVVec3@@_NHH@Z",
              Actor, class Vec3 const& a0, bool a1, int a2, int a3)
{
    logger.info("Actor::teleportTo");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(bool, "?tryTeleportTo@Actor@@UEAA_NAEBVVec3@@_N1HH@Z",
              Actor, class Vec3 const& a0, bool a1, bool a2, int a3, int a4)
{
    logger.info("Actor::tryTeleportTo");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4));
    return rtn;
}

TInstanceHook(void, "?chorusFruitTeleport@Actor@@UEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::chorusFruitTeleport");
    original(this, std::forward<decltype(a0)>(a0));
}

// there are 1 functions with the same rva

// ?setVelocity@Actor@@QEAAXAEBVVec3@@@Z

// TInstanceHook(void, "?lerpMotion@Actor@@UEAAXAEBVVec3@@@Z",
//     Actor, class Vec3 const& a0){
//     logger.info("Actor::lerpMotion");
//     original(this, std::forward<decltype(a0)>(a0));
// }

#include <MC/AddActorBasePacket.hpp>
TInstanceHook(std::unique_ptr<class AddActorBasePacket>&, "?tryCreateAddActorPacket@Actor@@UEAA?AV?$unique_ptr@VAddActorBasePacket@@U?$default_delete@VAddActorBasePacket@@@std@@@std@@XZ",
              Actor, std::unique_ptr<class AddActorBasePacket>& ret)
{
    logger.info("Actor::tryCreateAddActorPacket");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?normalTick@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::normalTick");
    original(this);
}

TInstanceHook(void, "?baseTick@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::baseTick");
    original(this);
}

TInstanceHook(void, "?vehicleTick@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::vehicleTick");
    original(this);
}

TInstanceHook(void, "?positionPassenger@Actor@@UEAAXAEAV1@M@Z",
              Actor, class Actor& a0, float a1)
{
    logger.info("Actor::positionPassenger");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// there are 1 functions with the same rva

// ?getDuration@RecordItem@@QEBAMXZ

// TInstanceHook(float, "?getRidingHeight@Actor@@UEAAMXZ",
//     Actor){
//     logger.info("Actor::getRidingHeight");
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(bool, "?startRiding@Actor@@UEAA_NAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::startRiding");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?addPassenger@Actor@@UEAAXAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::addPassenger");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?flagPassengerToRemove@Actor@@UEAAXAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::flagPassengerToRemove");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(std::string&, "?getExitTip@Actor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@W4InputMode@@@Z",
              Actor, std::string& ret, std::string const& a0, enum InputMode a1)
{
    logger.info("Actor::getExitTip");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?intersects@Actor@@UEBA_NAEBVVec3@@0@Z",
              Actor, class Vec3 const& a0, class Vec3 const& a1)
{
    logger.info("Actor::intersects");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?isInWall@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInWall");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInvisible@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInvisible");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canShowNameTag@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::canShowNameTag");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setNameTagVisible@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setNameTagVisible");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(std::string const&, "?getNameTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Actor)
{
    //logger.info("Actor::getNameTag");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(unsigned __int64&, "?getNameTagAsHash@Actor@@UEBA_KXZ",
              Actor, unsigned __int64& ret)
{
    logger.info("Actor::getNameTagAsHash");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(std::string&, "?getFormattedNameTag@Actor@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Actor, std::string& ret)
{
    logger.info("Actor::getFormattedNameTag");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?filterFormattedNameTag@Actor@@UEAAXAEBVUIProfanityContext@@@Z",
              Actor, class UIProfanityContext const& a0)
{
    logger.info("Actor::filterFormattedNameTag");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setNameTag@Actor@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::setNameTag");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setScoreTag@Actor@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Actor, std::string const& a0)
{
    logger.info("Actor::setScoreTag");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(std::string const&, "?getScoreTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ",
              Actor)
{
    logger.info("Actor::getScoreTag");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInWater@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInWater");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasEnteredWater@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::hasEnteredWater");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInLava@Actor@@UEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isInLava");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isUnderLiquid@Actor@@UEBA_NW4MaterialType@@@Z",
              Actor, enum MaterialType a0)
{
    //logger.info("Actor::isUnderLiquid");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isOverWater@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isOverWater");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setBlockMovementSlowdownMultiplier@Actor@@UEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::setBlockMovementSlowdownMultiplier");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?resetBlockMovementSlowdownMultiplier@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::resetBlockMovementSlowdownMultiplier");
    original(this);
}

TInstanceHook(float, "?getShadowHeightOffs@Actor@@UEAAMXZ",
              Actor)
{
    logger.info("Actor::getShadowHeightOffs");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getShadowRadius@Actor@@UEBAMXZ",
              Actor)
{
    logger.info("Actor::getShadowRadius");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Vec3&, "?getHeadLookVector@Actor@@UEBA?AVVec3@@M@Z",
              Actor, class Vec3& ret, float a0)
{
    logger.info("Actor::getHeadLookVector");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canSee@Actor@@UEBA_NAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::canSee");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canSee@Actor@@UEBA_NAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::canSee");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?isSkyLit@Actor@@UEAA_NM@Z",
              Actor, float a0)
{
    logger.info("Actor::isSkyLit");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getBrightness@Actor@@UEBAMM@Z",
              Actor, float a0)
{
    logger.info("Actor::getBrightness");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?onAboveBubbleColumn@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::onAboveBubbleColumn");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?onInsideBubbleColumn@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::onInsideBubbleColumn");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isImmobile@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isImmobile");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSilent@Actor@@UEAA_NXZ",
              Actor)
{
    //logger.info("Actor::isSilent");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setSneaking@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setSneaking");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isAlive@Actor@@UEBA_NXZ",
              Actor)
{
    //logger.info("Actor::isAlive");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isOnFire@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isOnFire");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isOnHotBlock@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isOnHotBlock");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isAffectedByWaterBottle@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isAffectedByWaterBottle");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canAttack@Actor@@UEBA_NPEAV1@_N@Z",
              Actor, class Actor* a0, bool a1)
{
    logger.info("Actor::canAttack");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?setTarget@Actor@@UEAAXPEAV1@@Z",
              Actor, class Actor* a0)
{
    logger.info("Actor::setTarget");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?attack@Actor@@UEAA_NAEAV1@AEBW4ActorDamageCause@@@Z",
              Actor, class Actor& a0, enum ActorDamageCause const& a1)
{
    logger.info("Actor::attack");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?performRangedAttack@Actor@@UEAAXAEAV1@M@Z",
              Actor, class Actor& a0, float a1)
{
    logger.info("Actor::performRangedAttack");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(int, "?getEquipmentCount@Actor@@UEBAHXZ",
              Actor)
{
    logger.info("Actor::getEquipmentCount");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setOwner@Actor@@UEAAXUActorUniqueID@@@Z",
              Actor, struct ActorUniqueID a0)
{
    logger.info("Actor::setOwner");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSitting@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setSitting");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?getInventorySize@Actor@@UEBAHXZ",
              Actor)
{
    logger.info("Actor::getInventorySize");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getEquipSlots@Actor@@UEBAHXZ",
              Actor)
{
    logger.info("Actor::getEquipSlots");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getChestSlots@Actor@@UEBAHXZ",
              Actor)
{
    logger.info("Actor::getChestSlots");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setStanding@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setStanding");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?canPowerJump@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::canPowerJump");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setCanPowerJump@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setCanPowerJump");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isEnchanted@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isEnchanted");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?shouldRender@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::shouldRender");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?playAmbientSound@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::playAmbientSound");
    original(this);
}

TInstanceHook(enum LevelSoundEvent, "?getAmbientSound@Actor@@UEBA?AW4LevelSoundEvent@@XZ",
              Actor)
{
    logger.info("Actor::getAmbientSound");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isInvulnerableTo@Actor@@UEBA_NAEBVActorDamageSource@@@Z",
              Actor, class ActorDamageSource const& a0)
{
    logger.info("Actor::isInvulnerableTo");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(enum ActorDamageCause, "?getBlockDamageCause@Actor@@UEBA?AW4ActorDamageCause@@AEBVBlock@@@Z",
              Actor, class Block const& a0)
{
    logger.info("Actor::getBlockDamageCause");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?actuallyHurt@Actor@@UEAAXHAEBVActorDamageSource@@_N@Z",
              Actor, int a0, class ActorDamageSource const& a1, bool a2)
{
    logger.info("Actor::actuallyHurt");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(bool, "?doFireHurt@Actor@@UEAA_NH@Z",
              Actor, int a0)
{
    logger.info("Actor::doFireHurt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?onLightningHit@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::onLightningHit");
    original(this);
}

TInstanceHook(void, "?feed@Actor@@UEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::feed");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?handleEntityEvent@Actor@@UEAAXW4ActorEvent@@H@Z",
              Actor, enum ActorEvent a0, int a1)
{
    logger.info("Actor::handleEntityEvent");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// there are 1 functions with the same rva

// ?getBaseAmbientValue@NetherBrightnessRamp@@UEBAMXZ

// TInstanceHook(float, "?getPickRadius@Actor@@UEAAMXZ",
//     Actor){
//     logger.info("Actor::getPickRadius");
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(class HashedString const&, "?getActorRendererId@Actor@@UEBAAEBVHashedString@@XZ",
              Actor)
{
    logger.info("Actor::getActorRendererId");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(class ItemActor*, "?spawnAtLocation@Actor@@UEAAPEAVItemActor@@HH@Z",
              Actor, int a0, int a1)
{
    logger.info("Actor::spawnAtLocation");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(class ItemActor*, "?spawnAtLocation@Actor@@UEAAPEAVItemActor@@HHM@Z",
              Actor, int a0, int a1, float a2)
{
    logger.info("Actor::spawnAtLocation");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(class ItemActor*, "?spawnAtLocation@Actor@@UEAAPEAVItemActor@@AEBVBlock@@H@Z",
              Actor, class Block const& a0, int a1)
{
    logger.info("Actor::spawnAtLocation");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(class ItemActor*, "?spawnAtLocation@Actor@@UEAAPEAVItemActor@@AEBVBlock@@HM@Z",
              Actor, class Block const& a0, int a1, float a2)
{
    logger.info("Actor::spawnAtLocation");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(class ItemActor*, "?spawnAtLocation@Actor@@UEAAPEAVItemActor@@AEBVItemStack@@M@Z",
              Actor, class ItemStack const& a0, float a1)
{
    logger.info("Actor::spawnAtLocation");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?despawn@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::despawn");
    original(this);
}

TInstanceHook(void, "?killed@Actor@@UEAAXAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::killed");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setArmor@Actor@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z",
              Actor, enum ArmorSlot a0, class ItemStack const& a1)
{
    logger.info("Actor::setArmor");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(class ItemStack const&, "?getArmor@Actor@@UEBAAEBVItemStack@@W4ArmorSlot@@@Z",
              Actor, enum ArmorSlot a0)
{
    logger.info("Actor::getArmor");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(std::vector<class ItemStack const*>&, "?getAllArmor@Actor@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ",
              Actor, std::vector<class ItemStack const*>& ret)
{
    logger.info("Actor::getAllArmor");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getEquippedSlot@Actor@@UEBAAEBVItemStack@@W4EquipmentSlot@@@Z",
              Actor, enum EquipmentSlot a0)
{
    logger.info("Actor::getEquippedSlot");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getCarriedItem@Actor@@UEBAAEBVItemStack@@XZ",
              Actor)
{
    logger.info("Actor::getCarriedItem");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setCarriedItem@Actor@@UEAAXAEBVItemStack@@@Z",
              Actor, class ItemStack const& a0)
{
    logger.info("Actor::setCarriedItem");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setOffhandSlot@Actor@@UEAAXAEBVItemStack@@@Z",
              Actor, class ItemStack const& a0)
{
    logger.info("Actor::setOffhandSlot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class ItemStack const&, "?getEquippedTotem@Actor@@UEBAAEBVItemStack@@XZ",
              Actor)
{
    logger.info("Actor::getEquippedTotem");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?consumeTotem@Actor@@UEAA_NXZ",
              Actor)
{
    logger.info("Actor::consumeTotem");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?save@Actor@@UEAA_NAEAVCompoundTag@@@Z",
              Actor, class CompoundTag& a0)
{
    logger.info("Actor::save");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?saveWithoutId@Actor@@UEAAXAEAVCompoundTag@@@Z",
              Actor, class CompoundTag& a0)
{
    logger.info("Actor::saveWithoutId");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?load@Actor@@UEAA_NAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              Actor, class CompoundTag const& a0, class DataLoadHelper& a1)
{
    logger.info("Actor::load");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?loadLinks@Actor@@UEAAXAEBVCompoundTag@@AEAV?$vector@UActorLink@@V?$allocator@UActorLink@@@std@@@std@@AEAVDataLoadHelper@@@Z",
              Actor, class CompoundTag const& a0, class std::vector<struct ActorLink, class std::allocator<struct ActorLink>>& a1, class DataLoadHelper& a2)
{
    logger.info("Actor::loadLinks");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(enum ActorType, "?getEntityTypeId@Actor@@UEBA?AW4ActorType@@XZ",
              Actor)
{
    logger.info("Actor::getEntityTypeId");
    auto rtn = original(this);
    return rtn;
}

// there are 1 functions with the same rva

// ?getRawName@ActorAnimationControllerStatePlayer@@UEBAAEBVHashedString@@XZ

// TInstanceHook(class HashedString const&, "?queryEntityRenderer@Actor@@UEBAAEBVHashedString@@XZ",
//     Actor){
//     logger.info("Actor::queryEntityRenderer");
//     auto& rtn = original(this);
//     return rtn;
// }

TInstanceHook(void, "?thawFreezeEffect@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::thawFreezeEffect");
    original(this);
}

TInstanceHook(bool const&, "?isWearingLeatherArmor@Actor@@UEBA?B_NXZ",
              Actor, bool const& ret)
{
    logger.info("Actor::isWearingLeatherArmor");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(class AABB&, "?getLiquidAABB@Actor@@UEBA?AVAABB@@W4MaterialType@@@Z",
              Actor, class AABB& ret, enum MaterialType a0)
{
    logger.info("Actor::getLiquidAABB");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?handleInsidePortal@Actor@@UEAAXAEBVBlockPos@@@Z",
              Actor, class BlockPos const& a0)
{
    logger.info("Actor::handleInsidePortal");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?getPortalCooldown@Actor@@UEBAHXZ",
              Actor)
{
    logger.info("Actor::getPortalCooldown");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void* /*class AutomaticID<class Dimension, int>&*/, "?getDimensionId@Actor@@UEBA?AV?$AutomaticID@VDimension@@H@@XZ",
              Actor, class AutomaticID<class Dimension, int>& ret)
{
    //logger.info("Actor::getDimensionId");
    auto rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?changeDimension@Actor@@UEAAXV?$AutomaticID@VDimension@@H@@_N@Z",
              Actor, class AutomaticID<class Dimension, int> a0, bool a1)
{
    logger.info("Actor::changeDimension");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?checkFallDamage@Actor@@UEAAXM_N@Z",
              Actor, float a0, bool a1)
{
    logger.info("Actor::checkFallDamage");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

#include <MC/ActorDamageSource.hpp>
TInstanceHook(void, "?causeFallDamage@Actor@@UEAAXMMVActorDamageSource@@@Z",
              Actor, float a0, float a1, class ActorDamageSource& a2)
{
    logger.info("Actor::causeFallDamage");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?handleFallDistanceOnServer@Actor@@UEAAXMM_N@Z",
              Actor, float a0, float a1, bool a2)
{
    logger.info("Actor::handleFallDistanceOnServer");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?playSynchronizedSound@Actor@@UEAAXW4LevelSoundEvent@@AEBVVec3@@AEBVBlock@@_N@Z",
              Actor, enum LevelSoundEvent a0, class Vec3 const& a1, class Block const& a2, bool a3)
{
    logger.info("Actor::playSynchronizedSound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?playSynchronizedSound@Actor@@UEAAXW4LevelSoundEvent@@AEBVVec3@@H_N@Z",
              Actor, enum LevelSoundEvent a0, class Vec3 const& a1, int a2, bool a3)
{
    logger.info("Actor::playSynchronizedSound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?onSynchedFlagUpdate@Actor@@UEAAXH_J0@Z",
              Actor, int a0, __int64 a1, __int64 a2)
{
    logger.info("Actor::onSynchedFlagUpdate");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?onSynchedDataUpdate@Actor@@UEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::onSynchedDataUpdate");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?canAddPassenger@Actor@@UEBA_NAEAV1@@Z",
              Actor, class Actor& a0)
{
    logger.info("Actor::canAddPassenger");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?tickLeash@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::tickLeash");
    original(this);
}

TInstanceHook(void, "?sendMotionPacketIfNeeded@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::sendMotionPacketIfNeeded");
    original(this);
}

TInstanceHook(void, "?stopRiding@Actor@@UEAAX_N00@Z",
              Actor, bool a0, bool a1, bool a2)
{
    logger.info("Actor::stopRiding");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?startSwimming@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::startSwimming");
    original(this);
}

TInstanceHook(void, "?stopSwimming@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::stopSwimming");
    original(this);
}

TInstanceHook(enum CommandPermissionLevel, "?getCommandPermissionLevel@Actor@@UEBA?AW4CommandPermissionLevel@@XZ",
              Actor)
{
    logger.info("Actor::getCommandPermissionLevel");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isClientSide@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isClientSide");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class AttributeInstance*, "?getMutableAttribute@Actor@@UEAAPEAVAttributeInstance@@AEBVAttribute@@@Z",
              Actor, class Attribute const& a0)
{
    logger.info("Actor::getMutableAttribute");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class AttributeInstance const&, "?getAttribute@Actor@@UEBAAEBVAttributeInstance@@AEBVAttribute@@@Z",
              Actor, class Attribute const& a0)
{
    //logger.info("Actor::getAttribute");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?heal@Actor@@UEAAXH@Z",
              Actor, int a0)
{
    logger.info("Actor::heal");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isInvertedHealAndHarm@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::isInvertedHealAndHarm");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?canBeAffected@Actor@@UEBA_NH@Z",
              Actor, int a0)
{
    logger.info("Actor::canBeAffected");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canBeAffected@Actor@@UEBA_NAEBVMobEffectInstance@@@Z",
              Actor, class MobEffectInstance const& a0)
{
    logger.info("Actor::canBeAffected");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?canBeAffectedByArrow@Actor@@UEBA_NAEBVMobEffectInstance@@@Z",
              Actor, class MobEffectInstance const& a0)
{
    logger.info("Actor::canBeAffectedByArrow");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?onEffectAdded@Actor@@UEAAXAEAVMobEffectInstance@@@Z",
              Actor, class MobEffectInstance& a0)
{
    logger.info("Actor::onEffectAdded");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?onEffectUpdated@Actor@@UEAAXAEAVMobEffectInstance@@@Z",
              Actor, class MobEffectInstance& a0)
{
    logger.info("Actor::onEffectUpdated");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?onEffectRemoved@Actor@@UEAAXAEAVMobEffectInstance@@@Z",
              Actor, class MobEffectInstance& a0)
{
    logger.info("Actor::onEffectRemoved");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(class AnimationComponent&, "?getAnimationComponent@Actor@@UEAAAEAVAnimationComponent@@XZ",
              Actor)
{
    logger.info("Actor::getAnimationComponent");
    auto& rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?openContainerComponent@Actor@@UEAAXAEAVPlayer@@@Z",
              Actor, class Player& a0)
{
    logger.info("Actor::openContainerComponent");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?useItem@Actor@@UEAAXAEAVItemStackBase@@W4ItemUseMethod@@_N@Z",
              Actor, class ItemStackBase& a0, enum ItemUseMethod a1, bool a2)
{
    logger.info("Actor::useItem");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?getDebugText@Actor@@UEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z",
              Actor, class std::vector<std::string, class std::allocator<std::string>>& a0)
{
    logger.info("Actor::getDebugText");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(float, "?getMapDecorationRotation@Actor@@UEBAMXZ",
              Actor)
{
    logger.info("Actor::getMapDecorationRotation");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getPassengerYRotation@Actor@@UEBAMAEBV1@@Z",
              Actor, class Actor const& a0)
{
    logger.info("Actor::getPassengerYRotation");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?add@Actor@@UEAA_NAEAVItemStack@@@Z",
              Actor, class ItemStack& a0)
{
    logger.info("Actor::add");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?drop@Actor@@UEAA_NAEBVItemStack@@_N@Z",
              Actor, class ItemStack const& a0, bool a1)
{
    logger.info("Actor::drop");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?getInteraction@Actor@@UEAA_NAEAVPlayer@@AEAVActorInteraction@@AEBVVec3@@@Z",
              Actor, class Player& a0, class ActorInteraction& a1, class Vec3 const& a2)
{
    logger.info("Actor::getInteraction");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(void, "?setSize@Actor@@UEAAXMM@Z",
              Actor, float a0, float a1)
{
    logger.info("Actor::setSize");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?onOrphan@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::onOrphan");
    original(this);
}

TInstanceHook(void, "?wobble@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::wobble");
    original(this);
}

TInstanceHook(bool, "?wasHurt@Actor@@UEAA_NXZ",
              Actor)
{
    logger.info("Actor::wasHurt");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?startSpinAttack@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::startSpinAttack");
    original(this);
}

TInstanceHook(void, "?setDamageNearbyMobs@Actor@@UEAAX_N@Z",
              Actor, bool a0)
{
    logger.info("Actor::setDamageNearbyMobs");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?reloadLootTable@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::reloadLootTable");
    original(this);
}

TInstanceHook(void, "?reloadLootTable@Actor@@UEAAXAEBUEquipmentTableDefinition@@@Z",
              Actor, struct EquipmentTableDefinition const& a0)
{
    logger.info("Actor::reloadLootTable");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?kill@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::kill");
    original(this);
}

TInstanceHook(void, "?die@Actor@@UEAAXAEBVActorDamageSource@@@Z",
              Actor, class ActorDamageSource const& a0)
{
    logger.info("Actor::die");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?shouldDropDeathLoot@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::shouldDropDeathLoot");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?shouldTick@Actor@@UEBA_NXZ",
              Actor)
{
    logger.info("Actor::shouldTick");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?extractSnapshot@Actor@@UEBAXAEAUPlayerSnapshotComponent@@@Z",
              Actor, struct PlayerSnapshotComponent& a0)
{
    logger.info("Actor::extractSnapshot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?applySnapshot@Actor@@UEAAXAEBUPlayerSnapshotComponent@@0@Z",
              Actor, struct PlayerSnapshotComponent const& a0, struct PlayerSnapshotComponent const& a1)
{
    logger.info("Actor::applySnapshot");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(float, "?getNextStep@Actor@@UEAAMM@Z",
              Actor, float a0)
{
    logger.info("Actor::getNextStep");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(class LootTable*, "?getLootTable@Actor@@UEAAPEAVLootTable@@XZ",
              Actor)
{
    logger.info("Actor::getLootTable");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?interpolatorTick@Actor@@UEAAXXZ",
              Actor)
{
    logger.info("Actor::interpolatorTick");
    original(this);
}

TInstanceHook(bool, "?shouldTryMakeStepSound@Actor@@MEAA_NXZ",
              Actor)
{
    logger.info("Actor::shouldTryMakeStepSound");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?_hurt@Actor@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
              Actor, class ActorDamageSource const& a0, int a1, bool a2, bool a3)
{
    logger.info("Actor::_hurt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(void, "?markHurt@Actor@@MEAAXXZ",
              Actor)
{
    logger.info("Actor::markHurt");
    original(this);
}

#include <MC/AnimationComponent.hpp>
TInstanceHook(class AnimationComponent&, "?_getAnimationComponent@Actor@@MEAAAEAVAnimationComponent@@AEAV?$shared_ptr@VAnimationComponent@@@std@@W4AnimationComponentGroup@@@Z",
              Actor, class std::shared_ptr<class AnimationComponent>& a0, enum AnimationComponentGroup a1)
{
    logger.info("Actor::_getAnimationComponent");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?readAdditionalSaveData@Actor@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              Actor, class CompoundTag const& a0, class DataLoadHelper& a1)
{
    logger.info("Actor::readAdditionalSaveData");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?addAdditionalSaveData@Actor@@MEAAXAEAVCompoundTag@@@Z",
              Actor, class CompoundTag& a0)
{
    logger.info("Actor::addAdditionalSaveData");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_playStepSound@Actor@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z",
              Actor, class BlockPos const& a0, class Block const& a1)
{
    logger.info("Actor::_playStepSound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_playFlySound@Actor@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z",
              Actor, class BlockPos const& a0, class Block const& a1)
{
    logger.info("Actor::_playFlySound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?checkInsideBlocks@Actor@@MEAAXM@Z",
              Actor, float a0)
{
    logger.info("Actor::checkInsideBlocks");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?pushOutOfBlocks@Actor@@MEAAXAEBVVec3@@@Z",
              Actor, class Vec3 const& a0)
{
    logger.info("Actor::pushOutOfBlocks");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?updateWaterState@Actor@@MEAA_NXZ",
              Actor)
{
    logger.info("Actor::updateWaterState");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?doWaterSplashEffect@Actor@@MEAAXXZ",
              Actor)
{
    logger.info("Actor::doWaterSplashEffect");
    original(this);
}

TInstanceHook(void, "?spawnTrailBubbles@Actor@@MEAAXXZ",
              Actor)
{
    logger.info("Actor::spawnTrailBubbles");
    original(this);
}

TInstanceHook(void, "?updateInsideBlock@Actor@@MEAAXXZ",
              Actor)
{
    logger.info("Actor::updateInsideBlock");
    original(this);
}

TInstanceHook(void, "?_removePassenger@Actor@@MEAAXAEBUActorUniqueID@@_N11@Z",
              Actor, struct ActorUniqueID const& a0, bool a1, bool a2, bool a3)
{
    logger.info("Actor::_removePassenger");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

// virtual.unordered : 26
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

// TInstanceHook(bool, "?canSeeInvisible@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::canSeeInvisible");
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

// TInstanceHook(bool, "?isCreativeModeAllowed@Actor@@UEAA_NXZ",
//     Actor){
//     logger.info("Actor::isCreativeModeAllowed");
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

// TInstanceHook(bool, "?isShootable@Actor@@UEAA_NXZ",
//     Actor){
//     logger.info("Actor::isShootable");
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

// TInstanceHook(bool, "?breaksFallingBlocks@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::breaksFallingBlocks");
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

// TInstanceHook(bool, "?isLeashableType@Actor@@UEAA_NXZ",
//     Actor){
//     logger.info("Actor::isLeashableType");
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

// TInstanceHook(bool, "?hasOutputSignal@Actor@@UEBA_NE@Z",
//     Actor, unsigned char a0){
//     logger.info("Actor::hasOutputSignal");
//     auto rtn = original(this, std::forward<decltype(a0)>(a0));
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

// TInstanceHook(bool, "?isLocalPlayer@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::isLocalPlayer");
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

// TInstanceHook(bool, "?_makeFlySound@Actor@@MEBA_NXZ",
//     Actor){
//     logger.info("Actor::_makeFlySound");
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

// TInstanceHook(bool, "?isPlayer@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::isPlayer");
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

// TInstanceHook(bool, "?getAlwaysShowNameTag@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::getAlwaysShowNameTag");
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

// TInstanceHook(bool, "?interactPreventDefault@Actor@@UEAA_NXZ",
//     Actor){
//     logger.info("Actor::interactPreventDefault");
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

// TInstanceHook(int, "?getOutputSignal@Actor@@UEBAHXZ",
//     Actor){
//     logger.info("Actor::getOutputSignal");
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

// TInstanceHook(class Actor*, "?findAttackTarget@Actor@@UEAAPEAV1@XZ",
//     Actor){
//     logger.info("Actor::findAttackTarget");
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

// TInstanceHook(void, "?_onSizeUpdated@Actor@@EEAAXXZ",
//     Actor){
//     logger.info("Actor::_onSizeUpdated");
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

// TInstanceHook(void, "?reloadHardcoded@Actor@@MEAAXW4InitializationMethod@1@AEBVVariantParameterList@@@Z",
//     Actor, enum Actor::InitializationMethod a0, class VariantParameterList const& a1){
//     logger.info("Actor::reloadHardcoded");
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

// TInstanceHook(void, "?changeDimension@Actor@@UEAAXAEBVChangeDimensionPacket@@@Z",
//     Actor, class ChangeDimensionPacket const& a0){
//     logger.info("Actor::changeDimension");
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

// TInstanceHook(void, "?renderDebugServerState@Actor@@UEAAXAEBVOptions@@@Z",
//     Actor, class Options const& a0){
//     logger.info("Actor::renderDebugServerState");
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

// TInstanceHook(void, "?_doAutoAttackOnTouch@Actor@@EEAAXAEAV1@@Z",
//     Actor, class Actor& a0){
//     logger.info("Actor::_doAutoAttackOnTouch");
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

// TInstanceHook(void, "?updateEntitySpecificMolangVariables@Actor@@MEAAXAEAVRenderParams@@@Z",
//     Actor, class RenderParams& a0){
//     logger.info("Actor::updateEntitySpecificMolangVariables");
//     original(this, std::forward<decltype(a0)>(a0));
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

// TInstanceHook(bool, "?canExistInPeaceful@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::canExistInPeaceful");
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

// TInstanceHook(bool, "?isFishable@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::isFishable");
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

// TInstanceHook(bool, "?isTargetable@Actor@@UEBA_NXZ",
//     Actor){
//     logger.info("Actor::isTargetable");
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

// TInstanceHook(bool, "?canMakeStepSound@Actor@@MEBA_NXZ",
//     Actor){
//     logger.info("Actor::canMakeStepSound");
//     auto rtn = original(this);
//     return rtn;
// }

// there are 44 functions with the same rva

// ?_getWalkTargetValue@Mob@@UEAAMAEBVBlockPos@@@Z
// ?getAmount@Amplifier@@UEBAMHM@Z
// ?getBaseAmbientValue@DimensionBrightnessRamp@@UEBAMXZ
// ?getCameraOffset@Actor@@UEBAMXZ
// ?getDamageBonus@Enchant@@UEBAMHAEBVActor@@@Z
// ?getDefaultScreenPositionX@AppPlatform@@UEBAMXZ
// ?getDefaultScreenPositionY@AppPlatform@@UEBAMXZ
// ?getDeletionDelayTimeSeconds@BlockActor@@UEBAMXZ
// ?getFlexibility@BlockLegacy@@UEBAMAEAVBlockSource@@AEBVBlockPos@@@Z
// ?getInterpolatedBodyYaw@Actor@@UEBAMM@Z
// ?getInterpolatedHeadRot@Actor@@UEBAMM@Z
// ?getItemUseIntervalProgress@Mob@@UEBAMXZ
// ?getItemUseStartupProgress@Mob@@UEBAMXZ
// ?getJumpRidingScale@DirectPlayerMovementProxy@@UEAAMXZ
// ?getPickRadius@Shulker@@UEAAMXZ
// ?getShadowHeightOffs@AbstractArrow@@UEAAMXZ
// ?getShadowHeightOffs@Boat@@UEAAMXZ
// ?getShadowHeightOffs@FallingBlock@@UEAAMXZ
// ?getShadowHeightOffs@Fireball@@UEAAMXZ
// ?getShadowHeightOffs@LlamaSpit@@UEAAMXZ

// TInstanceHook(float, "?getDeletionDelayTimeSeconds@Actor@@UEBAMXZ",
//     Actor){
//     logger.info("Actor::getDeletionDelayTimeSeconds");
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(class Actor&, "??1Actor@@UEAA@XZ",
              Actor)
{
    logger.info("Actor::~Actor");
    auto& rtn = original(this);
    return rtn;
}

// there are 4 functions with the same rva

// ?getControllingPlayer@Actor@@UEBA?AUActorUniqueID@@XZ
// ?getControllingPlayer@Minecart@@UEBA?AUActorUniqueID@@XZ
// ?getDamagingEntityUniqueID@ActorDamageSource@@UEBA?AUActorUniqueID@@XZ
// ?getEntityUniqueID@ActorDamageSource@@UEBA?AUActorUniqueID@@XZ

// TInstanceHook(struct ActorUniqueID&, "?getSourceUniqueID@Actor@@UEBA?AUActorUniqueID@@XZ",
//     Actor, struct ActorUniqueID& ret){
//     logger.info("Actor::getSourceUniqueID");
//     auto& rtn = original(this, ret);
//     return rtn;
// }

// vtbl_entry : 1

#endif // HOOK_CLASS_Actor

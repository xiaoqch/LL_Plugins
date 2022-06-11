#include "pch.h"
#include <MC/Mob.hpp>


#ifdef HOOK_CLASS_Mob
// child_types : 68
// parent_types : 1
// private : 3
TInstanceHook(bool, "?_initHardCodedComponents@Mob@@AEAA_NXZ",
              Mob)
{
    logger.info("Mob::_initHardCodedComponents");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?_updateSprintingState@Mob@@AEAAXXZ",
              Mob)
{
    logger.info("Mob::_updateSprintingState");
    original(this);
}

TInstanceHook(void, "?_verifyAttributes@Mob@@AEAAXXZ",
              Mob)
{
    logger.info("Mob::_verifyAttributes");
    original(this);
}

// private.static : 1
THook(bool, "?_tryApplyingLevitation@Mob@@CA_NAEBUIMobMovementProxy@@AEAVVec3@@@Z",
      struct IMobMovementProxy const& a0, class Vec3& a1)
{
    logger.info("Mob::_tryApplyingLevitation");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// protected : 9
TInstanceHook(void, "?_doSprintParticleEffect@Mob@@IEAAXXZ",
              Mob)
{
    logger.info("Mob::_doSprintParticleEffect");
    original(this);
}

TInstanceHook(void, "?_endJump@Mob@@IEAAXXZ",
              Mob)
{
    logger.info("Mob::_endJump");
    original(this);
}

TInstanceHook(void, "?_registerMobAttributes@Mob@@IEAAXXZ",
              Mob)
{
    logger.info("Mob::_registerMobAttributes");
    original(this);
}

TInstanceHook(int, "?getCurrentSwingDuration@Mob@@IEAAHXZ",
              Mob)
{
    logger.info("Mob::getCurrentSwingDuration");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?processSoulSpeed@Mob@@IEAAXXZ",
              Mob)
{
    logger.info("Mob::processSoulSpeed");
    original(this);
}

#include <MC/ListTag.hpp>
TInstanceHook(std::unique_ptr<class ListTag>&, "?saveOffhand@Mob@@IEBA?AV?$unique_ptr@VListTag@@U?$default_delete@VListTag@@@std@@@std@@XZ",
              Mob, std::unique_ptr<class ListTag>& ret)
{
    logger.info("Mob::saveOffhand");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?tickEffects@Mob@@IEAAXXZ",
              Mob)
{
    logger.info("Mob::tickEffects");
    original(this);
}

TInstanceHook(void, "?updateAttackAnim@Mob@@IEAAXXZ",
              Mob)
{
    logger.info("Mob::updateAttackAnim");
    original(this);
}

TInstanceHook(bool, "?updateGlidingDurability@Mob@@IEAA_NXZ",
              Mob)
{
    logger.info("Mob::updateGlidingDurability");
    auto rtn = original(this);
    return rtn;
}

// protected.static : 2
THook(void, "?_jumpFromGround@Mob@@KAXAEAUIMobMovementProxy@@@Z",
      struct IMobMovementProxy& a0)
{
    logger.info("Mob::_jumpFromGround");
    original(std::forward<decltype(a0)>(a0));
}

THook(int const&, "?MAX_INACTIVITY_TIMER@Mob@@1HB",
      int const& ret)
{
    logger.info("Mob::MAX_INACTIVITY_TIMER");
    auto& rtn = original(ret);
    return rtn;
}

// public : 67
TInstanceHook(class Mob&, "??0Mob@@QEAA@AEAVLevel@@AEAVEntityContext@@@Z",
              Mob, class Level& a0, class EntityContext& a1)
{
    logger.info("Mob::Mob");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(class Mob&, "??0Mob@@QEAA@PEAVActorDefinitionGroup@@AEBUActorDefinitionIdentifier@@AEAVEntityContext@@@Z",
              Mob, class ActorDefinitionGroup* a0, struct ActorDefinitionIdentifier const& a1, class EntityContext& a2)
{
    logger.info("Mob::Mob");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
    return rtn;
}

TInstanceHook(void, "?addSpeedModifier@Mob@@QEAAXAEBVUUID@mce@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@M@Z",
              Mob, class mce::UUID const& a0, std::string const& a1, float a2)
{
    logger.info("Mob::addSpeedModifier");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(float, "?calcMoveRelativeSpeed@Mob@@QEAAMW4TravelType@@@Z",
              Mob, enum TravelType a0)
{
    logger.info("Mob::calcMoveRelativeSpeed");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?checkTotemDeathProtection@Mob@@QEAA_NAEBVActorDamageSource@@@Z",
              Mob, class ActorDamageSource const& a0)
{
    logger.info("Mob::checkTotemDeathProtection");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?createAI@Mob@@QEAAXV?$vector@UGoalDefinition@@V?$allocator@UGoalDefinition@@@std@@@std@@@Z",
              Mob, std::vector<struct GoalDefinition>& a0)
{
    logger.info("Mob::createAI");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?discardFriction@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::discardFriction");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?emitJumpPreventedEvent@Mob@@QEAAXAEBVBlockPos@@@Z",
              Mob, class BlockPos const& a0)
{
    logger.info("Mob::emitJumpPreventedEvent");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?frostWalk@Mob@@QEAAXXZ",
              Mob)
{
    logger.info("Mob::frostWalk");
    original(this);
}

TInstanceHook(class BlockPos&, "?getBoundOrigin@Mob@@QEBA?AVBlockPos@@XZ",
              Mob, class BlockPos& ret)
{
    logger.info("Mob::getBoundOrigin");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getCaravanSize@Mob@@QEBAHXZ",
              Mob)
{
    logger.info("Mob::getCaravanSize");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getEatCounter@Mob@@QEBAHXZ",
              Mob)
{
    logger.info("Mob::getEatCounter");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class Mob*, "?getFirstCaravanHead@Mob@@QEAAPEAV1@XZ",
              Mob)
{
    logger.info("Mob::getFirstCaravanHead");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getFlightSpeed@Mob@@QEAAMXZ",
              Mob)
{
    logger.info("Mob::getFlightSpeed");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getFrictionModifier@Mob@@QEBAMXZ",
              Mob)
{
    logger.info("Mob::getFrictionModifier");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getGlidingTicks@Mob@@QEBAHXZ",
              Mob)
{
    logger.info("Mob::getGlidingTicks");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(class ItemStack const&, "?getItemSlot@Mob@@QEBAAEBVItemStack@@W4EquipmentSlot@@@Z",
              Mob, enum EquipmentSlot a0)
{
    logger.info("Mob::getItemSlot");
    auto& rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getJumpMultiplier@Mob@@QEAAMXZ",
              Mob)
{
    logger.info("Mob::getJumpMultiplier");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct Mob::JumpPreventionResult&, "?getJumpPrevention@Mob@@QEAA?AUJumpPreventionResult@1@XZ",
              Mob, struct Mob::JumpPreventionResult& ret)
{
    logger.info("Mob::getJumpPrevention");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(float, "?getMovementComponentCurrentSpeed@Mob@@QEBAMXZ",
              Mob)
{
    logger.info("Mob::getMovementComponentCurrentSpeed");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getNoActionTime@Mob@@QEBAHXZ",
              Mob)
{
    logger.info("Mob::getNoActionTime");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getRollCounter@Mob@@QEBAHXZ",
              Mob)
{
    logger.info("Mob::getRollCounter");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorUniqueID&, "?getTargetCaptain@Mob@@QEBA?AUActorUniqueID@@XZ",
              Mob, struct ActorUniqueID& ret)
{
    logger.info("Mob::getTargetCaptain");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(enum TravelType, "?getTravelType@Mob@@QEAA?AW4TravelType@@XZ",
              Mob)
{
    logger.info("Mob::getTravelType");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getYRotA@Mob@@QEBAMXZ",
              Mob)
{
    logger.info("Mob::getYRotA");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getZza@Mob@@QEBAMXZ",
              Mob)
{
    logger.info("Mob::getZza");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hasBoundOrigin@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::hasBoundOrigin");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isAbleToMove@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isAbleToMove");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isEating@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isEating");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isFrostWalking@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isFrostWalking");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isGliding@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isGliding");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isLayingEgg@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isLayingEgg");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPregnant@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isPregnant");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isRolling@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isRolling");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSprinting@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isSprinting");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isTransitioningSitting@Mob@@QEBA_NXZ",
              Mob)
{
    logger.info("Mob::isTransitioningSitting");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?onPlayerDimensionChanged@Mob@@QEAAXPEAVPlayer@@V?$AutomaticID@VDimension@@H@@@Z",
              Mob, class Player* a0, class AutomaticID<class Dimension, int> a1)
{
    logger.info("Mob::onPlayerDimensionChanged");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?onPlayerJump@Mob@@QEAAXH@Z",
              Mob, int a0)
{
    logger.info("Mob::onPlayerJump");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?removeSpeedModifier@Mob@@QEAAXAEBVUUID@mce@@@Z",
              Mob, class mce::UUID const& a0)
{
    logger.info("Mob::removeSpeedModifier");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?resetAttributes@Mob@@QEAAXXZ",
              Mob)
{
    logger.info("Mob::resetAttributes");
    original(this);
}

TInstanceHook(void, "?resetNoActionTime@Mob@@QEAAXXZ",
              Mob)
{
    logger.info("Mob::resetNoActionTime");
    original(this);
}

TInstanceHook(void, "?sendArmorDamageSlot@Mob@@QEAAXW4ArmorSlot@@@Z",
              Mob, enum ArmorSlot a0)
{
    logger.info("Mob::sendArmorDamageSlot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?sendArmorSlot@Mob@@QEAAXW4ArmorSlot@@@Z",
              Mob, enum ArmorSlot a0)
{
    logger.info("Mob::sendArmorSlot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setEatCounter@Mob@@QEAAXH@Z",
              Mob, int a0)
{
    logger.info("Mob::setEatCounter");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setEating@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setEating");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setFlightSpeed@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setFlightSpeed");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setFrictionModifier@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setFrictionModifier");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setIsLayingEgg@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setIsLayingEgg");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setIsPregnant@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setIsPregnant");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setJumpVelRedux@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setJumpVelRedux");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setJumping@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setJumping");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setMovementComponentCurrentSpeed@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setMovementComponentCurrentSpeed");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setNaturallySpawned@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setNaturallySpawned");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPassengerLockedBodyRot@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setPassengerLockedBodyRot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setPassengerRotLimit@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setPassengerRotLimit");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setRolling@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setRolling");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSpawnMethod@Mob@@QEAAXW4MobSpawnMethod@@@Z",
              Mob, enum MobSpawnMethod a0)
{
    logger.info("Mob::setSpawnMethod");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSpeedModifier@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setSpeedModifier");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setSurfaceMob@Mob@@QEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setSurfaceMob");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setTargetCaptain@Mob@@QEAAXUActorUniqueID@@@Z",
              Mob, struct ActorUniqueID a0)
{
    logger.info("Mob::setTargetCaptain");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setXxa@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setXxa");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setYHeadRot@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setYHeadRot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setYRotA@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setYRotA");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setYya@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setYya");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?setZza@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setZza");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?snapToYBodyRot@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::snapToYBodyRot");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?snapToYHeadRot@Mob@@QEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::snapToYHeadRot");
    original(this, std::forward<decltype(a0)>(a0));
}

// public.static : 24
THook(void, "?_aiStep@Mob@@SAXAEAUIMobMovementProxy@@@Z",
      struct IMobMovementProxy& a0)
{
    logger.info("Mob::_aiStep");
    original(std::forward<decltype(a0)>(a0));
}

THook(float, "?_calcMoveRelativeSpeed@Mob@@SAMAEAUIMobMovementProxy@@W4TravelType@@@Z",
      struct IMobMovementProxy& a0, enum TravelType a1)
{
    logger.info("Mob::_calcMoveRelativeSpeed");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(void, "?_travel@Mob@@SAXAEAUIMobMovementProxy@@MMM@Z",
      struct IMobMovementProxy& a0, float a1, float a2, float a3)
{
    logger.info("Mob::_travel");
    original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

THook(void, "?_updateMobTravel@Mob@@SAXAEAUIMobMovementProxy@@@Z",
      struct IMobMovementProxy& a0)
{
    logger.info("Mob::_updateMobTravel");
    original(std::forward<decltype(a0)>(a0));
}

THook(float, "?calculateJumpImpulse@Mob@@SAMAEBUIMobMovementProxy@@@Z",
      struct IMobMovementProxy const& a0)
{
    logger.info("Mob::calculateJumpImpulse");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(struct Mob::JumpPreventionResult&, "?getJumpPrevention@Mob@@SA?AUJumpPreventionResult@1@AEBUIMobMovementProxy@@@Z",
      struct Mob::JumpPreventionResult& ret, struct IMobMovementProxy const& a0)
{
    logger.info("Mob::getJumpPrevention");
    auto& rtn = original(ret, std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(enum TravelType, "?getTravelType@Mob@@SA?AW4TravelType@@AEAUIMobMovementProxy@@@Z",
      struct IMobMovementProxy& a0)
{
    logger.info("Mob::getTravelType");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?isImmobile@Mob@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Mob::isImmobile");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(bool, "?shouldApplyWaterGravity@Mob@@SA_NAEBUIActorMovementProxy@@@Z",
      struct IActorMovementProxy const& a0)
{
    logger.info("Mob::shouldApplyWaterGravity");
    auto rtn = original(std::forward<decltype(a0)>(a0));
    return rtn;
}

THook(class Mob*, "?tryGetFromEntity@Mob@@SAPEAV1@AEAVEntityContext@@_N@Z",
      class EntityContext& a0, bool a1)
{
    logger.info("Mob::tryGetFromEntity");
    auto rtn = original(std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

THook(float const&, "?PLAYER_SWIMMING_SURFACE_OFFSET@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::PLAYER_SWIMMING_SURFACE_OFFSET");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?GLIDING_FALL_RESET_DELTA@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::GLIDING_FALL_RESET_DELTA");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?SLOW_FALL_GRAVITY@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::SLOW_FALL_GRAVITY");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?DEFAULT_GRAVITY@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::DEFAULT_GRAVITY");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?LADDER_CLIMB_SPEED@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::LADDER_CLIMB_SPEED");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?ASCEND_BLOCK_BY_JUMPING_SPEED@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::ASCEND_BLOCK_BY_JUMPING_SPEED");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?ABSORPTION_FACTOR_MAX@Mob@@2HB",
      int const& ret)
{
    logger.info("Mob::ABSORPTION_FACTOR_MAX");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?ABSORPTION_FACTOR_MIN@Mob@@2HB",
      int const& ret)
{
    logger.info("Mob::ABSORPTION_FACTOR_MIN");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?TOTAL_ROLL_STEPS@Mob@@2HB",
      int const& ret)
{
    logger.info("Mob::TOTAL_ROLL_STEPS");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?REMOVE_PASSENGERS_DELAY@Mob@@2HB",
      int const& ret)
{
    logger.info("Mob::REMOVE_PASSENGERS_DELAY");
    auto& rtn = original(ret);
    return rtn;
}

THook(int const&, "?ARMOR_DAMAGE_DIVISOR@Mob@@2HB",
      int const& ret)
{
    logger.info("Mob::ARMOR_DAMAGE_DIVISOR");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?FRICTION_CONSTANT@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::FRICTION_CONSTANT");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?FRICTION_MODIFIER@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::FRICTION_MODIFIER");
    auto& rtn = original(ret);
    return rtn;
}

THook(float const&, "?FRICTION_CONSTANT_MODIFIED@Mob@@2MB",
      float const& ret)
{
    logger.info("Mob::FRICTION_CONSTANT_MODIFIED");
    auto& rtn = original(ret);
    return rtn;
}

// virtual : 356
TInstanceHook(bool, "?hasComponent@Mob@@UEBA_NAEBVHashedString@@@Z",
              Mob, class HashedString const& a0)
{
    logger.info("Mob::hasComponent");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?outOfWorld@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::outOfWorld");
    original(this);
}

TInstanceHook(void, "?reloadHardcoded@Mob@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              Mob, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Mob::reloadHardcoded");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?reloadHardcodedClient@Mob@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              Mob, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Mob::reloadHardcodedClient");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?initializeComponents@Mob@@UEAAXW4InitializationMethod@Actor@@AEBVVariantParameterList@@@Z",
              Mob, enum Actor::InitializationMethod a0, class VariantParameterList const& a1)
{
    logger.info("Mob::initializeComponents");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_doInitialMove@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::_doInitialMove");
    original(this);
}

TInstanceHook(float, "?getInterpolatedBodyRot@Mob@@UEBAMM@Z",
              Mob, float a0)
{
    logger.info("Mob::getInterpolatedBodyRot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getInterpolatedHeadRot@Mob@@UEBAMM@Z",
              Mob, float a0)
{
    logger.info("Mob::getInterpolatedHeadRot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getInterpolatedBodyYaw@Mob@@UEBAMM@Z",
              Mob, float a0)
{
    logger.info("Mob::getInterpolatedBodyYaw");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getYawSpeedInDegreesPerSecond@Mob@@UEBAMXZ",
              Mob)
{
    logger.info("Mob::getYawSpeedInDegreesPerSecond");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?blockedByShield@Mob@@UEAAXAEBVActorDamageSource@@AEAVActor@@@Z",
              Mob, class ActorDamageSource const& a0, class Actor& a1)
{
    logger.info("Mob::blockedByShield");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?teleportTo@Mob@@UEAAXAEBVVec3@@_NHH@Z",
              Mob, class Vec3 const& a0, bool a1, int a2, int a3)
{
    logger.info("Mob::teleportTo");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?normalTick@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::normalTick");
    original(this);
}

TInstanceHook(void, "?baseTick@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::baseTick");
    original(this);
}

TInstanceHook(void, "?vehicleTick@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::vehicleTick");
    original(this);
}

TInstanceHook(bool, "?startRiding@Mob@@UEAA_NAEAVActor@@@Z",
              Mob, class Actor& a0)
{
    logger.info("Mob::startRiding");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?addPassenger@Mob@@UEAAXAEAVActor@@@Z",
              Mob, class Actor& a0)
{
    logger.info("Mob::addPassenger");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isImmobile@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::isImmobile");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isPickable@Mob@@UEAA_NXZ",
              Mob)
{
    logger.info("Mob::isPickable");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSleeping@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::isSleeping");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setSleeping@Mob@@UEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setSleeping");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?isBlocking@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::isBlocking");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isAlive@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::isAlive");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isSurfaceMob@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::isSurfaceMob");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setTarget@Mob@@UEAAXPEAVActor@@@Z",
              Mob, class Actor* a0)
{
    logger.info("Mob::setTarget");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?attack@Mob@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
              Mob, class Actor& a0, enum ActorDamageCause const& a1)
{
    logger.info("Mob::attack");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?canPowerJump@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::canPowerJump");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?isJumping@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::isJumping");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum ActorDamageCause, "?getBlockDamageCause@Mob@@UEBA?AW4ActorDamageCause@@AEBVBlock@@@Z",
              Mob, class Block const& a0)
{
    logger.info("Mob::getBlockDamageCause");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?actuallyHurt@Mob@@UEAAXHAEBVActorDamageSource@@_N@Z",
              Mob, int a0, class ActorDamageSource const& a1, bool a2)
{
    logger.info("Mob::actuallyHurt");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?animateHurt@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::animateHurt");
    original(this);
}

TInstanceHook(bool, "?doFireHurt@Mob@@UEAA_NH@Z",
              Mob, int a0)
{
    logger.info("Mob::doFireHurt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(void, "?handleEntityEvent@Mob@@UEAAXW4ActorEvent@@H@Z",
              Mob, enum ActorEvent a0, int a1)
{
    logger.info("Mob::handleEntityEvent");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(enum ArmorMaterialType, "?getArmorMaterialTypeInSlot@Mob@@UEBA?AW4ArmorMaterialType@@W4ArmorSlot@@@Z",
              Mob, enum ArmorSlot a0)
{
    logger.info("Mob::getArmorMaterialTypeInSlot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(enum ArmorTextureType, "?getArmorMaterialTextureTypeInSlot@Mob@@UEBA?AW4ArmorTextureType@@W4ArmorSlot@@@Z",
              Mob, enum ArmorSlot a0)
{
    logger.info("Mob::getArmorMaterialTextureTypeInSlot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(float, "?getArmorColorInSlot@Mob@@UEBAMW4ArmorSlot@@H@Z",
              Mob, enum ArmorSlot a0, int a1)
{
    logger.info("Mob::getArmorColorInSlot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?setEquippedSlot@Mob@@UEAAXW4EquipmentSlot@@AEBVItemStack@@@Z",
              Mob, enum EquipmentSlot a0, class ItemStack const& a1)
{
    logger.info("Mob::setEquippedSlot");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(bool, "?canFreeze@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::canFreeze");
    auto rtn = original(this);
    return rtn;
}

#include <MC/ActorDamageSource.hpp>
TInstanceHook(void, "?causeFallDamage@Mob@@MEAAXMMVActorDamageSource@@@Z",
              Mob, float a0, float a1, class ActorDamageSource& a2)
{
    logger.info("Mob::causeFallDamage");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(bool, "?inCaravan@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::inCaravan");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?stopRiding@Mob@@UEAAX_N00@Z",
              Mob, bool a0, bool a1, bool a2)
{
    logger.info("Mob::stopRiding");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?buildDebugInfo@Mob@@UEBAXAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              Mob, std::string& a0)
{
    logger.info("Mob::buildDebugInfo");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?getDeathTime@Mob@@UEBAHXZ",
              Mob)
{
    logger.info("Mob::getDeathTime");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?swing@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::swing");
    original(this);
}

TInstanceHook(float, "?getYHeadRot@Mob@@UEBAMXZ",
              Mob)
{
    logger.info("Mob::getYHeadRot");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?kill@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::kill");
    original(this);
}

TInstanceHook(void, "?die@Mob@@UEAAXAEBVActorDamageSource@@@Z",
              Mob, class ActorDamageSource const& a0)
{
    logger.info("Mob::die");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?shouldDropDeathLoot@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::shouldDropDeathLoot");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?updateEntitySpecificMolangVariables@Mob@@MEAAXAEAVRenderParams@@@Z",
              Mob, class RenderParams& a0)
{
    logger.info("Mob::updateEntitySpecificMolangVariables");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?_hurt@Mob@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
              Mob, class ActorDamageSource const& a0, int a1, bool a2, bool a3)
{
    logger.info("Mob::_hurt");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(void, "?readAdditionalSaveData@Mob@@MEAAXAEBVCompoundTag@@AEAVDataLoadHelper@@@Z",
              Mob, class CompoundTag const& a0, class DataLoadHelper& a1)
{
    logger.info("Mob::readAdditionalSaveData");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?addAdditionalSaveData@Mob@@MEAAXAEAVCompoundTag@@@Z",
              Mob, class CompoundTag& a0)
{
    logger.info("Mob::addAdditionalSaveData");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?_playStepSound@Mob@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z",
              Mob, class BlockPos const& a0, class Block const& a1)
{
    logger.info("Mob::_playStepSound");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?_removePassenger@Mob@@MEAAXAEBUActorUniqueID@@_N11@Z",
              Mob, struct ActorUniqueID const& a0, bool a1, bool a2, bool a3)
{
    logger.info("Mob::_removePassenger");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?_onSizeUpdated@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::_onSizeUpdated");
    original(this);
}

TInstanceHook(void, "?knockback@Mob@@UEAAXPEAVActor@@HMMMMM@Z",
              Mob, class Actor* a0, int a1, float a2, float a3, float a4, float a5, float a6)
{
    logger.info("Mob::knockback");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3), std::forward<decltype(a4)>(a4), std::forward<decltype(a5)>(a5), std::forward<decltype(a6)>(a6));
}

TInstanceHook(void, "?setSprinting@Mob@@UEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setSprinting");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(enum LevelSoundEvent, "?getHurtSound@Mob@@UEAA?AW4LevelSoundEvent@@XZ",
              Mob)
{
    logger.info("Mob::getHurtSound");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(enum LevelSoundEvent, "?getDeathSound@Mob@@UEAA?AW4LevelSoundEvent@@XZ",
              Mob)
{
    logger.info("Mob::getDeathSound");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct TextureUVCoordinateSet const*, "?getItemInHandIcon@Mob@@UEAAPEBUTextureUVCoordinateSet@@AEBVItemStack@@H@Z",
              Mob, class ItemStack const& a0, int a1)
{
    logger.info("Mob::getItemInHandIcon");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(float, "?getSpeed@Mob@@UEBAMXZ",
              Mob)
{
    logger.info("Mob::getSpeed");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?setSpeed@Mob@@UEAAXM@Z",
              Mob, float a0)
{
    logger.info("Mob::setSpeed");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(float, "?getJumpPower@Mob@@UEBAMXZ",
              Mob)
{
    logger.info("Mob::getJumpPower");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?hurtEffects@Mob@@UEAA_NAEBVActorDamageSource@@H_N1@Z",
              Mob, class ActorDamageSource const& a0, int a1, bool a2, bool a3)
{
    logger.info("Mob::hurtEffects");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
    return rtn;
}

TInstanceHook(int, "?getMeleeWeaponDamageBonus@Mob@@UEAAHPEAV1@@Z",
              Mob, class Mob* a0)
{
    logger.info("Mob::getMeleeWeaponDamageBonus");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getMeleeKnockbackBonus@Mob@@UEAAHXZ",
              Mob)
{
    logger.info("Mob::getMeleeKnockbackBonus");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?travel@Mob@@UEAAXMMM@Z",
              Mob, float a0, float a1, float a2)
{
    logger.info("Mob::travel");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?travel@Mob@@UEBAXAEAUIMobMovementProxy@@MMM@Z",
              Mob, struct IMobMovementProxy& a0, float a1, float a2, float a3)
{
    logger.info("Mob::travel");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2), std::forward<decltype(a3)>(a3));
}

TInstanceHook(void, "?applyFinalFriction@Mob@@UEAAXM_N@Z",
              Mob, float a0, bool a1)
{
    logger.info("Mob::applyFinalFriction");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?aiStep@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::aiStep");
    original(this);
}

TInstanceHook(void, "?aiStep@Mob@@UEBAXAEAUIMobMovementProxy@@@Z",
              Mob, struct IMobMovementProxy& a0)
{
    logger.info("Mob::aiStep");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?pushActors@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::pushActors");
    original(this);
}

TInstanceHook(void, "?lookAt@Mob@@UEAAXPEAVActor@@MM@Z",
              Mob, class Actor* a0, float a1, float a2)
{
    logger.info("Mob::lookAt");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(bool, "?isLookingAtAnEntity@Mob@@UEAA_NXZ",
              Mob)
{
    logger.info("Mob::isLookingAtAnEntity");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?checkSpawnRules@Mob@@UEAA_N_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::checkSpawnRules");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(bool, "?checkSpawnObstruction@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::checkSpawnObstruction");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getAttackAnim@Mob@@UEAAMM@Z",
              Mob, float a0)
{
    logger.info("Mob::getAttackAnim");
    auto rtn = original(this, std::forward<decltype(a0)>(a0));
    return rtn;
}

TInstanceHook(int, "?getItemUseIntervalAxis@Mob@@UEBAHXZ",
              Mob)
{
    logger.info("Mob::getItemUseIntervalAxis");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(int, "?getTimeAlongSwing@Mob@@UEBAHXZ",
              Mob)
{
    logger.info("Mob::getTimeAlongSwing");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getMaxHeadXRot@Mob@@UEAAMXZ",
              Mob)
{
    logger.info("Mob::getMaxHeadXRot");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?doHurtTarget@Mob@@UEAA_NPEAVActor@@AEBW4ActorDamageCause@@@Z",
              Mob, class Actor* a0, enum ActorDamageCause const& a1)
{
    logger.info("Mob::doHurtTarget");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?leaveCaravan@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::leaveCaravan");
    original(this);
}

TInstanceHook(void, "?joinCaravan@Mob@@UEAAXPEAV1@@Z",
              Mob, class Mob* a0)
{
    logger.info("Mob::joinCaravan");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(bool, "?hasCaravanTail@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::hasCaravanTail");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(struct ActorUniqueID&, "?getCaravanHead@Mob@@UEBA?AUActorUniqueID@@XZ",
              Mob, struct ActorUniqueID& ret)
{
    logger.info("Mob::getCaravanHead");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getArmorValue@Mob@@UEAAHXZ",
              Mob)
{
    logger.info("Mob::getArmorValue");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(float, "?getArmorCoverPercentage@Mob@@UEBAMXZ",
              Mob)
{
    logger.info("Mob::getArmorCoverPercentage");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?hurtArmorSlots@Mob@@UEAAXAEBVActorDamageSource@@HAEBV?$bitset@$03@std@@@Z",
              Mob, class ActorDamageSource const& a0, int a1, class std::bitset<4> const& a2)
{
    logger.info("Mob::hurtArmorSlots");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1), std::forward<decltype(a2)>(a2));
}

TInstanceHook(void, "?setDamagedArmor@Mob@@UEAAXW4ArmorSlot@@AEBVItemStack@@@Z",
              Mob, enum ArmorSlot a0, class ItemStack const& a1)
{
    logger.info("Mob::setDamagedArmor");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?sendArmor@Mob@@UEAAXAEBV?$bitset@$03@std@@@Z",
              Mob, class std::bitset<4> const& a0)
{
    logger.info("Mob::sendArmor");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?containerChanged@Mob@@UEAAXH@Z",
              Mob, int a0)
{
    logger.info("Mob::containerChanged");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?updateEquipment@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::updateEquipment");
    original(this);
}

TInstanceHook(int, "?clearEquipment@Mob@@UEAAHXZ",
              Mob)
{
    logger.info("Mob::clearEquipment");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(std::vector<int>&, "?getAllArmorID@Mob@@UEBA?AV?$vector@HV?$allocator@H@std@@@std@@XZ",
              Mob, std::vector<int>& ret)
{
    logger.info("Mob::getAllArmorID");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(std::vector<class ItemStack const*>&, "?getAllHand@Mob@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ",
              Mob, std::vector<class ItemStack const*>& ret)
{
    logger.info("Mob::getAllHand");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(std::vector<class ItemStack const*>&, "?getAllEquipment@Mob@@UEBA?AV?$vector@PEBVItemStack@@V?$allocator@PEBVItemStack@@@std@@@std@@XZ",
              Mob, std::vector<class ItemStack const*>& ret)
{
    logger.info("Mob::getAllEquipment");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(int, "?getArmorTypeHash@Mob@@UEAAHXZ",
              Mob)
{
    logger.info("Mob::getArmorTypeHash");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?dropEquipmentOnDeath@Mob@@UEAAXAEBVActorDamageSource@@H@Z",
              Mob, class ActorDamageSource const& a0, int a1)
{
    logger.info("Mob::dropEquipmentOnDeath");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

TInstanceHook(void, "?dropEquipmentOnDeath@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::dropEquipmentOnDeath");
    original(this);
}

TInstanceHook(void, "?clearVanishEnchantedItemsOnDeath@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::clearVanishEnchantedItemsOnDeath");
    original(this);
}

TInstanceHook(void, "?sendInventory@Mob@@UEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::sendInventory");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(int, "?getDamageAfterMagicAbsorb@Mob@@UEAAHAEBVActorDamageSource@@H@Z",
              Mob, class ActorDamageSource const& a0, int a1)
{
    logger.info("Mob::getDamageAfterMagicAbsorb");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(bool, "?createAIGoals@Mob@@UEAA_NXZ",
              Mob)
{
    logger.info("Mob::createAIGoals");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(bool, "?setItemSlot@Mob@@UEAA_NW4EquipmentSlot@@AEBVItemStack@@@Z",
              Mob, enum EquipmentSlot a0, class ItemStack const& a1)
{
    logger.info("Mob::setItemSlot");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?setTransitioningSitting@Mob@@UEAAX_N@Z",
              Mob, bool a0)
{
    logger.info("Mob::setTransitioningSitting");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?attackAnimation@Mob@@UEAAXPEAVActor@@M@Z",
              Mob, class Actor* a0, float a1)
{
    logger.info("Mob::attackAnimation");
    original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
}

// there are 6 functions with the same rva

// ?getCooldownTime@EnderpearlItem@@UEBAHXZ
// ?getExperienceDrop@SculkCatalystBlock@@UEBAHAEAVRandom@@@Z
// ?getExperienceDrop@SculkShriekerBlock@@UEBAHAEAVRandom@@@Z
// ?getId@PassengerJumpPacket@@UEBA?AW4MinecraftPacketIds@@XZ
// ?getRandomEatingEnd@SnackGoal@@MEBAHXZ
// ?getTickDelay@BasePressurePlateBlock@@UEBAHXZ

// TInstanceHook(int, "?getAttackTime@Mob@@UEAAHXZ",
//     Mob){
//     logger.info("Mob::getAttackTime");
//     auto rtn = original(this);
//     return rtn;
// }

TInstanceHook(bool, "?canExistWhenDisallowMob@Mob@@UEBA_NXZ",
              Mob)
{
    logger.info("Mob::canExistWhenDisallowMob");
    auto rtn = original(this);
    return rtn;
}

TInstanceHook(void, "?ascendLadder@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::ascendLadder");
    original(this);
}

TInstanceHook(void, "?ascendBlockByJumping@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::ascendBlockByJumping");
    original(this);
}

TInstanceHook(void, "?descendBlockByCrouching@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::descendBlockByCrouching");
    original(this);
}

TInstanceHook(void, "?dropContainer@Mob@@UEAAXXZ",
              Mob)
{
    logger.info("Mob::dropContainer");
    original(this);
}

#include <MC/BodyControl.hpp>
TInstanceHook(std::unique_ptr<class BodyControl>&, "?initBodyControl@Mob@@MEAA?AV?$unique_ptr@VBodyControl@@U?$default_delete@VBodyControl@@@std@@@std@@XZ",
              Mob, std::unique_ptr<class BodyControl>& ret)
{
    logger.info("Mob::initBodyControl");
    auto& rtn = original(this, ret);
    return rtn;
}

TInstanceHook(void, "?jumpFromGround@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::jumpFromGround");
    original(this);
}

TInstanceHook(void, "?jumpFromGround@Mob@@MEBAXAEAUIMobMovementProxy@@@Z",
              Mob, struct IMobMovementProxy& a0)
{
    logger.info("Mob::jumpFromGround");
    original(this, std::forward<decltype(a0)>(a0));
}

TInstanceHook(void, "?updateAi@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::updateAi");
    original(this);
}

TInstanceHook(void, "?newServerAiStep@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::newServerAiStep");
    original(this);
}

TInstanceHook(int, "?getDamageAfterEnchantReduction@Mob@@MEAAHAEBVActorDamageSource@@H@Z",
              Mob, class ActorDamageSource const& a0, int a1)
{
    logger.info("Mob::getDamageAfterEnchantReduction");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(int, "?getDamageAfterArmorAbsorb@Mob@@MEAAHAEBVActorDamageSource@@H@Z",
              Mob, class ActorDamageSource const& a0, int a1)
{
    logger.info("Mob::getDamageAfterArmorAbsorb");
    auto rtn = original(this, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

TInstanceHook(void, "?dropBags@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::dropBags");
    original(this);
}

TInstanceHook(void, "?tickDeath@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::tickDeath");
    original(this);
}

TInstanceHook(void, "?updateGliding@Mob@@MEAAXXZ",
              Mob)
{
    logger.info("Mob::updateGliding");
    original(this);
}

TInstanceHook(class AABB&, "?_getAdjustedAABBForSpawnCheck@Mob@@MEBA?AVAABB@@AEBV2@AEBVVec3@@@Z",
              Mob, class AABB& ret, class AABB const& a0, class Vec3 const& a1)
{
    logger.info("Mob::_getAdjustedAABBForSpawnCheck");
    auto& rtn = original(this, ret, std::forward<decltype(a0)>(a0), std::forward<decltype(a1)>(a1));
    return rtn;
}

// virtual.unordered : 9
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

// TInstanceHook(bool, "?canBeControlledByPassenger@Mob@@UEAA_NXZ",
//     Mob){
//     logger.info("Mob::canBeControlledByPassenger");
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

// TInstanceHook(void, "?ate@Mob@@UEAAXXZ",
//     Mob){
//     logger.info("Mob::ate");
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

// TInstanceHook(void, "?_serverAiMobStep@Mob@@MEAAXXZ",
//     Mob){
//     logger.info("Mob::_serverAiMobStep");
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

// TInstanceHook(void, "?renderDebugServerState@Mob@@UEAAXAEBVOptions@@@Z",
//     Mob, class Options const& a0){
//     logger.info("Mob::renderDebugServerState");
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

// TInstanceHook(bool, "?isShootable@Mob@@UEAA_NXZ",
//     Mob){
//     logger.info("Mob::isShootable");
//     auto rtn = original(this);
//     return rtn;
// }

// there are 1048 functions with the same rva

// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_22965a617e6ab392d6b1f1a7a48586ba>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
// ?_Do_call@?$_Func_impl_no_alloc@V<lambda_bac109946998141606a5d33732ab2465>@@_NAEBVDefinitionInstanceGroup@@@std@@EEAA_NAEBVDefinitionInstanceGroup@@@Z
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
// ?_validate@?$JsonSchemaTypedNode@UArbitraryBiomeComponent@@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UBiomeMetadata@@@JsonUtil@@UBiomeMetadata@@@JsonUtil@@UBiomeMetadata@@@JsonUtil@@U1@@JsonUtil@@UEBA_NAEAV?$JsonParseState@V?$JsonParseState@V?$JsonParseState@V?$JsonParseState@VEmptyClass@JsonUtil@@UBiomeMetadata@@@JsonUtil@@UBiomeMetadata@@@JsonUtil@@UBiomeMetadata@@@JsonUtil@@UArbitraryBiomeComponent@@@2@_N@Z

// TInstanceHook(bool, "?_allowAscendingScaffolding@Mob@@MEBA_NXZ",
//     Mob){
//     logger.info("Mob::_allowAscendingScaffolding");
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

// TInstanceHook(bool, "?useNewAi@Mob@@UEBA_NXZ",
//     Mob){
//     logger.info("Mob::useNewAi");
//     auto rtn = original(this);
//     return rtn;
// }

// there are 44 functions with the same rva

// ?getAmount@Amplifier@@UEBAMHM@Z
// ?getBaseAmbientValue@DimensionBrightnessRamp@@UEBAMXZ
// ?getCameraOffset@Actor@@UEBAMXZ
// ?getDamageBonus@Enchant@@UEBAMHAEBVActor@@@Z
// ?getDefaultScreenPositionX@AppPlatform@@UEBAMXZ
// ?getDefaultScreenPositionY@AppPlatform@@UEBAMXZ
// ?getDeletionDelayTimeSeconds@Actor@@UEBAMXZ
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

// TInstanceHook(float, "?_getWalkTargetValue@Mob@@UEAAMAEBVBlockPos@@@Z",
//     Mob, class BlockPos const& a0){
//     logger.info("Mob::_getWalkTargetValue");
//     auto rtn = original(this, std::forward<decltype(a0)>(a0));
//     return rtn;
// }

TInstanceHook(class Mob&, "??1Mob@@UEAA@XZ",
              Mob)
{
    logger.info("Mob::~Mob");
    auto& rtn = original(this);
    return rtn;
}

// vtbl_entry : 1

#endif // HOOK_CLASS_Mob

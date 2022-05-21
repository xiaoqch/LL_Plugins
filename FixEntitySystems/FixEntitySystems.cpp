#include "pch.h"
#include <MC/SimulatedPlayer.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <Utils/DbgHelper.h>
#include <filesystem>
#include <MC/Level.hpp>

#define ADDR_HOOK
//#define BATCH_HOOK

#ifdef DEBUG
template <typename T>
void logActorInfo(T* actor, std::string const& func);

#include <MC/CommandUtils.hpp>
#include <MC/ActorClassTree.hpp>
namespace
{
constexpr int maxDistance = 10;
constexpr float ha = 75.0f;
constexpr float va = 45.0f;
} // namespace
TInstanceHook(void, "?attack@Player@@UEAA_NAEAVActor@@AEBW4ActorDamageCause@@@Z",
              Player, Actor* actor, ActorDamageCause& cause)
{
#ifdef DEBUG
    logger.info("Player::startSpinAttack - {}", getNameTag());
#endif // DEBUG

    auto dimid = getDimensionId();
    auto playerRot = getRotation();
    auto playerPos = getPosition();
    auto viewVector = getViewVector(1.0f);
    for (auto actor : Global<Level>->getRuntimeActorList())
    {
        if (actor == this)
            continue;
        if (!ActorClassTree::isMob(actor->getEntityTypeId()))
            continue;
        if (dimid != actor->getDimensionId())
            continue;
        if (distanceTo(*actor) > maxDistance)
            continue;
        auto posVector = actor->getPosition() - playerPos;
        auto posRot = Vec3::rotationFromDirection(posVector);
#ifdef DEBUG
        LOG_VAR(playerPos.toString());
        LOG_VAR(playerRot.toString());
        LOG_VAR(posVector.toString());
        LOG_VAR(posRot.toString());
#endif // DEBUG

        if (std::fmodf(abs(posRot.x - playerRot.x), 360) < ha && std::fmodf(abs(posRot.y - playerRot.y), 360) < va)
        {
#ifdef DEBUG
            logger.warn("Player::attack - {} -> {}", getNameTag(), CommandUtils::getActorName(*actor));
#endif // DEBUG
            original(this, actor, cause);
        }
    }
}
#endif // DEBUG

void entry()
{
    std::filesystem::create_directories(PLUGIN_DIR);
#ifdef DEBUG
    //logActorInfo((Actor*)114514, "Test");
    logger.error("Actor::`vftable' Rva: {}", (uintptr_t)dlsym("??_7Actor@@6B@") - (uintptr_t)GetModuleHandle(NULL));
    PrintCurrentStackTraceback(&logger);
#endif // DEBUG
}

#pragma region ForEachSystem

#define ForEachSystem(Func)                  \
    Func(ActorDataSyncSystem);               \
    Func(ActorLegacyTickSystem);             \
    Func(ActorLimitedLifetimeTickSystem);    \
    Func(ActorMotionSyncSystem);             \
    Func(ActorMovementTickFilterSystem);     \
    Func(ActorUpdatePreviousPositionSystem); \
    Func(AgeableSystem);                     \
    Func(AgentCommandSystem);                \
    Func(AgentMoveCommandSystem);            \
    Func(AngrySystem);                       \
    Func(AreaAttackSystem);                  \
    Func(AttackCooldownSystem);              \
    Func(BalloonSystem);                     \
    Func(BehaviorSystem);                    \
    Func(BlockBreakSensorSystem);            \
    Func(BlockClimberSystem);                \
    Func(BlockPosTrackerSystem);             \
    Func(BodyControlSystem);                 \
    Func(BoostableSystem);                   \
    Func(BossSystem);                        \
    Func(BreakBlocksSystem);                 \
    Func(BreakDoorAnnotationSystem);         \
    Func(BreathableSystem);                  \
    Func(BreedableSystem);                   \
    Func(BribeableSystem);                   \
    Func(BuoyancySystem);                    \
    Func(BurnsInDaylightSystem);             \
    Func(CelebrateHuntSystem);               \
    Func(CombatRegenerationSystem);          \
    Func(CommandBlockSystem);                \
    Func(DamageOverTimeSystem);              \
    Func(DanceSystem);                       \
    Func(DespawnSystem);                     \
    Func(DispatcherUpdateSystem);            \
    Func(DryingOutTimerSystem);              \
    Func(DwellerSystem);                     \
    Func(EntityEnterVolumeSystem);           \
    Func(EntityExitVolumeSystem);            \
    Func(EntitySensorSystem);                \
    Func(EnvironmentSensorSystem);           \
    Func(ExplodeSystem);                     \
    Func(FlockingSystem);                    \
    Func(FreezingSystem);                    \
    Func(GlobalActorLegacyTickSystem);       \
    Func(GoalSelectorSystem);                \
    Func(GroupSizeSystem);                   \
    Func(GrowCropSystem);                    \
    Func(HomeSystem);                        \
    Func(HopperSystem);                      \
    Func(HurtOnConditionSystem);             \
    Func(InsideBlockNotifierSystem);         \
    Func(InsomniaSystem);                    \
    Func(InstantDespawnSystem);              \
    Func(InteractSystem);                    \
    Func(JumpControlSystem);                 \
    Func(LeashableSystem);                   \
    Func(LevelChunkTickingSystem);           \
    Func(LookAtSystem);                      \
    Func(LookControlSystem);                 \
    Func(MobEffectSystem);                   \
    Func(MountTamingSystem);                 \
    Func(MoveControlSystem);                 \
    Func(MovementECSFeatureToggleSystem);    \
    Func(NavigationSystem);                  \
    Func(NpcSystem);                         \
    Func(OnFireServerSystem);                \
    Func(OpenDoorAnnotationSystem);          \
    Func(OutOfWorldSystem);                  \
    Func(PeekSystem);                        \
    Func(PlayerMovementRateSystem);          \
    Func(ProjectileSystem);                  \
    Func(RaidBossSystem);                    \
    Func(RailActivatorSystem);               \
    Func(SaveSurroundingChunksSystem);       \
    Func(ScaleByAgeSystem);                  \
    Func(SchedulerSystem);                   \
    Func(SensingSystem);                     \
    Func(SpawnActorSystem);                  \
    Func(TargetNearbySystem);                \
    Func(TeleportSystem);                    \
    Func(TimerSystem);                       \
    Func(TradeableSystem);                   \
    Func(TrailSystem);                       \
    Func(TransformationSystem);              \
    Func(WardenSpawnTrackerSystem);

#pragma endregion


#include <MC/StructureTemplate.hpp>
namespace
{
bool kill = true;
}
template <typename T>
void logActorInfo(T* actor, std::string const& func)
{
    bool ignoreKill = false;
    if (actor == nullptr)
    {
        return logger.error("Detected actor nullptr in {}", func);
    }
    logger.error("Detected region nullptr in {}", func);
    logger.error("Type: {}", typeid(T).name());
    try
    {
        logger.error("vftable RVA: {}", dAccess<uintptr_t, 0>(actor) - (uintptr_t)GetModuleHandle(NULL));
    }
    catch (const std::exception&)
    {
        logger.error("Error in get actor vftable RVA");
        logger.error("Actor pointer: {:X}", (uintptr_t)actor);
    }
    try
    {
        std::string debugInfo;
        actor->buildDebugInfo(debugInfo);
        logger.error("DebugInfo: \n{}", debugInfo);
        logger.error("Pos: {}, DimId: {}",
                     actor->getPosition().toString(), (int)actor->getDimensionId());
        auto bpos = ((Actor*)actor)->getPosition().toBlockPos();
        auto block = Level::getBlockEx(bpos, actor->getDimensionId());
        if (block)
            logger.error("Block: {} - {}", bpos.toString(), block->toDebugString());
        else
            logger.error("Block: {} - nullptr", bpos.toString());
        logger.error("isRemoved: {}", actor->isRemoved());
        logger.error("isAlive: {}", actor->isAlive());
        logger.error("isGlobal: {}", actor->isGlobal());
        logger.error("isTickingEntity: {}", actor->isTickingEntity());
    }
    catch (...)
    {
        logger.error("Error in actor->buildDebugInfo()");
    }
    // NBT
    try
    {
        auto nbtFilePath = fmt::format("{}Actor-{:%Y%m%d-%H%M%S}.snbt", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
        logger.error("NBT: in {}", nbtFilePath);
        WriteAllFile(nbtFilePath, actor->getNbt()->toSNBT(4), true);
    }
    catch (...)
    {
        ignoreKill = true;
        logger.error("Error in actor->getNbt()->toSNBT()");
    }
    // Structure
    try
    {
        auto nbtFilePath = fmt::format("{}Structure-{:%Y%m%d-%H%M%S}.snbt", PLUGIN_DIR, fmt::localtime(_time64(nullptr)));
        Vec3 const& range = {16, 16, 16};
        auto structure = StructureTemplate::fromWorld("EmptyRegionStructure", ((Actor*)actor)->getDimensionId(), ((Actor*)actor)->getBlockPos() - range, ((Actor*)actor)->getBlockPos() + range, false, false);
        logger.error("Structure: in {}", nbtFilePath);
        WriteAllFile(nbtFilePath, structure.save()->toSNBT(4), true);
    }
    catch (...)
    {
        logger.error("Error in Save Structure");
    }
    try
    {
        for (auto& player : Level::getAllPlayers())
        {
            logger.error("Player: {},\t Pos: {},\t DimId: {}",
                         player->getNameTag(), player->getPosition().toString(), (int)player->getDimensionId());
            auto& region = player->getRegion();
            logger.error("Block: {} - {},\t {} - {}", player->getBlockPos().toString(),
                         region.getBlock(player->getBlockPos()).toDebugString(),
                         player->getBlockPosCurrentlyStandingOn(nullptr).toString(),
                         region.getBlock(player->getBlockPosCurrentlyStandingOn(nullptr)).toDebugString());
        }
    }
    catch (...)
    {
        logger.error("Error in log players message");
    }
    logger.error("StackTraceback:");
    PrintCurrentStackTraceback(&logger);
    logger.info << Logger::endl;
    if (kill && !ignoreKill)
    {
        try
        {
            actor->kill();
        }
        catch (...)
        {
            logger.error("Error in kill actor");
        }
    }
    return;
}

//BreakDoorAnnotationComponent::_shouldBreakDoor
TClasslessInstanceHook(bool, "?_shouldBreakDoor@BreakDoorAnnotationComponent@@AEAA_NAEAVMob@@@Z",
                       Mob* mob)
{
    if (mob == nullptr || &mob->getRegion() == nullptr)
    {
        logActorInfo(mob, "BreakDoorAnnotationComponent::_shouldBreakDoor");
        return false;
    }
    return original(this, mob);
}

//Actor::fetchNearbyActorsSorted
TInstanceHook(class std::vector<struct DistanceSortedActor>&, "11111?fetchNearbyActorsSorted@Actor@@QEAA?AV?$vector@UDistanceSortedActor@@V?$allocator@UDistanceSortedActor@@@std@@@std@@AEBVVec3@@W4ActorType@@@Z",
              Actor, class std::vector<struct DistanceSortedActor>& res, class Vec3 const& pos, enum ActorType type)
{
    if (this == nullptr || !this->isRegionValid())
    {
        logActorInfo(this, fmt::format("Actor::fetchNearbyActorsSorted(pos: {}, type: {})", pos.toString(), (int)type));
        return res;
    }
    return original(this, res, pos, type);
}

//Actor::isInWaterOrRain
TInstanceHook(bool, "?isInWaterOrRain@Actor@@QEBA_NXZ",
              Actor)
{
    if (this == nullptr || &getRegion() == nullptr)
    {
        logActorInfo(this, "Actor::isInWaterOrRain");
        return false;
    }
    return original(this);
}

//Actor::getBrightness
TInstanceHook(float, "?getBrightness@Actor@@UEBAMM@Z",
              Actor, float a2)
{
    if (this == nullptr || &getRegion() == nullptr)
    {
        logActorInfo(this, "Actor::getBrightness");
        return 0;
    }
    return original(this, a2);
}

//SensingComponent::canSee
TClasslessInstanceHook(bool, "?canSee@SensingComponent@@QEAA_NAEAVMob@@AEBVActor@@@Z",
                       class Mob& a2, class Actor const& a3)
{
    if (&a2 == nullptr || &a2.getRegion() == nullptr)
    {
        logActorInfo(&a2, "SensingComponent::canSee");
        return false;
    }
    return original(this, a2, a3);
}

#ifdef BATCH_HOOK

template <typename Sys>
void logSystemCrash(std::string const& systemName)
{
    logger.error("Error in {}::tick", systemName);
}

#define HookSystemTick(System)                                    \
    THook(void, "?tick@" #System "@@UEAAXAEAVEntityRegistry@@@Z", \
          class System& system, class EntityRegistry& registry)   \
    {                                                             \
        try                                                       \
        {                                                         \
            original(system, registry);                           \
        }                                                         \
        catch (const std::exception&)                             \
        {                                                         \
            logSystemCrash<System>(#System);                      \
            logger.error("StackTraceback:");                      \
            PrintCurrentStackTraceback(&logger);                  \
            logger.info << Logger::endl;                          \
        }                                                         \
    }

ForEachSystem(HookSystemTick);

#endif // BATCH_HOOK

#ifdef ADDR_HOOK

void const* HOOK_ADDR = ([]() {
    return (void*)((uintptr_t)GetModuleHandle(NULL) + 0x7F11A0);
})();
constexpr auto HOOK_NAME = "std___Func_impl_no_alloc__lambda_402054a1cc8ac232f46e648b3b6daed6__void_ITickingSystem______Do_call";

class ITickingSystem
{
public:
    /*0*/ virtual ~ITickingSystem() = 0;
    /*1*/ virtual void registerEvents(class entt::dispatcher&);
    /*2*/ virtual void tick(class EntityRegistry&);
};
template <>
struct THookTemplate<do_hash(HOOK_NAME), do_hash2(HOOK_NAME)>
{
    typedef void (*original_type)(void* a1, ITickingSystem* a2);
    static original_type& _original()
    {
        static original_type storage;
        return storage;
    }
    template <typename... Params>
    static void original(Params&&... params)
    {
        return _original()(std::forward<Params>(params)...);
    }
    static void _hook(void* a1, ITickingSystem* a2);
};
template <>
static THookRegister THookRegisterTemplate<do_hash(HOOK_NAME), do_hash2(HOOK_NAME)>{
    const_cast<void*>(HOOK_ADDR), &THookTemplate<do_hash(HOOK_NAME), do_hash2(HOOK_NAME)>::_hook,
    (void**)&THookTemplate<do_hash(HOOK_NAME), do_hash2(HOOK_NAME)>::_original()};

class EntityRegistryBase
{
public:
    void* mEntityId;
    int unk8 = -1;
    std::string const* unk16;
    unsigned char unk24 = 0;
    int index;

public:
    MCAPI EntityRegistryBase(class entt::basic_registry<class EntityId>&);
    MCAPI bool isValidEntity(class EntityContextBase const&) const;
    MCAPI ~EntityRegistryBase();

protected:
    MCAPI void _assertValidRegistry(class EntityContextBase const&) const;
    MCAPI static struct std::atomic<unsigned int> mRegistryCount;
};
class EntityRegistry : public EntityRegistryBase
{
protected:
    MCAPI EntityRegistry();
};

#include <MC/EntitySystems.hpp>

inline std::string tryGetSystemName(void* vtbl_ptr)
{
#define ReturnIfSameVtbl(System)      \
    if (vtbl_ptr == dlsym_static("??_7" #System "@@6BITickingSystem@@@") || vtbl_ptr == dlsym_static("??_7" #System "@@6B@")) \
        return #System;
    ForEachSystem(ReturnIfSameVtbl);
    auto rva = (uintptr_t)vtbl_ptr - (uintptr_t)GetModuleHandle(NULL);
    return fmt::format("UnknownSystem(vftable rva: {}, ida addr: 0x{:X}", rva, rva + 0x14000000);
#undef ReturnIfSameVtbl
}

void logTickingInfo(void* a1, ITickingSystem* a2) 
{
    try
    {
        logger.error("vftable RVA: {}", dAccess<uintptr_t, 0>(a2) - (uintptr_t)GetModuleHandle(NULL));
        logger.error("SystemName: {}", tryGetSystemName(dAccess<void*, 0>(a2)));
    }
    catch (const std::exception&)
    {
    }
};
void THookTemplate<do_hash(HOOK_NAME), do_hash2(HOOK_NAME)>::_hook(void* a1, ITickingSystem* a2)
{

#ifdef DEBUG
    //logger.warn("tick {}", tryGetSystemName(dAccess<void*, 0>(a2)));
    auto& reg = dAccess<EntityRegistry>(a1, 8);
    auto& sys = *dAccess<EntitySystems*>(a1, 16);
    auto& unk = *(voids<>*)&sys;
    auto& unka1 = **(voids<>**)&a1;
    auto& unka2 = **(voids<>**)&a2;
    auto& unkreg = *(voids<>*)&reg;
    unk.filler;
    unka1.filler;
    unka2.filler;
    unkreg.filler;

#endif // DEBUG
    try
    {
        original(a1, a2);
    }
    catch (...)
    {
        logger.error("Error in DefaultEntitySystemsCollection::foreachTickingSystem");
        logger.error("StackTraceback:");
        PrintCurrentStackTraceback(&logger);
        logger.info << Logger::endl;
        logTickingInfo(a1, a2);
    }
}
#endif // ADDR_HOOK
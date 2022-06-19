#include "pch.h"
#include "TestAI.h"
#include <RegCommandAPI.h>
#include <MC/CommandUtils.hpp>
#include <MC/Level.hpp>
#ifdef ENABLE_TEST_AI

Logger aiLogger("AI");

DECLSPEC_ALIGN(8) struct GoalDefinition {
    char filler[4588];

public:
    MCAPI GoalDefinition(struct GoalDefinition&&);
    MCAPI GoalDefinition(struct GoalDefinition const&);
    MCAPI GoalDefinition();
    MCAPI enum POIType _getPOITypeFromString(std::string);
    MCAPI struct GoalDefinition& operator=(struct GoalDefinition&&);
    MCAPI struct GoalDefinition& operator=(struct GoalDefinition const&);
    MCAPI bool parse(struct ConstDeserializeDataParams const&, int);
    MCAPI ~GoalDefinition();
};

TInstanceHook(void, "?aiStep@SimulatedPlayer@@UEAAXXZ",
    SimulatedPlayer ) {
    //aiLogger.warn("SimulatedPlayer::aiStep - {}", CommandUtils::getActorName(*this));
    original(this);
}

TInstanceHook(void, "?createAI@Mob@@QEAAXV?$vector@UGoalDefinition@@V?$allocator@UGoalDefinition@@@std@@@std@@@Z",
    Mob, std::vector<struct GoalDefinition>& goals) {
    aiLogger.warn("Mob::createAI - {} - goals.size(): {}", CommandUtils::getActorName(*this), goals.size());
    original(this, goals);
}

TInstanceHook(bool, "?createAIGoals@Mob@@UEAA_NXZ",
    Mob) {
    auto rtn = original(this);
    aiLogger.warn("Mob({})::createAIGoals -> {}", CommandUtils::getActorName(*this), rtn);
    return rtn;
}

TInstanceHook(void, "?updateAi@Mob@@MEAAXXZ",
    Mob) {
    aiLogger.warn("Mob::updateAi - {}", CommandUtils::getActorName(*this));
    original(this);
}

//TInstanceHook(void, "?aiStep@Mob@@UEAAXXZ",
//    Mob) {
//    aiLogger.warn("Mob::aiStep - {}", CommandUtils::getActorName(*this));
//    original(this);
//}

//TInstanceHook(void, "?aiStep@Mob@@UEBAXAEAUIMobMovementProxy@@@Z",
//    Mob, struct IMobMovementProxy& proxy) {
//    aiLogger.warn("Mob::aiStep(IMobMovementProxy) - {}", CommandUtils::getActorName(*this));
//    original(this, proxy);
//}

//TInstanceHook(void, "?newServerAiStep@Mob@@MEAAXXZ",
//    Mob) {
//    aiLogger.warn("Mob::newServerAiStep - {}", CommandUtils::getActorName(*this));
//    original(this);
//}

THook(void, "?onStartDestroyBlock@ServerPlayerBlockUseHandler@@YAXAEAVServerPlayer@@AEBVBlockPos@@H@Z",
    class ServerPlayer& sp, class BlockPos const& bpos, int face) {
    original(sp, bpos, face);
    for (auto& pl : Level::getAllPlayers()) {
        if (pl->isSimulatedPlayer()) {
            auto fp = (SimulatedPlayer*)pl;
            auto res = fp->simulateNavigateToLocation(bpos.relative(face, 1).center(), 1.0f);
            LOG_VAR(res.mIsFullPath);
            for (auto& node : res.mPath) {
                LOG_VAR(node.toString());
            }
        }
    }
}

bool testAddGoal(Actor* actor, Mob* mob);
#include <MC/Container.hpp>
#include <MC/ItemStack.hpp>
#include <MC/ActorDamageSource.hpp>
#include <ScheduleAPI.h>
TInstanceHook(bool, "?_hurt@Player@@MEAA_NAEBVActorDamageSource@@H_N1@Z",
    Player, class ActorDamageSource const& ads, int damage, bool a4, bool a5) {
    auto rtn = original(this, ads, damage, a4, a5);
    if (isSimulatedPlayer()) {
        auto fp = (SimulatedPlayer*)this;
        auto& inv = fp->getInventory();
        auto maxDagame = 0;
        for (auto slot = 0; slot < fp->getInventorySize(); ++slot) {
            auto& item = inv.getItem(slot);
            auto attackDamage = item.getAttackDamage();
            if (attackDamage > maxDagame) {
                maxDagame = attackDamage;
                fp->setSelectedSlot(slot);
            }
        }
        auto& sourceActor = *Global<Level>->fetchEntity(ads.getDamagingEntityUniqueID(), true);
        if (!&sourceActor)
            return rtn;
        fp->simulateLookAt(sourceActor);
        Schedule::delay([fp]() {
            if (Player::isValid(fp)) {
                auto target = fp->getLastHurtByMob();
                if (!target)
                    return;
                if (fp->canAttack(target, true)) {
                    fp->simulateAttack();
                }
                else {
                    auto res = fp->simulateNavigateToEntity(*target, 1.0f);
                    LOG_VAR(res.mIsFullPath);
                    for (auto& node : res.mPath) {
                        LOG_VAR(node.toString());
                    }
                }
            }
            }, 10);
    }
    else {
        auto& sourceActor = *Global<Level>->fetchEntity(ads.getDamagingEntityUniqueID(), true);
        if (!&sourceActor)
            return rtn;
        testAddGoal(this, (Mob*)&sourceActor);
        return rtn;
    }
    return rtn;
}

// ========== Goal ==========


#define tryGetComponent(T, actor)\
((class T*(*)(Actor*))dlsym("??$tryGetComponent@V"#T"@@@Actor@@QEAAPEAV"#T"@@XZ"))(actor)

//template <class T>
//inline T* tryGetComponent2(Actor* actor) {
//    auto typeName = "";
//    auto symbol = fmt::format("??$tryGetComponent@V{}@@@Actor@@QEAAPEAV{}@@XZ", typeName, typeName);
//    return ((class T* (*)(Actor*))dlsym(symbol.c_str()))(actor);
//}
#define _getContext(actor) dAccess<EntityContextBase*>(actor, 8)
// Error!
#define getOrAddComponent(T, actor)\
(_getContext(actor)->isValid()?((class T*(*)(EntityContextBase*))dlsym("??$getOrAddComponent@V"#T"@@@EntityContextBase@@QEAAAEAV"#T"@@XZ"))(_getContext(actor)):nullptr)

// Actor::tryGetComponent<GoalSelectorComponent>(__int64 a1)
// GoalSelectorComponent::addGoal(__int64 a1, int a2, Goal **a3)
#include <MC/GoalSelectorComponent.hpp>
//#include <MC/Goal.hpp>
DECLSPEC_ALIGN(8)
class Goal
{
    // Goal - size = 56
    char filler8[48];

public:
    /*0*/ virtual ~Goal();
    /*1*/ virtual bool canUse() = 0;
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual bool canBeInterrupted();
    /*4*/ virtual void start() = 0;
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string&) const;
    /*8*/ virtual bool isTargetGoal() const;
};
//#include <MC/LookAtActorGoal.hpp>
class LookAtActorGoal : public Goal {
    // LookAtActorGoal - size = 200
    char filler56[200 - 56];

public:
    /*0*/ virtual ~LookAtActorGoal();
    /*1*/ virtual bool canUse();
    /*2*/ virtual bool canContinueToUse();
    /*3*/ virtual bool canBeInterrupted();
    /*4*/ virtual void start();
    /*5*/ virtual void stop();
    /*6*/ virtual void tick();
    /*7*/ virtual void appendDebugInfo(std::string&) const;
    /*8*/ virtual bool isTargetGoal() const;
    MCAPI LookAtActorGoal(class Mob&, float lookDistance, float probability, int minLookTime, int maxLookTime, int angleOfViewX, int angleOfViewY);
};
static_assert(sizeof(LookAtActorGoal) == 200);
// ========== Test Add Goal ==========
bool testAddGoal(Actor* actor, Mob* mob) {
    //auto ctx = dAccess<EntityContextBase*>(actor, 8);
    //if (!ctx->isValid()) {
    //    aiLogger.error("Error to get EntityContextBase from {}", CommandUtils::getActorName(*actor));
    //    return false;
    //}
    //auto comp = getOrAddComponent(GoalSelectorComponent, actor);

    auto comp = tryGetComponent(GoalSelectorComponent, actor);
    //logger.warn("{}", (void*)tryGetComponent(UserEntityIdentifierComponent, actor));
    if (!comp) {
        aiLogger.error("Error to get GoalSelectorComponent from {}", CommandUtils::getActorName(*actor));
        return false;
    }
    comp->addGoal(/* priority */ 9, std::make_unique<LookAtActorGoal>(*mob, 6.0f, 0.02f, 400, 800, 360, 360));
    aiLogger.info("Success to add LookAtActorGoal to {}", CommandUtils::getActorName(*actor));
    return true;
}
//bedrock_server_mod.exe!LookAtActorGoal::LookAtActorGoal()
//bedrock_server_mod.exe!<lambda>(void)()
//bedrock_server_mod.exe!std::_Func_impl_no_alloc<<lambda>(void),std::unique_ptr<Goal,std::default_delete<Goal>>,Mob &,GoalDefinition const &>::_Do_call()
//bedrock_server_mod.exe!GoalDefinition::CreateGoal(class Mob &,struct GoalDefinition const &)
//bedrock_server_mod.exe!Mob::createAIGoals(void)
TInstanceHook(LookAtActorGoal*, "??0LookAtActorGoal@@QEAA@AEAVMob@@MMHHHH@Z",
    LookAtActorGoal, class Mob& mob, float lookDistance, float probability,
    int minLookTime, int maxLookTime, int angleOfViewX, int angleOfViewY) {
    aiLogger.warn("LookAtActorGoal::LookAtActorGoal({}, {}, {}, {}, {}, {}, {})",
        CommandUtils::getActorName(mob), lookDistance, probability, minLookTime, maxLookTime, angleOfViewX, angleOfViewY);
    return original(this, mob, lookDistance, probability, minLookTime, maxLookTime, angleOfViewX, angleOfViewY);
}
//bedrock_server_mod.exe!Mob::createAIGoals(void)
TInstanceHook(LookAtActorGoal*, "?addGoal@GoalSelectorComponent@@QEAAXHV?$unique_ptr@VGoal@@U?$default_delete@VGoal@@@std@@@std@@@Z",
    GoalSelectorComponent, int priority, std::unique_ptr<class Goal> goal) {
    std::string info;
    goal->appendDebugInfo(info);
    aiLogger.warn("GoalSelectorComponent::addGoal({}, {})",
        priority, info);
    return original(this, priority, std::move(goal));
}

// ========== Hook Goal Start ==========

// Stack
//LLFakePlayer.dll!logGoal(void * goal, const std::string & name)
//bedrock_server_mod.exe!GoalSelectorUtility::tickGoals(class Mob &,bool)
//bedrock_server_mod.exe!EntityRegistryBase::View<1,class EntityContext,class EntityRegistry,struct ...
//bedrock_server_mod.exe!GoalSelectorSystem::tick(class EntityRegistry &)
//bedrock_server_mod.exe!`anonymous namespace'::DefaultEntitySystemsCollection::foreachTickingSystem()
//bedrock_server_mod.exe!EntitySystems::tick(class EntityRegistry &)

#define HookGoalStart(goal)                                   \
    TClasslessInstanceHook(void, "?start@" #goal "@@UEAAXXZ")                 \
    {                                                                         \
        logGoalFunc(this, #goal, "start");                                    \
        original(this);                                                       \
    }                                                                         \
    TClasslessInstanceHook(bool, "?canUse@" #goal "@@UEAA_NXZ")               \
    {                                                                         \
        auto rtn = original(this);                                            \
        logGoalFunc(this, #goal, "canUse", rtn ? "true" : "false");           \
        return rtn;                                                           \
    }                                                                         \
    TClasslessInstanceHook(bool, "?canContinueToUse@" #goal "@@UEAA_NXZ")     \
    {                                                                         \
        auto rtn = original(this);                                            \
        logGoalFunc(this, #goal, "canContinueToUse", rtn ? "true" : "false"); \
        return rtn;                                                           \
    }                                                                         \
    TClasslessInstanceHook(void, "?stop@" #goal "@@UEAAXXZ")                  \
    {                                                                         \
        logGoalFunc(this, #goal, "stop");                                     \
        original(this);                                                       \
    }\
    TClasslessInstanceHook(void, "?tick@" #goal "@@UEAAXXZ")                  \
    {                                                                         \
        logGoalFunc(this, #goal, "tick");                                     \
        original(this);                                                       \
    }\

// for debug break
void logGoalFunc(void* goal, std::string const& name, std::string const& func, std::string const& rtn = "void")
{
    aiLogger.warn("{}::{}() -> {}", name, func, rtn);
}


HookGoalStart(AvoidBlockGoal);
HookGoalStart(AvoidMobTypeGoal);
HookGoalStart(SneezeGoal);
HookGoalStart(StalkAndPounceOnTargetGoal);
HookGoalStart(TakeFlowerGoal);
HookGoalStart(TemptGoal);
HookGoalStart(TradeInterestGoal);
HookGoalStart(WorkGoal);
HookGoalStart(RamAttackGoal);
HookGoalStart(FindMountGoal);
HookGoalStart(FindUnderwaterTreasureGoal);
HookGoalStart(FollowCaravanGoal);
HookGoalStart(FollowOwnerGoal);
HookGoalStart(GoHomeGoal);
HookGoalStart(GuardianAttackGoal);
HookGoalStart(HoldGroundGoal);
HookGoalStart(KnockbackRoarGoal);
HookGoalStart(MakeLoveGoal);
HookGoalStart(MeleeAttackGoal);
HookGoalStart(MingleGoal);
HookGoalStart(BaseMoveToGoal);
HookGoalStart(BegGoal);
HookGoalStart(BreakDoorGoal);
HookGoalStart(ChargeAttackGoal);
HookGoalStart(DragonChargePlayerGoal);
HookGoalStart(DragonFlamingGoal);
HookGoalStart(DragonHoldingPatternGoal);
HookGoalStart(DragonLandingGoal);
HookGoalStart(DragonScanningGoal);
HookGoalStart(DragonStrafePlayerGoal);
HookGoalStart(DragonTakeoffGoal);
HookGoalStart(DropItemForGoal);
HookGoalStart(EatCarriedItemGoal);
HookGoalStart(ExploreOutskirtsGoal);
HookGoalStart(MoveIndoorsGoal);
HookGoalStart(MoveToBlockGoal);
HookGoalStart(MoveToRandomBlockGoal);
HookGoalStart(OpenDoorGoal);
HookGoalStart(PickupItemsGoal);
HookGoalStart(PlayGoal);
HookGoalStart(RaiderCelebrationGoal);
HookGoalStart(RandomLookAroundAndSitGoal);
HookGoalStart(RangedAttackGoal);
HookGoalStart(RollGoal);
HookGoalStart(ScaredGoal);
HookGoalStart(ShareItemsGoal);
HookGoalStart(ShulkerPeekGoal);
HookGoalStart(SleepGoal);
HookGoalStart(SnackGoal);
HookGoalStart(JumpToBlockGoal);
HookGoalStart(ChargeHeldItemGoal);
HookGoalStart(FollowFlockGoal);
HookGoalStart(OfferFlowerGoal);
HookGoalStart(RandomStrollGoal);
HookGoalStart(RiverFollowingGoal);
HookGoalStart(SendEventGoal);
HookGoalStart(SummonActorGoal);

//HookGoalStart(AdmireItemGoal);
//HookGoalStart(AvoidBlockGoal);
//HookGoalStart(AvoidMobTypeGoal);
//HookGoalStart(SneezeGoal);
//HookGoalStart(StalkAndPounceOnTargetGoal);
//HookGoalStart(StompAttackGoal);
//HookGoalStart(StompBlockGoal);
//HookGoalStart(SwellGoal);
//HookGoalStart(SwimIdleGoal);
//HookGoalStart(SwimWanderGoal);
//HookGoalStart(SwimWithEntityGoal);
//HookGoalStart(SwoopAttackGoal);
//HookGoalStart(TakeFlowerGoal);
//HookGoalStart(TargetWhenPushedGoal);
//HookGoalStart(TemptGoal);
//HookGoalStart(TradeInterestGoal);
//HookGoalStart(TradeWithPlayerGoal);
//HookGoalStart(WitherRandomAttackPosGoal);
//HookGoalStart(WorkGoal);
//HookGoalStart(PlayDeadGoal);
//HookGoalStart(RamAttackGoal);
//HookGoalStart(FindMountGoal);
//HookGoalStart(FindUnderwaterTreasureGoal);
//HookGoalStart(FollowCaravanGoal);
//HookGoalStart(FollowMobGoal);
//HookGoalStart(FollowOwnerGoal);
//HookGoalStart(FollowTargetCaptainGoal);
//HookGoalStart(GoHomeGoal);
//HookGoalStart(GuardianAttackGoal);
//HookGoalStart(OcelotSitOnBlockGoal);
//HookGoalStart(HideGoal);
//HookGoalStart(HoldGroundGoal);
//HookGoalStart(HoverGoal);
//HookGoalStart(KnockbackRoarGoal);
//HookGoalStart(LayDownGoal);
//HookGoalStart(LayEggGoal);
//HookGoalStart(LeapAtTargetGoal);
//HookGoalStart(LookAtActorGoal);
//HookGoalStart(MakeLoveGoal);
//HookGoalStart(MeleeAttackGoal);
//HookGoalStart(MingleGoal);
//HookGoalStart(BaseMoveToGoal);
//HookGoalStart(BegGoal);
//HookGoalStart(BreakDoorGoal);
//HookGoalStart(ChargeAttackGoal);
//HookGoalStart(CircleAroundAnchorGoal);
//HookGoalStart(ControlledByPlayerGoal);
//HookGoalStart(DefendVillageTargetGoal);
//HookGoalStart(DoorInteractGoal);
//HookGoalStart(DragonChargePlayerGoal);
//HookGoalStart(DragonDeathGoal);
//HookGoalStart(DragonFlamingGoal);
//HookGoalStart(DragonHoldingPatternGoal);
//HookGoalStart(DragonLandingGoal);
//HookGoalStart(DragonScanningGoal);
//HookGoalStart(DragonStrafePlayerGoal);
//HookGoalStart(DragonTakeoffGoal);
//HookGoalStart(DropItemForGoal);
//HookGoalStart(EatBlockGoal);
//HookGoalStart(EatCarriedItemGoal);
//HookGoalStart(ExploreOutskirtsGoal);
//HookGoalStart(MoveIndoorsGoal);
//HookGoalStart(MoveThroughVillageGoal);
//HookGoalStart(MoveToBlockGoal);
//HookGoalStart(MoveToRandomBlockGoal);
//HookGoalStart(MoveToVillageGoal);
//HookGoalStart(MoveTowardsRestrictionGoal);
//HookGoalStart(MoveTowardsTargetGoal);
//HookGoalStart(NapGoal);
//HookGoalStart(OpenDoorGoal);
//HookGoalStart(OwnerHurtByTargetGoal);
//HookGoalStart(PanicGoal);
//HookGoalStart(PetSleepWithOwnerGoal);
//HookGoalStart(PickupItemsGoal);
//HookGoalStart(PlayGoal);
//HookGoalStart(RaidGardenGoal);
//HookGoalStart(RaiderCelebrationGoal);
//HookGoalStart(RandomBreachingGoal);
//HookGoalStart(RandomLookAroundAndSitGoal);
//HookGoalStart(RandomLookAroundGoal);
//HookGoalStart(RandomSitGoal);
//HookGoalStart(RangedAttackGoal);
//HookGoalStart(RestrictOpenDoorGoal);
//HookGoalStart(RestrictSunGoal);
//HookGoalStart(RollGoal);
//HookGoalStart(ScaredGoal);
//HookGoalStart(ShareItemsGoal);
//HookGoalStart(ShulkerPeekGoal);
//HookGoalStart(SleepGoal);
//HookGoalStart(SlimeAttackGoal);
//HookGoalStart(SnackGoal);
//HookGoalStart(JumpToBlockGoal);
//HookGoalStart(AgentCommandExecutionGoal);
//HookGoalStart(BreatheAirGoal);
//HookGoalStart(ChargeHeldItemGoal);
//HookGoalStart(DefendTrustedTargetGoal);
//HookGoalStart(FindCoverGoal);
//HookGoalStart(FollowFlockGoal);
//HookGoalStart(HurtByTargetGoal);
//HookGoalStart(OfferFlowerGoal);
//HookGoalStart(RandomHoverGoal);
//HookGoalStart(RandomStrollGoal);
//HookGoalStart(RiverFollowingGoal);
//HookGoalStart(SendEventGoal);
//HookGoalStart(SummonActorGoal);
//HookGoalStart(SilverfishMergeWithStoneGoal);
//HookGoalStart(NearestAttackableTargetGoal);
//HookGoalStart(TargetGoal);
//HookGoalStart(VexCopyOwnerTargetGoal);
//HookGoalStart(SquidDiveGoal);
//HookGoalStart(SquidIdleGoal);
//HookGoalStart(SquidMoveAwayFromGroundGoal);
//HookGoalStart(SquidOutOfWaterGoal);




// ================ testai Command ================
#define KEY_NO_TARGET "%commands.generic.noTargetMatch"
#define KEY_TOO_MANY_TARGER "%commands.generic.tooManyTargets"

#define AssertUniqueTarger(results) \
if (results.empty())\
    return output.error(KEY_NO_TARGET);\
else if(results.count()>1)\
    return output.error(KEY_TOO_MANY_TARGER);

using namespace RegisterCommandHelper;

class TestAICommand :public Command {
    enum class Operation {
        Look,
    } operation;
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override {
        switch (operation)
        {
        case TestAICommand::Operation::Look:
            for (auto en : Level::getAllEntities()) {
                testAddGoal(en, (Mob*)origin.getEntity());
            }
            break;
        default:
            break;
        }
    };
public:
    static void setup(CommandRegistry& registry) {
        registry.registerCommand("testai", "Test AI", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
        registry.addEnum<Operation>("LookAction", {
            {"look", Operation::Look},
            });
        auto action = makeMandatory<CommandParameterDataType::ENUM>(&TestAICommand::operation, "action", "LookAction");
        registry.registerOverload<TestAICommand>("testai", action);

    };
};

namespace AiTest {
inline std::string getSym_canUse(std::string const& name)
{
    return "?canUse@" + name + "@@UEAA_NXZ";
}
inline std::string getSym_canContinueToUse(std::string const& name)
{
    return "?canContinueToUse@" + name + "@@UEAA_NXZ";
}
inline std::string getSym_canBeInterrupted(std::string const& name)
{
    return "?canBeInterrupted@" + name + "@@UEAA_NXZ";
}

inline std::string getSym_start(std::string const& name)
{
    return "?start@" + name + "@@UEAAXXZ";
}
inline std::string getSym_stop(std::string const& name)
{
    return "?stop@" + name + "@@UEAAXXZ";
}
inline std::string getSym_tick(std::string const& name)
{
    return "?tick@" + name + "@@UEAAXXZ";
}
inline bool isUnique(std::string const& sym)
{
    auto ptr = dlsym_real(sym.c_str());
    if (!ptr)
        return false;
    auto syms = dlsym_reverse((int)ptr);
    return syms.size() == 2;
}


    void setupCommand(CommandRegistry& registry) {
        std::vector<std::string> allAiGoals{
            "AdmireItemGoal",
            "AvoidBlockGoal",
            "AvoidMobTypeGoal",
            "SneezeGoal",
            "StalkAndPounceOnTargetGoal",
            "StompAttackGoal",
            "StompBlockGoal",
            "SwellGoal",
            "SwimIdleGoal",
            "SwimWanderGoal",
            "SwimWithEntityGoal",
            "SwoopAttackGoal",
            "TakeFlowerGoal",
            "TargetWhenPushedGoal",
            "TemptGoal",
            "TradeInterestGoal",
            "TradeWithPlayerGoal",
            "WitherRandomAttackPosGoal",
            "WorkGoal",
            "PlayDeadGoal",
            "RamAttackGoal",
            "FindMountGoal",
            "FindUnderwaterTreasureGoal",
            "FollowCaravanGoal",
            "FollowMobGoal",
            "FollowOwnerGoal",
            "FollowTargetCaptainGoal",
            "GoHomeGoal",
            "GuardianAttackGoal",
            "OcelotSitOnBlockGoal",
            "HideGoal",
            "HoldGroundGoal",
            "HoverGoal",
            "KnockbackRoarGoal",
            "LayDownGoal",
            "LayEggGoal",
            "LeapAtTargetGoal",
            "LookAtActorGoal",
            "MakeLoveGoal",
            "MeleeAttackGoal",
            "MingleGoal",
            "BaseMoveToGoal",
            "BegGoal",
            "BreakDoorGoal",
            "ChargeAttackGoal",
            "CircleAroundAnchorGoal",
            "ControlledByPlayerGoal",
            "DefendVillageTargetGoal",
            "DoorInteractGoal",
            "DragonChargePlayerGoal",
            "DragonDeathGoal",
            "DragonFlamingGoal",
            "DragonHoldingPatternGoal",
            "DragonLandingGoal",
            "DragonScanningGoal",
            "DragonStrafePlayerGoal",
            "DragonTakeoffGoal",
            "DropItemForGoal",
            "EatBlockGoal",
            "EatCarriedItemGoal",
            "ExploreOutskirtsGoal",
            "MoveIndoorsGoal",
            "MoveThroughVillageGoal",
            "MoveToBlockGoal",
            "MoveToRandomBlockGoal",
            "MoveToVillageGoal",
            "MoveTowardsRestrictionGoal",
            "MoveTowardsTargetGoal",
            "NapGoal",
            "OpenDoorGoal",
            "OwnerHurtByTargetGoal",
            "PanicGoal",
            "PetSleepWithOwnerGoal",
            "PickupItemsGoal",
            "PlayGoal",
            "RaidGardenGoal",
            "RaiderCelebrationGoal",
            "RandomBreachingGoal",
            "RandomLookAroundAndSitGoal",
            "RandomLookAroundGoal",
            "RandomSitGoal",
            "RangedAttackGoal",
            "RestrictOpenDoorGoal",
            "RestrictSunGoal",
            "RollGoal",
            "ScaredGoal",
            "ShareItemsGoal",
            "ShulkerPeekGoal",
            "SleepGoal",
            "SlimeAttackGoal",
            "SnackGoal",
            "JumpToBlockGoal",
            "AgentCommandExecutionGoal",
            "BreatheAirGoal",
            "ChargeHeldItemGoal",
            "DefendTrustedTargetGoal",
            "FindCoverGoal",
            "FollowFlockGoal",
            "HurtByTargetGoal",
            "OfferFlowerGoal",
            "RandomHoverGoal",
            "RandomStrollGoal",
            "RiverFollowingGoal",
            "SendEventGoal",
            "SummonActorGoal",
            "SilverfishMergeWithStoneGoal",
            "NearestAttackableTargetGoal",
            "TargetGoal",
            "VexCopyOwnerTargetGoal",
            "SquidDiveGoal",
            "SquidIdleGoal",
            "SquidMoveAwayFromGroundGoal",
            "SquidOutOfWaterGoal",
        };
        std::set<std::string> removeAiGoals;
        for (auto& name : allAiGoals) {
            if (!isUnique(getSym_canUse(name)))
            {
                removeAiGoals.insert(name);
                logger.warn("{}::canUse not unique",name);
                continue;
            }
            if (!isUnique(getSym_canContinueToUse(name)))
            {
                removeAiGoals.insert(name);
                logger.warn("{}::canContinueToUse not unique",name);
                continue;
            }
            //if (!isUnique(getSym_canBeInterrupted(name)))
            //{
            //    removeAiGoals.insert(name);
            //    continue;
            //}
            if (!isUnique(getSym_start(name)))
            {
                removeAiGoals.insert(name);
                logger.warn("{}::start not unique",name);
                continue;
            }
            if (!isUnique(getSym_stop(name)))
            {
                removeAiGoals.insert(name);
                logger.warn("{}::stop not unique",name);
                continue;
            }
            if (!isUnique(getSym_tick(name)))
            {
                removeAiGoals.insert(name);
                logger.warn("{}::tick not unique",name);
                continue;
            }
            

        }
        allAiGoals.erase(std::remove_if(allAiGoals.begin(), allAiGoals.end(), [&removeAiGoals](std::string const& name) {
            return removeAiGoals.find(name) != removeAiGoals.end();
        }), allAiGoals.end());

        logger.error("Removed:");
        for (auto& name : removeAiGoals)
        {
            logger.warn("{}", name);
        }
        logger.error("All:");
        for (auto& name : allAiGoals)
        {
            logger.warn("{}", name);
        }
        Schedule::repeat([]() { logger.info("tick"); }, 1);
        TestAICommand::setup(registry);
    }
} // namespace AiTest

#endif // ENABLE_TEST_AI
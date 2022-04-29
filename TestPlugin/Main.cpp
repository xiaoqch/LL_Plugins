#include "pch.h"
#include "TestRegRecipe.h"
#include <EventAPI.h>
#include "TestDBStorage.h"
#include "TestCommandReg.h"
#include "EnumGenerator.h"
#include "TestNbt.h"
#include "TestDlsym.h"

//#include <MC/ItemDescriptor.hpp>
void entry()
{
    logger.consoleLevel = logger.warn.level;
    logger.fileLevel = logger.info.level;
    // ItemDescriptor i1;
    // ItemDescriptor i2;
    // i1 = i2;
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev) -> bool {
        testRegRecipe();
        testStaticDlsym();
        testMCAPI();
        TestNbt::test();
        TestCommandReg::test();
        TestDBStorage::test();
        EnumGenerator::gen();
        // verifyHashUnique();
        return true;
    });
    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent const& ev) -> bool {
#ifdef ENABLE_TEST_DBSTORAGE
        RemovePlayerCommand::setup(*ev.mCommandRegistry);
        DBTestCommand::setup(*ev.mCommandRegistry);
#endif // ENABLE_TEST_DBSTORAGE
#ifdef ENABLE_TEST_AI
        AiTest::setupCommand(*ev.mCommandRegistry);
#endif // ENABLE_TEST_AI
        return true;
    });
}

// namespace
//{
// bool isEdu = false;
// }
// TClasslessInstanceHook(bool, "?isEducationEditionLevel@LevelData@@QEBA_NXZ")
//{
//     return isEdu;
// }
// TClasslessInstanceHook(void, "?setupStandardServer@ServerCommands@@YAXAEAVMinecraft@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PEAVPermissionsFile@@@Z",
//                        class Minecraft& mc, std::string const&a2, std::string const& a3, class PermissionsFile* a4)
//{
//     isEdu = true;
//     original(this, mc, a2, a3, a4);
//     isEdu = false;
// }

// TClasslessInstanceHook(void, "?updateServerAnnouncement@ServerNetworkHandler@@QEAAXXZ")
//{
//#ifdef DEBUG
//
//    auto v8 = *dAccess<voids<>*>(this, 13 * 8);
//    auto motd = dAccess<char*>(this, 632);
//    using Fn = void (*)(void*, char *, std::string const&, unsigned int, int, int, char);
//    auto v9 = dAccess<Fn>(&v8, 24);
//    auto v10 = dAccess<int>(this, 188 * 4);
//    std::string levelName = "TestName";
//    v9(&v8, motd, levelName, 1, 12, v10, 1);
//#endif // DEBUG
//    //original(this);
// }

#ifdef ABILITYPRO

#include <MC/ServerPlayer.hpp>
#include <MC/Level.hpp>

class Ability
{

public:
    enum Options : unsigned char;
    enum Type;

    Type mType;
    int mValue;
    Options mOptions;

    MCAPI bool getBool() const;
    MCAPI float getFloat() const;
    MCAPI enum Ability::Type getType() const;
    MCAPI void setBool(bool);
};

class Abilities
{

public:
    std::unique_ptr<class PermissionsHandler> mPermissions;
    std::array<Ability, 18> mAbilities;
    std::array<Ability, 8> mCustomAbilityCache;
    int unk320;
    int unk324;
    int unk328;

public:
    MCAPI Abilities(class Abilities const&);
    MCAPI Abilities();
    MCAPI void addSaveData(class CompoundTag&) const;
    MCAPI void forEachAbility(class std::function<void(class Ability&, char const*)> const&, enum Ability::Options);
    MCAPI class Ability& getAbility(enum AbilitiesIndex);
    MCAPI class Ability const& getAbility(enum AbilitiesIndex) const;
    MCAPI bool getBool(enum AbilitiesIndex) const;
    MCAPI enum CommandPermissionLevel getCommandPermissions() const;
    MCAPI class Ability const& getCustomAbilityFromCache(enum AbilitiesIndex) const;
    MCAPI class Ability& getCustomAbilityFromCache(enum AbilitiesIndex);
    MCAPI enum PlayerPermissionLevel getPlayerPermissions() const;
    MCAPI bool isFlying() const;
    MCAPI bool loadSaveData(class CompoundTag const&);
    MCAPI class Abilities& operator=(class Abilities const&);
    MCAPI void setAbility(enum AbilitiesIndex, bool);
    MCAPI void setAbilityDiff(enum AbilitiesIndex, bool, bool&);
    MCAPI void setCommandPermissions(enum CommandPermissionLevel);
    MCAPI void setPlayerPermissions(enum PlayerPermissionLevel);
    MCAPI ~Abilities();
    MCAPI static char const* getAbilityName(enum AbilitiesIndex);
    MCAPI static enum AbilitiesIndex nameToAbilityIndex(std::string const&);

protected:
private:
    MCAPI void _registerAbilities();
    MCAPI static class std::array<char const*, 18> ABILITY_NAMES;
    MCAPI static std::string const TAG;

public:
inline static class std::array<char const*, 18>& ABILITY_NAMES_ = Abilities::ABILITY_NAMES;
};

inline class Abilities* getPlayerAbilities(struct ActorUniqueID const& a0)
{
    class Abilities* (Level::*rv)(struct ActorUniqueID const&);
    *((void**)&rv) = dlsym("?getPlayerAbilities@Level@@UEAAPEAVAbilities@@AEBUActorUniqueID@@@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID const&>(a0));
}

enum class AdventureFlag : int
{
    FlagWorldImmutable = 1,
    SettingsFlagsNoPvM = 2,
    SettingsFlagsNoMvP = 4,
    SettingsFlagsUnused = 8,
    SettingsFlagsShowNameTags = 16,
    FlagAutoJump = 32,
    FlagAllowFlight = 64,
    FlagNoClip = 128,
    FlagWorldBuilder = 256,
    FlagFlying = 512,
    FlagMuted = 1024,
};

enum class ActionPermission : int
{
    Mine = 1,
	DoorsAndSwitches = 2,
	OpenContainers = 4,
	AttackPlayers = 8,
	AttackMobs = 16,
	Operator = 32,
	Teleport = 64,
	Build = 128,
	Default = 256,
};

enum class PermissionLevel : int
{
    Visitor,
    Menber,
    Operator,
    Custom,
};
struct AdventureSettings;
inline struct AdventureSettings& getAdventureSettings()
{
    struct AdventureSettings& (Level::*rv)();
    *((void**)&rv) = dlsym("?getAdventureSettings@Level@@UEAAAEAUAdventureSettings@@XZ");
    return (Global<Level>->*rv)();
}

#include <MC/Packet.hpp>
class AdventureSettingsPacket : public Packet
{
public:
    uint64_t mFlag;
    CommandPermissionLevel mCommandPermissionLevel;
    int mActionPermissions;
    PermissionLevel mPermissionLevel;
    int mCustomStoredPermissions;
    ActorUniqueID mUniqueId;

    /*0*/ virtual ~AdventureSettingsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AdventureSettingsPacket(struct AdventureSettings const&, class Abilities const&, struct ActorUniqueID, bool);
};

#include <MC/NetworkItemStackDescriptor.hpp>
class AddPlayerPacket : public Packet
{
public:
    std::vector<struct ActorLink> mActorLinks;         // 48
    std::string mName;                                 // 72
    mce::UUID mUuid;                                   // 104
    ActorUniqueID mUniqueId;                           // 120
    ActorRuntimeID mRuntimeId;                         // 128
    std::string mPlatformOnlineId;                     // 136
    Vec3 mPosition;                                    // 168
    Vec3 mVelocity;                                    // 180
    float mPitch;                                      // 192
    float mYaw;                                        // 196
    float mHeadYaw;                                    // 200
    std::vector<std::unique_ptr<DataItem>> mDataItems; // 208, only for read
    Abilities mAbilities;                              // 232
    std::string mDeviceId;                             // 568
    enum BuildPlatform mBuildPlatform;                 // 600
    NetworkItemStackDescriptor mCarriedItem;           // 608
    SynchedActorData* mActorData;                      // 736
public:
    /*0*/ virtual ~AddPlayerPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AddPlayerPacket(class Player&);
    MCAPI AddPlayerPacket();
};
//TClasslessInstanceHook(void, "?sendToClient@LoopbackPacketSender@@UEAAXAEBVNetworkIdentifier@@AEBVPacket@@E@Z", 
//    NetworkIdentifier const& nid, Packet const& pkt, unsigned char subId)
//{
//    if (pkt.getId() == MinecraftPacketIds::AdventureSettings) {
//        auto& packet = (AdventureSettingsPacket&)pkt;
//        logger.error("noclip: {}", (bool)((int)packet.mFlag & (int)AdventureFlag::FlagNoClip));
//        __debugbreak();
//    }
//    original(this, nid, pkt, subId);
//}

enum AbilitiesIndex : unsigned short
{
    Build = 0,
    Mine,
    DoorAndSwitches,
    OpenContainers,
    AttackPlayers,
    AttackMobs,
    Op,
    Teleport,
    Invulnerable,
    Flying,
    MayFly,
    InstaBuild,
    Lightning,
    FlySpeed,
    WalkSpeed,
    Mute,
    WorldBuilder,
    NoClip,
};
TClasslessInstanceHook(void, "?_sendInternal@NetworkHandler@@AEAAXAEBVNetworkIdentifier@@AEBVPacket@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
              NetworkIdentifier& nid, class Packet& pkt, std::string const& data)
{

    if (pkt.getId() == MinecraftPacketIds::AdventureSettings)
    {
        auto names = Abilities::ABILITY_NAMES_;
        auto& packet = (AdventureSettingsPacket&)pkt;
        logger.error("noclip: {}", (bool)((int)packet.mFlag & (int)AdventureFlag::FlagNoClip));
        //__debugbreak();
    }
    original(this, nid, pkt, data);
}

TInstanceHook(void, "?write@AdventureSettingsPacket@@UEBAXAEAVBinaryStream@@@Z",
              AdventureSettingsPacket, class BinaryStream& bs)
{
    //this->mFlag = this->mFlag | (int)AdventureFlag::FlagNoClip;
    original(this, bs);
}

TInstanceHook(void, "?jumpFromGround@Player@@UEAAXXZ", Player)
{
    auto abilities = getPlayerAbilities(getUniqueID());
    auto noclip = abilities->getAbility(AbilitiesIndex::NoClip).getBool();
    logger.warn("noclip: {} -> {}", noclip, !noclip);
    abilities->setAbility(AbilitiesIndex::NoClip, !noclip);
    AdventureSettingsPacket pkt(getAdventureSettings(), *abilities, getUniqueID(), false);
    sendNetworkPacket(pkt);
    original(this);
}

void setPlayerAbility(Player& player, AbilitiesIndex index, bool value)
{
    ActorUniqueID uid = player.getUniqueID();
    auto abilities = getPlayerAbilities(uid);
    abilities->setAbility(index, value);
    AdventureSettingsPacket pkt(getAdventureSettings(), *abilities, uid, false);
    player.sendNetworkPacket(pkt);
}

using namespace RegisterCommandHelper;
class AbilityProCommand : public Command
{
    AbilitiesIndex mIndex;
    CommandSelector<Player> mPlayer;
    bool mSwitch;
    float mValue;

    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override
    {
        auto players = mPlayer.results(origin);
        std::string names = "";
        for (auto player : players) {
            names += ", " + player->getName();
            setPlayerAbility(*player, mIndex, mSwitch);
        }
        if (names.empty()) {
            output.error("%command.generic.noTarget");
        }
        else
        {
            names = names.substr(2);
            output.success(fmt::format("Success to set ability \"{}\" to {} for {}", magic_enum::enum_name(mIndex), mSwitch, names));
        }
    }

public:
    static void setup(CommandRegistry& registry)
    {
        registry.registerCommand("abilitypro", "Abilities Pro", CommandPermissionLevel::GameMasters, {CommandFlagValue::None}, {(CommandFlagValue)0x80});
        registry.addEnum<AbilitiesIndex>("AbilityPro", {
            {"build", AbilitiesIndex::Build},
            {"mine", AbilitiesIndex::Mine},
            {"doorandswitches", AbilitiesIndex::DoorAndSwitches},
            {"opencontainers", AbilitiesIndex::OpenContainers},
            {"attackplayers", AbilitiesIndex::AttackPlayers},
            {"attackmobs", AbilitiesIndex::AttackMobs},
            {"op", AbilitiesIndex::Op},
            {"teleport", AbilitiesIndex::Teleport},
            {"invulnerable", AbilitiesIndex::Invulnerable},
            {"flying", AbilitiesIndex::Flying},
            {"mayfly", AbilitiesIndex::MayFly},
            {"instabuild", AbilitiesIndex::InstaBuild},
            {"lightning", AbilitiesIndex::Lightning},
            //{"FlySpeed", AbilitiesIndex::FlySpeed},
            //{"WalkSpeed", AbilitiesIndex::WalkSpeed},
            {"mute", AbilitiesIndex::Mute},
            {"worldbuilder", AbilitiesIndex::WorldBuilder},
            {"noclip", AbilitiesIndex::NoClip},
            });
        
        auto playerParam = makeMandatory<AbilityProCommand>(&AbilityProCommand::mPlayer, "target");
        auto indexParam = makeMandatory<CommandParameterDataType::ENUM, AbilityProCommand>(&AbilityProCommand::mIndex, "ability", "AbilityPro");
        auto valueParam = makeMandatory<AbilityProCommand>(&AbilityProCommand::mSwitch, "value");

        registry.registerOverload<AbilityProCommand>("abilitypro", playerParam, indexParam, valueParam);
    }
};

bool inited = ([]() -> bool {
    Event::RegCmdEvent::subscribe_ref([](Event::RegCmdEvent const& ev) -> bool {
        AbilityProCommand::setup(*ev.mCommandRegistry);
        return true;
    });
    return true;
    })();


#endif // ABILITYPRO
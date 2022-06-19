#include "pch.h"
#include "AbilityProCommand.h"
//#include <MC/Abilities.hpp>
//#include <MC/Ability.hpp>
#include <MC/Packet.hpp>
#include <MC/SynchedActorData.hpp>
#include <MC/Level.hpp>
#include <third-party/magic_enum/magic_enum.hpp>

using namespace RegisterCommandHelper;

enum class AdventureFlag : int
{
    WorldImmutable = 1,
    NoPvM = 2,
    NoMvP = 4,
    Unused = 8,
    ShowNameTags = 16,
    AutoJump = 32,
    AllowFlight = 64,
    NoClip = 128,
    WorldBuilder = 256,
    Flying = 512,
    Muted = 1024,
};
#ifdef DEBUG
struct AdventureSettings
{
    bool mNoPvM;
    bool mNoMvP;
    bool mWorldImmutable;
    bool mShowNameTags;
    bool mAutoJump;

public:
    MCAPI AdventureSettings();
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
class Ability
{

public:
    enum Options : unsigned char;
    enum Type : unsigned char;

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

    std::unordered_map<AbilitiesIndex, bool> toMap() const
    {
        std::unordered_map<AbilitiesIndex, bool> res;
        for (auto& [index,name] : magic_enum::enum_entries<AbilitiesIndex>())
        {
            res[index] = mAbilities[(int)index].getBool();
        }
        return res;
    }

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
    inline static class std::array<char const*, 18> ABILITY_NAMES_ = Abilities::ABILITY_NAMES;
};
#else
#include <MC/Abilities.hpp>
#endif // DEBUG

class RequestAbilityPacket : public Packet
{
public:
    AbilitiesIndex mAbility = (AbilitiesIndex)-1;
    bool mHasValue = false;
    char filler51;
    bool mValue = false;
    char filler53[3];
    bool unk56 = false;


public:
    /*0*/ virtual ~RequestAbilityPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);

    MCAPI RequestAbilityPacket(enum AbilitiesIndex, bool);
    MCAPI RequestAbilityPacket();
    MCAPI enum AbilitiesIndex getAbility() const;
    MCAPI bool tryGetBool(bool&) const;
};
class AdventureSettingsPacket : public Packet
{
public:
    unsigned int mFlag;                             // 48
    CommandPermissionLevel mCommandPermissionLevel; // 52
    unsigned int mActionPermissions;                // 56
    unsigned char mPermissionLevel;                 // 60
    ActorUniqueID mUniqueId;                        // 64
    int unk72;                                      // 72
    unsigned int mCustomStoredPermissions;          // 76

    /*0*/ virtual ~AdventureSettingsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    MCAPI AdventureSettingsPacket(struct AdventureSettings const&, class Abilities const&, struct ActorUniqueID, bool);
};

//static_assert(offsetof(AdventureSettingsPacket, mCustomStoredPermissions) == 76);

inline struct AdventureSettings& getAdventureSettings()
{
    struct AdventureSettings& (Level::*rv)();
    *((void**)&rv) = dlsym("?getAdventureSettings@Level@@UEAAAEAUAdventureSettings@@XZ");
    return (Global<Level>->*rv)();
}

inline void sendAllPlayerAbilities(class Player const& a0)
{
    void (Level::*rv)(class Player const&);
    *((void**)&rv) = dlsym("?sendAllPlayerAbilities@Level@@UEAAXAEBVPlayer@@@Z");
    return (Global<Level>->*rv)(std::forward<class Player const&>(a0));
}

inline class Abilities* getPlayerAbilities(struct ActorUniqueID const& a0)
{
    class Abilities* (Level::*rv)(struct ActorUniqueID const&);
    *((void**)&rv) = dlsym("?getPlayerAbilities@Level@@UEAAPEAVAbilities@@AEBUActorUniqueID@@@Z");
    return (Global<Level>->*rv)(std::forward<struct ActorUniqueID const&>(a0));
}

inline void sendNetworkPacket(Player& player, class Packet& a0)
{
    void (Player::*rv)(class Packet&);
    *((void**)&rv) = dlsym("?sendNetworkPacket@ServerPlayer@@UEBAXAEAVPacket@@@Z");
    return (player.*rv)(std::forward<class Packet&>(a0));
}

void _updateAbility(Player& player, AbilitiesIndex index, bool value)
{
}

void setPlayerAbility(Player& player, AbilitiesIndex index, bool value)
{
    ActorUniqueID uid = player.getUniqueID();
    //auto abilities = Global<Level>->getPlayerAbilities(uid);
    auto abilities = &dAccess<Abilities>(&player, 2512);
#ifdef DEBUG
    auto map = abilities->toMap();
#endif // DEBUG
    auto flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
    if (index == AbilitiesIndex::Flying && value && player.isOnGround())
    {
        abilities->setAbility(AbilitiesIndex::MayFly, value);
    }
    if (index == AbilitiesIndex::MayFly && value == false && flying)
    {
        abilities->setAbility(AbilitiesIndex::Flying, false);
    }
    abilities->setAbility(index, value);
    auto mayfly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
    auto noclip = abilities->getAbility(AbilitiesIndex::NoClip).getBool();
    player.setCanFly(mayfly || noclip);
    if (index == AbilitiesIndex::NoClip)
    {
        abilities->setAbility(AbilitiesIndex::Flying, value);
    }
#ifdef DEBUG
    auto map2 = abilities->toMap();
#endif // DEBUG
    flying = abilities->getAbility(AbilitiesIndex::Flying).getBool();
    AdventureSettingsPacket pkt(getAdventureSettings(), *abilities, uid, false);
    
    pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
    if (flying)
        pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
    player._sendDirtyActorData();
    sendNetworkPacket(player, pkt);
}

bool getPlayerAbility(Player& player, AbilitiesIndex index)
{
    //ActorUniqueID uid = player.getUniqueID();
    //auto abilities = getPlayerAbilities(uid);
    auto abilities = &dAccess<Abilities>(&player, 2512);
    return abilities->getAbility(index).getBool();
}

void AbilityProCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const
{
    auto players = mPlayer.results(origin);
    if (players.empty()) {
        return output.error("%commands.generic.noTargetMatch");
    }
    std::string names = "";
    if (!mIndex_isSet) {
        return output.success("build, mine, doorandswitches, opencontainers, attackplayers, attackmobs, op, teleport, invulnerable, flying, mayfly, instabuild, lightning, mute, worldbuilder, noclip");
    }
    if (!mSwitch_isSet)
    {
        for (auto player : players)
        {
            output.success(fmt::format("{}: {} = {}", 
                player->getName(), magic_enum::enum_name(mIndex), getPlayerAbility(*player, mIndex)));
        }
        return;
    }
    for (auto player : players)
    {
        names += ", " + player->getName();
        setPlayerAbility(*player, mIndex, mSwitch);
    }
    if (names.empty())
    {
        output.error("%commands.generic.noTargetMatch");
    }
    else
    {
        names = names.substr(2);
        output.success(fmt::format("Success to set ability \"{}\" {} for {}", magic_enum::enum_name(mIndex), mSwitch, names));
    }
}

void AbilityProCommand::setup(CommandRegistry& registry)
{
    registry.registerCommand("abilitypro", "Abilities Pro", CommandPermissionLevel::Any, {CommandFlagValue::None}, {(CommandFlagValue)0x80});
    if (!Config::commandAlias.empty()) {
        registry.registerAlias("abilitypro", Config::commandAlias);
    }
    registry.addEnum<AbilitiesIndex>(
        "AbilityPro",
        {
            {"build", AbilitiesIndex::Build},
            {"mine", AbilitiesIndex::Mine},
            {"doorandswitches", AbilitiesIndex::DoorAndSwitches},
            {"opencontainers", AbilitiesIndex::OpenContainers},
            {"attackplayers", AbilitiesIndex::AttackPlayers},
            {"attackmobs", AbilitiesIndex::AttackMobs},
            //{"op", AbilitiesIndex::Op},
            {"teleport", AbilitiesIndex::Teleport},
            {"invulnerable", AbilitiesIndex::Invulnerable},
            {"flying", AbilitiesIndex::Flying},
            {"mayfly", AbilitiesIndex::MayFly},
            {"instabuild", AbilitiesIndex::InstaBuild},
            {"lightning", AbilitiesIndex::Lightning},
            //{"FlySpeed", AbilitiesIndex::FlySpeed},
            //{"WalkSpeed", AbilitiesIndex::WalkSpeed},
            {"mute", AbilitiesIndex::Mute},
            //{"worldbuilder", AbilitiesIndex::WorldBuilder},
            {"noclip", AbilitiesIndex::NoClip},
        });

    auto playerParam = makeMandatory<AbilityProCommand>(&AbilityProCommand::mPlayer, "target");
    auto indexParam = makeMandatory<CommandParameterDataType::ENUM, AbilityProCommand>(&AbilityProCommand::mIndex, "ability", "AbilityPro", &AbilityProCommand::mIndex_isSet);
    auto valueParam = makeMandatory<AbilityProCommand>(&AbilityProCommand::mSwitch, "value", &AbilityProCommand::mSwitch_isSet);
    auto indexOptional = makeOptional<CommandParameterDataType::ENUM, AbilityProCommand>(&AbilityProCommand::mIndex, "ability", "AbilityPro", &AbilityProCommand::mIndex_isSet);

    registry.registerOverload<AbilityProCommand>("abilitypro", playerParam, indexParam, valueParam);
    registry.registerOverload<AbilityProCommand>("abilitypro", playerParam, indexOptional);
}
#include <MC/ServerPlayer.hpp>
TInstanceHook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVRequestAbilityPacket@@@Z",
              ServerNetworkHandler, class NetworkIdentifier const& nid, class RequestAbilityPacket const& pkt)
{
    original(this, nid, pkt);
    auto index = pkt.getAbility();
    if (index == AbilitiesIndex::Flying)
    {
        auto sp = _getServerPlayer(nid, pkt.clientSubId);
        if (!sp)
            return;
        if (!sp->getUserEntityIdentifierComponent())
            return;
        bool flying;
        if (!pkt.tryGetBool(flying))
            return;
        auto abilities = &dAccess<Abilities>(sp, 2512);
        auto mayFly = abilities->getAbility(AbilitiesIndex::MayFly).getBool();
        flying = flying && mayFly;
        AdventureSettingsPacket pkt(getAdventureSettings(), *abilities, sp->getUniqueID(), false);
        pkt.mFlag &= ~static_cast<unsigned int>(AdventureFlag::Flying);
        if (flying)
            pkt.mFlag |= static_cast<unsigned int>(AdventureFlag::Flying);
        abilities->setAbility(AbilitiesIndex::Flying, flying);
        sp->sendNetworkPacket(pkt);
        DEBUGW("{} set may flying -> {}", getName(), flying);
    }
}
#ifdef DEBUG

TInstanceHook(AdventureSettingsPacket&, "??0AdventureSettingsPacket@@QEAA@AEBUAdventureSettings@@AEBVAbilities@@UActorUniqueID@@_N@Z",
              AdventureSettingsPacket, struct AdventureSettings const& settings, class Abilities const& abilities, struct ActorUniqueID uniqueId, bool unk_0)
{
    auto map = abilities.toMap();
    auto&pkt = original(this, settings, abilities, uniqueId, unk_0);
    if (abilities.getAbility(AbilitiesIndex::MayFly).getBool() && abilities.getAbility(AbilitiesIndex::Flying).getBool()) {
        pkt.mFlag |= (int)AdventureFlag::Flying;
    }
    return pkt;
}
TInstanceHook(bool, "?canUseAbility@Player@@QEBA_NW4AbilitiesIndex@@@Z",
              Player, enum AbilitiesIndex index)
{
    auto rtn = original(this, index);
    DEBUGW("{} {} use ability {}", getName(), rtn ? "can" : "can not", magic_enum::enum_name(index));
    return rtn;
}
TClasslessInstanceHook(bool, "?isFlying@PlayerMovement@@YA_NAEBUIPlayerMovementProxy@@@Z",
              struct IPlayerMovementProxy const& a1)
{
    auto rtn = original(this, a1);
    DEBUGW("isFlying: {}", rtn);
    return rtn;
}
//TInstanceHook(bool, "?isFlying@Abilities@@QEBA_NXZ",
//              Abilities)
//{
//    //auto rtn = original(this);
//    auto rtn = this->getAbility(AbilitiesIndex::Flying).getBool();
//    DEBUGW("Abilities::isFlying: {}", rtn);
//    return true;
//}

#endif // DEBUG
#pragma once

enum AbilitiesIndex
{
    Build = 0,           // Action - ?
    Mine = 1,            // Action - 1
    DoorAndSwitches = 2, // Action - 2
    OpenContainers = 3,  // Action - 4
    AttackPlayers = 4,   // Action - 8
    AttackMobs = 5,      // Action - 16
    Op = 6,              // Action - 32
    Teleport = 7,        // Action - 128
    Invulnerable = 8,    // Adventure -
    Flying = 9,          // Adventure - 512
    MayFly = 10,         // Adventure - 64
    InstaBuild = 11,     // Adventure -
    Lightning = 12,      // Adventure -
    FlySpeed = 13,       // Adventure -
    WalkSpeed = 14,      // Adventure -
    Mute = 15,           // Adventure - 1024
    WorldBuilder = 16,   // Adventure - ?
    NoClip = 17,         // Adventure - 128
};

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
        for (auto& [index, name] : magic_enum::enum_entries<AbilitiesIndex>())
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
#else

#include <MC/Abilities.hpp>
#include <MC/RequestAbilityPacket.hpp>
struct AdventureSettings;

#endif // DEBUG

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

public:
    /*0*/ virtual ~AdventureSettingsPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*6*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);

    MCAPI AdventureSettingsPacket(struct AdventureSettings const&, class LayeredAbilities const&, struct ActorUniqueID);
    MCAPI AdventureSettingsPacket();

    MCAPI void _initAbilitiesData(class Abilities const&);
    MCAPI void _initCustomCacheData(class Abilities const&);


private:
};

namespace AbilitiesHelper
{
Abilities* getAbilities(Player& player);
void setPlayerAbility(Player& player, AbilitiesIndex index, bool value);
bool getPlayerAbility(Player& player, AbilitiesIndex index);
//void setPlayerAbilityFloat(Player& player, AbilitiesIndex index, bool value);
float getPlayerAbilityFloat(Player& player, AbilitiesIndex index);
std::vector<AbilitiesIndex> getPlayerAbilities(Player& player);


};

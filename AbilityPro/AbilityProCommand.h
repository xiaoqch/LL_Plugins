#pragma once
#include <RegCommandAPI.h>
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

class AbilityProCommand : public Command
{
    AbilitiesIndex mIndex;
    CommandSelector<Player> mPlayer;
    bool mSwitch;
    bool mIndex_isSet;
    bool mSwitch_isSet;

    virtual void execute(class CommandOrigin const&, class CommandOutput&) const override;

public:
    static void setup(CommandRegistry& registry);
};

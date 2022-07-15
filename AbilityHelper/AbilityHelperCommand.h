#pragma once
#include <RegCommandAPI.h>
#include "AbilityHelper.h"

#define DISABLE_COMMAND
#ifndef DISABLE_COMMAND
class AbilityHelperCommand : public Command
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
#endif // DISABLE_COMMAND


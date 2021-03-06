#pragma once
#include <RegCommandAPI.h>

class ActorDebugCommand :
    public Command
{
    CommandSelector<Player> mPlayer;
    bool mPlayer_isSet;
    virtual void execute(class CommandOrigin const&, class CommandOutput&) const override;
public:
    static void setup(CommandRegistry& registry);
};


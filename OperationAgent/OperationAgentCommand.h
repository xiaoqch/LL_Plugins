#pragma once
#include <RegCommandAPI.h>

class OperationAgentCommand :
    public Command
{
    enum class Operation {
        Set,
        Clear,
        Query,
        Help,
        List,
        ClearAll,
        Version,
        Reload,
    };
    Operation mOperation;
    CommandSelector<Actor> mMaster;
    CommandSelector<Actor> mAgent;
    bool mAgent_isSet;

    virtual void execute(class CommandOrigin const&, class CommandOutput&) const override;
public:
    static void setup(CommandRegistry& registry);
};


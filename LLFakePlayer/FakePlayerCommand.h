#pragma once
class SimulatedPlayer;

class FakePlayerCommand : public Command
{
    static std::vector<std::string> mList;
    std::string name;
    enum class Operation
    {
        Help,
        List,
        Create,
        Remove,
        Login,
        Logout,
        GUI,
        Import,
    } operation;
    CommandPosition commandPos;
    int dimensionId;
    bool name_isSet, commandPos_isSet, dimensionId_isSet;
    inline BlockPos getExpectedPosition(CommandOrigin const& origin) const;
    SimulatedPlayer* createSimulatedPlayer(class CommandOrigin const& origin, class CommandOutput& output) const;
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;

public:
    static void setup(CommandRegistry& registry);
};

#ifdef PLUGIN_DEV_MODE

// =============== Test ===============
class TickingCommand : public Command
{
    CommandSelector<Player> selector;
    bool selector_isSet;
    int range;
    bool range_isSet;

    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;

public:
    static void setup(CommandRegistry& registry);
};

#endif // PLUGIN_DEV_MODE
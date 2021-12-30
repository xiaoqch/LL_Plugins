#pragma once
class SimulatedPlayer;

class FakePlayerCommand :
    public Command
{
    static std::vector<std::string> mList;
    std::string name;
    enum class Operation {
        Help,
        List,
        Create,
        Remove,
        Login,
        Logout,
        GUI,
    } operation;
    CommandPosition commandPos;
    int dimensionId;
    bool commandPos_isSet, dimensionId_isSet;
    inline BlockPos getExpectedPosition(CommandOrigin const& origin) const;
    SimulatedPlayer* createSimulatedPlayer(class CommandOrigin const& origin, class CommandOutput& output) const;
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;
public:
    static void setup(CommandRegistry& registry);
};

#if PLUGIN_VERSION_IS_BETA

// =============== Test ===============
class TickingCommand :public Command {
    CommandSelector<Player> selector;
    bool selector_isSet;

    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;
public:
    static void setup(CommandRegistry& registry);
};

#endif // PLUGIN_VERSION_IS_BETA
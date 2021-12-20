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
    } operation;
    CommandPosition commandPos;
    int dimensionId;
    bool commandPos_isSet, dimensionId_isSet;
    inline BlockPos getPositionFromCommand(CommandOrigin const& origin) const;
    SimulatedPlayer* createSimulatedPlayer(class CommandOrigin const& origin, class CommandOutput& output) const;
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;
public:
    static void setup(CommandRegistry& registry);
};


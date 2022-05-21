#pragma once
#include <RegCommandAPI.h>
#include <MC/ItemStack.hpp>
#include <MC/ItemRegistry.hpp>
#include <MC/Dimension.hpp>
#include <MC/Level.hpp>
#include <MC/VanillaBlocks.hpp>
#include "MyHeaders.h"
class EndGatewayCommand : public Command
{
    enum class Operation
    {
        Get,  // get Item
        Give, // give Item
        Set,  // set Block
        Edit, // edit BlockActor
        FindSpawn,//findValidSpawnAround
        FindExit, //
        FindTallest,
    } mAction;
    int mCount;
    CommandPosition mPosition;
    CommandPosition mDestination;
    int mDistance;
    bool mEndStoneOnly;
    bool mAllowBedrock;
    bool mOperation_isSet;
    bool mCount_isSet;
    bool mPosition_isSet;
    bool mDestination_isSet;
    bool mDistance_isSet;
    bool mEndStoneOnly_isSet;
    bool mAllowBedrock_isSet;
    
    virtual void execute(class CommandOrigin const& origin, class CommandOutput& output) const override;

public:
    static void setup(CommandRegistry& registry);
};

#include "pch.h"
#include "EndGatewayCommand.h"

using namespace RegisterCommandHelper;

void EndGatewayCommand::execute(class CommandOrigin const& origin, class CommandOutput& output) const
{
    switch (mAction)
    {
        case EndGatewayCommand::Operation::Get:
            if (auto sp = getPlayerFromOrigin(origin))
            {
                auto count = mCount_isSet ? mCount : 1;
                ItemStack item(*ItemRegistry::lookupByName("minecraft:end_gateway"), count);
                if (sp->add(item))
                {
                    output.success(fmt::format("get {} {}", count, item.getName()));
                    sp->refreshInventory();
                }
                else
                    output.error("not enough space");
            }
            break;
        case EndGatewayCommand::Operation::Set:
        {
            auto pos = mPosition_isSet ? mPosition.getBlockPos(origin, Vec3::ZERO)
                                       : origin.getBlockPosition();
            auto dim = origin.getDimension();
            int dimid = dim ? (int)dim->getDimensionId() : 0;
            if (Level::setBlock(pos, dimid, const_cast<Block*>(VanillaBlocks::mEndGateway)))
                output.success(fmt::format("set End Gateway {} {}", pos.toString(), dimid));
            else
                output.error("failed to set End Gateway");
            break;
        }
        case EndGatewayCommand::Operation::Edit:

            break;
        case EndGatewayCommand::Operation::FindSpawn:
        {
            BlockSource* region = nullptr;
            if (auto entity = origin.getEntity())
                region = &entity->getRegion();
            else if (auto dim = origin.getDimension())
                region = &dim->getBlockSourceFromMainChunkSource();
            if (!region)
            {
                output.error("no region");
                break;
            }
            auto pos = mPosition_isSet ? mPosition.getBlockPos(origin, Vec3::ZERO)
                                       : origin.getBlockPosition();
            auto distance = mDistance_isSet ? mDistance : 16;
            auto endStoneOnly = mEndStoneOnly_isSet ? mEndStoneOnly : true;
            if (distance % 16 != 0)
            {
                output.error("distance must be multiple of 16");
                break;
            }
            auto res = EndGatewayBlockActor::findValidSpawnAround(*region, pos, endStoneOnly, distance / 16);
            output.success(fmt::format("spawn pos ({}) for ({}) found", res.toString(), pos.toString()));
        }
        break;
        case EndGatewayCommand::Operation::FindTallest:
        {
            BlockSource* region = nullptr;
            if (auto entity = origin.getEntity())
                region = &entity->getRegion();
            else if (auto dim = origin.getDimension())
                region = &dim->getBlockSourceFromMainChunkSource();
            if (!region)
            {
                output.error("no region");
                break;
            }
            auto pos = mPosition_isSet ? mPosition.getBlockPos(origin, Vec3::ZERO)
                                       : origin.getBlockPosition();
            auto distance = mDistance_isSet ? mDistance : 16;
            auto allowBedrock = mAllowBedrock_isSet ? mAllowBedrock : true;
            if (distance % 16 != 0)
            {
                output.error("distance must be multiple of 16");
                break;
            }
            auto res = EndGatewayBlockActor::findTallestBlock(*region, pos, distance, allowBedrock);
            output.success(fmt::format("tallest pos ({}) for ({}) found", res.toString(), pos.toString()));
        }
        case EndGatewayCommand::Operation::FindExit:
        {
            auto dimension = Global<Level>->createDimension(2);
            if (!dimension)
            {
                output.error("failed to create dimension");
                break;
            }
            auto generator = dimension->getWorldGenerator();
            if (!generator)
            {
                output.error("no generator");
                break;
            }
            auto pos = mPosition_isSet ? mPosition.getBlockPos(origin, Vec3::ZERO)
                                       : origin.getBlockPosition();
            auto res = EndGatewayBlockActor::findExitPortal(*generator, pos);
            output.success(fmt::format("exit pos ({}) for ({}) found", res.toString(), pos.toString()));
        }
        break;
        default:
            break;
    }
};

void EndGatewayCommand::setup(CommandRegistry& registry)
{    
    registry.registerCommand("gateway", "End Gateway Helper Command", CommandPermissionLevel::Any, {(CommandFlagValue)0}, {(CommandFlagValue)0x80});

    //Get, Set, Edit, FindSpawn, FindExit, FindTallest
    registry.addEnum<Operation>("Gateway_Action_Get", {{"get", Operation::Get}});
    registry.addEnum<Operation>("Gateway_Action_Set", {{"setblock", Operation::Set}});
    registry.addEnum<Operation>("Gateway_Action_Edit", {{"edit", Operation::Edit}});
    registry.addEnum<Operation>("Gateway_Action_FindSpawn", {{"findspawn", Operation::FindSpawn}});
    registry.addEnum<Operation>("Gateway_Action_FindExit", {{"findexit", Operation::FindExit}});
    registry.addEnum<Operation>("Gateway_Action_FindTallest", {{"findtallest", Operation::FindTallest}});
    
    auto actionGet = makeMandatory<CommandParameterDataType::ENUM>(
        &EndGatewayCommand::mAction, "action", "Gateway_Action_Get", &EndGatewayCommand::mOperation_isSet);
    auto actionSet = makeMandatory<CommandParameterDataType::ENUM>(
        &EndGatewayCommand::mAction, "action", "Gateway_Action_Set", &EndGatewayCommand::mOperation_isSet);
    auto actionEdit = makeMandatory<CommandParameterDataType::ENUM>(
        &EndGatewayCommand::mAction, "action", "Gateway_Action_Edit", &EndGatewayCommand::mOperation_isSet);
    auto actionFindSpawn = makeMandatory<CommandParameterDataType::ENUM>(
        &EndGatewayCommand::mAction, "action", "Gateway_Action_FindSpawn", &EndGatewayCommand::mOperation_isSet);
    auto actionFindExit = makeMandatory<CommandParameterDataType::ENUM>(
        &EndGatewayCommand::mAction, "action", "Gateway_Action_FindExit", &EndGatewayCommand::mOperation_isSet);
    auto actionFindTallest = makeMandatory<CommandParameterDataType::ENUM>(
        &EndGatewayCommand::mAction, "action", "Gateway_Action_FindTallest", &EndGatewayCommand::mOperation_isSet);
    
    // gateway <get> [count]
    // gateway <set> [pos]
    // gateway <edit> [pos] [destination]
    // gateway <findspawn> [pos] [distance] [endStoneOnly]
    // gateway <findtallest> [pos] [distance] [allowBedrock]
    // gateway <findexit> [pos]
    auto count = makeOptional(&EndGatewayCommand::mCount, "count", &EndGatewayCommand::mCount_isSet);
    auto position = makeOptional(&EndGatewayCommand::mPosition, "pos", &EndGatewayCommand::mPosition_isSet);
    auto destination = makeOptional(&EndGatewayCommand::mDestination, "destination", &EndGatewayCommand::mDestination_isSet);
    auto distance = makeOptional(&EndGatewayCommand::mDistance, "distance", &EndGatewayCommand::mDistance_isSet);
    auto endStoneOnly = makeOptional(&EndGatewayCommand::mEndStoneOnly, "endStoneOnly", &EndGatewayCommand::mEndStoneOnly_isSet);
    auto allowBedrock = makeOptional(&EndGatewayCommand::mAllowBedrock, "allowBedrock", &EndGatewayCommand::mAllowBedrock_isSet);
    
    registry.registerOverload<EndGatewayCommand>("gateway", actionGet, count);
    registry.registerOverload<EndGatewayCommand>("gateway", actionSet, position);
    registry.registerOverload<EndGatewayCommand>("gateway", actionEdit, position, destination);
    registry.registerOverload<EndGatewayCommand>("gateway", actionFindSpawn, position, distance, endStoneOnly);
    registry.registerOverload<EndGatewayCommand>("gateway", actionFindTallest, position, distance, allowBedrock);
    registry.registerOverload<EndGatewayCommand>("gateway", actionFindExit, position);
    
}
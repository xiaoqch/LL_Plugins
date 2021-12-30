#include "pch.h"
#include "Config.h"
#include <MC/StructureTemplate.hpp>
#include "LLStructureCommand.h"

#include <MC/StructureManager.hpp>
//static_assert(offsetof(StructureTemplate, data.size) ==44);
static_assert(sizeof(StructureTemplate) == 216);
StructureManager* manager;

THook(StructureManager*, "??0StructureManager@@QEAA@XZ", StructureManager* _this) {
    auto rtn = original(std::forward<StructureManager*>(_this));
    manager = _this;
    return std::forward<StructureManager*>(rtn);
}

using namespace RegisterCommandHelper;
#include <MC/Minecraft.hpp>
#include <MC/Level.hpp>
#include <MC/ServerLevel.hpp>
#include <MC/CompoundTag.hpp>
#include <MC/ListTag.hpp>
#include <MC/CommandArea.hpp>
#include <MC/CommandAreaFactory.hpp>
#include <MC/Dimension.hpp>
#include <Utils/FileHelper.h>
void testStructure() {
    //manager->tryPlaceStructureInWorld()
}
//optional<StructureTemplate> LLStructureCommand::getStructure(class CommandOutput& outp) const {
//    auto filePath = fmt::format("struct/{}.mcstructure", name);
//    auto nbt = ReadAllFile(filePath, true);
//    if (!nbt.has_value()) {
//        outp.error(fmt::format("Structure {} Not Found", name));
//        return {};
//    }
//    auto tag = CompoundTag::fromBinaryNBT((void*)nbt.value().c_str(), nbt.value().size());
//    return StructureTemplate::fromTag(name, *tag);
//}
void LLStructureCommand::execute(class CommandOrigin const& ori, class CommandOutput& outp) const {
    try
    {
        switch (operation)
        {
        case LLStructureCommand::Operation::Help:
            break;
        case LLStructureCommand::Operation::List:
            break;
        case LLStructureCommand::Operation::Load:
        {
            auto filePath = fmt::format("struct/{}.mcstructure", name);
            auto nbt = ReadAllFile(filePath, true);
            if (!nbt.has_value()) {
                outp.error(fmt::format("Structure {} Not Found", name));
                return;
            }
            auto tag = CompoundTag::fromBinaryNBT((void*)nbt.value().c_str(), nbt.value().size());
            BlockPos bpos;
            if (commandPos_isSet) {
                bpos = commandPos1.getBlockPos(ori, { 0,0,0 });
            }
            else {
                auto posTag = tag->getList("structure_world_origin");
                if (!posTag) {
                    outp.error("load structure failed");
                    return;
                }
                bpos = { posTag->getInt(0) ,posTag->getInt(1),posTag->getInt(2) };
            }
            auto structure = StructureTemplate::fromTag(name, *tag);
            auto result = structure.toWorld(ori.getDimension()->getDimensionId(), bpos);
            if (result)
                outp.success("Success to load structure " + name);
        }
        break;
        case LLStructureCommand::Operation::Save:
        {
            auto filePath = fmt::format("struct/{}.mcstructure", name);
            auto pos1 = commandPos1.getBlockPos(ori, { 0,0,0 });
            BlockPos pos2;
            if (commandPos_isSet) {
                pos2 = commandPos2.getBlockPos(ori, { 0,0,0 });
            }
            else {
                pos2 = ori.getBlockPosition();
            }
            auto structure = StructureTemplate::fromWorld(name, ori.getDimension()->getDimensionId(), pos1, pos2, false, false);
            WriteAllFile(filePath, structure.toTag()->toBinaryNBT(true));
            outp.success("Structure Saved");
        }
        break;
        case LLStructureCommand::Operation::Import:
            break;
        case LLStructureCommand::Operation::Export:
            break;
        case LLStructureCommand::Operation::Delete:
            break;
        default:
            break;
        }
        return;
    }
    catch (const seh_exception& e) {
        logger.error("Uncaught SEH Exception Detected!");
        logger.error("In Command struct");
    }
    catch (const std::exception& e) {
        logger.error("Uncaught Exception Detected!");
        logger.error("In Command struct");
    }
    outp.error("Unknown Error");
}

void LLStructureCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("llstructure", "Mcstructure Helper for LiteLoader", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.registerAlias("llstructure", "struct");
    registry.addEnum< LLStructureCommand::Operation>("loadAction", {
        {"load", Operation::Load},
        });
    registry.addEnum< LLStructureCommand::Operation>("saveAction", {
        {"save", Operation::Save},
        });
    auto loadAction = makeMandatory<CommandParameterDataType::ENUM>(&LLStructureCommand::operation, "action", "loadAction");
    auto saveAction = makeMandatory<CommandParameterDataType::ENUM>(&LLStructureCommand::operation, "action", "saveAction");
    loadAction.addOptions((CommandParameterOption)1);
    saveAction.addOptions((CommandParameterOption)1);

    auto nameParam = makeMandatory(&LLStructureCommand::name, "name");
    auto positionParam = makeMandatory(&LLStructureCommand::commandPos1, "pos1");
    auto optionalPositionParam = makeOptional(&LLStructureCommand::commandPos1, "pos2", &LLStructureCommand::commandPos_isSet);
    registry.registerOverload<LLStructureCommand>("llstructure",
        loadAction, nameParam, optionalPositionParam);
    registry.registerOverload<LLStructureCommand>("llstructure",
        saveAction, nameParam, positionParam, optionalPositionParam);
}
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
#include <MC/CommandArea.hpp>
#include <MC/CommandAreaFactory.hpp>
#include <Utils/FileHelper.h>
void testStructure() {
    //manager->tryPlaceStructureInWorld()
}

void LLStructureCommand::execute(class CommandOrigin const& ori, class CommandOutput& outp) const {
    string fullname = name.find(":") != name.npos ? name : fmt::format("mystructure:{}", name);
    auto structure = manager->getStructure(fullname);
    auto st = StructureTemplate::fromWorld(fullname, 0, { 1,2,3 }, { 500, 100, 500 },false, true);
    //WriteAllFile("./test.msctructure", st.toTag()->toBinaryNBT(), true);
    std::cout << st.toTag()->toBinaryNBT().size() << std::endl;
    return;
    testStructure();
    //auto srpm = Global<ServerLevel>->getServerResourcePackManager();
    if(!structure)
        return outp.error(fmt::format("structure {} not found!", fullname));
    auto newStruct = StructureTemplate::fromTag("mystructure:bbbbbb", structure->toTag().release());
    auto area = ori.getAreaAt({ 0,66,0 });
    if(area.get())
        outp.success("ori.getAreaAt(0,66,0)");
    auto res = manager->load(newStruct, nullptr, nullptr);
    if (res)
        outp.success("structure mystructure:bbb load success");
    else
        outp.error("structure mystructure:bbb load error");
}

void LLStructureCommand::setup(CommandRegistry& registry) {
    registry.registerCommand("llstructure", "Mcstructure Helper for LiteLoader", CommandPermissionLevel::Any, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });
    registry.registerAlias("llstructure", "struct");
    registry.registerOverload<LLStructureCommand>("llstructure", makeMandatory(&LLStructureCommand::name, "name"));
}
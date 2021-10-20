#include "pch.h"
#include <mc/OffsetHelper.h>
#include "BlockType.h"
#include "EnumGen.h"
#include <api/scheduler/scheduler.h>
#include <seh_exception/seh_exception.hpp>
#include "SymHelper.h"

struct voids;

bool oncmd_reg(CommandOrigin const& ori, CommandOutput& outp) {
    genActorFlags(ori.getEntity());
    //dynReg();
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("reg", "Dynamic Register Recipe", 0);
        CmdOverload(reg, oncmd_reg);
        });
    Event::addEventListener([](ServerStartedEV ev) {
        auto task = DelayedTask([]()->void {
            genEnum();
            }, 10);
        auto taskId = Handler::schedule(std::move(task));
        });
    Event::addEventListener([](PlayerUseItemEV ev) {
        auto itemstack = ev.ItemStack;
        auto item = SymCall("?getItem@ItemStackBase@@QEBAPEBVItem@@XZ", void*, ItemStack*)(itemstack);
        //SymCall("?getTextureUVCoordinateSet@Item@@SA?AUTextureUVCoordinateSet@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z",
        //    void*, void*, string&)();
        });
}

void entry() {
    _set_se_translator(seh_exception::TranslateSEHtoCE);
    regListener();
}

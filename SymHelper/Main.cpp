#include "pch.h"
#include <mc/OffsetHelper.h>
#include "BlockType.h"
#include "EnumGen.h"
#include <api/scheduler/scheduler.h>
#include <seh_exception/seh_exception.hpp>
#include "SymHelper.h"

struct voids;


bool oncmd_reg(CommandOrigin const& ori, CommandOutput& outp) {

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
}

void entry() {
    _set_se_translator(seh_exception::TranslateSEHtoCE);
    regListener();
}
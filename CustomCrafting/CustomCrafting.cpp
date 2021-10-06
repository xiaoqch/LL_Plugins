#include "pch.h"
#include <api/scheduler/scheduler.h>
#include <seh_exception/seh_exception.hpp>
#include "RecipeHelper.h"

using namespace std;


bool oncmd_reg(CommandOrigin const& ori, CommandOutput& outp) {
    dynReg();
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("cc", "Dynamic Register Recipe", 0);
        CmdOverload(cc, oncmd_reg);
        });
    Event::addEventListener([](ServerStartedEV ev) {
        auto task = DelayedTask([]()->void {
            //genEnum();
            }, 10);
        auto taskId = Handler::schedule(std::move(task));
        });
}

void entry() {
    _set_se_translator(seh_exception::TranslateSEHtoCE);
    regListener();
}
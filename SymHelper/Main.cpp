#include "pch.h"
#include <mc/OffsetHelper.h>
#include "BlockType.h"
#include "EnumGen.h"
#include <api/scheduler/scheduler.h>
#include <seh_exception/seh_exception.hpp>
#include "RecipeHook.h"
#include "SymHelper.h"
//Recipes::_loadHardcodedRecipes

struct voids;

struct SystemAddress {
    void* v[17];
};
struct RakNetGUID {
    uint64_t unk;
    short unk8;
};

template <typename T>
struct DataList {
    T* v;
    int start;
    int end;
};

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
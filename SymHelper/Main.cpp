#include "pch.h"
#include <mc/OffsetHelper.h>
#include "BlockType.h"
#include "EnumGen.h"
#include <api/scheduler/scheduler.h>
#include <seh_exception/seh_exception.hpp>
#include "RecipeHook.h"
#include "SymHelper.h"
//Recipes::_loadHardcodedRecipes



bool oncmd_reg(CommandOrigin const& ori, CommandOutput& outp) {

    dynReg();
    auto snh = getServerNetworkHandler();
    for (auto& pl : liteloader::getAllPlayers()) {
        auto nid = offPlayer::getNetworkIdentifier(pl);
        ServerPlayer* sp = MakeSP(pl);
        //SymCall("?_sendLevelData@ServerNetworkHandler@@AEAAXAEAVServerPlayer@@AEBVNetworkIdentifier@@@Z",
        //    void, ServerNetworkHandler*, ServerPlayer*, NetworkIdentifier*)(snh, sp, nid);
        SymCall("?_sendAdditionalLevelData@ServerNetworkHandler@@AEAAXAEAVServerPlayer@@AEBVNetworkIdentifier@@@Z",
            void, ServerNetworkHandler*, ServerPlayer*, NetworkIdentifier*)(snh, sp, nid);
    }
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
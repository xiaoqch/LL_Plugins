#include "pch.h"
#include "SimulatedPlayer.h"

#define VERSION "0.0.1"
#define PLUGIN_NAME "LL TEMPLATE"

using namespace std;

bool oncmd_sp(CommandOrigin const& ori, CommandOutput& outp, string name, int x, int y, int z, int dimid) {
    SimulatedPlayerHelper::createSP(name, x, y, z, dimid);
    return true;
}

bool oncmd_sp_quick(CommandOrigin const& ori, CommandOutput& outp, string name) {
    auto actor = ori.getEntity();
    if (!actor) {
        outp.error("创建失败");
        return false;
    }
    SimulatedPlayerHelper::createSP(name, ((Vec3)actor->getPos()).toBlockPos(), actor->getDimensionId());
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("sp", "Dynamic Register Recipe", 0);
        CmdOverload(sp, oncmd_sp, "name", "x", "y", "z", "dimid");
        CmdOverload(sp, oncmd_sp_quick, "name");
        });
}

void entry() {
    regListener();
    cout << PLUGIN_NAME << "Loaded, Version: " << VERSION << endl;
}
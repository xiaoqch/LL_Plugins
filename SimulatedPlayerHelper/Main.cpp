#include "pch.h"
#include "SimulatedPlayer.h"
#include <mc/OffsetHelper.h>
#define VERSION "0.0.1"
#define PLUGIN_NAME "LL TEMPLATE"

using namespace std;

bool oncmd_sp(CommandOrigin const& ori, CommandOutput& outp, string name, int x, int y, int z, optional<int>& optDimid) {
    int dimid=0;
    if (optDimid.set)
        dimid = optDimid.val();
    else {
        auto dim = ori.getDimension();
        if (!dim)
            dimid = 0;
        else
            dimid = SymCall("?getDimensionId@Dimension@@QEBA?AV?$AutomaticID@VDimension@@H@@XZ", int, Dimension*)(dim);
    }
    auto sp=SimulatedPlayerHelper::createSP(name, x, y, z, dimid);
    outp.success("创建模拟玩家 " + name + " 成功");
    return true;
}

bool oncmd_sp_quick(CommandOrigin const& ori, CommandOutput& outp, string name) {
    auto actor = ori.getEntity();
    if (actor) {
        SimulatedPlayerHelper::createSP(name, ori.getBlockPosition(), actor->getDimensionId());
    }
    else {
        int dimid = 0;
        auto& pos = SymCall("?getDefaultSpawn@Level@@UEBAAEBVBlockPos@@XZ", const BlockPos&, Level*)(ori.getLevel());
        SimulatedPlayerHelper::createSP(name, pos, dimid);
    }
    outp.success("创建模拟玩家 " + name + " 成功");
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
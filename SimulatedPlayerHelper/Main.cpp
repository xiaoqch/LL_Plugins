#include "pch.h"
#include "SimulatedPlayer.h"
#include <mc/OffsetHelper.h>
#include "SyncHelper.h"

#define VERSION "0.0.1"
#define PLUGIN_NAME "LL TEMPLATE"

using namespace std;

bool oncmd_sp(CommandOrigin const& ori, CommandOutput& outp, string name, int x, int y, int z, optional<int>& optDimid) {
    int dimid = 0;
    if (optDimid.set)
        dimid = optDimid.val();
    else {
        auto dim = ori.getDimension();
        if (!dim)
            dimid = 0;
        else
            dimid = SymCall("?getDimensionId@Dimension@@QEBA?AV?$AutomaticID@VDimension@@H@@XZ", int, Dimension*)(dim);
    }
    auto sp = SimulatedPlayerHelper::createSP(name, x, y, z, dimid);
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

bool oncmd_rmsp(CommandOrigin const& ori, CommandOutput& outp, CommandSelector<Player>& plSel) {
    auto pls = plSel.results(ori);
    string resultList;
    bool isFirst = true;
    for (auto& pl : pls) {
        if (isSimulatedPlayer(pl)) {
            auto sp = ((SimulatedPlayer*)pl);
            resultList.append((isFirst ? "" : ", ") + sp->getNameTag());
            sp->simulateDisconnect();
            outp.success();
            isFirst = false;
        }
    }
    if (resultList.empty()) {
        outp.error("%commands.generic.noTargetMatch");
    }
    else {
        outp.success("成功移除以下模拟玩家：" + resultList);
    }
    return !resultList.empty();
}

bool oncmd_spmv(CommandOrigin const& ori, CommandOutput& outp, CommandSelector<Player>& plSel) {
    auto pls = plSel.results(ori);
    string resultList;
    bool isFirst = true;
    for (auto& pl : pls) {
        if (isSimulatedPlayer(pl)) {
            auto sp = ((SimulatedPlayer*)pl);
            resultList.append((isFirst ? "" : ", ") + sp->getNameTag());
            sp->simulateLocalMove({ 0.0f, 0.0f, 1.0f }, 1);
            outp.success();
            isFirst = false;
        }
    }
    if (resultList.empty()) {
        outp.error("%commands.generic.noTargetMatch");
    }
    else {
        outp.success("以下模拟玩家成功模拟移动：" + resultList);
    }
    return !resultList.empty();
}


bool oncmd_spstopmv(CommandOrigin const& ori, CommandOutput& outp, CommandSelector<Player>& plSel) {
    auto pls = plSel.results(ori);
    string resultList;
    bool isFirst = true;
    for (auto& pl : pls) {
        if (isSimulatedPlayer(pl)) {
            auto sp = ((SimulatedPlayer*)pl);
            resultList.append((isFirst ? "" : ", ") + sp->getNameTag());
            sp->simulateStopMoving();
            outp.success();
            isFirst = false;
        }
    }
    if (resultList.empty()) {
        outp.error("%commands.generic.noTargetMatch");
    }
    else {
        outp.success("以下模拟玩家成功模拟停止移动：" + resultList);
    }
    return !resultList.empty();
}

enum class SYNC_OP_1 {
    start = 1,
};

enum class SYNC_OP_2 {
    stop = 1,
    //list,
};

bool oncmd_sync_start(CommandOrigin const& ori, CommandOutput& outp, MyEnum<SYNC_OP_1>& op, CommandSelector<Player>& selector) {
    auto en = ori.getEntity();
    if (!en||!isPlayer(en)) {
        outp.error("仅允许玩家执行");
        return false;
    }
    auto pls = selector.results(ori);
    SimulatedPlayer* sp=nullptr;
    bool hasSP = false;
    for (auto& pl : pls) {
        if (isSimulatedPlayer(pl)) {
            if (hasSP) {
                outp.error("%commands.generic.tooManyTargets");
                return false;
            }
            sp = (SimulatedPlayer*)pl;
            hasSP = true;
        }
    }
    if (!sp) {
        outp.error("%commands.generic.noTargetMatch");
        return false;
    }
    auto result = startSync((Player*)ori.getEntity(), sp);
    if (!result)
        outp.error("同步模拟玩家失败");
    else
        outp.success("同步模拟玩家成功");
    return result;
}

bool oncmd_sync_stop(CommandOrigin const& ori, CommandOutput& outp, MyEnum<SYNC_OP_2>& op) {
    auto en = ori.getEntity();
    if (!en||!isPlayer(en)) {
        outp.error("仅允许玩家执行");
        return false;
    }
    auto result = stopSync((Player*)ori.getEntity());
    if (!result)
        outp.error("停止同步模拟玩家失败");
    else
        outp.success("停止同步模拟玩家成功");
    return result;
}
void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("sp", "create simulated player", 0);
        MakeCommand("sprm", "remove simulated player", 0);
        MakeCommand("spmv", "remove simulated player", 0);
        MakeCommand("spstopmv", "remove simulated player", 0);
        MakeCommand("spsync", "sync", 0);
        CmdOverload(sp, oncmd_sp_quick, "name");
        CmdOverload(sp, oncmd_sp, "name", "x", "y", "z", "dimid");
        CmdOverload(sprm, oncmd_rmsp, "simulatedplayer");
        CmdOverload(spmv, oncmd_spmv, "simulatedplayer");
        CmdOverload(spstopmv, oncmd_spstopmv, "simulatedplayer");
        CEnum<SYNC_OP_1> _1("start", { "start" });
        CEnum<SYNC_OP_2> _2("stop", { "stop" });
        CmdOverload(spsync, oncmd_sync_start, "start", "simulatedplayer");
        CmdOverload(spsync, oncmd_sync_stop, "stop");
        });
}

void entry() {
    regListener();
    cout << PLUGIN_NAME << "Loaded, Version: " << VERSION << endl;
}
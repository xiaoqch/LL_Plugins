#include "pch.h"
#include "Config.h"
#include "ActorFlagsGen.h"

#ifdef GEN_ACTOR_FLAGS

#include "SymHelper.h"
#include <api/scheduler/scheduler.h>

using namespace std;

Minecraft* mc;

THook(void, "?initAsDedicatedServer@Minecraft@@QEAAXXZ", void* self) {
    original(self);
    mc = (Minecraft*)self;
}

ServerNetworkHandler* getServerNetworkHandler() {
    return mc->getServerNetworkHandler();
};

string toCamelCase(string const& src, char c = '_') {
    string dst;
    dst = SymCall("?toCamelCase@Util@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV23@D@Z",
        string&, string&, string const&, char)(dst, src, c);
    return dst;
}
class SimulatedPlayer;
SimulatedPlayer* createSP(string const& name, BlockPos const& bpos, int dimid) {
    auto snh = getServerNetworkHandler();
    auto sp = SymCall("?create@SimulatedPlayer@@SAPEAV1@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVBlockPos@@V?$AutomaticID@VDimension@@H@@AEAVServerNetworkHandler@@@Z",
        SimulatedPlayer*, string const&, BlockPos const&, int, ServerNetworkHandler*)(name, bpos, dimid, snh);
    return sp;
};
SimulatedPlayer* createSP(string const& name, int x, int y, int z, int dimid) {
    return createSP(name, { x, y, z }, dimid);
}

map<int, string> genFlagMap(Actor* actor) {
    int flagMax = 100;
    map<int, string> flagMap = {};
    for (int i = 0; i <= flagMax; ++i) {
        auto flag = (ActorFlags)i;
        setStatusFlag(actor, flag, false);
    }
    for (int i = 0; i <= flagMax; ++i) {
        auto flag = (ActorFlags)i;
        setStatusFlag(actor, flag, true);
        auto text = getActorDebugText(actor);
        if (text.size() < 6)
            continue;
        string flagName = text[5].substr(1);
        flagMap[i] = flagName;
        setStatusFlag(actor, flag, false);
    }
    return flagMap;
}

void genActorFlagsForCmd(map<int, string>& flagMap) {
    cout << "enum class ActorFlagsForCmd : int {" << endl;
    bool isFirst = true;
    for (auto& [flag, name] : flagMap) {
        if (isFirst)
            cout << "    " << name << " = 1," << endl;
        else
            cout << "    " << name << "," << endl;
        isFirst = false;
    }
    cout << "};" << endl;
}

void genActorFlags(map<int, string>& flagMap) {
    cout << "enum class ActorFlags : int {" << endl;
    for (auto& [flag, name] : flagMap) {
        cout << "    " << name << " = " << flag << ", " << endl;
    }
    cout << "};" << endl;
}

void genFlagCmdMap(map<int, string>& flagMap) {
    cout << "static std::map<ActorFlagsForCmd, ActorFlags> flagCmdMap = {" << endl;
    for (auto& [flag, name] : flagMap) {
        cout << "    {ActorFlagsForCmd::" << name << ", ActorFlags::" << name << "}," << endl;
    }
    cout << "};" << endl;
}

void genFlagsNameMap(map<int, string>& flagMap) {
    cout << "static std::map<ActorFlags, string> actorFlagsNameMap = {" << endl;
    for (auto& [flag, name] : flagMap) {
        cout << "    { ActorFlags::" << name << ", \"" << name << "\"}," << endl;
    }
    cout << "};" << endl;
}

void genCmdOptions(map<int, string>& flagMap) {
    cout << "#define CMD_FLAG_OPTIONS { ";
    for (auto& [flag, name] : flagMap) {
        cout << "\"" << strToLower(name) << "\", ";
    }
    cout << " }" << endl;
}

void genActorFlags(Actor* actor) {
    auto flagMap = genFlagMap(actor);
    cout << "#pragma once\n#include <map>\n" << endl;
    genCmdOptions(flagMap);
    cout << endl;
    genActorFlagsForCmd(flagMap);
    cout << endl;
    genActorFlags(flagMap);
    cout << endl;
    genFlagCmdMap(flagMap);
    cout << endl;
    genFlagsNameMap(flagMap);
    cout << endl;
}

void startGenActorFlags() {
    auto actor = (Actor*)createSP("FlagGen",0,66,0,0);
    auto task = DelayedTask(std::move([actor]() {
        genActorFlags(actor);
        }), 3);
    auto taskId = Handler::schedule(std::move(task));
}

#endif // GEN_ACTOR_FLAGS
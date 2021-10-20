#include "pch.h"

#define VERSION "0.0.1"
#define PLUGIN_NAME "LL TEMPLATE"

using namespace std;

bool oncmd_cmd(CommandOrigin const& ori, CommandOutput& outp) {
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("cmd", "Dynamic Register Recipe", 0);
        CmdOverload(cmd, oncmd_cmd);
        });
}

void entry() {
    regListener();
    cout << PLUGIN_NAME << "Loaded, Version: " << VERSION << endl;
}
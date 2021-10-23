#include "pch.h"
#include "Config.h"

using namespace std;

bool oncmd_cmd(CommandOrigin const& ori, CommandOutput& outp) {
    return true;
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("cmd", "CMD Description", 0);
        CmdOverload(cmd, oncmd_cmd);
        });
}

void entry() {
    regListener();
    cout << PLUGIN_NAME << "Loaded, Version: " << VERSION_STRING << endl;
}
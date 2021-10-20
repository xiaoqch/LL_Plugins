#include "pch.h"
#include "ActorFlags.h"
#include "SymHelper.h"
#include <mc/OffsetHelper.h>

#define VERSION "0.0.1"
#define PLUGIN_NAME "LL TEMPLATE"

using namespace std;

enum class OPERATION_0 : int {
    list = 1,
};
enum class OPERATION_1 : int {
    add = 1,
    remove = 2,
    query = 3,
};

bool oncmd_actorflags_0(CommandOrigin const& ori, CommandOutput& outp, CommandSelector<Actor>& target, MyEnum<OPERATION_0>& op) {
    WPlayer(*(Player*)ori.getEntity()).sendText("text");
    auto actors = target.results(ori);
    switch (op.val)
    {
    case OPERATION_0::list:
        if (actors.count() == 0) {
            outp.error("%commands.generic.noTargetMatch");
        }
        else if (actors.count() > 1) {
            outp.error("%commands.generic.tooManyTargets");
        }
        else {
            auto flags = getAllFlags(*actors.begin());
            string result;
            for (auto& flag : flags) {
                result.append(flag).append(", ");
            }
            outp.success(result.c_str());
        }
        break;
    default:
        break;
    }
    return SymCall("?getSuccessCount@CommandOutput@@QEBAHXZ", unsigned int, CommandOutput&)(outp);
}
bool oncmd_actorflags_1(CommandOrigin const& ori, CommandOutput& outp, CommandSelector<Actor>& target, MyEnum<OPERATION_1>& op, MyEnum<ActorFlagsForCmd>& flagForCmd) {
    auto actors = target.results(ori);
    auto flag = flagCmdMap[flagForCmd];
    if (actors.count() == 0) {
        outp.error("%commands.generic.noTargetMatch");
        return false;
    }
    size_t count = 0;
    switch (op)
    {
    case OPERATION_1::add:
        for (auto& actor : actors) {
            count += addActorFlag(actor, flag);
        }
        if (!count) {
            outp.error("No target needs to add flag " + actorFlagsNameMap[flag]);
        }
        else {
            outp.success("Add Flag " + actorFlagsNameMap[flag] + " Success ");
        }
        break;
    case OPERATION_1::remove:
        for (auto& actor : actors) {
            count += removeActorFlag(actor, flag);
        }
        if (!count) {
            outp.error("No target has flag " + actorFlagsNameMap[flag]);
        }
        else {
            outp.success("Remove Flag " + actorFlagsNameMap[flag] + " Success");
        }
        break;
    case OPERATION_1::query:
        if (actors.count() > 1) {
            outp.error("%commands.generic.tooManyTargets");
        }
        else {
            auto hasFlag = getStatusFlag(*actors.begin(), flag);
            outp.success("Qeury Flag " + actorFlagsNameMap[flag] + " , Result: " + (hasFlag ? "true" : "false"));
        }
        break;
    default:
        break;
    }
    return SymCall("?getSuccessCount@CommandOutput@@QEBAHXZ", unsigned int, CommandOutput&)(outp);
}

void regListener() {
    Event::addEventListener([](RegCmdEV ev) {
        CMDREG::SetCommandRegistry(ev.CMDRg);
        MakeCommand("actorflags", "modifier actor flags", 0);
        CEnum<OPERATION_0> _0("list", { "list" });
        CEnum<OPERATION_1> _1("op", { "add", "remove" });
        CEnum<ActorFlagsForCmd> _2("flag", { "onfire", "sneaking", "riding", "sprinting", "usingitem", "invisible", "tempted", "inlove", "saddled", "powered", "ignited", "baby", "converting", "critical", "showname", "noai", "silent", "wallclimbing", "resting", "sitting", "angry", "interested", "charged", "tamed", "orphaned", "leashed", "sheared", "gliding", "elder", "moving", "breathing", "chested", "stackable", "idling", "has_gravity", "swimming", "bribed", "layingdown", "sneezing", "trusting", "scared", "blocking", "is_illager_captain", "stunned", "roaring", "is_avoiding_mobs", "out_of_control", "playing_dead" });
        CmdOverload(actorflags, oncmd_actorflags_0, "actor", "list");
        CmdOverload(actorflags, oncmd_actorflags_1, "actor", "op", "flag");
        });
}

void entry() {
    regListener();
    cout << PLUGIN_NAME << "Loaded, Version: " << VERSION << endl;
}


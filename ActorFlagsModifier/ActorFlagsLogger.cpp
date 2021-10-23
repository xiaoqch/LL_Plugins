#include "pch.h"
#include "Config.h"
#include "SymHelper.h"
#include "ActorFlags.h"

#ifdef ENABLE_LOGGER
void logFlag(Actor* actor, ActorFlags flag, bool value) {
    bool oldValue = getStatusFlag(actor, flag);
    int i = (int)flag;
    if (value == oldValue)
        return;

    auto flagName = strToLower(actorFlagsNameMap[flag]);
    flagName.append("(" + to_string((int)flag) + ")");
    string actorName;
    actorName = SymCall("?getActorName@CommandUtils@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBVActor@@@Z",
        string&, string&, Actor*)(actorName, actor);
    cout << "setStatusFlag - " << actorName << " - " << flagName << ": " << (oldValue ? "true" : "false") << " -> " << (value ? "true" : "false") << endl;

}

THook(bool, "?setStatusFlag@Actor@@QEAA_NW4ActorFlags@@_N@Z",
    Actor* actor, ActorFlags flag, bool value) {
    logFlag(actor, flag, value);
    return original(actor, flag, value);
}

THook(bool, "?setStatusFlag@Actor@@SA_NAEAVSynchedActorData@@W4ActorFlags@@_N@Z",
    class SynchedActorData* data, ActorFlags flag, bool value) {
    Actor* actor = (Actor *)((uintptr_t)data - 376);
    logFlag(actor, flag, value);
    return original(data, flag, value);
}
#endif // ENABLE_LOGGER
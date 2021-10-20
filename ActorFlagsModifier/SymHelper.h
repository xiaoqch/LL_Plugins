#pragma once
#include "pch.h"
#include "ActorFlags.h"
#include <vector>

using namespace std;

inline bool setStatusFlag(Actor* actor, ActorFlags flag, bool val) {
    return SymCall("?setStatusFlag@Actor@@QEAA_NW4ActorFlags@@_N@Z",
        bool, Actor*, ActorFlags, bool)(actor, flag, val);
}

inline bool getStatusFlag(Actor* actor, ActorFlags flag) {
    return SymCall("?getStatusFlag@Actor@@QEBA_NW4ActorFlags@@@Z",
        bool, Actor*, ActorFlags)(actor, flag);
}

inline bool addActorFlag(Actor* actor, ActorFlags flag) {
    auto hasStatus = getStatusFlag(actor, flag);
    if (hasStatus)
        return false;
    return setStatusFlag(actor, flag, true);
}

inline bool removeActorFlag(Actor* actor, ActorFlags flag) {
    auto hasStatus = getStatusFlag(actor, flag);
    if (!hasStatus)
        return false;
    return setStatusFlag(actor, flag, false);
}

inline vector<string> getActorDebugText(Actor* actor) {
    vector<string> text;
    SymCall("?getDebugText@Actor@@UEAAXAEAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Z",
        void, Actor*, vector<string>&)(actor, text);
    return text;
}

inline string strToLower(const string& str) {
    auto result = string(str);
    transform(result.begin(), result.end(), result.begin(), tolower);
    return result;
}

inline vector<string> getAllFlags(Actor* actor) {
    vector<string> flags;
    auto text = getActorDebugText(actor);
    for (auto& str : text) {
        if (!str._Starts_with("+"))
            continue;
        flags.emplace_back(strToLower(str.substr(1)));
    }
    return flags;
}
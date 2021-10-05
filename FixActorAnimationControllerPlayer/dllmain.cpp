// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"

void entry() {};
THook(class ActorAnimationControllerPlayer*, "??0ActorAnimationControllerPlayer@@QEAA@AEBVHashedString@@AEBVActorAnimationControllerPtr@@AEAVAnimationComponent@@AEBVExpressionNode@@@Z",
    ActorAnimationControllerPlayer* _this, HashedString& str, struct ActorAnimationControllerPtr* aacp, struct AnimationComponent* ac, const struct ExpressionNode* en) {
    str = HashedString(str.getString().c_str());
    auto rtn = original(_this, str, aacp, ac, en);
    return rtn;
}

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        entry();
    }
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
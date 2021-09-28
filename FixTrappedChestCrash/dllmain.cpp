// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include "loader/Loader.h"
#include <functional>

using namespace std;

#define VERSION "1.0.0"

void entry() {
    cout << "Fix Trapped Chest Crash Loaded. Version: " << VERSION << endl;
};

THook(void, "?serverInitItemStackIds@CraftingContainer@@UEAAXHHV?$function@$$A6AXHAEBVItemStack@@@Z@std@@@Z",
    __int64 a1, class ContainerModel* a2) {
    // nullptr ChestBlockActor in ChestBlockActor::serverInitItemStackIds
    // and CraftingContainer is get from ChestBlockActor
    if (a1 == 240)
        return;
    original(a1, a2);
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
// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include "loader/Loader.h"

using namespace std;

#define VERSION "1.0.2"

void entry() {
    cout << "Fix Trapped Chest Crash Loaded. Version: " << VERSION << endl;
};

THook(void, "?serverInitItemStackIds@CraftingContainer@@UEAAXHHV?$function@$$A6AXHAEBVItemStack@@@Z@std@@@Z",
    __int64 _this, int a1, int a2, void* a3) {
    // nullptr ChestBlockActor in ChestBlockActor::serverInitItemStackIds
    // and CraftingContainer is get from ChestBlockActor
    // offset 204 for bds 1.17.3x and 248 for bds 1.17.1x
    //if (a1 == 240 || a1 == 248)
    __int64 size = 640; // size of ChestBlockActor
    if(_this <= size)
        return;
    original(_this, a1, a2, a3);
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
// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include "loader/Loader.h"

using namespace std;

void entry() {};


THook(bool, "?_hasChunk@DBChunkStorage@@AEAA_NAEBVDBChunkStorageKey@@@Z",
    void* _this, void* dbChunkStorageKey, void* a) {
    auto rtn = original(_this, dbChunkStorageKey, a);
    //if (!rtn) {
    //    auto k = dbChunkStorageKey->toString();
    //}
    return true;
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
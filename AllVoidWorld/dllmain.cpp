// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include "loader/Loader.h"

using namespace std;

void entry() {};

struct DBChunkStorageKey {
    int cx;
    int cy;
    int dimid;
};

THook(bool, "?_hasChunk@DBChunkStorage@@AEAA_NAEBVDBChunkStorageKey@@@Z",
    void* _this, DBChunkStorageKey* key, void* a) {
    auto rtn = original(_this, key, a);
    //if(!rtn)
    //    printf("OnChunkFirstLoaded: (%d, %d) in dim: %d\n", key->cx, key->cy, key->dimid);
    //else
    //    printf("OnChunkLoaded: (%d, %d) in dim: %d\n", key->cx, key->cy, key->dimid);
    return true;
}

THook(bool, "?_hasChunkUncached@DBChunkStorage@@AEAA_NAEBVDBChunkStorageKey@@@Z",
    void* _this, DBChunkStorageKey* key, void* a) {
    auto rtn = original(_this, key, a);
    //if(rtn)
    //    printf("hasChunkUncached: (%d, %d) in dim: %d\n", key->cx, key->cy, key->dimid);
    //else
    //    printf("!hasChunkUncached: (%d, %d) in dim: %d\n", key->cx, key->cy, key->dimid);
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
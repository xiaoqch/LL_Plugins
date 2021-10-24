// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "framework.h"
#include "Config.h"

void entry();

extern "C" _declspec(dllexport) void onPostInit() {
    std::ios::sync_with_stdio(false);
    entry();
    //Logger::Info("{} Loaded, Version: {}", PLUGIN_NAME, VERSION_STRING);
    std::cout << PLUGIN_NAME << " Loaded, Version: " << VERSION_STRING << std::endl;
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
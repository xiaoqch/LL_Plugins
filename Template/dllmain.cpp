// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Config.h"

void entry();

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LL::registerPlugin(PLUGIN_DISPLAY_NAME, PLUGIN_DESCRIPTION, PLUGIN_VERSION_STRING, PLUGIN_WEBSIDE, PLUGIN_LICENCE);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        entry();
        Logger::Info("{} Loaded, Version: {}, Author: {}",PLUGIN_DISPLAY_NAME, PLUGIN_VERSION_STRING, PLUGIN_AUTHOR);
        if (PLUGIN_USAGE)
            Logger::Info("Usage: {}", PLUGIN_USAGE);
    }
}

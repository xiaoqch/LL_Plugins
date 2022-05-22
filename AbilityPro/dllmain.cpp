// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Config.h"

Logger logger(PLUGIN_NAME);

void entry();

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            LL::registerPlugin(PLUGIN_NAME, PLUGIN_INTRODUCTION,
                               LL::Version(
                                   PLUGIN_VERSION_MAJOR,
                                   PLUGIN_VERSION_MINOR,
                                   PLUGIN_VERSION_REVISION,
                                   PLUGIN_LLVERSION_STATUS),
                               {
                                   //{"Git", PLUGIN_WEBSIDE},
                                   //{"License", PLUGIN_LICENCE},
                                   //{"Website", PLUGIN_WEBSIDE},
                                   {"Target LL Version: ", TARGET_LITELOADER_VERSION},
                                   {"Target BDS Version: ", TARGET_BDS_VERSION},
                               });
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

extern "C" {
_declspec(dllexport) void onPostInit()
{
    std::ios::sync_with_stdio(false);
#if PLUGIN_VERSION_STATUS != PLUGIN_VERSION_RELEASE
    logger.warn("This plugin is a beta version and may have bugs");
#endif // DEBUG
    if constexpr (ENABLE_CONFIG)
        Config::initConfig();
    entry();
    logger.info("{} Loaded, Version: {}, Author: {}", PLUGIN_NAME, PLUGIN_FILE_VERSION_STRING, PLUGIN_AUTHOR);
#ifdef PLUGIN_USAGE
    logger.info("Usage: \n{}", PLUGIN_USAGE);
#endif // PLUGIN_USAGE
    if constexpr (ENABLE_LOG_FILE)
        logger.setFile(PLUGIN_LOG_PATH, std::ios::app);
}
}

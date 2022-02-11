// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "Config.h"

Logger logger(PLUGIN_NAME);

void entry();

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LL::registerPlugin(PLUGIN_DISPLAY_NAME, PLUGIN_DESCRIPTION,
            LL::Version(
                PLUGIN_VERSION_MAJOR,
                PLUGIN_VERSION_MINOR,
                PLUGIN_VERSION_REVISION,
                PLUGIN_VERSION_IS_BETA ? LL::Version::Beta : LL::Version::Release
            ), {
                { "Git", PLUGIN_WEBSIDE },
                { "License", PLUGIN_LICENCE },
                { "Website", PLUGIN_LICENCE },
                { "Target LL Version: ", TARGET_LITELOADER_VERSION },
                { "Target BDS Version: ", TARGET_BDS_VERSION },
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
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
#ifdef DEBUG
        logConfig();
#else
        //Set global SEH-Exception handler
        _set_se_translator(seh_exception::TranslateSEHtoCE);
#endif // DEBUG
        entry();
        logger.info("{} Loaded, Version: {}, Author: {}", PLUGIN_DISPLAY_NAME, PLUGIN_VERSION_STRING, PLUGIN_AUTHOR);
        if (PLUGIN_USAGE)
            logger.info("Usage: {}", PLUGIN_USAGE);
        if (ENABLE_LOG_FILE)
            logger.setFile(LOG_PATH, std::ios::app);
    }
}

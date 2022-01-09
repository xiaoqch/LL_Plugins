#pragma once
#include <LoggerAPI.h>

// Plugin Info
#define PLUGIN_NAME "LLFakePlayer"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "Fake Player For LiteLoader"
#define PLUGIN_DESCRIPTION "Fake Player For LiteLoader"
#define PLUGIN_WEBSIDE "https://github.com/xiaoqch/LL_Plugins/" PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"
#define PLUGIN_USAGE R"(
llfakeplayer help - Show this message
llfakeplayer create - Create new fake player
llfakeplayer remove - Remove a fake player forever
llfakeplayer list - List all fake player
llfakeplayer login - Login a existing fake player
llfakeplayer logout - Logout a existing fake player
llfakeplayer gui - Show fake player manage gui)"


// Version
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 0
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_IS_BETA true

#define STR1(R) #R
#define STR2(R) STR1(R)

#if PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_STRING STR2(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION beta)
#else
#define PLUGIN_VERSION_STRING STR2(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION)
#endif // PLUGIN_VERSION_IS_BETA


// Path
#define LOG_DIR "./logs/"
#define PLUGINS_DIR "./plugins/"
#define PLUGIN_DIR PLUGINS_DIR PLUGIN_NAME "/"
#define LOG_PATH LOG_DIR PLUGIN_NAME ".log"
#define CONFIG_PATH PLUGIN_DIR PLUGIN_NAME ".config"
#define DATA_PATH PLUGIN_DIR PLUGIN_NAME ".json"

#if PLUGIN_VERSION_IS_BETA
#define ASSERT(var) if (!(var)) { __debugbreak(); }
#define DEBUG(...) logger.info(__VA_ARGS__)
#define DEBUGW(...) logger.warn(__VA_ARGS__)
#else
#define ASSERT(var) ((void)0)
#define DEBUG(...) ((void)0)
#define DEBUGW(...) ((void)0)
#endif // PLUGIN_VERSION_IS_BETA


#if PLUGIN_VERSION_IS_BETA
#define LOG_VAR(var) logger.debug("{} = {}", #var, var);
inline void logConfig() {
    logger.debug("beta version, log config:");
    LOG_VAR(PLUGIN_NAME);
    LOG_VAR(PLUGIN_AUTHOR);
    LOG_VAR(PLUGIN_DISPLAY_NAME);
    LOG_VAR(PLUGIN_DESCRIPTION);
    LOG_VAR(PLUGIN_WEBSIDE);
    LOG_VAR(PLUGIN_LICENCE);
    LOG_VAR(PLUGIN_USAGE);

    LOG_VAR(LOG_DIR);
    LOG_VAR(PLUGINS_DIR);
    LOG_VAR(PLUGIN_DIR);
    LOG_VAR(LOG_PATH);
    LOG_VAR(DATA_PATH);

    LOG_VAR(PLUGIN_VERSION_STRING);
}

#endif // PLUGIN_VERSION_IS_BETA

// config
namespace Config {

}

#if !PLUGIN_VERSION_IS_BETA
static_assert(PLUGIN_NAME != "Template");
static_assert(PLUGIN_DISPLAY_NAME != "Template");
static_assert(PLUGIN_DESCRIPTION != "Template");
#endif // !PLUGIN_VERSION_IS_BETA


//extern void* fakeSimulatedPlayerVftbl[445];
#pragma once
#include "../Global/GlobalConfig.h"

// Plugin Info
#define PLUGIN_NAME "LLFakePlayer"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "Fake Player For LiteLoader-Test"
#define PLUGIN_DESCRIPTION "Fake Player For LiteLoader-Test"
#define PLUGIN_WEBSIDE GITHUB_LINK PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"
#define PLUGIN_USAGE R"(
llfakeplayer help - Show this message
llfakeplayer create - Create new fake player
llfakeplayer remove - Remove a fake player forever
llfakeplayer list - List all fake player
llfakeplayer login - Login a existing fake player
llfakeplayer logout - Logout a existing fake player
llfakeplayer import - Import data from ddf8196's FakePlayer Client
llfakeplayer gui - Show fake player manage gui
)"

// Version
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 0
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_IS_BETA true

#ifdef DEBUG
#undef PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_IS_BETA true
#endif // DEBUG

// Path
#define PLUGIN_DIR PLUGINS_DIR PLUGIN_NAME "/"
#define PLUGIN_LOG_PATH LOG_DIR PLUGIN_NAME ".log"
#define PLUGIN_CONFIG_PATH PLUGIN_DIR "config.json"
#define PLUGIN_DATA_PATH PLUGIN_DIR "leveldb/"

// Switch
#define ENABLE_LOG_FILE false
#define ENABLE_CONFIG false

namespace Config
{
//inline bool test = true;

bool saveConfig();
bool initConfig();
} // namespace Config

#if PLUGIN_VERSION_IS_BETA
void logBetaInfo();
#endif // !PLUGIN_VERSION_IS_BETA

#if PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_STRING MACRO_TO_STR(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION beta)
#else
#define PLUGIN_VERSION_STRING MACRO_TO_STR(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION)
#endif // PLUGIN_VERSION_IS_BETA

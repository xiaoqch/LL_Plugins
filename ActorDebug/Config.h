#pragma once
#include "../Global/GlobalConfig.h"
#include "Version.h"

#ifdef DEBUG
#undef PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_IS_BETA true
#endif // DEBUG

// Path
#define PLUGIN_DIR PLUGINS_DIR PLUGIN_NAME "/"
#define PLUGIN_LOG_PATH LOG_DIR PLUGIN_NAME ".log"
#define PLUGIN_CONFIG_PATH PLUGIN_DIR "config.json"
#define PLUGIN_DATA_PATH PLUGIN_DIR PLUGIN_NAME ".json"

// Switch
#define ENABLE_LOG_FILE false
#define ENABLE_CONFIG false

#include <MC/Command.hpp>
namespace Config
{
inline bool globalActive = true;
inline std::string commandAlias = "actdbg";
inline CommandPermissionLevel permissionLevel = (CommandPermissionLevel)1;

bool saveConfig();
bool initConfig();
bool switchActivation();
} // namespace Config

#if PLUGIN_VERSION_IS_BETA
void logBetaInfo();
#endif // !PLUGIN_VERSION_IS_BETA

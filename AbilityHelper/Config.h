#pragma once
#include "../Global/GlobalConfig.h"
#include "version.h"

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
#define ENABLE_CONFIG true

enum CommandPermissionLevel;
namespace Config
{
static std::string commandAlias = "abi";
static CommandPermissionLevel permission = (CommandPermissionLevel)1;
static bool fixFlying = true;
static bool fixLoadNbt = true;

bool saveConfig();
bool initConfig();
} // namespace Config

#if PLUGIN_VERSION_IS_BETA
void logBetaInfo();
#endif // !PLUGIN_VERSION_IS_BETA

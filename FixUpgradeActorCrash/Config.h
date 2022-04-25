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
#define ENABLE_LOG_FILE true
#define ENABLE_CONFIG true

namespace Config
{
//static bool test = true;
static size_t SizeThreshold = 1000000;

bool saveConfig();
bool initConfig();
} // namespace Config

#if PLUGIN_VERSION_IS_BETA
void logBetaInfo();
#endif // !PLUGIN_VERSION_IS_BETA

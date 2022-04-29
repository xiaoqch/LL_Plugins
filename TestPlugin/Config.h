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
#define ENABLE_CONFIG false

//#define ENABLE_TEST_AI
//#define ENABLE_TEST_DBSTORAGE
//#define ENABLE_TEST_FAKENAME
//#define ENABLE_TEST_NBT
//#define ENABLE_TEST_COMMAND_REG
//#define ENABLE_TEST_PACKET
//#define ENABLE_TEST_RECIPES
//#define ENABLE_TEST_ENUM
#define ENABLE_TEST_DLSYM


//#define HOOK_CLASS_SimulatedPlayer
//#define HOOK_CLASS_Actor
//#define HOOK_CLASS_Mob
//#define HOOK_CLASS_Player
//#define HOOK_CLASS_ServerPlayer

//#define HOOK_CLASS_DBStorage
//#define HOOK_CLASS_LevelStorage

namespace Config
{
//inline bool test = true;

bool saveConfig();
bool initConfig();
} // namespace Config

#if PLUGIN_VERSION_IS_BETA
void logBetaInfo();
#endif // !PLUGIN_VERSION_IS_BETA

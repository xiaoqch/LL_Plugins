#pragma once
#include "../Global/GlobalConfig.h"

// Plugin Info
#define PLUGIN_NAME "OperationAgent"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "Operation Agent"
#define PLUGIN_DESCRIPTION "Operation Agent"
#define PLUGIN_WEBSIDE GITHUB_LINK PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"
#define PLUGIN_USAGE false

const std::string HELP_TEXT_FOR_PLAYER = "\
[操作代理] 帮助\n\
注：方括号为可选参数，默认值为当前玩家\n\
opagent help                      // 显示帮助信息\n\
opagent set 被代理实体 [操作实体] // 设置操作代理\n\
opagent list                      // 列出当前代理设置，格式：操作实体 -> 被代理实体\n\
opagent clear [操作实体]          // 清除某（些）实体的代理设置\n\
opagent clearall                  // 清除所有实体的代理设置，效果同opagent clear @e";
const std::string HELP_TEXT = "\
[操作代理] 帮助\n\
注：方括号为可选参数，默认值为当前玩家\n\
opagent set 被代理实体 [操作实体] - 设置代理\n\
opagent list - 列出当前代理\n\
opagent clear [操作实体] - 清除代理\n\
opagent clearall - 清除所有\n\
";

// Version
#define PLUGIN_VERSION_MAJOR 1
#define PLUGIN_VERSION_MINOR 2
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_IS_BETA false

#ifdef DEBUG
#undef PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_IS_BETA true
#endif // DEBUG

// Path
#define PLUGIN_DIR PLUGINS_DIR PLUGIN_NAME "/"
#define PLUGIN_LOG_PATH LOG_DIR PLUGIN_NAME ".log"
#define PLUGIN_CONFIG_PATH PLUGIN_DIR "config.json"
#define PLUGIN_DATA_PATH PLUGIN_DIR "data.json"

// Switch
#define ENABLE_LOG_FILE false
#define ENABLE_CONFIG true

namespace Config
{
static bool autoClean = true;
static bool cancelAfterSleep = true;
static bool cancelAfterRide = true;
static bool autoSleep = true;
static bool autoRideWhenJoin = true;
static bool useNewProjectMode = false;
static bool forProjectile = true;
static bool forAttack = true;
static bool forSleep = true;
//static bool forMove = false;
static bool forRide = true;
static bool autoSwapAttack = true;


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

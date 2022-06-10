#pragma once
#include <LoggerAPI.h>
#include <third-party/magic_enum/magic_enum.hpp>
// Global Info
#define TARGET_BDS_VERSION "1.19.1.01"
#define TARGET_LITELOADER_VERSION "2.3.0"
#define TARGET_PROTOCOL_VERSION 526
#define GITHUB_LINK "https://github.com/xiaoqch/LL_Plugins/"

#define PLUGIN_WEBSIDE GITHUB_LINK PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"

// Path
#define LOG_DIR "./logs/"
#define PLUGINS_DIR "./plugins/"

// Transfer macro to string
#define __MACRO_TO_STR(str) #str
#define MACRO_TO_STR(str) __MACRO_TO_STR(str)


// Tools
#include "DebugHelper.h"

// Global logger
extern Logger logger;
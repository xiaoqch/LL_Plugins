#pragma once
#include <third-party/magic_enum/magic_enum.hpp>
#include <LoggerAPI.h>
#include <Utils/FileHelper.h>

// Global Info
#define TARGET_BDS_VERSION "1.19.10.03"
#define TARGET_LITELOADER_VERSION "2.4.0"
#define TARGET_PROTOCOL_VERSION 534
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
extern class Logger logger;

#pragma once
#include <LoggerAPI.h>
#include <third-party/magic_enum/magic_enum.hpp>
// Global Info
#define TARGET_BDS_VERSION "1.18.33.02"
#define TARGET_LITELOADER_VERSION "2.2.5"
#define GITHUB_LINK "https://github.com/xiaoqch/LL_Plugins/"

// Path
#define LOG_DIR "./logs/"
#define PLUGINS_DIR "./plugins/"

// Transfer macro to string
#define __MACRO_TO_STR(str) #str
#define MACRO_TO_STR(str) __MACRO_TO_STR(str)


// Tools
#include "DlsymStatic.h"
#include "DebugHelper.h"

// Global logger
extern Logger logger;
#pragma once
#include <string>

//#define PLUGIN_DEV_MODE

// Plugin Name
#define PLUGIN_NAME "LLTemplate"

// Path
#define LOG_DIR "./logs/"
#define PLUGINS_DIR "./plugins/"
#define PLUGIN_DIR PLUGINS_DIR PLUGIN_NAME "/"
#define LOG_PATH LOG_DIR PLUGIN_NAME ".log"
#define CONFIG_PATH PLUGIN_DIR PLUGIN_NAME ".config"
#define DATA_PATH PLUGIN_DIR PLUGIN_NAME ".json"


// Version
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_REVISION 1
#define VERSION_IS_BETA true

#define VERSION_STRING getVersionString()

inline std::string getVersionString() {
    return std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR) + "." + std::to_string(VERSION_REVISION) + (VERSION_IS_BETA ? " beta" : "");
}

#ifdef PLUGIN_DEV_MODE
#define LOG_VAR(var) std::cout << #var << ": " << var << std::endl;
inline void logConfig() {
    LOG_VAR(LOG_DIR);
    LOG_VAR(PLUGINS_DIR);
    LOG_VAR(PLUGIN_DIR);
    LOG_VAR(LOG_PATH);
    LOG_VAR(DATA_PATH);
    LOG_VAR(VERSION_STRING);
}
#endif // PLUGIN_DEV_MODE

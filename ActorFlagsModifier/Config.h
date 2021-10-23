#pragma once
#include <string>

// Plugin Name
#define PLUGIN_NAME "LL TEMPLATE"

// Version
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_REVISION 1
#define VERSION_IS_BETA true

// whether enable logger
//#define ENABLE_LOGGER

// whether generate ActorFlags.h
//#define GEN_ACTOR_FLAGS

inline std::string getVersionString() {
    return std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR) + "." + std::to_string(VERSION_REVISION) + (VERSION_IS_BETA ? " beta" : "");
}
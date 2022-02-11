#pragma once
#include <LoggerAPI.h>

// Plugin Info
#define PLUGIN_NAME "LLStructure"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "LL Structure"
#define PLUGIN_DESCRIPTION "LiteLoader Structure Helper"
#define PLUGIN_WEBSIDE "https://github.com/xiaoqch/LL_Plugins/" PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"
#define PLUGIN_USAGE false


// Version
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 0
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_IS_BETA true

#ifdef DEBUG
#undef PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_IS_BETA true
#endif // DEBUG

#define STR1(R) #R
#define STR2(R) STR1(R)

#if PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_STRING STR2(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION beta)
#else
#define PLUGIN_VERSION_STRING STR2(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_REVISION)
#endif // PLUGIN_VERSION_IS_BETA


// Path
#define LOG_DIR "./logs/"
#define PLUGINS_DIR "./plugins/"
#define PLUGIN_DIR PLUGINS_DIR PLUGIN_NAME "/"
#define PLUGIN_LOG_PATH LOG_DIR PLUGIN_NAME ".log"
#define PLUGIN_CONFIG_PATH PLUGIN_DIR "config.json"
#define PLUGIN_DATA_PATH PLUGIN_DIR PLUGIN_NAME ".json"

#if PLUGIN_VERSION_IS_BETA
inline void logConfig() {
    logger.debug("beta version, log config:");
    LOG_VAR(PLUGIN_NAME);
    LOG_VAR(PLUGIN_AUTHOR);
    LOG_VAR(PLUGIN_DISPLAY_NAME);
    LOG_VAR(PLUGIN_DESCRIPTION);
    LOG_VAR(PLUGIN_WEBSIDE);
    LOG_VAR(PLUGIN_LICENCE);
    LOG_VAR(PLUGIN_USAGE);

    LOG_VAR(LOG_DIR);
    LOG_VAR(PLUGINS_DIR);
    LOG_VAR(PLUGIN_DIR);
    LOG_VAR(PLUGIN_LOG_PATH);
    LOG_VAR(PLUGIN_DATA_PATH);

    LOG_VAR(PLUGIN_VERSION_STRING);
}

#endif // PLUGIN_VERSION_IS_BETA

// Config
#include <third-party/Nlohmann/json.hpp>
#include <filesystem>
#define SerializeVaule(var) json[#var] = Config::var
#define DeserializeVaule(var)\
if (json.find(#var) != json.end())\
    Config::var = json.value(#var, Config::var);\
else{\
    logger.warn("Missing Config {}, use default value {}", #var, Config::var);\
    needUpdate = true;\
}

namespace Config {
    //static bool test = true;

    inline std::string serialize() {
        nlohmann::json json;
        //SerializeVaule(test);
        return json.dump(4);
    }
    inline bool deserialize(std::string jsonStr) {
        auto json = nlohmann::json::parse(jsonStr, nullptr, true, true);
        bool needUpdate = false;
        //DeserializeVaule(test);

        if (needUpdate) {
            WriteAllFile(PLUGIN_CONFIG_PATH, serialize(), false);
        }
        return true;
    }
    inline bool initConfig() {
        auto jsonStr = ReadAllFile(PLUGIN_CONFIG_PATH);
        if (jsonStr.has_value()) {
            return deserialize(jsonStr.value());
        }
        else {
            logger.warn("Config File \"{}\" Not Found, Use Default Config", PLUGIN_CONFIG_PATH);
            std::filesystem::create_directories(std::filesystem::path(PLUGIN_CONFIG_PATH).remove_filename());
            return WriteAllFile(PLUGIN_CONFIG_PATH, serialize(), false);
        }
        return false;
    };
}

#if !PLUGIN_VERSION_IS_BETA
static_assert(PLUGIN_NAME != "Template");
static_assert(PLUGIN_DISPLAY_NAME != "Template");
static_assert(PLUGIN_DESCRIPTION != "Template");
#endif // !PLUGIN_VERSION_IS_BETA

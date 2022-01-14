#pragma once
#include <LoggerAPI.h>

// Plugin Info
#define PLUGIN_NAME "OperationAgent"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "Operation Agent"
#define PLUGIN_DESCRIPTION "Operation Agent"
#define PLUGIN_WEBSIDE "https://github.com/xiaoqch/LL_Plugins/" PLUGIN_NAME
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
#define PLUGIN_VERSION_REVISION 0
#define PLUGIN_VERSION_IS_BETA false

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
#define PLUGIN_DATA_PATH PLUGIN_DIR "data.json"

#define ENABLE_LOG_FILE false

#if PLUGIN_VERSION_IS_BETA
#define LOG_VAR(var) logger.debug("{} = {}", #var, var);
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
    LOG_VAR(PLUGIN_CONFIG_PATH);
    LOG_VAR(PLUGIN_DATA_PATH);

    LOG_VAR(PLUGIN_VERSION_STRING);
}

#endif // PLUGIN_VERSION_IS_BETA

// config
#include <third-party/Nlohmann/json.hpp>

#define SerializeVaule(var) json[#var] = Config::var
#define DeserializeVaule(var)\
if (json.find(#var) != json.end())\
    Config::var = json.value(#var, Config::var);\
else{\
    logger.warn("Missing Config {}, use default value {}", #var, Config::var);\
    needUpdate = true;\
}

namespace Config {
    static bool autoClean = true;
    static bool cancelAfterSleep = true;
    static bool cancelAfterRide = true;
    static bool autoSleep = true;
    static bool autoRideWhenJoin = true;
    static bool useNewProjectMode = false;
    static bool forProjectile = true;
    static bool forAttack = true;
    static bool forSleep = true;
    static bool forMove = false;
    static bool forRide = true;

    inline std::string serialize() {
        nlohmann::json json;
        SerializeVaule(autoClean);
        SerializeVaule(cancelAfterSleep);
        SerializeVaule(cancelAfterRide);
        SerializeVaule(autoSleep);
        SerializeVaule(autoRideWhenJoin);
        SerializeVaule(useNewProjectMode);
        SerializeVaule(forProjectile);
        SerializeVaule(forAttack);
        SerializeVaule(forSleep);
        SerializeVaule(forMove);
        SerializeVaule(forRide);
        return json.dump(4);
    }
    inline bool deserialize(std::string jsonStr) {
        auto json = nlohmann::json::parse(jsonStr, nullptr, true, true);
        bool needUpdate=false;
        DeserializeVaule(autoClean);
        DeserializeVaule(cancelAfterSleep);
        DeserializeVaule(cancelAfterRide);
        DeserializeVaule(autoSleep);
        DeserializeVaule(autoRideWhenJoin);
        DeserializeVaule(useNewProjectMode);
        DeserializeVaule(forProjectile);
        DeserializeVaule(forAttack);
        DeserializeVaule(forSleep);
        DeserializeVaule(forMove);
        DeserializeVaule(forRide);

        if (needUpdate) {
            auto jsonStr = serialize();
            WriteAllFile(PLUGIN_CONFIG_PATH, jsonStr, false);
        }
        return true;
    }
    inline bool initConfig() {
        auto jsonStr = ReadAllFile(PLUGIN_CONFIG_PATH);
        if (jsonStr.has_value()) {
            return deserialize(jsonStr.value());
        }
        return false;
    };
}

#if !PLUGIN_VERSION_IS_BETA
static_assert(PLUGIN_NAME != "Template");
static_assert(PLUGIN_DISPLAY_NAME != "Template");
static_assert(PLUGIN_DESCRIPTION != "Template");
#endif // !PLUGIN_VERSION_IS_BETA

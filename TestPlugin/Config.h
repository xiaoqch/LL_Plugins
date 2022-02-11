#pragma once

//#define ENABLE_TEST_AI
//#define ENABLE_TEST_DBSTORAGE
//#define ENABLE_TEST_FAKENAME
#define ENABLE_TEST_NBT
//#define ENABLE_TEST_PACKET
//#define ENABLE_TEST_RECIPES
//#define ENABLE_TEST_ENUM
//#define ENABLE_TEST_DLSYM


// Plugin Info
#define PLUGIN_NAME "TestPlugin"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "Test Plugin"
#define PLUGIN_DESCRIPTION "Test LiteLoader Plugin"
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


#define LOG_VAR(var) logger.warn("{} = {}", #var, var);
#if PLUGIN_VERSION_IS_BETA
inline void logConfig()
{
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

#if PLUGIN_VERSION_IS_BETA
#define DEBUGL(...) logger.info(__VA_ARGS__)
#define DEBUGW(...) logger.warn(__VA_ARGS__)
#else
#define ASSERT(var) ((void)0)
#define DEBUGL(...) ((void)0)
#define DEBUGW(...) ((void)0)
#endif // PLUGIN_VERSION_IS_BETA

// Config
#include <third-party/Nlohmann/json.hpp>
#include <filesystem>
#define SerializeVaule(var) json[#var] = Config::var
#define SerializeEnumVaule(var) json[#var] = magic_enum::enum_name(Config::var)

#define DeserializeVaule(var)                                                         \
    if (json.find(#var) != json.end())                                                \
    {                                                                                 \
        Config::var = json.value(#var, Config::var);                                  \
    }                                                                                 \
    else                                                                              \
    {                                                                                 \
        logger.info("Missing config {}, use default value ", #var /*, Config::var*/); \
        needUpdate = true;                                                            \
    }

#define DeserializeEnumVaule(var)                                            \
    if (json.find(#var) != json.end())                                       \
    {                                                                        \
        auto svar = magic_enum::enum_name(Config::var);                      \
        svar = json.value(#var, svar);                                       \
        auto enumValue = magic_enum::enum_cast<decltype(Config::var)>(svar); \
        if (enumValue.has_value())                                           \
            Config::var = enumValue.value();                                 \
        else                                                                 \
        {                                                                    \
            logger.warn("Unsupported config value {}, use default value {}", \
                        svar, magic_enum::enum_name(Config::var));           \
            needUpdate = true;                                               \
        }                                                                    \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        logger.warn("Missing config {}, use default value {}",               \
                    #var, magic_enum::enum_name(Config::var));               \
        needUpdate = true;                                                   \
    }

namespace Config
{
//static bool test = true;

inline std::string serialize()
{
    nlohmann::json json;

    //SerializeVaule(test);

    return json.dump(4);
}
inline bool deserialize(std::string jsonStr)
{
    auto json = nlohmann::json::parse(jsonStr, nullptr, false, true);
    bool needUpdate = false;

    //DeserializeVaule(test);

    return !needUpdate;
}
inline bool saveConfig()
{
    return WriteAllFile(PLUGIN_CONFIG_PATH, serialize(), false);
}
inline bool initConfig()
{
    bool res = false;
    auto jsonStr = ReadAllFile(PLUGIN_CONFIG_PATH);
    if (jsonStr.has_value())
    {
        try
        {
            res = deserialize(jsonStr.value());
        }
        catch (const std::exception&)
        {
            logger.error("Error in loading config file \"{}\", Use default config", PLUGIN_CONFIG_PATH);
            res = false;
        }
    }
    else
    {
        logger.info("Config File \"{}\" Not Found, Use Default Config", PLUGIN_CONFIG_PATH);
        std::filesystem::create_directories(std::filesystem::path(PLUGIN_CONFIG_PATH).remove_filename());
    }
    if (!res)
        res = saveConfig();
    return res;
};
} // namespace Config

#if !PLUGIN_VERSION_IS_BETA
static_assert(PLUGIN_NAME != "Template");
static_assert(PLUGIN_DISPLAY_NAME != "Template");
static_assert(PLUGIN_DESCRIPTION != "Template");
#endif // !PLUGIN_VERSION_IS_BETA

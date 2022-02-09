#pragma once
#include <LoggerAPI.h>

// Plugin Info
#define PLUGIN_NAME "LLFakePlayer-Test"
#define PLUGIN_AUTHOR "xiaoqch"
#define PLUGIN_DISPLAY_NAME "Fake Player For LiteLoader-Test"
#define PLUGIN_DESCRIPTION "Fake Player For LiteLoader-Test"
#define PLUGIN_WEBSIDE "https://github.com/xiaoqch/LL_Plugins/" PLUGIN_NAME
#define PLUGIN_LICENCE "GPLv3"
#define PLUGIN_USAGE R"(
llfakeplayer help - Show this message
llfakeplayer create - Create new fake player
llfakeplayer remove - Remove a fake player forever
llfakeplayer list - List all fake player
llfakeplayer login - Login a existing fake player
llfakeplayer logout - Logout a existing fake player
llfakeplayer import - Import data from ddf8196's FakePlayer Client
llfakeplayer gui - Show fake player manage gui
)"


// Version
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 0
#define PLUGIN_VERSION_REVISION 1
#define PLUGIN_VERSION_IS_BETA true

#ifdef PLUGIN_DEV_MODE
#undef PLUGIN_VERSION_IS_BETA
#define PLUGIN_VERSION_IS_BETA true
#endif // PLUGIN_DEV_MODE

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
#define PLUGIN_DATA_PATH PLUGIN_DIR "leveldb/"

#if PLUGIN_VERSION_IS_BETA
#define ASSERT(var) \
    if (!(var)) { __debugbreak(); }
#define DEBUGL(...) logger.info(__VA_ARGS__)
#define DEBUGW(...) logger.warn(__VA_ARGS__)
#else
#define ASSERT(var) ((void)0)
#define DEBUGL(...) ((void)0)
#define DEBUGW(...) ((void)0)
#endif // PLUGIN_VERSION_IS_BETA


#if PLUGIN_VERSION_IS_BETA
#define LOG_VAR(var) logger.debug("{} = {}", #var, var);
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

// Config
#include <third-party/Nlohmann/json.hpp>
#include <filesystem>
#define SerializeVaule(var) json[#var] = Config::var
#define DeserializeVaule(var)                                                      \
    if (json.find(#var) != json.end())                                             \
        Config::var = json.value(#var, Config::var);                               \
    else                                                                           \
    {                                                                              \
        logger.warn("Missing Config {}, use default value {}", #var, Config::var); \
        needUpdate = true;                                                         \
    }

namespace Config
{


inline std::string serialize()
{
    nlohmann::json json;
    //SerializeVaule(test);
    return json.dump(4);
}
inline bool deserialize(std::string jsonStr)
{
    auto json = nlohmann::json::parse(jsonStr, nullptr, true, true);
    bool needUpdate = false;
    //DeserializeVaule(test);

    if (needUpdate)
    {
        WriteAllFile(PLUGIN_CONFIG_PATH, serialize(), false);
    }
    return true;
}
inline bool initConfig()
{
    auto jsonStr = ReadAllFile(PLUGIN_CONFIG_PATH);
    if (jsonStr.has_value())
    {
        return deserialize(jsonStr.value());
    }
    else
    {
        logger.warn("Config File \"{}\" Not Found, Use Default Config", PLUGIN_CONFIG_PATH);
        std::filesystem::create_directories(std::filesystem::path(PLUGIN_CONFIG_PATH).remove_filename());
        return WriteAllFile(PLUGIN_CONFIG_PATH, serialize(), false);
    }
    return false;
};
} // namespace Config

#if !PLUGIN_VERSION_IS_BETA
static_assert(PLUGIN_NAME != "Template");
static_assert(PLUGIN_DISPLAY_NAME != "Template");
static_assert(PLUGIN_DESCRIPTION != "Template");
#endif // !PLUGIN_VERSION_IS_BETA


//extern void* fakeSimulatedPlayerVftbl[445];
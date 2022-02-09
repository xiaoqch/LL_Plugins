#include "pch.h"

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

bool globalActive = true;
std::string commandAlias = "actdbg";
CommandPermissionLevel permissionLevel = CommandPermissionLevel::GameMasters;

std::string serialize()
{
    nlohmann::json json;

    SerializeVaule(globalActive);
    SerializeVaule(commandAlias);
    SerializeEnumVaule(permissionLevel);

    return json.dump(4);
}

bool deserialize(std::string jsonStr)
{
    auto json = nlohmann::json::parse(jsonStr, nullptr, false, true);
    bool needUpdate = false;

    DeserializeVaule(globalActive);
    DeserializeVaule(commandAlias);
    DeserializeEnumVaule(permissionLevel);

    return !needUpdate;
}

bool saveConfig()
{
    return WriteAllFile(PLUGIN_CONFIG_PATH, serialize(), false);
}

bool initConfig()
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
}

bool switchActivation()
{
    globalActive = !globalActive;
    saveConfig();
    return globalActive;
}

} // namespace Config

#if PLUGIN_VERSION_IS_BETA
void logConfig()
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
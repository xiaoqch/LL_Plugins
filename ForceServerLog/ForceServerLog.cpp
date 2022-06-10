#include "pch.h"
#include <MC/ContentLog.hpp>
#include <EventAPI.h>

void entry()
{
#ifdef PRINT_ENUM
    Event::ServerStartedEvent::subscribe([](Event::ServerStartedEvent const& ev) {
        auto unk = (__int64)dlsym("?gAssertTelemetryRegistered@DebugUtils@@3_NA");
        auto gAreaFilterMap = (std::map<std::string, unsigned int>*)(unk + 8);
        for (auto& [name, area] : *gAreaFilterMap)
        {
            logger.info("{} = {},", name, (int)area);
        }
        auto gPriorityFilterMap = (std::map<std::string, unsigned int>*)(unk + 24);
        for (auto& [name, priority] : *gPriorityFilterMap)
        {
            logger.info("{} = {},", name, (int)priority);
        }
        return true;
    });
#endif // DEBUG
}

namespace
{
bool enable = true;
//ContentLog* globalContentLog;
} // namespace

#pragma region ContentLog

//THook(ContentLog*, "??0ContentLog@@QEAA@XZ", ContentLog* _this)
//{
//    auto rtn = original(std::forward<ContentLog*>(_this));
//    if (enable)
//    {
//        globalContentLog = _this;
//        dAccess<bool>(_this, 24) = true;
//    }
//    return std::forward<ContentLog*>(rtn);
//}
enum class FakeLogLevel
{
    Inform,
    Warning,
    Error,
};
TInstanceHook(void, "?updateEnabledStatus@ContentLog@@QEAAXXZ", ContentLog)
{
    if (!enable)
        return original(this);
    dAccess<bool>(this, 24) = true;
    //_this->log(true, LogLevel::Warning, (LogArea)2, "test %s %d %.2f %s", "arg1", 2, 3.4, "arg4");
}

TInstanceHook(void, "?log@ContentLog@@QEAAX_NW4LogLevel@@W4LogArea@@ZZ",
      ContentLog, bool a1, enum FakeLogLevel level, enum LogArea area, char const* format, ...)
{
    if (enable)
    {
        char buf[1024];
        va_list ap;
        va_start(ap, format);

        vsprintf_s(buf, 1024, format, ap);

        va_end(ap);
        switch (level)
        {
            case FakeLogLevel::Inform:
                logger.info("{} : {}", ContentLog::getLogAreaName(area), buf);
                break;
            case FakeLogLevel::Warning:
                logger.warn("{} : {}", ContentLog::getLogAreaName(area), buf);
                break;
            case FakeLogLevel::Error:
                logger.error("{} : {}", ContentLog::getLogAreaName(area), buf);
                break;
            default:
                logger.fatal("{} : {}", ContentLog::getLogAreaName(area), buf);
                break;
        }
    }
    else
    {
    }
}

#pragma endregion

#pragma region ItemTransactionLogger

Logger itemLogger("Item");
THook(void, "?initializeLogger@ItemTransactionLogger@@YAX_N@Z",
      bool unable)
{
    return original(true);
}
THook(void, "?log@ItemTransactionLogger@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
      std::string const str)
{
    if (str._Starts_with("ActorEventCoordinator"))
        return;
    itemLogger.info(str);
}

#pragma endregion


#pragma region BedrockLog

constexpr auto ERROR_BAK = ERROR;
#undef ERROR
enum class FakeLogAreaID
{
    ALL = 0,
    ANIMATION = 9,
    ASSETPACKAGES = 34,
    AUTOMATION = 31,
    BLOCKS = 24,
    DATABASE = 3,
    DLC = 13,
    ENTITY = 2,
    FILE = 15,
    GAMEFACE = 26,
    GUI = 4,
    INPUT = 10,
    INTERACTIVE = 28,
    ITEMS = 35,
    LEVEL = 11,
    LOCALIZATION = 40,
    LOOTTABLE = 38,
    MEMORY = 8,
    MOVEMENT = 41,
    NETWORK = 6,
    PERF = 22,
    PERSONA = 32,
    PHYSICS = 14,
    PLATFORM = 1,
    PLAYFAB = 30,
    RAKNET = 25,
    REALMS = 17,
    REALMSAPI = 18,
    RENDER = 7,
    SCRIPTING = 29,
    SERVER = 12,
    SERVICES = 36,
    SIDEBAR = 39,
    SOUND = 27,
    STORAGE = 16,
    SYSTEM = 5,
    TELEMETRY = 23,
    TEXTURE = 33,
    UNKNOWN = 42,
    USERMANAGER = 20,
    VOLUMES = 37,
    XBOXLIVE = 19,
    XSAPI = 21,
};
enum class FakeLogPriority
{
    ALL = -1,
    ERROR = 8,
    INFO = 2,
    UNKNOWN = 0x40000000,
    VERBOSE = 1,
    WARN = 4,
};

#include <MC/BedrockLog.hpp>
THook(void, "?log_va@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4PEAD@Z",
      enum BedrockLog::LogCategory category, class std::bitset<3> bset, enum BedrockLog::LogRule rule,
      FakeLogAreaID areaID, FakeLogPriority priority, char const* funcName, int messageId, char const* format, va_list args)
{
    //auto unk = dlsym("?gBreakpadSetupFailed@DebugUtils@@3_NA");
    char buf[1024];
    auto size = vsprintf_s(buf, format, args);
    if (size >= 1 && buf[size - 1] == '\n')
        buf[size - 1] = '\0';
    Logger::OutputStream* log = &logger.info;
    switch (priority)
    {
        case FakeLogPriority::ALL:
            break;
        case FakeLogPriority::ERROR:
            log = &logger.error;
            break;
        case FakeLogPriority::INFO:
            break;
        case FakeLogPriority::UNKNOWN:
            break;
        case FakeLogPriority::VERBOSE:
            break;
        case FakeLogPriority::WARN:
            log = &logger.warn;
            break;
        default:
            break;
    }
    auto content = string(buf);
    auto str = fmt::format("[{}] {}{}", magic_enum::enum_name(areaID), content._Starts_with(funcName) ? "" : string(funcName) + " - ", content);
    if (str.find('{') == str.find('}'))
        logger.info << str << logger.endl;
    else
        original(category, bset, rule, areaID, priority, funcName, messageId, format, args);
}
static_assert(magic_enum::enum_name(FakeLogAreaID::ANIMATION) == "ANIMATION");

THook(bool, "?updateLogSetting@BedrockLog@@YAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z",
      std::string const& str, bool b)
{
    logger.info("BedrockLog::updateLogSetting({}, {})", str, b);
    b = true;
    auto rtn = original(str, b);
    logger.info("BedrockLog::updateLogSetting({}, {}) -> {}", str, b, rtn);
    return true;
}
THook(void, "?updateLogFilter@BedrockLog@@YAXV?$unique_ptr@VLogSettingsUpdater@@U?$default_delete@VLogSettingsUpdater@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@3@AEAV43@_N@Z",
      class LogSettingsUpdater** updater, std::string const& str, std::vector<std::string>& strs, std::string& str2, bool b)
{
    logger.info("BedrockLog::updateLogFilter({}, {})", str, b);
    auto a = strs.size();
    strs = {"ALL"};
    original(std::move(updater), str, strs, str2, false);
}
#define ERROR ERROR_BAK

#pragma endregion
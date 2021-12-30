#include "pch.h"
#include <MC/ContentLog.hpp>

ContentLog* globalContentLog;
bool enable = false;
THook(ContentLog*, "??0ContentLog@@QEAA@XZ", ContentLog* _this) {
    auto rtn = original(std::forward<ContentLog*>(_this));
    if (enable) {
        globalContentLog = _this;
        dAccess<bool>(_this, 24) = true;
    }
    return std::forward<ContentLog*>(rtn);
}
enum LogLevel {
    Inform,
    Warning,
    Error,
};
THook(void, "?updateEnabledStatus@ContentLog@@QEAAXXZ", ContentLog* _this) {
    if (!enable)
        return original(_this);
    dAccess<bool>(_this, 24) = true;
    _this->log(true, LogLevel::Warning, (LogArea)2, "test %s %d %.2f %s", "arg1", 2, 3.4, "arg4");
}

THook(void, "?log@ContentLog@@QEAAX_NW4LogLevel@@W4LogArea@@ZZ",
    ContentLog* _this, bool a1, enum LogLevel level, enum LogArea area, char const* format, ...) {
    if (enable) {
        char buf[1024];
        va_list ap;
        va_start(ap, format);

        vsprintf_s(buf, 1024, format, ap);

        va_end(ap);
        switch (level)
        {
        case Inform:
            logger.info("{} : {}", ContentLog::getLogAreaName(area), buf);
            break;
        case Warning:
            logger.warn("{} : {}", ContentLog::getLogAreaName(area), buf);
            break;
        case Error:
            logger.error("{} : {}", ContentLog::getLogAreaName(area), buf);
            break;
        default:
            logger.fatal("{} : {}", ContentLog::getLogAreaName(area), buf);
            break;
        }
    }
    else {

    }
}

Logger itemLogger("Item");
THook(void, "?log@ItemTransactionLogger@@YAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z",
    std::string const str) {
    itemLogger.info(str);
}
void entry() {

}
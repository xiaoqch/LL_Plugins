#include "pch.h"
#include <EventAPI.h>
#include <RemoteCallAPI.h>
#include <ScheduleAPI.h>

namespace
{
template <typename S, typename... Args, enable_if_type<(fmt::v8::detail::is_string<S>::value), int> = 0>
void success(const S& formatStr, const Args&... args)
{
    if constexpr (0 == sizeof...(args))
        logger.info << "\x1b[38;2;085;255;085m" << formatStr << "\x1b[0m" << logger.endl;
    else
    {
        std::string str = fmt::format(formatStr, args...);
        logger.info << "\x1b[38;2;085;255;085m" << str << "\x1b[0m" << logger.endl;
    }
}

template <typename... Args>
void success(const char* formatStr, const Args&... args)
{
    if constexpr (0 == sizeof...(args))
        logger.info << "\x1b[38;2;085;255;085m" << formatStr << "\x1b[0m" << logger.endl;
    else
    {
        std::string str = fmt::format(formatStr, args...);
        logger.info << "\x1b[38;2;085;255;085m" << str << "\x1b[0m" << logger.endl;
    }
}
template <typename S, typename... Args>
void error(S formatStr, const Args&... args)
{
    logger.error(formatStr, args...);
}
} // namespace

std::string TestRemoteCall(std::string const& from)
{
    logger.warn("Print By LL: {}", from);
    return "Data From LL";
}
#define EXPORT_NAMESPACE "TestRemoteCall"
void entry()
{
    RemoteCall::exportAs(EXPORT_NAMESPACE, "LLFunc", TestRemoteCall);
    Schedule::delay(
        []() {
            auto JsFunc = RemoteCall::importAs<decltype(TestRemoteCall)>(EXPORT_NAMESPACE, "JsFunc");
            logger.info("Call Remote Function LL -> js_export");
            auto jsRes = JsFunc("DataFromLL");
            if (!jsRes.empty())
                success("Call Remote Js Function Success -> {}", jsRes);
            else
                error("Call Remote Js Function Failed -> {}", jsRes);
            auto LuaFunc = RemoteCall::importAs<decltype(TestRemoteCall)>(EXPORT_NAMESPACE, "LuaFunc");
            logger.info("Call Remote Function LL -> lua_export");
            auto luaRes = LuaFunc("DataFromLL");
            if (!luaRes.empty())
                success("Call Remote Lua Function Success -> {}", luaRes);
            else
                error("Call Remote Lua Function Failed -> {}", luaRes);
        },
        20);
}

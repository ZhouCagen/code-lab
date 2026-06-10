#pragma once

#include <string_view>
namespace coreLog
{

    enum class LogLevel
    {
        Trace = 0,
        Debug,
        Info,
        Warning,
        Error,
        Fatal
    };

    std::string_view levelToString(LogLevel level);

} // namespace coreLog

#include "coreLog/LogLevel.hpp"

namespace coreLog
{
    std::string_view levelToString(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::Trace:
                return "TRACE";
            case LogLevel::Debug:
                return "DEBUG";
            case LogLevel::Info:
                return "INFO";
            case LogLevel::Warning:
                return "WARNING";
            case LogLevel::Error:
                return "ERROR";
            case LogLevel::Fatal:
                return "FATAL";
            default:
                return "UNKNOWN";
        }
    }

} // namespace coreLog

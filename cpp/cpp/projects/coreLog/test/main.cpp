#include "coreLog/LogLevel.hpp"
#include <iostream>
int main()
{
    std::cout << coreLog::levelToString(coreLog::LogLevel::Trace) << '\n';
    std::cout << coreLog::levelToString(coreLog::LogLevel::Debug) << '\n';
    std::cout << coreLog::levelToString(coreLog::LogLevel::Info) << '\n';
    std::cout << coreLog::levelToString(coreLog::LogLevel::Warning) << '\n';
    std::cout << coreLog::levelToString(coreLog::LogLevel::Error) << '\n';
    std::cout << coreLog::levelToString(coreLog::LogLevel::Fatal) << '\n';
    return 0;
}

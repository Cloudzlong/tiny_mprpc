#pragma once
#include <string>
#include "lockqueue.h"

enum LogLevel
{
    INFO, //普通日志信息
    ERROR //错误信息
};

class Logger
{
public:
    static Logger &GetInstance();
    void StLogLevel(LogLevel level);
    void Log(std::string msg);

private:
    LogLevel m_loglevel;
    LockQueue<std::pair<std::string, LogLevel>> m_lockQueue;

    Logger();
    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
};

#define LOG_INFO(logmsgformat, ...)                     \
    do                                                  \
    {                                                   \
        Logger &logger = Logger::GetInstance();         \
        logger.StLogLevel(INFO);                        \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0)

#define LOG_ERR(logmsgformat, ...)                      \
    do                                                  \
    {                                                   \
        Logger &logger = Logger::GetInstance();         \
        logger.StLogLevel(ERROR);                       \
        char c[1024] = {0};                             \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger.Log(c);                                  \
    } while (0)

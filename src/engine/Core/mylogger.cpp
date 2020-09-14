//
// Created by jared on 9/10/20.
//

#include <vector>
#include <cstdio>
#include "Core/mylogger.h"
#include <mutex>
namespace PHYSZY
{
    static std::mutex critical;
    static void printLogInfo(std::stringstream *_buffer)
    {
        std::lock_guard<std::mutex> lock(critical);
        std::cout << _buffer->str() << std::endl;
        std::cout.flush();
    }
    static void printLogWarn(std::stringstream *_buffer)
    {
        std::lock_guard<std::mutex> lock(critical);
        std::cout << _buffer->str() << std::endl;
        std::cout.flush();
    }
    static void printLogError(std::stringstream *_buffer)
    {
        std::lock_guard<std::mutex> lock(critical);
        std::cerr << _buffer->str() << std::endl;
        std::cerr.flush();
    }

    static void printLogDebug(std::stringstream *_buffer)
    {
        std::lock_guard<std::mutex> lock(critical);
        std::cout << "\033[33m"<< _buffer->str()<<"\033[0m" << std::endl;
        std::cout.flush();
    }

    static void(* logFuncs[])(std::stringstream *) = {printLogInfo , printLogWarn, printLogError, printLogDebug};
    static const Logger::Level LevelAll[] = { Logger::Level::LEVEL_INFO, Logger::Level::LEVEL_WARN, Logger::Level::LEVEL_ERROR, Logger::Level::LEVEL_DEBUG };


    Logger::State::State() : _logFunctionC(nullptr), _logFunctionLua(nullptr), _enabled(true)
    {
    }

    Logger::State::~State()
    {
    }

    void Logger::State::flush()
    {

        if (_logFunctionC)
        {
            // Pass call to registered C log function
            (*_logFunctionC)(&_buffer);
        }
        else if (_logFunctionLua)
        {
            // Pass call to registered Lua log function
            //Game::getInstance()->getScriptController()->executeFunction<void>(state.logFunctionLua, "[Logger::Level]s", NULL, level, str);
        }
    }

    Logger::Logger()
    {
        /*for (auto i : LevelAll)
        {
            set(i, logFuncs[static_cast<int>(i)]);
        }*/
    }

    Logger::~Logger()
    {
        for (auto i : LevelAll)
        {
            _state[static_cast<int>(i)].flush();
        }
    }

    const Logger::State &Logger::operator[](Logger::Level level) const
    {
        const_cast<Logger*>(this)->set(level, logFuncs[static_cast<int>(level)]);
        return _state[static_cast<int>(level)] << getHeader(level);
    }


    std::string Logger::getHeader(Level level) const
    {
        auto now =
                std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char timeStr[20];
        strftime(timeStr, sizeof(timeStr), "%F %T", std::localtime(&now));
        char header[256];
        snprintf(header, sizeof(header), "[%s] %s ", levelToString(level).c_str(),
                 timeStr);
        return header;
    }


    bool Logger::isEnabled(Level level)
    {
        return _state[static_cast<int>(level)]._enabled;
    }

    void Logger::setEnabled(Level level, bool enabled)
    {
        _state[static_cast<int>(level)]._enabled = enabled;
    }

    void Logger::set(Level level, void (*logFunction) (std::stringstream*))
    {
        State& state = _state[static_cast<int>(level)];
        state._logFunctionC = logFunction;
        state._logFunctionLua = NULL;
    }

    void Logger::set(Level level, const char* logFunction)
    {
        State& state = _state[static_cast<int>(level)];
        state._logFunctionLua = logFunction;
        state._logFunctionC = NULL;
    }
}
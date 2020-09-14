//
// Created by jared on 9/10/20.
//

#ifndef PHYSZY_MYLOGGER_H
#define PHYSZY_MYLOGGER_H

#include <stdarg.h>
#include <iostream>
#include <sstream>
#include <string>
namespace PHYSZY
{
    class Logger final
    {
    public:

        enum class Level : uint8_t
        {
            LEVEL_INFO = 0,
            LEVEL_WARN = 1,
            LEVEL_ERROR = 2,
            LEVEL_DEBUG = 3
        };

        struct State
        {
            State();
            ~State();
            void flush();
            void (*_logFunctionC)(std::stringstream*);

            template <typename T>
            const State& operator<<(const T& str) const
            {
                if (!_enabled)
                    return *this;
                _buffer << str;
                return *this;
            }

            mutable std::stringstream _buffer;
            const char *_logFunctionLua;
            bool _enabled;
        };

        Logger();
        ~Logger();
        const State& operator[](Level level) const;

    private:
        bool isEnabled(Level level);

        void setEnabled(Level level, bool enabled);

        void set(Level level, void (*logFunction)(std::stringstream* _buffer));

        void set(Level level, const char *logFunction);
        State _state[4];
        std::string getHeader(Level level) const;

        inline std::string levelToString(Level level) const
        {
            switch (level) {
                case Level::LEVEL_INFO:
                    return "INFO";
                case Level::LEVEL_WARN:
                    return "WARN";
                case Level::LEVEL_ERROR:
                    return "ERROR";
                case Level::LEVEL_DEBUG:
                    return "DEBUG";
                default:
                    return "";
            }
        }
    };

#define LOG_INFO \
    (Logger()[Logger::Level::LEVEL_INFO] \
     << "[" << __FILE__ << ":" << __LINE__ << " (" << __func__ << ")] ")
#define LOG_WARN \
    (Logger()[Logger::Level::LEVEL_WARN] \
     << "[" << __FILE__ << ":" << __LINE__ << " (" << __func__ << ")] ")
#define LOG_ERROR \
    (Logger()[Logger::Level::LEVEL_ERROR] \
     << "[" << __FILE__ << ":" << __LINE__ << " (" << __func__ << ")] ")
#define LOG_DEBUG \
    (Logger()[Logger::Level::LEVEL_DEBUG] \
     << "[" << __FILE__ << ":" << __LINE__ << " (" << __func__ << ")] ")

}
#endif //PHYSZY_MYLOGGER_H

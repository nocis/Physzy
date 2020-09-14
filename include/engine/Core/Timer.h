//
// Created by jared on 9/10/20.
//

#ifndef PHYSZY_TIMER_H
#define PHYSZY_TIMER_H

#include <chrono>

namespace PHYSZY
{
    class Timer
    {
    public:
        Timer() {_start = std::chrono::steady_clock::now();}
        double getDuration() const
        {
            auto _end = std::chrono::steady_clock::now();
            auto count = std::chrono::duration_cast<std::chrono::microseconds>(_end - _start).count();
            return count / 1000000.0;
        }
        double reset() {_start = std::chrono::steady_clock::now(); return getDuration(); }
    private:
        std::chrono::steady_clock _clock;
        std::chrono::steady_clock::time_point _start;
    };
}
#endif //PHYSZY_TIMER_H

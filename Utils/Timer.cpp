#ifndef HAUSARBEITWEGSUCHE_TIMER_HPP
#define HAUSARBEITWEGSUCHE_TIMER_HPP

#include "Timer.h"
#include <chrono>

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
}

void Timer::stop() {
    endTime = std::chrono::steady_clock::now();
}
float Timer::getDuration() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
}

#endif

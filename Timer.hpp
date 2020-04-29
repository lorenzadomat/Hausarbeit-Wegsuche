#include <chrono>
#ifndef HAUSARBEITWEGSUCHE_TIMER_HPP
#define HAUSARBEITWEGSUCHE_TIMER_HPP

class Timer{
    private:
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;
    public:
        void start();
        void stop();
        float getDuration();
    };
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

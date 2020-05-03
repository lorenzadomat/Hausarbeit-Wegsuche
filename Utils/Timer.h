#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer{
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
public:
    void start();
    void stop();
    float getDuration();
};

#endif

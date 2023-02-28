#include <util/Timer.hpp>
#include <chrono>
using namespace std::chrono;

const uint64_t Timer::UNINIT_MARK = -__LONG_MAX__;
uint64_t Timer::mark = Timer::UNINIT_MARK;

// Starts the timer
void Timer::start(){
    mark = duration_cast<microseconds>(system_clock().now().time_since_epoch()).count();
}

// Returns the duration between last lap in microseconds
uint64_t Timer::lap(){
    if(mark == UNINIT_MARK){
        start();
        return 0ULL;
    }
    uint64_t oldMark = mark;
    start();
    return mark - oldMark;
}

// Converts a given time in microseconds to time in milliseconds
double Timer::toMilli(uint64_t micro){
    return (double)micro / 1000;
}

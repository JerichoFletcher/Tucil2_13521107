#ifndef TIMER_HPP
#define TIMER_HPP

#include <cstdint>

class Timer{
    public:
        static void start();
        static uint64_t lap();
        static double toMilli(uint64_t micro);
    private:
        static uint64_t mark;
        static const uint64_t UNINIT_MARK;
};

#endif

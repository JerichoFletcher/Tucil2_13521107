#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <struct/vec/Vector.hpp>
#include <ctime>

class Random{
    public:
        static void init();
        static double nextDouble();
        static Vector nextVector(int);
    private:
        static time_t seed;
        static const time_t UNINIT_SEED;
};

#endif

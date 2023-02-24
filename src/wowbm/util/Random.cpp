#include <util/Random.hpp>
#include <random>

const time_t Random::UNINIT_SEED = -__LONG_MAX__;
time_t Random::seed = Random::UNINIT_SEED;

// Initializes the random generator
void Random::init(){
    seed = time(NULL);
    srand((unsigned)seed);
}

// Returns a pseudo-random double between 0 and 1 (inclusive)
double Random::nextDouble(){
    if(seed == UNINIT_SEED)init();
    return (double)rand() / RAND_MAX;
}

// Returns an n-dimensional vector with pseudo-random components
Vector Random::nextVector(int dimension){
    Vector res(dimension);
    for(int i = 0; i < dimension; i++){
        res[i] = nextDouble();
    }
    return res;
}

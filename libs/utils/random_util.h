#ifndef RANDOM_UTIL_H
#define RANDOM_UTIL_H

class Random;

#include <random>

class Random{
    private:
        std::uniform_int_distribution<std::mt19937::result_type> distribution;
        std::mt19937 rng;

    public:
        Random(float min, float max);
        
        // returns a random number with 2 decimal places range (min, max)
        float getFloat();
        
        // in integer
        int getInt();
};

#endif
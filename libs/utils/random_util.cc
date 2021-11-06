/*
Original way:

srand((unsigned)time(0)); 
rand();
*/

#include <random>
#include <math.h>
#include "libs/utils/random_util.h"

Random::Random(float min, float max){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(min*100, max*100);
    this->rng = rng;
    this->distribution = distribution;
}

float Random::getFloat(){
    return ((float)this->distribution(this->rng))/(100.0f);
}

int Random::getInt(){
    return (int)(floor((float)this->distribution(this->rng))/(100.0f));
}


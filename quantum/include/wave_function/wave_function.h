#pragma once
#include "point/Point.h"

// A mathematical description of the quantum state 
// of an isolated Quant
template <typename T, unsigned int n>
class WaveFunction
{
public:
    // Measure wave function at given Point
    virtual float measure_at(Point<T, n>&) = 0;
    // Calculate the complementary events sum for further 
    // validation (must equal to 1.0)
    virtual float complementary_events_sum() = 0;
};
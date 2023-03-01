#pragma once
#include "point/Point.h"

// A mathematical description of the quantum state 
// of an isolated Quant
class WaveFunction
{
public:
    // Measure wave function at given Point
    virtual float measure_at(Point) = 0;
    // Calculate the complementary events sum for further 
    // validation (must equal to 1)
    virtual bool complementary_events_sum() = 0;
};
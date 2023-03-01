#pragma once
#include <array>

// n-dimensional position of the Quant in the World
template <typename T, unsigned int n>
class Point
{
public:
    Point(std::array<T, n> coords) : coords(coords) {}
    ~Point() {}

    T operator[](const size_t &i) const
    {
        return coords[i];
    }

public:
    // Point's coordinates
    mutable std::array<T, n> coords;
};
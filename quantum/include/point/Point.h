#pragma once
#include <array>
#include <functional>

// n-dimensional position of the Quant in the World
template <typename T, unsigned int n>
class Point
{
public:
    Point(std::array<T, n> coords) : coords(coords) {}
    ~Point() {}

    T operator[](const size_t &i) const { return coords[i]; }
    bool operator==(const Point<T, n> &point) const { return coords == point.coords; }

private:
    // Point's coordinates
    mutable std::array<T, n> coords;

    // TODO (Timur)
    // template <typename Tt, unsigned int nn>
    // friend class PointPtrHash;
};

// TODO (Timur)
// template <typename T, unsigned int n>
// class PointPtrHash
// {
// public:
//     size_t operator()(const Point<T, n> *point) const
//     {
//         return std::hash<std::array<T, n>>{}(point->coords);
//     }
// };
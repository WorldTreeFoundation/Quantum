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

    template <typename Tt, unsigned int nn>
    friend size_t point_hasher(const Point<T, n> point);
};

template <typename T, unsigned int n>
size_t point_hasher(const Point<T, n> point)
{
    // NOTE (Timur): better to check one more time
    // or use boost::hash
    std::hash<T> hasher;
    size_t result = 144451;
    for (size_t i = 0; i < point.coords.size(); ++i)
    {
        result = (result << 1) ^ hasher(point[i]);
    }
    return result;
}

template <typename T, unsigned int n>
class PointHash
{
public:
    size_t operator()(const Point<T, n> point) const
    {
        return point_hasher<T, n>(point);
    }
};

template <typename T, unsigned int n>
class PointPtrHash
{
public:
    size_t operator()(const Point<T, n> *point) const
    {
        return point_hasher<T, n>(*point);
    }
};
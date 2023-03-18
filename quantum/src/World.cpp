#include <iostream>
#include "world/World.h"

template <typename T, unsigned int n>
World<T, n>::World() {}

template <typename T, unsigned int n>
World<T, n>::~World() {}

template <typename T, unsigned int n>
void World<T, n>::place_quant(Quant<T, n> quant, std::vector<Point<T, n>> points)
{
    Quant<T, n> *quant_ptr = &quant;

    quants.insert(quant_ptr);

    if (!possibilities.contains(quant_ptr))
    {
        possibilities[quant_ptr] = {};
    }

    for (int i = 0; i < points.size(); i++)
    {
        Point<T, n> *point_ptr = &points[i];

        possibilities[quant_ptr].insert(point_ptr);

        space.insert(point_ptr);

        if (!entanglements.contains(point_ptr))
        {
            entanglements[point_ptr] = {};
        }
    }

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            entanglements[&points[i]].insert(&points[j]);
            entanglements[&points[j]].insert(&points[i]);
        }
    }
}

#include <iostream>
#include "world/World.h"

template <typename T, unsigned int n>
World<T, n>::World() {}

template <typename T, unsigned int n>
World<T, n>::~World() {}

template <typename T, unsigned int n>
void World<T, n>::place_quant(
    Quant<T, n> *quant,
    std::vector<Point<T, n> *> points
)
{
    // TODO: isolate quant and points insertion to create_quant and create_point
    quants.insert(quant);

    if (!possibilities.contains(quant))
    {
        possibilities[quant] = {};
    }

    for (int i = 0; i < points.size(); i++)
    {
        Point<T, n> *point_ptr = points[i];

        possibilities[quant].insert(point_ptr);

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
            entanglements[&points[i]].insert(points[j]);
            entanglements[&points[j]].insert(points[i]);
        }
    }
}

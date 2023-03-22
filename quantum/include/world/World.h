#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "point/Point.h"
#include "quant/Quant.h"

template <typename T, unsigned int n>
using QuantSet = std::unordered_set<Quant<T, n> *>;

template <typename T, unsigned int n>
using PointSet = std::unordered_set<Point<T, n> *, PointPtrHash<T, n>>;

template <typename T, unsigned int n>
using PossibilitiesMap = std::unordered_map<Quant<T, n> *, PointSet<T, n>>;

template <typename T, unsigned int n>
using EntanglementsMap = std::unordered_map<Point<T, n> *, PointSet<T, n>, PointPtrHash<T, n>>;

template <typename T, unsigned int n>
class World
{
public:
    World();
    ~World();

    void place_quant(Quant<T, n>, std::vector<Point<T, n>>);

private:
    QuantSet<T, n> quants;
    PointSet<T, n> space;
    PossibilitiesMap<T, n> possibilities;
    EntanglementsMap<T, n> entanglements;
};
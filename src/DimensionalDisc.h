//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_DIMENSIONALDISC_H
#define DRAGONS_DIMENSIONALDISC_H
#include "Edge.h"
#include "House.h"
#include "Dragons.h"
#include "DimensionalHouse.h"

using namespace dragon_constants;

struct DimensionalDisc
{
    Prime num_houses;
    int dimension, facing, rotation;
    std::vector<DimensionalHouse> houses;

    DimensionalDisc(int dimension, const Prime &num_houses, int facing, int rotation) : dimension(dimension), num_houses(num_houses),
        facing(facing), rotation(rotation)
    {
        for (auto h = 1; h <= num_houses; ++h){
            houses.emplace_back(DimensionalHouse{House{dimension, h}});
        }
    }

    void spin(int tug){
        rotation += tug;
    }

    void add_edge(int start_house, House to, Prime weight){
        houses[start_house - 1].add_edge(to, weight);
    }

    bool has_edge(House from, House to) const {
        return (from.aspect == dimension && houses[from.number-1].has_edge(to));
    }

    void advance(){
        facing += rotation;
    }

    friend std::ostream &operator<<(std::ostream &os, const DimensionalDisc &disc) {
        os << "facing " << disc.facing << " of " << disc.num_houses << " houses with rotation of " << disc.rotation;
        return os;
    }

    bool operator==(const DimensionalDisc &rhs) const {
        return num_houses == rhs.num_houses &&
               facing == rhs.facing &&
               rotation == rhs.rotation &&
               houses == rhs.houses &&
               dimension == rhs.dimension;
    }

    bool operator!=(const DimensionalDisc &rhs) const {
        return !(rhs == *this);
    }
};

#include <vector>
#include <array>
#include <list>
#include "MinSet.h"
#include "Prime.h"
#include "Edge.h"

#endif //DRAGONS_DIMENSIONALDISC_H

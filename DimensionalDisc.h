//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_DIMENSIONALDISC_H
#define DRAGONS_DIMENSIONALDISC_H
#include "Edge.h"
#include "House.h"
#include "Dragons.h"

using namespace dragon_constants;

struct DimensionalDisc
{
    Prime num_houses;
    int facing, rotation;
    std::__1::vector<Edge> edges;
    std::vector<House> houses;

    DimensionalDisc(const Prime &num_houses, int facing, int rotation) : num_houses(num_houses),
        facing(facing), rotation(rotation), edges(num_houses, Edge{}), houses(num_houses, House{num_houses})
    {
    }

    void spin(int tug){
        rotation += tug;
    }

    void add_edge(int start_house, int target_disc, int target_house, Prime weight){
        edges[start_house-1] = Edge{target_disc, target_house, weight};
    }

    void advance(){
        facing += rotation;
    }

    friend std::__1::ostream &operator<<(std::__1::ostream &os, const DimensionalDisc &disc) {
        os << "facing " << disc.facing << " of " << disc.num_houses << " houses with rotation of " << disc.rotation;
        os  << disc.edges;
        return os;
    }

    bool operator==(const DimensionalDisc &rhs) const {
        return num_houses == rhs.num_houses &&
               facing == rhs.facing &&
               rotation == rhs.rotation &&
               edges == rhs.edges &&
               houses == rhs.houses;
    }

    bool operator!=(const DimensionalDisc &rhs) const {
        return !(rhs == *this);
    }

    static bool Test()
    {
        DimensionalDisc disc1{Prime{1}, 1, 0};
        cout << "Made a Prime Dimension with " << disc1.num_houses << " houses" << endl;

        std::__1::vector<DimensionalDisc> dimensions;
        dimensions.push_back(disc1);

        for (int i = 1; i <= dragon_constants::num_higher_dimensions; ++i){
            dimensions.push_back(DimensionalDisc{Prime::Nth(i), 1, 0});
        }

        for (auto d : dimensions) {
            d.spin(d.num_houses);

            if (d.rotation != d.num_houses){
                cout << "Disc failed to rotate" << endl;
                return false;
            }
        }

        cout << "Made a bunch of dimensions" << endl;

        dimensions[0].add_edge(1, 1, 2, 3);
        dimensions[3].spin(5);
        dimensions[3].advance();

        for (auto d : dimensions){
            cout << d << endl;
        }

        return true;
    }
};

#include <vector>
#include <array>
#include <list>
#include "MinSet.h"
#include "Prime.h"
#include "Edge.h"

#endif //DRAGONS_DIMENSIONALDISC_H

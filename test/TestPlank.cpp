//
// Created by Patrick Meade on 2019-03-07.
//
#define CATCH_CONFIG_MAIN

#include <iostream>
using namespace std;

#include "catch.hpp"
#include "../Plank.h"

TEST_CASE("Plank Constructor Test") {
    // Create thew most basic Plank
    // 17 DimensionalDiscs and a MinSet to describe a position on each disc
    Plank plank{MinSet{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}};
    plank.add_edge(3, 3, 10, 11, 5);
    REQUIRE (plank.higher_dimensions[2].edges[2].target_dimension == 10);
    REQUIRE (plank.higher_dimensions[2].edges[2].target_house == 11);
    REQUIRE (plank.higher_dimensions[2].edges[2].weight == Prime{5});
}

TEST_CASE("Plank Spin Test") {
    Plank plank{MinSet{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}};
    plank.higher_dimensions[2].spin(45);
    plank.advance();

    REQUIRE (plank.higher_dimensions[2].rotation == 45);
    REQUIRE (plank.higher_dimensions[2].facing == 46);
}

TEST_CASE("Plank Full Connected Test"){
    // Create a fully connected plank
    Plank fp;
    for (int d = 1; d < num_higher_dimensions; ++d){
        for (int h = 1; h <= fp.higher_dimensions[d-1].num_houses; ++h) {
            fp.add_edge(d, h, d + 1, h, Prime{h});
            REQUIRE(fp.higher_dimensions[d-1].edges[h-1].target_dimension == d + 1);
            REQUIRE(fp.higher_dimensions[d-1].edges[h-1].target_house == h);
            REQUIRE(fp.higher_dimensions[d-1].edges[h-1].weight == Prime{h});
        }
    }
}

TEST_CASE("Plank collapses correctly"){
    Plank plank;
    REQUIRE(plank.value() == Prime{16});
}


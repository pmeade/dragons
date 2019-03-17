//
// Created by Patrick Meade on 2019-03-07.
//


#include <iostream>
using namespace std;

#include "catch.hpp"
#include "../src/Edge.h"

TEST_CASE("Edge Constructor Test") {
    Edge edge{1, 2, 3};
    REQUIRE (edge.target_dimension == Prime{1});
    REQUIRE(edge.target_house == Prime{2});
    REQUIRE(edge.weight == Prime{3});
}
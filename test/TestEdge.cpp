//
// Created by Patrick Meade on 2019-03-07.
//


#include <iostream>
using namespace std;

#include "catch.hpp"
#include "../src/Edge.h"

TEST_CASE("Edge Constructor Test") {
    Edge edge{House{2,1}, House{4,3}, Prime::Nth(5)};
    REQUIRE (edge.from.aspect == 2);
    REQUIRE (edge.from.number == 1);
    REQUIRE (edge.to.aspect == 4);
    REQUIRE (edge.to.number == 3);
    REQUIRE (edge.weight == Prime::Nth(5));
}
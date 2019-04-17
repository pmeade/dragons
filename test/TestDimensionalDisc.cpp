#include "../src/DimensionalDisc.h"
#include "catch.hpp"

TEST_CASE("Constructor"){
    DimensionalDisc disc(5,7,1,0);
    REQUIRE(disc.houses.size() == 7);
}


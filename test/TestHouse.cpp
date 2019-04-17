//
// Created by Patrick Meade on 2019-03-09.
//


#include "../src/DimensionalHouse.h"
#include "catch.hpp"

TEST_CASE("House can set value"){
    DimensionalHouse house{House{3,3}};
    house.set_value(Prime{5});
}
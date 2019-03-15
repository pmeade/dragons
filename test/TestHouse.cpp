//
// Created by Patrick Meade on 2019-03-09.
//


#include "../House.h"
#include "catch.hpp"

TEST_CASE("F of X = x % value"){
    House house{5};
    house.value = Prime{5};
    REQUIRE(house.func.f(4) == 4);
    REQUIRE(house.func.f(5) == 5);
    REQUIRE(house.func.f(6) == 1);
    REQUIRE(house.func.f(7) == 2);
}
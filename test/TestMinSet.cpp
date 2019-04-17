//
// Created by Patrick Meade on 2019-03-23.
//

#include "../src/MinSet.h"
#include "catch.hpp"

TEST_CASE("Constructor and copy constructor "){
    MinSet ms1;
    ms1[2] = 5;
    MinSet ms2(ms1);

    REQUIRE(ms2[2] == 5);
}


TEST_CASE("Constructor with inital value"){
    MinSet ms1{{1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    REQUIRE(ms1[2] == 3);
}


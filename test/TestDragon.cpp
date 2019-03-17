//
// Created by Patrick Meade on 2019-03-09.
//

#include "../src/Dragon.h"
#include "catch.hpp"
#include "../src/Plank.h"

TEST_CASE("Breathe produces new world"){
    Plank spell;
    auto world = Plank::make_world();
    auto dragon = Dragon::make_dragon();
    auto new_world = dragon->breathe(spell, *world);
    REQUIRE(new_world != *world);
}

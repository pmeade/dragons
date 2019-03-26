//
// Created by Patrick Meade on 2019-03-09.
//

#include "../src/Dragon.h"
#include "catch.hpp"
#include "../src/SeptumDecum.h"
#include "../src/Spell.h"
#include "../src/Verse.h"

TEST_CASE("Dragon can acquire a Schema") {
    auto dragon = Dragon::make_dragon();

    auto schema1 = dragon->view_schema();

    dragon->hold_schema(move(Schema::new_schema()));

    auto schema2 = dragon->view_schema();

    auto cmp = schema1 == Schema();

    REQUIRE(cmp);
}

TEST_CASE("Schema can add an edge"){
    // Make default schema
    auto dragon = Dragon::make_dragon();

    // Add edge
    dragon->draw_edge(House{1,1}, House{5,5}, Prime{7});

    // Check for existence of edge
    REQUIRE(dragon->has_edge(House{1,1}, House{5,5}));
}

TEST_CASE("Dragon can update a house"){
    // Make default schema
    auto dragon = Dragon::make_dragon();

    // update house value
    dragon->set_house_value(House{5,5}, Prime{19});

    // check house value
    REQUIRE(dragon->check_house_value(House{5,5}) == Prime{19});
}

TEST_CASE("Dragon can create breath uniquely"){
    // Make default schema
    auto dragon = Dragon::make_dragon();

    // Create breath with input of 1
    auto breath1 = dragon->breathe(1);

    // Create breath with input of 1
    auto breath2 = dragon->breathe(1);

    REQUIRE(*breath1 == *breath2);

    // Modify schema
    dragon->set_house_value(House(5,5), Prime{17});

    // Create breath with input of 1
    auto breath3 = dragon->breathe(1);

    // confirm breaths are different
    REQUIRE(breath1 != breath3);
}

TEST_CASE("Dragon can modify world state"){
    auto dragon1 = Dragon::make_dragon();
    auto verse = Verse::make_world();
    auto test_value = verse->value();
    REQUIRE(test_value == verse->value());

    // Change universal state
    auto breath = dragon1->breathe(Prime::Nth(60));
    verse->absord_breath(*breath);

    REQUIRE(test_value == verse->value());
}

//TEST_CASE("Dragon can view contents of a plane"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can grab from a plane"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can place on a plane"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can change direction in any aspect"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can change orbit in any aspect"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can mutate their nature"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can view their true nature"){
//    REQUIRE(false);
//}
//
//TEST_CASE("Dragon can scintillate"){
//    REQUIRE(false);
//}


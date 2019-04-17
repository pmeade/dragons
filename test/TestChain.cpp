//
// Created by Patrick Meade on 2019-03-25.
//

#include "catch.hpp"
#include "../src/Chain.h"
#include "../src/Dragon.h"

TEST_CASE("Create Account")
{
    auto chain = Chain::new_chain();
    chain->add_account(5, "Test Account");
    REQUIRE(chain->has_account(5));
}

TEST_CASE("Modify Account")
{
    auto chain = Chain::new_chain();
    chain->add_account(5, "Test Account");
    auto state = chain->get_state(5);
    REQUIRE(chain->get_state(5) == state);

    chain->update_state(5, "Foo");
    REQUIRE(chain->get_state(5) != state);
}

TEST_CASE("Add Dragon")
{
    auto chain = Chain::new_chain();
    chain->add_account(5, "Test Account");

    auto dragon = Dragon::make_dragon();
    auto state = dragon->save_state();
    chain->add_dragon(5, state);

    auto dragons = chain->get_dragons(5);
    auto restored_dragon = Dragon::restore_dragon(*dragons.begin());

    auto cmd = *dragon == *restored_dragon;
    REQUIRE(*dragon == *restored_dragon);
}

TEST_CASE("Add Breath")
{
    auto chain = Chain::new_chain();
    chain->add_account(5, "Test Account");

    auto dragon = Dragon::make_dragon();
    chain->add_dragon(5, dragon->save_state());

    auto breath = dragon->breathe(Prime{5});
    chain->add_breath(*breath);

    auto chain_breath = chain->get_breaths().front();
    REQUIRE(chain_breath == *breath);
}

TEST_CASE("Stake for claim")
{
    auto chain = Chain::new_chain();
    chain->add_account(5, "Test Account");

    auto dragon = Dragon::make_dragon();
    chain->add_dragon(5, dragon->save_state());

    auto breath = dragon->breathe(Prime{5});
    chain->add_breath(*breath);

    auto breaths = chain->get_breaths();
    auto new_verse = chain->get_verse().clone_verse();

    auto breath_queue{breaths};
    while (!breath_queue.empty()) {
        new_verse->absorb_breath(breath_queue.front());
        breath_queue.pop();
    }

    chain->process_breaths(breaths, *new_verse);

    REQUIRE(chain->get_breaths().empty());
    REQUIRE(chain->get_verse() == *new_verse);
}

TEST_CASE("Store Schema")
{
    auto chain = Chain::new_chain();
    chain->add_account(5, "Test Account");

    auto schema = Schema::new_schema();
    schema->add_edge(House{1,1}, House{5,5}, Prime{7});
    chain->add_schema(5, schema->save_state());

    auto restored_schema = Schema::restore_state(chain->get_schemas(5).front());
    REQUIRE(*schema == *restored_schema);
}
//
// Created by Patrick Meade on 2019-03-23.
//

#include "catch.hpp"
#include "../src/Schema.h"

TEST_CASE("Clone Schema")
{
    unique_ptr<Schema> schema1 = make_unique<Schema>();
    schema1->add_edge(House{1,1}, House{2,2}, Prime{3});

    unique_ptr<Schema> schema2 = make_unique<Schema>(*schema1);
    REQUIRE(schema2->has_edge(House{1,1}, House{2,2}));

}
//
// Created by Patrick Meade on 2019-03-22.
//

#ifndef DRAGONS_SCHEMA_H
#define DRAGONS_SCHEMA_H


#include "SeptumDecum.h"

class Schema : public SeptumDecum {

public:

    void add_edge(House from, House to, Prime weight) {
        aspects[from.aspect - 1].add_edge(from.number, to, weight);
        aspects[from.aspect - 1].spin(-weight);
        aspects[to.aspect - 1].spin(weight);
    }

    void pulse(Prime input) {
        aspects[0].houses[0].set_input(input);
        for (auto &aspect : aspects){
            for (auto &house : aspect.houses){
                for (auto &edge : house.edges){
                    auto &target_house = aspects[edge.to.aspect-1].houses[edge.to.number-1];
                    target_house.set_input(house.func(house.get_value()));
                }
            }
        }
    }

    Prime value() const override {
        auto sum = std::accumulate(minSet.begin(), minSet.end(), 0);
        int highest_value = Prime::Nth(16);
        sum %= highest_value;
        auto p = Prime{sum};
        return p;
    }

    static unique_ptr<Schema> new_schema()
    {
        return std::move(make_unique<Schema>());
    }

    Schema() = default;
    Schema(const Schema &schema) = default;


    bool has_edge(House from, House to) const override {
        return aspects[from.aspect - 1].has_edge(from, to);
    }


    unique_ptr<Schema> clone_schema() const { return make_unique<Schema>(*this);}

};


#endif //DRAGONS_SCHEMA_H

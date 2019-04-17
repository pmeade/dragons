//
// Created by Patrick Meade on 2019-03-22.
//

#ifndef DRAGONS_SCHEMA_H
#define DRAGONS_SCHEMA_H


#include <ostream>
#include <queue>
#include "SeptumDecum.h"
#include "SchemaState.h"

class Schema : public SeptumDecum {

public:

    Schema(const SchemaState &state)
    {
        for (auto i = 0; i < num_dimensions - 1; ++i) {
            minSet[i] = state.minSet[i];
        }

        for (auto &aspect : aspects){
            for (auto &house : aspect.houses){
                house.set_value(house.value);
            }
        }

        for (auto &edge : state.edges){
            aspects[edge.from_dimension-1].add_edge(
                    edge.to_dimension, House{edge.to_dimension, edge.to_number}, edge.weight);
        }
    }

    Schema(const MinSet &minSet, const array<DimensionalDisc, num_dimensions> &aspects) : SeptumDecum{minSet, aspects}
    {

    }

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

    SchemaState save_state() const {
        SchemaState state;

        for (auto i = 0; i < num_dimensions-1; ++i) {
            state.minSet[i] = minSet[i];
        }

        queue<Edge> edges;

        auto i = 0;
        for (auto aspect : aspects) {
            for (auto house : aspect.houses) {
                auto &state_house = state.houses[i++];
                state_house.value = house.get_value();
                for (auto edge : house.edges) {
                    edges.emplace(edge);
                }
            }
        }

        while (!edges.empty()) {
            auto &edge = edges.front();
            state.edges.push_back(
                    EdgeState{
                            (uint8_t)edge.from.aspect,
                            (uint8_t)edge.from.number,
                            (uint8_t)edge.to.aspect,
                            (uint8_t)edge.to.number,
                            (uint8_t)edge.weight
                    }
            );
        }

        return state;
    }

    static unique_ptr<Schema> restore_state(const SchemaState &schema_state) {
        return move(make_unique<Schema>(schema_state));
    }

    unique_ptr<Schema> clone_schema() const { return make_unique<Schema>(*this);}
};


#endif //DRAGONS_SCHEMA_H

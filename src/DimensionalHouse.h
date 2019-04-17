//
// Created by Patrick Meade on 2019-03-22.
//

#ifndef DRAGONS_DIMENSIONALHOUSE_H
#define DRAGONS_DIMENSIONALHOUSE_H
#include "House.h"
#include "Edge.h"
#include "Func.h"
#include "Filament.h"
#include "Snip.h"

struct DimensionalHouse : House
{
    Prime value, prime;

    Func func;

    vector<Edge> edges;

    explicit DimensionalHouse(House house) : House{house}{

    }

    void add_edge(House to, Prime weight){
        edges.emplace_back(Edge{House{aspect, number}, to, weight});
    }

    bool has_edge(House to) const{
        for (auto e : edges){
            if (e.to == to) return true;
        }

        return false;
    }

    Prime get_value() const { return value; }

    unique_ptr<Filament> breath() const {
        if (value > cost()) return move(make_unique<Filament>(*this, value));
        return nullptr;
    }

    void set_value(Prime prime){
        value = prime;
    }

    void set_input(Prime v){
        func.store_input(v);
    }

    Prime cost() const {
        return Prime::Nth(aspect);
    }
};


#endif //DRAGONS_DIMENSIONALHOUSE_H

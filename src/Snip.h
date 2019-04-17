//
// Created by Patrick Meade on 2019-03-23.
//

#ifndef DRAGONS_SNIP_H
#define DRAGONS_SNIP_H
#include <vector>
#include <tuple>
using namespace std;

#include "House.h"
#include "Edge.h"

class Snip {
    vector<pair<House, Edge>> tendrils;

    void add_tendril(House house, Edge edge){
        tendrils.emplace_back(make_tuple(house, edge));
    }
};


#endif //DRAGONS_SNIP_H

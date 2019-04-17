//
// Created by Patrick Meade on 2019-03-25.
//

#ifndef DRAGONS_SCHEMASTATE_H
#define DRAGONS_SCHEMASTATE_H
#include "Dragons.h"
#include "EdgeState.h"
#include "HouseState.h"
#include <vector>
#include <ostream>

using namespace dragon_constants;
using namespace std;

struct SchemaState {
    uint8_t minSet[num_dimensions-1];
    HouseState houses[num_houses];
    vector<EdgeState> edges;

    SchemaState() {};

    SchemaState(const SchemaState &rhs) {
        memcpy(minSet, rhs.minSet, num_dimensions - 1);
        memcpy(houses, rhs.houses, num_houses);
        edges = rhs.edges;
    }

    friend ostream &operator<<(ostream &os, const SchemaState &state) {
        ios_base::fmtflags stream_state( os.flags() );
        os << std::hex;

        for (auto i = 0; i < num_dimensions - 1; ++i){
            os << state.minSet[i];
        }

        for (auto i = 0; i < num_houses; ++i){
            os << state.houses[i];
        }

        os << (uint16_t) state.edges.size();

        for (auto edge : state.edges){
            os << edge;
        }

        os.flags( stream_state );

        return os;
    }
};


#endif //DRAGONS_SCHEMASTATE_H

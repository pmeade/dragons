//
// Created by Patrick Meade on 2019-03-26.
//

#ifndef DRAGONS_EDGESTATE_H
#define DRAGONS_EDGESTATE_H

#include <ostream>

using namespace std;

struct EdgeState {
    uint8_t from_dimension;
    uint8_t from_number;
    uint8_t to_dimension;
    uint8_t to_number;
    uint8_t function;
    uint32_t weight;

    friend ostream &operator<<(ostream &os, const EdgeState &state) {
        ios_base::fmtflags stream_state( os.flags() );
        os << std::hex;
        os
        << state.from_dimension
        << state.from_number
        << state.to_dimension
        << state.to_number
        << state.function
        << state.weight;

        os.flags( stream_state );

        return os;
    }
};


#endif //DRAGONS_EDGESTATE_H

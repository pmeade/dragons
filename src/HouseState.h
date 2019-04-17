//
// Created by Patrick Meade on 2019-03-26.
//

#ifndef DRAGONS_HOUSESTATE_H
#define DRAGONS_HOUSESTATE_H


#include <ostream>

struct HouseState {
    uint8_t dimension;
    uint8_t number;
    uint32_t value;

    friend ostream &operator<<(ostream &os, const HouseState &state) {
        ios_base::fmtflags stream_state( os.flags() );
        os << std::hex;
        os << state.dimension << state.number << state.value;
        os.flags( stream_state );

        return os;
    }
};


#endif //DRAGONS_HOUSESTATE_H

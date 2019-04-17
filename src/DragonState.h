//
// Created by Patrick Meade on 2019-03-25.
//

#ifndef DRAGONS_DRAGONSTATE_H
#define DRAGONS_DRAGONSTATE_H

#include "SchemaState.h"

struct DragonState {
    int id;
    SchemaState schema_state;

    DragonState(int id, const SchemaState &schema_state) : id(id), schema_state(schema_state) {}

    bool operator<(const DragonState &rhs) const {
        return id < rhs.id;
    }

    bool operator>(const DragonState &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const DragonState &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const DragonState &rhs) const {
        return !(*this < rhs);
    }
};


#endif //DRAGONS_DRAGONSTATE_H

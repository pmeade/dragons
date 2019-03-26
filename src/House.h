//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_HOUSE_H
#define DRAGONS_HOUSE_H

#include "Prime.h"

struct House {
    int aspect, number;
    bool operator==(const House &rhs) const;

    bool operator!=(const House &rhs) const;

    House(int dimension, int number);

    friend std::ostream &operator<<(std::ostream &os, const House &house);

    friend std::ostream &operator<<(std::ostream &os, const vector<House> &houses) {
        for (auto h : houses){
            os << " " << h << " ";
        }
        return os;
    }

};

#include <vector>
#include "Prime.h"

#endif //DRAGONS_HOUSE_H

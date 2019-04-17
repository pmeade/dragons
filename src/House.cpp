//
// Created by Patrick Meade on 2019-03-07.
//

#include "SeptumDecum.h"
#include <iostream>
#include "House.h"

ostream &operator<<(ostream &os, const House &house) {
    cout << "[" << house.aspect << ":" << house.number << "}";
    return os;
}

bool House::operator==(const House &rhs) const {
    return aspect == rhs.aspect &&
           number == rhs.number;
}

bool House::operator!=(const House &rhs) const {
    return !(rhs == *this);
}

House::House(int dimension, int number) : aspect(dimension), number(number) {}


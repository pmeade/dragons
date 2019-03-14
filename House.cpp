//
// Created by Patrick Meade on 2019-03-07.
//

#include "Plank.h"
#include <iostream>
#include "House.h"

ostream &operator<<(ostream &os, const House &house) {
    os << house.value << " of " << house.prime;
    return os;
}

bool House::operator==(const House &rhs) const {
    return value == rhs.value &&
           prime == rhs.prime;
}

bool House::operator!=(const House &rhs) const {
    return !(rhs == *this);
}

House::House(const Prime &prime) : value(0), prime(prime) {}


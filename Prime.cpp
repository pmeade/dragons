//
// Created by Patrick Meade on 2019-03-07.
//

#include "Plank.h"
#include <iostream>
#include "Prime.h"
#include <boost/math/special_functions/prime.hpp>


ostream &operator<<(ostream &os, const Prime &prime) {
    os << prime.value;
    return os;
}

void Prime::clamp() {
    int clamped = 1; // not a magic number. Just the lowest value supported by this class
    for (auto pidx = 0; pidx < num_higher_dimensions; ++pidx)
    {
        auto prime_value = boost::math::prime(pidx);
        if (prime_value > value) break;
        clamped = prime_value;
    }

    value = clamped;
}

Prime::Prime(int value) : value(value) {clamp();}

bool Prime::operator==(const Prime &rhs) const {
    return value == rhs.value;
}

bool Prime::operator!=(const Prime &rhs) const {
    return !(rhs == *this);
}

Prime::Prime() : value(1) {}

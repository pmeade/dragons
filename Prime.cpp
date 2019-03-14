//
// Created by Patrick Meade on 2019-03-07.
//

#include "Plank.h"
#include <iostream>
#include "Prime.h"

array<int, num_dimensions> Prime::primes{1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

ostream &operator<<(ostream &os, const Prime &prime) {
    os << prime.value;
    return os;
}

void Prime::clamp() {
    int clamped = primes[0];
    for (auto v : primes){
        if (v > value) break;
        clamped = v;
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

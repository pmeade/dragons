//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_PRIME_H
#define DRAGONS_PRIME_H

#include <array>
#include <iostream>
#include <algorithm>

#include <boost/math/special_functions/prime.hpp>

#include "Dragons.h"

using namespace dragon_constants;
using namespace std;

class Prime
{
    int value;
    void clamp();

public:
    Prime(int value);

    Prime();

    void add(int v) {
        value += v;
        clamp();
    }

    static Prime Nth(uint8_t n){
        if (n == 0) return 1;   // Bad case. Why can we pass 0 to this function?

        return boost::math::prime(n-1);
    }

    operator int() const {return value;}

    bool operator==(const Prime &rhs) const;

    bool operator!=(const Prime &rhs) const;

    int operator+(int rhs) const {
        return value + rhs;
    }

    friend std::ostream &operator<<(std::ostream &os, const Prime &prime);
};

#include <vector>
#include <array>
#include "MinSet.h"

#endif //DRAGONS_PRIME_H

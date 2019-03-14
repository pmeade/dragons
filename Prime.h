//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_PRIME_H
#define DRAGONS_PRIME_H

#include <array>
#include <iostream>
#include <algorithm>

#include "Dragons.h"

using namespace dragon_constants;
using namespace std;

class Prime
{
    static std::__1::array<int, dragon_constants::num_dimensions> primes;
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
        if (n == 0) return primes[0];   // Bad case. Why can we pass 0 to this function?

        // This function makes me unhappy. Passing in a higher param for now will just be
        // mapped to the highest value possible
        n = std::min(n, dragon_constants::num_dimensions);
        --n; // We are internally dealing with an array index
        return primes[(n % dragon_constants::num_dimensions)];
    }

    operator int() const {return value;}

    bool operator==(const Prime &rhs) const;

    bool operator!=(const Prime &rhs) const;

    friend std::__1::ostream &operator<<(std::__1::ostream &os, const Prime &prime);

    static int max_val(int d){
        return primes[min(std::__1::max(0, d), dragon_constants::num_dimensions - 1)];
    }
};

#include <vector>
#include <array>
#include "MinSet.h"

#endif //DRAGONS_PRIME_H

//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_MINSET_H
#define DRAGONS_MINSET_H

#include <array>
#include <iostream>
#include "Dragons.h"
using namespace dragon_constants;
using namespace std;

struct MinSet : public std::array<int, dragon_constants::num_dimensions> {

    friend std::ostream &operator<<(std::ostream &os, const MinSet &set) {


        os << "{";

        for (auto v : set) {
            os << v << ", ";
        }

        os << "}" << endl;
        return os;
    }

    MinSet() : array<int, num_dimensions>{0} {}

    MinSet(const MinSet &minSet)  = default;

    explicit MinSet(array<int, num_dimensions> const &values) : array<int, num_dimensions>{values} {}
};

#include <vector>
#include <array>
#include <list>
#include "Dragons.h"

#endif //DRAGONS_MINSET_H

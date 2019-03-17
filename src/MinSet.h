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

struct MinSet : public std::__1::array<int, dragon_constants::num_higher_dimensions>
{

    // What is a MinSet?
    // It is a set of 16 integers that describe a distinct configuration of 16 higher dimensions. Each integer
    // is drawn from a finite set defined by its position in the Plank. Each set is a consecutive prime
    // starting with 2{1,2} in the 0th position up to 53 {1,2,...52,53} in the 15th position.
    //
    // What is it used for?
    // It is the base data type of the Dragons Universe. It describes a location to the most granular
    // detail possible.
    //
    // How is it used?
    // It is used as a constant.

    friend std::__1::ostream &operator<<(std::__1::ostream &os, const MinSet &set) {


        os << "{1, ";

        for (auto v : set){
            os << v << ", ";
        }

        os << "}" << endl;
        return os;
    }

    MinSet(array<int, dragon_constants::num_higher_dimensions> const &values) : array<int, dragon_constants::num_higher_dimensions>(values) {}

    // Test
    static bool Test() {

        MinSet ms{{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53}};

        if (ms[0] != 2) return false;
        if (ms[1] != 3) return false;
        if (ms[2] != 5) return false;
        if (ms[3] != 7) return false;
        if (ms[4] != 11) return false;
        if (ms[5] != 13) return false;
        if (ms[6] != 17) return false;
        if (ms[7] != 19) return false;
        if (ms[8] != 23) return false;
        if (ms[9] != 29) return false;
        if (ms[10] != 31) return false;
        if (ms[11] != 37) return false;
        if (ms[12] != 41) return false;
        if (ms[13] != 43) return false;
        if (ms[14] != 47) return false;
        if (ms[15] != 53) return false;

        MinSet ms2{{2,3,5,7,11,11,17,19,23,29,31,37,41,43,47,53}};
        MinSet ms3{{2,3,5,7,11,11,17,19,23,29,31,37,41,43,47,53}};

        if (ms == ms2) return false;
        if (ms2 != ms3) return false;

        cout << "Minset passes " << ms << endl;

        return true;
    }
};

#include <vector>
#include <array>
#include <list>
#include "Dragons.h"

#endif //DRAGONS_MINSET_H

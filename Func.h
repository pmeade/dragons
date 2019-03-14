//
// Created by Patrick Meade on 2019-03-10.
//

#ifndef DRAGONS_FUNC_H
#define DRAGONS_FUNC_H
#include "Dragons.h"
#include <vector>
#include "Prime.h"
#include <numeric>

using namespace std;

class Func {

    vector<Prime> inputs;

    int reduce_args() const {
        return std::accumulate(inputs.begin(), inputs.end(), 0);
    }

    // TODO - fake function. This just adds
    int f(Prime value) {
        auto result = value + reduce_args();
        inputs.clear();
        return result;
    }
};


#endif //DRAGONS_FUNC_H

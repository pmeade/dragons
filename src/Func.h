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

public:
    // TODO - fake function. This just adds
    Prime operator()(Prime value) {
        auto result = value + reduce_args();
        inputs.clear();
        return result;
    }

    void store_input(Prime input){
        inputs.push_back(input);
    }
};


#endif //DRAGONS_FUNC_H

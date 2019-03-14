//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_HOUSE_H
#define DRAGONS_HOUSE_H

#include "Prime.h"
#include "Func.h"
#include "Edge.h"

struct House
{
    Prime value, prime;

    Func f;

    vector<Edge> edges;

    bool operator==(const House &rhs) const;

    bool operator!=(const House &rhs) const;

    House(const Prime &prime);

    void act(){
        for (auto &edge : edges){
            edge.add(f.f(value));
        }
    }

    void input(Prime v){
        f.inputs.push_back(v);
    }

    friend std::__1::ostream &operator<<(std::__1::ostream &os, const House &house);
};

#include <vector>
#include "Prime.h"

#endif //DRAGONS_HOUSE_H

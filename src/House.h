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

    Func func;

    vector<Edge> edges;

    bool operator==(const House &rhs) const;

    bool operator!=(const House &rhs) const;

    explicit House(const Prime &prime);

    void act(){
    }

    void input(Prime v){
    }

    friend std::ostream &operator<<(std::ostream &os, const House &house);
};

#include <vector>
#include "Prime.h"

#endif //DRAGONS_HOUSE_H

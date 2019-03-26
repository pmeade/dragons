//
// Created by Patrick Meade on 2019-03-05.
//

#include <iostream>
#include "SeptumDecum.h"
#include "House.h"


ostream &operator<<(ostream &os, const list<Edge> &edges) {
    for (auto &e : edges) {
        os << e;
    }

    return os;
}

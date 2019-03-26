//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_EDGE_H
#define DRAGONS_EDGE_H

#include "Dragons.h"
#include "Prime.h"
#include "House.h"

using namespace dragon_constants;
using namespace std;

struct Edge
{
    House from, to;
    Prime weight;

    Edge() : from{0,0}, to{0,0} {}

    Edge(House from, House to, const Prime &weight) : from(from), to(to), weight(weight) {}

    bool operator==(const Edge &rhs) const {
        return from == rhs.from &&
               to == rhs.to &&
               weight == rhs.weight;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
        os << "=>" << edge.to << "|" << edge.from << ":=" << edge.weight;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const std::vector<Edge> &edges) {
        for (auto i = 0; i < edges.size(); ++i)
        {
            if (edges[i].to.aspect > 0){
                os << endl << i << edges[i];
            }
        }
        return os;
    }
};

#endif //DRAGONS_EDGE_H

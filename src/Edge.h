//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_EDGE_H
#define DRAGONS_EDGE_H

#include "Dragons.h"
#include "Prime.h"
using namespace dragon_constants;
using namespace std;

struct Edge
{
    int target_house, target_dimension;
    Prime weight;

    Edge() : target_dimension{0}, target_house{0} {}

    Edge(int target_dimension, int target_house, const Prime &weight) : target_dimension(target_dimension),
                                                                        target_house(target_house),
                                                                        weight(weight) {}

    bool operator==(const Edge &rhs) const {
        return target_house == rhs.target_house &&
               target_dimension == rhs.target_dimension &&
               weight == rhs.weight;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
        os << "=>" << edge.target_dimension << "|" << edge.target_house << ":=" << edge.weight;
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const std::vector<Edge> &edges) {
        for (auto i = 0; i < edges.size(); ++i)
        {
            if (edges[i].target_dimension > 0){
                os << endl << i << edges[i];
            }
        }
        return os;
    }
};

#endif //DRAGONS_EDGE_H

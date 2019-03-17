//
// Created by Patrick Meade on 2019-03-05.
//

#ifndef DRAGONS_PLANK_H
#define DRAGONS_PLANK_H

#include <string>
#include <vector>
#include <array>
#include <list>
#include <ostream>
#include <numeric>

#include "MinSet.h"
#include "Prime.h"
#include "Edge.h"
#include "DimensionalDisc.h"

using namespace std;

using namespace dragon_constants;


struct Plank {

    MinSet minSet;
    array<DimensionalDisc, num_higher_dimensions> higher_dimensions;
    DimensionalDisc &d1 = higher_dimensions[0];

    Plank() : Plank(MinSet{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}) {}
    Plank(const MinSet &minSet) : minSet(minSet),
    higher_dimensions{{
                              DimensionalDisc{Prime::Nth(2), 1, 0},
                              DimensionalDisc{Prime::Nth(3), 1, 0},
                              DimensionalDisc{Prime::Nth(4), 1, 0},
                              DimensionalDisc{Prime::Nth(5), 1, 0},
                              DimensionalDisc{Prime::Nth(6), 1, 0},
                              DimensionalDisc{Prime::Nth(7), 1, 0},
                              DimensionalDisc{Prime::Nth(8), 1, 0},
                              DimensionalDisc{Prime::Nth(9), 1, 0},
                              DimensionalDisc{Prime::Nth(10), 1, 0},
                              DimensionalDisc{Prime::Nth(11), 1, 0},
                              DimensionalDisc{Prime::Nth(12), 1, 0},
                              DimensionalDisc{Prime::Nth(13), 1, 0},
                              DimensionalDisc{Prime::Nth(14), 1, 0},
                              DimensionalDisc{Prime::Nth(15), 1, 0},
                              DimensionalDisc{Prime::Nth(16), 1, 0},
                              DimensionalDisc{Prime::Nth(17), 1, 0}
    }} {}

    void add_edge(int start_dimension, int start_house, int target_dimension, int target_house, Prime weight){
        higher_dimensions[start_dimension - 1].add_edge(start_house, target_dimension, target_house, weight);
        higher_dimensions[start_dimension - 1].spin(-weight);
        higher_dimensions[target_dimension - 1].spin(weight);
    }

    void advance(){
        for (auto &d : higher_dimensions){
            d.advance();
        }
    }

    Prime value() const {
        auto sum = std::accumulate(minSet.begin(), minSet.end(), 0);
        int highest_value = Prime::Nth(17);
        sum %= highest_value;
        auto p = Prime{sum};
        return p;
    }

    friend ostream &operator<<(ostream &os, const Plank &plank) {
        os << plank.minSet << endl;
        for (auto d : plank.higher_dimensions){
            os << d << endl;
        }
        return os;
    }

    bool operator==(const Plank &rhs) const {
        return minSet == rhs.minSet &&
               higher_dimensions == rhs.higher_dimensions;
    }

    bool operator!=(const Plank &rhs) const {
        return !(rhs == *this);
    }

    static unique_ptr<Plank> make_world(){
        unique_ptr<Plank> plank(new Plank());
        for (int d = 0; d < num_higher_dimensions; ++d){
            for (int h = 0; h < plank->higher_dimensions[d].num_houses; ++h){
                plank->higher_dimensions[d].houses[h].value = Prime{h + 1};
            }
        }

        return plank;
    }

    //
    // It is always constant and there are a finite number of possible states.
    //
    // 16 dimensions * 15 other dimensions = 240 states
    //
    //
    //
    // What is a ConnectedPlank
    // Is it the minimum amount of information required to describe an instance
    // of the Dragons Universe from a single point of view in a 17 dimensional universe
    //
    // It is formed by describe a series of 17 concentric rings that are
    // connected through a set of edges between discrete spots on
    // any of the rings.
    //
    // The rings are divided into smaller sections known as houses. Edges connect a
    // house in one ring to a house in any other ring.
    //
    // The number of houses in each dimension are the prime numbers in order starting
    // with 1 house in the Prime Dimension, 2 houses in the 2cd, 3 in the 3rd,
    // 5 in the 4th and so on up to 53 houses in the 17th dimension.
    //
    // The values of nodes and edges are recursive functions that may or may not infinitely recurse
    // while traversing the graph of the Plank
    //
    // Checking a value is done by first defining a point of view/frame of reference and then
    // evaluating a value.
    //
    //
    // What is it used for?
    //
    // A Plank can be used to store and exchange information. It can be designed to evaluate
    // mechanically in order to produce an intentionally interesting state at the end.
    //
    // A neural net can be implemented on a Plank
    //
    // How is it used?
    //
    // A Plank needs to be able to record an instance of the universe from the point of view of
    // a conscious entity. The entity experiences the universe as the 17 dimensional structure
    // of concentric rings that are connected through edges. Therefore the Plank has a singular
    // point of view and includes a function,
    //
    //  get_pov

};


#endif //DRAGONS_PLANK_H

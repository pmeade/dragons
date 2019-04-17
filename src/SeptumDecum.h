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


struct SeptumDecum {
    MinSet minSet;
    typedef array<DimensionalDisc, num_dimensions> Aspects;
    Aspects aspects;

    SeptumDecum() :
        aspects{{
            DimensionalDisc{1, Prime{1}, 1, 0},
            DimensionalDisc{2, Prime::Nth(1), 1, 0},
            DimensionalDisc{3, Prime::Nth(2), 1, 0},
            DimensionalDisc{4, Prime::Nth(3), 1, 0},
            DimensionalDisc{5, Prime::Nth(4), 1, 0},
            DimensionalDisc{6, Prime::Nth(5), 1, 0},
            DimensionalDisc{7, Prime::Nth(6), 1, 0},
            DimensionalDisc{8, Prime::Nth(7), 1, 0},
            DimensionalDisc{9, Prime::Nth(8), 1, 0},
            DimensionalDisc{10, Prime::Nth(9), 1, 0},
            DimensionalDisc{11, Prime::Nth(10), 1, 0},
            DimensionalDisc{12, Prime::Nth(11), 1, 0},
            DimensionalDisc{13, Prime::Nth(12), 1, 0},
            DimensionalDisc{14, Prime::Nth(13), 1, 0},
            DimensionalDisc{15, Prime::Nth(14), 1, 0},
            DimensionalDisc{16, Prime::Nth(15), 1, 0},
            DimensionalDisc{17, Prime::Nth(16), 1, 0}}}
            {}

    SeptumDecum(const MinSet &minSet, const Aspects &aspects) : minSet(minSet), aspects(aspects) {}


    friend ostream &operator<<(ostream &os, const SeptumDecum &plank) {
        os << plank.minSet << endl;
        for (auto &d : plank.aspects){
            os << d << endl;
        }
        return os;
    }

    bool operator==(const SeptumDecum &rhs) const {
        if (minSet != rhs.minSet) return false;
        for (auto i = 0; i < num_dimensions; ++i)
        {
            if (aspects[i] != rhs.aspects[i]) return false;
        }

        return true;
    }

    bool operator!=(const SeptumDecum &rhs) const {
        return !(rhs == *this);
    }

    virtual bool has_edge(House from, House to) const = 0;

    virtual Prime value() const = 0;
};

class DragonPlank : public SeptumDecum
{
    DragonPlank() = default;

 public:

    void add_edge(House from, House to, Prime weight) {
        aspects[from.aspect - 1].add_edge(from.number, to, weight);
        aspects[from.aspect - 1].spin(-weight);
        aspects[to.aspect - 1].spin(weight);
    }

    Prime value() const override {
        auto sum = std::accumulate(minSet.begin(), minSet.end(), 0);
        int highest_value = Prime::Nth(17);
        sum %= highest_value;
        auto p = Prime{sum};
        return p;
    }

    void advance() {
        for (auto &d : aspects){
            d.advance();
        }
    }

    bool has_edge(House from, House to) const override {
        return aspects[from.aspect - 1].has_edge(from, to);
    }
};

#endif //DRAGONS_PLANK_H

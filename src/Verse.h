//
// Created by Patrick Meade on 2019-03-22.
//

#ifndef DRAGONS_VERSE_H
#define DRAGONS_VERSE_H


#include "SeptumDecum.h"
#include "Breath.h"
#include "Filament.h"

using namespace std;

class Verse : public SeptumDecum{
public:

    static unique_ptr<Verse> make_world() {
        return make_unique<Verse>();
    }

    unique_ptr<Verse> clone_verse() const {
        return move(make_unique<Verse>(*this));
    }

    void absord_breath(const Breath &breath) {
        for (auto &aspect : aspects){
            for (auto &house : aspect.houses)
            {
                house.value.add(breath.ex(house));
            }
        }
    }

    Prime value() const override {
        Prime sum{0};
        for (auto &aspect : aspects){
            for (auto &house : aspect.houses){
                sum.add(house.get_value());
            }
        }
        return Prime::Nth(1);
    }

    bool has_edge(House from, House to) const override {
        return false;
    }
};


#endif //DRAGONS_VERSE_H

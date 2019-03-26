//
// Created by Patrick Meade on 2019-03-25.
//

#ifndef DRAGONS_BREATH_H
#define DRAGONS_BREATH_H

#include <vector>
using namespace std;

#include "Filament.h"
#include "Schema.h"

class Breath : public SeptumDecum
{
    vector<Filament> filiments;

public:

    static unique_ptr<Breath> new_breath(const Schema &schema){
        auto breath = make_unique<Breath>();

        for (auto &aspect: schema.aspects){
            for (auto &house : aspect.houses){
                auto filiment = house.breath();
                if (filiment != nullptr){
                    breath->filiments.push_back(*filiment);
                }
            }
        }

        return move(breath);
    }


    Prime ex(const House &house) const {
        auto filiment = find_if(filiments.begin(), filiments.end(), [=](const Filament &fili){ return house == fili.house;});
        if (filiment != filiments.end()) return filiment->value;
        return Prime{1};
    }

    bool has_edge(House from, House to) const override {
        return false;
    }

    Prime value() const override {
        return aspects[0].houses[0].value;
    }

    const vector<Filament> &get_filiments() const { return filiments; }
};

#include "SeptumDecum.h"

#endif //DRAGONS_BREATH_H

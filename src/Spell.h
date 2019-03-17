//
// Created by Patrick Meade on 2019-03-06.
//

#ifndef DRAGONS_SPELL_H
#define DRAGONS_SPELL_H

#include <ostream>
#include "Dragons.h"
#include "Plank.h"
#include "Dragon.h"

using namespace dragon_constants;

class Spell {

    Plank plank;
    int dragon_id;
public:
    Spell(int dragon_id, int power) : dragon_id(dragon_id) {}
};


#endif //DRAGONS_SPELL_H

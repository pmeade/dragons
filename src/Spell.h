//
// Created by Patrick Meade on 2019-03-06.
//

#ifndef DRAGONS_SPELL_H
#define DRAGONS_SPELL_H

#include <ostream>
#include "Dragons.h"
#include "Schema.h"

class Spell : public SeptumDecum{

public:

    Prime value() const override { return Prime{1};}

    bool has_edge(House from, House to) const override {
        return aspects[from.aspect - 1].has_edge(from, to);
    }

    static unique_ptr<Spell> make_spell(){
        return make_unique<Spell>();
    }
};


#endif //DRAGONS_SPELL_H

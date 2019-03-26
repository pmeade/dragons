//
// Created by Patrick Meade on 2019-03-25.
//

#ifndef DRAGONS_FILIMENT_H
#define DRAGONS_FILIMENT_H

#include "Dragons.h"
#include "House.h"

struct Filament {
    House house;
    Prime value;
    Filament(const House &h, const Prime &v) : house{h}, value{v}{}
};


#endif //DRAGONS_FILIMENT_H

//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_DRAGON_H
#define DRAGONS_DRAGON_H
#include <memory>
#include <iostream>

#include "Plank.h"

using namespace std;

class Dragon {
    int id;
    explicit Dragon(int id) : id(id) {}

public:
    int get_id() const {
        return id;
    }

    Plank breathe(const Plank &cone, const Plank &world){

        Plank new_world;

        // walk through cone, updating world as we go
        // Start with the cone value and pass
        // that to the first node
        auto fx = cone.value();
        for (int d = 0; d < num_higher_dimensions; ++d){
            auto &dim = cone.higher_dimensions[d];
            for (int h = 0; h < dim.num_houses; ++h)
            {
                auto actual_house_index = (h + dim.facing) % dim.num_houses;
                auto &house = dim.houses[actual_house_index];
                fx = house.func.f(fx);

                auto &world_house = world.higher_dimensions[d].houses[actual_house_index];
                auto &new_world_house = new_world.higher_dimensions[d].houses[actual_house_index];
                new_world_house.value = world_house.func.f(fx);

                auto target_dimension = dim.edges[actual_house_index].target_dimension;
                if (target_dimension != 0){
                    d = target_dimension - 1;
                    auto target_house = dim.edges[actual_house_index].target_house;
                    h = target_house - 1;
                }
            }
        }



        return new_world;
    }

    static bool Test(){
        Dragon dragon(5);
        if (dragon.get_id() != 5){
            cout << "Dragon failed to set id" << endl;
            return false;
        }

        return true;
    }

    static unique_ptr<Dragon> make_dragon(){
        static int id_source = 0;
        return unique_ptr<Dragon>(new Dragon(++id_source));
    }
};


#endif //DRAGONS_DRAGON_H

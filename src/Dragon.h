//
// Created by Patrick Meade on 2019-03-07.
//

#ifndef DRAGONS_DRAGON_H
#define DRAGONS_DRAGON_H
#include <memory>
#include <iostream>

#include "Spell.h"
#include "Verse.h"
#include "Breath.h"


using namespace std;

class Dragon {
    int id;

    unique_ptr<Schema> schema;

public:

    explicit Dragon(int id) : id(id), schema(Schema::new_schema()) {}
    int get_id() const {
        return id;
    }

    void hold_schema(unique_ptr<Schema> s){
        schema = move(s);
    }

    const Schema &view_schema() const { return *schema;}

    void draw_edge(House from, House to, Prime weight){
        schema->add_edge(from, to, weight);
    }

    bool has_edge(House from, House to) const {
        return schema->aspects[from.aspect-1].houses[from.number - 1].has_edge(to);
    }

    void set_house_value(House house, Prime value){
        schema->aspects[house.aspect-1].houses[house.number-1].value = value;
    }

    Prime check_house_value(House house) const {
        return schema->aspects[house.aspect-1].houses[house.number-1].value;
    }


    unique_ptr<Breath> breathe(Prime input) {
        schema->pulse(input);
        return Breath::new_breath(*schema);
    }

    static unique_ptr<Dragon> make_dragon(){
        static int id_source = 0;
        return move(make_unique<Dragon>(++id_source));
    }
};


#endif //DRAGONS_DRAGON_H

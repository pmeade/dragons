//
// Created by Patrick Meade on 2019-03-25.
//

#ifndef DRAGONS_CHAIN_H
#define DRAGONS_CHAIN_H

#include <map>
#include <set>
#include <queue>
#include "DragonState.h"
#include "Verse.h"

using namespace std;

class Chain {
    Verse verse;
    set<int> accounts;
    map<int, set<DragonState>> dragons;
    map<int, string> state;
    map<int, vector<SchemaState>> schemas;
    queue<Breath> breaths;

public:
    static unique_ptr<Chain> new_chain(){
        return move(make_unique<Chain>());
    }

    void add_account(int id, string initial_state){
        if (!has_account(id)){
            accounts.insert(id);
            state[id] = initial_state;
            dragons[id] = set<DragonState>{};
            schemas[id] = vector<SchemaState>();
        }
    }

    bool has_account(int id) const {
        return accounts.count(id) > 0;
    }

    void update_state(int id, string new_state) {
        if (has_account(id)){
            state[id] = new_state;
        }
    }

    string get_state(int id) const {
        return (has_account(id)) ? state.at(id):string();
    }

    void add_dragon(int id, const DragonState &dragon){
        if (has_account(id) && !has_dragon(id, dragon)){
            dragons[id].insert(dragon);
        }
    }

    bool has_dragon(int id, const DragonState &dragon) const {
        return has_account(id) && dragons.at(id).count(dragon) > 0;
    }

    const set<DragonState> get_dragons(int id) const {
        if (has_account(id)){
            return dragons.at(id);
        }

        return set<DragonState>();
    }

    void add_breath(const Breath &breath) {
        breaths.push(breath);
    }

    const queue<Breath> get_breaths() const { return breaths;}

    const Verse &get_verse() const { return verse; }

    void add_schema(int id, const SchemaState &schema) {
        if (has_account(id)) {
            schemas[id].push_back(schema);
        }
    }

    const vector<SchemaState> get_schemas(int id) const {
        return (has_account(id)) ? schemas.at(id) : vector<SchemaState>();
    }

    void process_breaths(queue<Breath> processed, const Verse &new_verse){
        auto work_queue {breaths};
        while (!processed.empty()){
            if (work_queue.front() == processed.front()){
                processed.pop();
                work_queue.pop();
            }
        }

        if (processed.empty()){
            verse = new_verse;
            std::swap(breaths, work_queue);
        }
    }

};


#endif //DRAGONS_CHAIN_H

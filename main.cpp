#define _USE_MATH_DEFINES_

#include <iostream>
#include "Plank.h"
#include "Dragons.h"
#include "Dragon.h"
#include "MinSet.h"
#include "Spell.h"

using namespace std;
using namespace dragon_constants;

void run_simulation()
{

}

bool unit_tests() {

    cout << "Test MinSet" << endl;
    if (!MinSet::Test()) {
        cout << "Minset Failed" << endl;
        return false;
    }

    cout << "Test Edge" << endl;
    if (!Edge::Test()){
        cout << "Edge failed" << endl;
        return false;
    }

    cout << "Test DimensionDisc" << endl;
    if (!DimensionalDisc::Test()) {
        cout << "DimensionDisc Failed" << endl;
        return false;
    }

    if (!Plank::Test()){
        std::cout << "Plank failed" << endl;
        return false;
    }

    if (!Dragon::Test()){
        std::cout << "Plank failed" << endl;
        return false;
    }

    if (!Spell::Test()){
        std::cout << "Plank failed" << endl;
        return false;
    }

    std::cout << "Unit Tests Success" << std::endl;

    return true;
}


int main() {

    std::cout << "Hello Dragons!" << std::endl;

    if (unit_tests())
    {
        srand(time(NULL));
        run_simulation();
    }

    return 0;
}
#ifndef LEVEL3TEST_H
#define LEVEL3TEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Level3.h"

using namespace sf;
using namespace std;

class Level3Test {
    public:
        void runTests() {
            testConstructor();
            testSetupLevel();
        }

    private:

        void testConstructor() {
            Level3 level;
            if (level.get_Rocket() != nullptr || level.get_Monster() != nullptr) {
                cout << "Level3 constructor test failed!" << endl;
            }
        }

        void testSetupLevel() {
            Level3 level;
            level.setupLevel();
            if (level.get_Rocket() == nullptr || level.get_Monster() == nullptr) {
                cout << "Level3 setupLevel test failed!" << endl;
            }
        }
};

#endif

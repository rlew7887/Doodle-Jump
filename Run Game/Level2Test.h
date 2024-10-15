#ifndef LEVEL2TEST_H
#define LEVEL2TEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Level1.h"
#include "Level2.h"

using namespace sf;
using namespace std;

class Level2Test {
    public:
        void runTests() {
            testConstructor();
            testSetupLevel();
        }

    private:

        void testConstructor() {
            Level2 level;
            if (level.get_HotAirBalloon() != nullptr) {
                cout << "Level2 constructor test failed!" << endl;
            }
        }

        void testSetupLevel() {
            Level2 level;
            level.setupLevel();
            if (level.get_HotAirBalloon() == nullptr) {
                cout << "Level2 setupLevel test failed!" << endl;
            }
        }
};

#endif

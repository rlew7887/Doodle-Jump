#ifndef LEVEL1TEST_H
#define LEVEL1TEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Level1.h"

using namespace sf;
using namespace std;

class Level1Test {
    public:
        void runTests() {
            testConstructor();
            testSetupLevel();
        }

    private:

        void testConstructor() {
            Level1 level;
            if (level.get_NormalPlat() != nullptr || level.get_BrokenPlat() != nullptr || level.get_Boots() != nullptr) {
                cout << "Level1 constructor test failed!" << endl;
            }
        }

        void testSetupLevel() {
            Level1 level;
            level.setupLevel();
            if (level.get_NormalPlat() == nullptr || level.get_BrokenPlat() == nullptr || level.get_Boots() == nullptr) {
                cout << "Level1 setupLevel test failed!" << endl;
            }
        }
};

#endif

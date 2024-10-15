#ifndef NORMALPLATTEST_H
#define NORMALPLATTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "NormalPlat.h"

using namespace sf;
using namespace std;

class NormalPlatTest {
public:
    void runTests() {
        testConstructor();
        testShiftDown();
    }

private:
    void testConstructor() {
        NormalPlat normalPlat;
        if (normalPlat.plat[0].x != 250 || normalPlat.plat[0].y != 800) {
            cout << "NormalPlat constructor test failed!" << endl;
        }
    }

    void testShiftDown() {
        NormalPlat normalPlat;
        normalPlat.shiftDown(10.0f);

        //ensure platforms are shifted down correctly
        if (normalPlat.plat[0].y > 50 || normalPlat.plat[0].y < 0 ) { // Once platform is below 750, it gets regenerated between 0-50
            cout << "NormalPlat shift down test failed!" << endl;
        }
    }
};

#endif

#ifndef BROKENPLATTEST_H
#define BROKENPLATTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BrokenPlat.h"

using namespace sf;
using namespace std;

class BrokenPlatTest {
public:
    void runTests() {
        testConstructor();
        testShiftDown();
    }

private:
    void testConstructor() {
        BrokenPlat brokenPlat;
        if (brokenPlat.plat[0].x != 250 || brokenPlat.plat[0].y != 800) {
            cout << "BrokenPlat constructor test failed!" << endl;
        }
    }

    void testShiftDown() {
        BrokenPlat brokenPlat;
        brokenPlat.shiftDown(10.0f);

        // Ensure platforms are shifted down correctly
        if (brokenPlat.plat[0].y > 50 || brokenPlat.plat[0].y < 0 ) { // Once platform is below 750, it gets regenerated between 0-50
            cout << "BrokenPlat shift down test failed!" << endl;
        }
    }
};

#endif

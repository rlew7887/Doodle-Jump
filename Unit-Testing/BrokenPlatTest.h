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
        testRender();
        testShiftDown();
    }

private:
    void testConstructor() {
        BrokenPlat brokenPlat;
        if (brokenPlat.plat[0].x != 250 || brokenPlat.plat[0].y != 800) {
            cout << "BrokenPlat constructor test failed!" << endl;
        }
    }

    void testRender() {
        RenderWindow window(VideoMode(500, 800), "BrokenPlat Render Test");
        BrokenPlat brokenPlat;
        brokenPlat.render(&window);

        //check if platforms are within valid screen bounds
        for (int i = 0; i < 2; ++i) {
            if (brokenPlat.plat[i].x < 0 || brokenPlat.plat[i].x > 420 ||
                brokenPlat.plat[i].y < 0 || brokenPlat.plat[i].y > 800) {
                cout << "BrokenPlat render test failed: Invalid platform position!" << endl;
            }
        }
    }

    void testShiftDown() {
        BrokenPlat brokenPlat;
        brokenPlat.shiftDown(10.0f);

        // Ensure platforms are shifted down correctly
        if (brokenPlat.plat[0].y != 810) {
            cout << "BrokenPlat shift down test failed!" << endl;
        }
    }
};

#endif

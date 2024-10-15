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
        testRender();
        testShiftDown();
    }

private:
    void testConstructor() {
        NormalPlat normalPlat;
        if (normalPlat.plat[0].x != 250 || normalPlat.plat[0].y != 800) {
            cout << "NormalPlat constructor test failed!" << endl;
        }
    }

    void testRender() {
        RenderWindow window(VideoMode(500, 800), "NormalPlat Render Test");
        NormalPlat normalPlat;
        normalPlat.render(&window);

        //check if platforms are within valid screen bounds
        for (int i = 0; i < 10; ++i) {
            if (normalPlat.plat[i].x < 0 || normalPlat.plat[i].x > 420 ||
                normalPlat.plat[i].y < 0 || normalPlat.plat[i].y > 800) {
                cout << "NormalPlat render test failed: Invalid platform position!" << endl;
            }
        }
    }

    void testShiftDown() {
        NormalPlat normalPlat;
        normalPlat.shiftDown(10.0f);

        //ensure platforms are shifted down correctly
        if (normalPlat.plat[0].y != 810) {
            cout << "NormalPlat shift down test failed!" << endl;
        }
    }
};

#endif

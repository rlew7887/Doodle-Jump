#ifndef PLATFORMTEST_H
#define PLATFORMTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"

using namespace sf;
using namespace std;

class PlatformTest {
public:
    void runTests() {
        testGeneratePlatforms();
        testShiftDown();
        testRender();
    }

private:
    void testGeneratePlatforms() {
        Platform platform;
        platform.generatePlatforms(10);

        //ensure that platforms are generated within valid screen bounds
        for (int i = 0; i < 10; ++i) {
            if (platform.plat[i].x < 0 || platform.plat[i].x > 420 ||
                platform.plat[i].y < 0 || platform.plat[i].y > 800) {
                cout << "Platform generate test failed!" << endl;
            }
        }
    }

    void testShiftDown() {
        Platform platform;
        platform.shiftDown(10.0f);

        //ensure platforms are shifted down correctly
        if (platform.plat[0].y != 810) {
            cout << "Platform shift down test failed!" << endl;
        }
    }

    void testRender() {
        RenderWindow window(VideoMode(500, 800), "Platform Render Test");
        Platform platform;
        platform.render(&window);

        //ensure platforms are rendered within valid screen bounds
        for (int i = 0; i < 10; ++i) {
            if (platform.plat[i].x < 0 || platform.plat[i].x > 420 ||
                platform.plat[i].y < 0 || platform.plat[i].y > 800) {
                cout << "Platform render test failed!" << endl;
            }
        }
    }
};

#endif

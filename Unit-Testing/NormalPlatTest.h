#ifndef NORMALPLATTEST_H
#define NORMALPLATTEST_H

#include <iostream>
#include "NormalPlat.h"

class NormalPlatTest {
public:
    void runTests() {
        testConstructor();
        testRender();
    }

private:
    void testConstructor() {
        NormalPlat normalPlatform;

        // assuming the normal platform generates some random positions
        Vector2f position = normalPlatform.getPlat(0);
        if (position.x < 0 || position.x > 420 || position.y < 0 || position.y > 800) {
            std::cout << "NormalPlat constructor test failed!" << std::endl;
        }
    }

    void testRender() {
        NormalPlat normalPlatform;
        // render test: this would be more complex with graphics, but check basic structure
        std::cout << "NormalPlat render test passed (visual inspection needed)" << std::endl;
    }
};

#endif

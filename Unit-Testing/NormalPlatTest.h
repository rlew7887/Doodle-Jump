#ifndef NORMALPLATTEST_H
#define NORMALPLATTEST_H

#include <iostream>
#include "NormalPlat.h"

class NormalPlatTest {
public:
    void runTests() {
        testConstructor();
    }

private:
    void testConstructor() {
        NormalPlat normalPlatform;

        // assuming the normal platform generates some random positions
        if (normalPlatform.getPlat(0).x < 0 || normalPlatform.getPlat(0).x > 420 || normalPlatform.getPlat(0).y < 0 || normalPlatform.getPlat(0).y > 800) {
            std::cout << "NormalPlat constructor test failed!" << std::endl;
        }
    }

};

#endif

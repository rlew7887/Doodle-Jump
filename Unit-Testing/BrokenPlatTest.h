#ifndef BROKENPLATTEST_H
#define BROKENPLATTEST_H

#include <iostream>
#include "BrokenPlat.h"

class BrokenPlatTest {
public:
    void runTests() {
        testConstructor();
    }

private:
    void testConstructor() {
        BrokenPlat brokenPlatform;
        if (brokenPlatform.getPlat(0).x < 0 || brokenPlatform.getPlat(0).x > 420 || brokenPlatform.getPlat(0).y < 0 || brokenPlatform.getPlat(0).y > 800) {
            std::cout << "BrokenPlat constructor test failed!" << std::endl;
        }
    }
};

#endif

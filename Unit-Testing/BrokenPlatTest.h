#ifndef BROKENPLATTEST_H
#define BROKENPLATTEST_H

#include <iostream>
#include "BrokenPlat.h"

class BrokenPlatTest {
public:
    void runTests() {
        testConstructor();
        testBreakPlatform();
    }

private:
    void testConstructor() {
        BrokenPlat brokenPlatform;
        Vector2f position = brokenPlatform.getPlat(0);

        if (position.x < 0 || position.x > 420 || position.y < 0 || position.y > 800) {
            std::cout << "BrokenPlat constructor test failed!" << std::endl;
        }
    }

    void testBreakPlatform() {
        BrokenPlat brokenPlatform;
        bool isBroken = brokenPlatform.breakPlatform(0); //simulate breaking the platform

        if (!isBroken) {
            std::cout << "BrokenPlat breakPlatform test failed!" << std::endl;
        } else {
            std::cout << "BrokenPlat breakPlatform test passed!" << std::endl;
        }
    }
};

#endif

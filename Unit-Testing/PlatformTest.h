#ifndef PLATFORMTEST_H
#define PLATFORMTEST_H

#include <iostream>
#include "Platform.h"

class PlatformTest {
public:
    void runTests() {
        testGeneratePlatforms();
        testGetPlat();
    }

private:
    void testGeneratePlatforms() {
        Platform platform;
        platform.generatePlatforms(10);

        //check if platforms have been generated correctly
        for (int i = 0; i < 10; i++) {
            auto pos = platform.getPlat(i);
            if (pos.x < 0 || pos.x > 420 || pos.y < 0 || pos.y > 800) {
                std::cout << "Platform generatePlatforms test failed at index " << i << std::endl;
            }
        }
    }

    void testGetPlat() {
        Platform platform;
        platform.generatePlatforms(10);

        // check if getPlat returns correct values
        for (int i = 0; i < 10; i++) {
            if (platform.getPlat(i).x < 0 || platform.getPlat(i).x > 420 || platform.getPlat(i).y < 0 || platform.getPlat(i).y > 800) {
                std::cout << "Platform getPlat test failed at index " << i << std::endl;
            }
        }
    }
};

#endif

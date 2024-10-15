#ifndef ROCKETTEST_H
#define ROCKETTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rocket.h"

using namespace sf;
using namespace std;

class RocketTest {
    public:
        void runTests() {
            testConstructor();
            testSetupPowerUp();
            testApplyEffect();
            testShiftDown();
        }

    private:

        void testConstructor() {
            Rocket testRocket;
            Vector2f testPosition = testRocket.getRocket().getPosition();  // Check initial position
            if (testPosition.x != 100 || testPosition.y != 0) {
                cout << "Rocket constructor test failed!" << endl;
            }
        }

        void testSetupPowerUp() {
            Rocket testRocket;
            testRocket.setupPowerUp();  // Call setup function
            
            // Check if texture is loaded 
            if (testRocket.getRocket().getTexture() == nullptr) {
                cout << "Rocket setupPowerUp test failed!" << endl;
            }
        }

        void testApplyEffect() {
            Rocket testRocket;
            testRocket.applyEffect();
            if (!testRocket.getHasAppliedEffect()) {
                cout << "Apply effect test failed!" << endl;
            }
        }
        

        void testShiftDown() {
            Rocket testRocket;
            testRocket.rocketPoint = {100, 20};  // Set initial position
            int initialY = testRocket.rocketPoint.y;
            testRocket.shiftDown(10, 100);  // Shift down by 10 units

            if (testRocket.rocketPoint.y <= initialY) {
                cout << "Shift down test failed!" << endl;
            }
        }
};

#endif

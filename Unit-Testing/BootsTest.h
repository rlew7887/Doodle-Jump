#ifndef BOOTSTEST_H
#define BOOTSTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Boots.h"
#include "Platform.h"
#include "PowerUps.h"
#include "Player.h"

using namespace sf;
using namespace std;

class BootsTest {
    public:
        void runTests() {
            testConstructor();
            testSetupPowerUp();
            testApplyEffect();
            testShiftDown();
        }

    private:
        // Test constructor behaviour
        void testConstructor() {
            Boots testBoots;
            Vector2f testPoint = testBoots.getBoots().getPosition();
            // Check if boots position is initialised correctly
            if (testPoint.x != 100 || testPoint.y != 0) {
                cout << testBoots.getPoint().x << ", " << testBoots.getPoint().y << endl;
                cout << "Boots constructor test failed!" << endl;
            }
        }

        // Test if setupPowerUp correctly initializes the boots power-up
        void testSetupPowerUp() {
            Boots testBoots;
            testBoots.setupPowerUp();
            Vector2f testPoint = testBoots.getBoots().getPosition();

            // Check if boots position is initialised correctly
            if (testPoint.x != 100 || testPoint.y != 0) {
                cout << "Setup power-up test failed!" << endl;
            }
        }

        // Test if the applyEffect correctly sets hasAppliedEffect to true
        void testApplyEffect() {
            Boots testBoots;
            testBoots.applyEffect();
            if (!testBoots.getHasAppliedEffect()) {
                cout << "Apply effect test failed!" << endl;
            }
        }

        // Test shiftDown functionality and ensure it moves the boots down by a specific distance
        void testShiftDown() {
            Boots testBoots;
            PowerUps::Point originalPoint = testBoots.getPoint();
            testBoots.shiftDown(10.0f, 100); // Move down by 10 units
            PowerUps::Point newPoint = testBoots.getPoint();
            if (newPoint.y != originalPoint.y + 10) {
                cout << "Shift down test failed!" << endl;
            }
        }
};

#endif

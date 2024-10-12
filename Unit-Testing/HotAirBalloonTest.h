#ifndef HOTAIRBALLOONTEST_H
#define HOTAIRBALLOONTEST_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HotAirBalloon.h"
#include "Platform.h"

using namespace sf;
using namespace std;

class HotAirBalloonTest {
public:
    void runTests() {
        testConstructor();
        testSetupPowerUp();
        testApplyEffect();
        testUpdateEffect();
        testShiftDown();
    }

private:
    void testConstructor() {
        HotAirBalloon balloon;
        Sprite testSprite = balloon.getBalloon();
        if (testSprite.getTexture() == nullptr) {
            cout << "HotAirBalloon constructor test failed: Texture not loaded!" << endl;
        }
    }

    void testSetupPowerUp() {
        HotAirBalloon balloon;
        balloon.setupPowerUp();
        Vector2f position = balloon.getBalloon().getPosition();
        if (position.x < 0 || position.x > 420 || position.y < 0 || position.y > 20) {
            cout << "HotAirBalloon setupPowerUp test failed: Invalid position!" << endl;
        }
    }

    void testApplyEffect() {
        HotAirBalloon balloon;
        balloon.applyEffect();
        if (!balloon.getHasAppliedEffect()) { 
            cout << "HotAirBalloon applyEffect test failed: Effect not applied!" << endl;
        }
    }

    void testUpdateEffect() {
        HotAirBalloon balloon;
        Platform testPlatform;

        float previousPos = testPlatform.getPlat(5).y; // store previous y pos

        balloon.applyEffect(); // Simulate power-up being collected
        balloon.updateEffect(&testPlatform, true); // Pass powerUpCollected as true
        
        // Verify if the platform is shifted down
        if (testPlatform.getPlat(5).y != previousPos+50.0f) {
            cout << "HotAirBalloon updateEffect test failed: Platform not shifted down!" << endl;
        } 
    }

    void testShiftDown() {
        HotAirBalloon balloon;
        int score = 700; // Test condition where a power-up should be generated
        balloon.shiftDown(50.0f, score); 
        Vector2f balloonPosition = balloon.getBalloon().getPosition();
        
        // Check if the balloon's y-coordinate increased (shifted down)
        if (balloonPosition.y <= 0) {
            cout << "HotAirBalloon shiftDown test failed: Balloon not shifted down!" << endl;
        } 
    }
};

#endif

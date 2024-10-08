#ifndef PLAYERTEST_H
#define PLAYERTEST_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Platform.h"
#include "Home.h"
#include "gameOver.h"
#include "Level1.h"
#include "NormalPlat.h"
#include "Button.h"

using namespace sf;
using namespace std;

class PlayerTest {
    public:
        void runTests() {
            testConstructor();
            testMoveLeft();
            testMoveRight();
            testJump();
        }
        
    private:
        
        void testConstructor() {
            Player testPlayer;
            Vector2f testPosition = testPlayer.get_Position();
            if (testPosition.x != 250 && testPosition.y != 700) {
                cout << "Constructor test failed!" << endl;
            }
        }

        void testMoveLeft() {
            Player testPlayer;
            float FPS = (1.0f/120.0f);
            testPlayer.moveLeft(FPS);
            Vector2f testPosition = testPlayer.get_Position();
            if (testPosition.x != (250-(370*FPS))) {
                cout << "Move left test failed!" << endl;
            }
        }

        void testMoveRight() {
            Player testPlayer;
            float FPS = (1.0f/120.0f);
            testPlayer.moveRight(FPS);
            Vector2f testPosition = testPlayer.get_Position();
            if (testPosition.x != (250+(370*FPS))) {
                cout << "Move right test failed!" << endl;
            }
        }

        void testJump() {
            Player testPlayer;
            Platform* testPlatform = new Platform();
            float velocity = 0.0f; // No jump
            float FPS = (1.0f/120.0f);
            testPlayer.jump(velocity, FPS, *testPlatform);  
            Vector2f testPosition = testPlayer.get_Position();
            if (testPosition.y != 700.0f) { // No jumping occured, so height should remain the same
                cout << "Jump test failed!" << endl;
            }

            delete testPlatform;
        }

};

#endif
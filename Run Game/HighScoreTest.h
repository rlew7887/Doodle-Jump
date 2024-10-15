#ifndef HIGHSCORE_TEST_H
#define HIGHSCORE_TEST_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HighScore.h"

using namespace sf;
using namespace std;

class HighScoreTest {
    public:
        void runTests() {
            testConstructor();
            testAddScore();
        }
        
    private:
        
        void testConstructor() {
            HighScore highscoreTest;

            // Ensure all top scores are initialized to 0
            bool allZero = true;
            for (int i = 0; i < 10; ++i) {
                if (highscoreTest.getTopScore() != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if (!allZero) {
                cout << "HighScore constructor test failed!" << endl;
            }
        }

        void testAddScore() {
            HighScore highscoreTest;
            highscoreTest.addScore(9999999); // Highest score
            if (highscoreTest.getTopScore() != 9999999) { // Score should be sorted in descending order
                cout << "Add score test failed!" << endl;
            }
        }
};

#endif

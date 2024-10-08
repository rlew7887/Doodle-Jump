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
            for (int i = 0; i<10; i++) {
                if (highscoreTest.getTopScores(i) != 0) {
                    cout << "Constructor test failed!" << endl;
                }
            }
        }

        void testAddScore() {
            HighScore highscoreTest;
            highscoreTest.addScore(100);
            highscoreTest.addScore(1);
            highscoreTest.addScore(37.7);
            highscoreTest.addScore(80);
            highscoreTest.addScore(12);
            highscoreTest.addScore(24);
            highscoreTest.addScore(9999999);
            highscoreTest.addScore(7892);
            highscoreTest.addScore(3);
            highscoreTest.addScore(54);
            highscoreTest.addScore(6);
            highscoreTest.addScore(0);

            if (
                highscoreTest.getTopScores(0) != 9999999 ||
                highscoreTest.getTopScores(1) != 7892 ||
                highscoreTest.getTopScores(2) != 100 ||
                highscoreTest.getTopScores(3) != 80 ||
                highscoreTest.getTopScores(4) != 54 ||
                highscoreTest.getTopScores(5) != 37.7 ||
                highscoreTest.getTopScores(6) != 24 ||
                highscoreTest.getTopScores(7) != 12 ||
                highscoreTest.getTopScores(8) != 6 ||
                highscoreTest.getTopScores(9) != 3
            ) {
                cout << "Add score test failed!" << endl;
            }


        }

};

#endif
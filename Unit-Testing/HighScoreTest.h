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
            testFileIO();
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

            // Adding scores to the leaderboard
            highscoreTest.addScore(100);
            highscoreTest.addScore(50);
            highscoreTest.addScore(999);
            highscoreTest.addScore(0);
            highscoreTest.addScore(25);
            highscoreTest.addScore(9999);
            highscoreTest.addScore(250);
            highscoreTest.addScore(75);
            highscoreTest.addScore(500);
            highscoreTest.addScore(9999999); // Highest score
            highscoreTest.addScore(10);

            // Check the sorted order of the top 10 scores
            int expectedScores[] = {9999999, 9999, 999, 500, 250, 100, 75, 50, 25, 10};

            bool testPassed = true;
            if (highscoreTest.getTopScore() != expectedScores[0]) {
                testPassed = false;
            }
            

            if (!testPassed) {
                cout << "Add score test failed!" << endl;
            } 
        }

        void testFileIO() {
            HighScore highscoreTest;

            // Adding scores to the leaderboard
            highscoreTest.addScore(100);
            highscoreTest.addScore(500);
            highscoreTest.addScore(9999);

            // Save the scores to a file
            highscoreTest.saveScoresToFile();

            // Create a new instance and load the scores
            HighScore newHighscoreTest;
            newHighscoreTest.readScoresToFile();

            // Ensure scores were loaded correctly
            bool testPassed = true;
            int expectedScores[] = {9999, 500, 100, 0, 0, 0, 0, 0, 0, 0};
            
            if (newHighscoreTest.getTopScore() != expectedScores[0]) {
                testPassed = false;
            }

            if (!testPassed) {
                cout << "File I/O test failed!" << endl;
            }
        }

};

#endif

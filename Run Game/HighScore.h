#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Home.h"
using namespace sf;

class HighScore{
protected:
    int* highScores;
    int capacity;
    int size;
    Font font;
    Button* homeBTN;
public:
    HighScore();
    void home();
    void addScore(int score);
    int getTopScore(); //Get highest score from array to display in gameOver
    void saveScoresToFile(int score); //Append highscores to txt file
    void saveSortedScores(); //Overwrite txt file with sorted scores
    void readScoresFromFile();
    void displayTopScores();
    ~HighScore();
};

#endif 
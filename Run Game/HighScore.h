#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Home.h"
using namespace sf;

class Player;

class HighScore{
protected:
    Font font;
    int scoreCount;
    int* highScores;
    Button* homeBTN;
public:
    HighScore();
    //static HighScore& getInstance();
    void home();
    void addScore(int score); //add new score to the leaderboard
    int getTopScore(); //Get highest score from array
    void saveScoresToFile(); //Write highscores to txt file
    void readScoresToFile(); //Read highscores from txt file
    void displayTopScores(Player& player);
    ~HighScore();
};

#endif
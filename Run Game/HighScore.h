#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Home.h"
using namespace sf;

class Player;

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
    int getTopScore(); //Get highest score from array
    void saveScoresToFile(int score); //Write highscores to txt file
    void saveSortedScores();
    void readScoresFromFile(); //Read highscores from txt file
    void displayTopScores(Player& player);
    ~HighScore();
};

#endif 
#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <SFML/Graphics.hpp>
using namespace sf;

class HighScore{
protected:
    Font font;
    int topScore;
    int* highScores;
public:
    HighScore();
    void addScore(int score); //add new score to the leaderboard
    int getTopScores(int index); //May not be neccessary because inGame already has a getScore() function
    void saveScoresToFile();
    void readScoresToFile();
    void displayTopScores();
    ~HighScore();
};

#endif
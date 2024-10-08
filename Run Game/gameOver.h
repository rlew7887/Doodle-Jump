#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

class gameOver { //rename to GameOver class?
  protected:
    //Player player;
    int score;
    Font font;
    Button* playAgainBTN;
    Button* homeBTN;
    Button* LeaderboardBTN;
  public:  
    gameOver(); //default constructor
    void countScore();
    int getScore();
    void playAgain();
    void home();
    void Leaderboard();
    //void gameOver();
    void render();
    ~gameOver(); //destructor
};

#endif

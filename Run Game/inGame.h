#ifndef INGAME_H
#define INGAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Button.h"

using namespace sf;

class inGame {
  protected:
    //Player player;
    int score;
    Font font;
    Button* playAgainBTN;
    Button* homeBTN;
    Button* LeaderboardBTN;
  public:  
    inGame(); //default constructor
    void countScore();
    int getScore();
    void playAgain();
    void home();
    void Leaderboard();
    void gameOver();
    void render();
    ~inGame(); //destructor
};

#endif
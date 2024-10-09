#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

class Player;

class GameOver{
  protected:
    //Player player;
    int score;
    Font font;
    Button* playAgainBTN;
    Button* homeBTN;
    Button* LeaderboardBTN;
  public:  
    GameOver(); //default constructor
    void playAgain();
    void home();
    void Leaderboard();
    //void gameOver();
    void render(Player& player);
    ~GameOver(); //destructor
};

#endif

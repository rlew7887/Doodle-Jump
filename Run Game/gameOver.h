#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "HighScore.h"

using namespace sf;

class Player;
class HighScore;

class GameOver{
  protected:
    //Player player;
    int score;
    Font font;
    Button* playAgainBTN;
    Button* homeBTN;
    Button* LeaderboardBTN;
    HighScore* highscore;
  public:  
    GameOver(); //default constructor
    void playAgain();
    void home();
    void Leaderboard();
    void render(Player& player);
    ~GameOver(); //destructor
};

#endif

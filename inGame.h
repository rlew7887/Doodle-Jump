#ifndef INGAME_H
#define INGAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class inGame {
  protected:
    Player player;
    int score;

  public:  
    void render();
    void gameOver();
    void countScore();
    int getScore();
};

#endif
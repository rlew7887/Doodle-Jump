#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:
    

  public:  
    void moveLeft(RectangleShape& rect);

    void moveRight(RectangleShape& rect);

    void jump();

    void render();
};

#endif
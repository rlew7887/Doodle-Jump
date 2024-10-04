#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:
    RectangleShape defaultPlayer;

  public:  
    Player();

    void moveLeft(RectangleShape& player, float FPS);

    void moveRight(RectangleShape& player, float FPS);

    void jump(RectangleShape& player, float& velocity, float FPS);

    void render();

    ~Player() {}

};

#endif
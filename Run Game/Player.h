#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:
    //RectangleShape defaultPlayer;
    sf::Sprite defaultPlayer;
    sf::Texture sharkPlayer;

  public:  
    Player();

    void moveLeft(float FPS);

    void moveRight(float FPS);

    void jump(float& velocity, float FPS);

    void render();

    ~Player() {}

};

#endif

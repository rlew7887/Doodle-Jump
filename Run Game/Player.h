#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "NormalPlat.h"
#include "inGame.h"
#include "Level1.h"

using namespace sf;

class Player {
  private:
    sf::Sprite defaultPlayer;
    sf::Texture sharkPlayer;
    bool onPlatform;
    Font font;

    inGame* gameOver;

  public:  
    Player();

    void moveLeft(float FPS);

    void moveRight(float FPS);

    void jump(float& velocity, float FPS, Platform& platform);

    void render();

    bool getOnPlatform();

    ~Player() {};

};

#endif

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "NormalPlat.h"
#include "BrokenPlat.h"
#include "gameOver.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

using namespace sf;

class Player {
  private:
    sf::Sprite defaultPlayer;
    sf::Texture sharkPlayer;
    bool onPlatform;
    Font font;
    int score;
    float velocity;
    bool blackholeActive;
    float scaleX;
    float scaleY;
    int scale_count;

    //gameOver gameOver;

  public:  
    Player();

    void moveLeft(float FPS);

    void moveRight(float FPS);

    void jump(float& velocity, float FPS, Platform& platform, BrokenPlat& brokenPlatform);

    int getScore();

    void render();
    void incrementScore(int amount);

    bool getOnPlatform();

    Vector2f get_Position();

    ~Player() {};

};

#endif

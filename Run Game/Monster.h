#ifndef ENEMIES_H
#define ENEMIES_H
#include "Player.h"
#include "Enemies.h"

class Monster{
protected:
    sf::Sprite monster;
    sf::Texture fishMonster;
    float X;
    float Y;
public:
    Monster();
    void onCollide(Player& player);
    void render();
    void randomizeEnemies();
    ~Monster();
};

#endif
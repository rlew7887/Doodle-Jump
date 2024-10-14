#ifndef MONSTER_H
#define MONSTER_H
#include "Player.h"

class Monster{
protected:
    int X;
    int Y;
    sf::Sprite monster;
    sf::Texture fishMonster;
public:
    Monster();
    void render(RenderWindow* window);
    void randomizeEnemies(int score);
    void shiftDown(float distance);
    Sprite getMonster();
    ~Monster();
};

#endif
#ifndef MONSTER_H
#define MONSTER_H
#include "Player.h"
#include "Enemies.h"

class Monster : public Enemies{
protected:
    sf::Sprite monster;
    sf::Texture fishMonster;
public:
    Monster();
    void render(RenderWindow* window);
    void randomizeEnemies(int score);
    Sprite getMonster();
    ~Monster();
};

#endif
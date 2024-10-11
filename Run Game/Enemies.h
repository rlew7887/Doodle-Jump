#ifndef ENEMIES_H
#define ENEMIES_H
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemies{
protected:
    float X;
    float Y;
public:
    Enemies();
    virtual void onCollide(Player& player) = 0;
    void render();
    void randomizeEnemies();
    ~Enemies();
};

#endif
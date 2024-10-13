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
    virtual void render(RenderWindow* window) = 0;
    virtual void randomizeEnemies(int score) = 0;
    ~Enemies();
};

#endif
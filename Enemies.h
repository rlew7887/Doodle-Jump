#ifndef ENEMIES_H
#define ENEMIES_H

class Enemies{
protected:
    float X;
    float Y;
public:
    //virtual void onCollide(Player& player) = 0;
    void render();
    void randomizeEnemies();
};

#endif
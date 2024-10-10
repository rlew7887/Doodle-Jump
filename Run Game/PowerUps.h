#ifndef POWERUPS_H
#define POWERUPS_H

#include <iostream>
#include "Platform.h"

using namespace sf;

class PowerUps {
    private:
        struct Point {int x, y;};

    public:
        Point powerups;
        PowerUps();
        virtual void setupPowerUp() = 0;
        virtual void applyEffect() = 0;
        virtual void render(RenderWindow* window) = 0;
        void shiftDown(float distance, int score);
        Point getPoint();
        virtual ~PowerUps() {};
};

#endif
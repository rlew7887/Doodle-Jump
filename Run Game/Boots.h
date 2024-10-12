#ifndef BOOTS_H
#define BOOTS_H

#include "PowerUps.h"
#include "HotAirBalloon.h"
#include <iostream>

using namespace sf;

class Boots : public PowerUps {
    private:
        Sprite boots;
        Texture bootsTexture;

    public:
        Boots();
        PowerUps::Point bootsPoint;
        void setupPowerUp() override;
        void applyEffect() override;
        void updateEffect(Platform* platform, bool powerUpCollected);
        void shiftDown(float distance, int score) override;
        void render(RenderWindow* window) override;
        Sprite getBoots();

        ~Boots() {}
};

#endif
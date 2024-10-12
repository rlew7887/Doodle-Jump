#ifndef ROCKET_H
#define ROCKET_H

#include "PowerUps.h"
#include "gameOver.h"

class Rocket : public PowerUps {
    private:
        Sprite rocket;
        Texture rocketTexture;
        CircleShape blackhole;
        float blackholeRadius;
        bool blackholeDrawn;

    public:
        PowerUps::Point rocketPoint;
        Rocket();
        void setupPowerUp() override;
        void applyEffect() override;
        void render(RenderWindow* window) override;
        void renderBlackhole(RenderWindow* window);
        void shiftDown(float distance, int score) override;
        Sprite getRocket();
        bool getBlackholeDrawn();

        ~Rocket() {}
};
#endif
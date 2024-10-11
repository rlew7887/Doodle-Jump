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

    public:
        PowerUps::Point rocketPoint;
        Rocket();
        void setupPowerUp() override;
        void applyEffect() override;
        void updateEffect(Platform* platform, bool powerUpCollected) override;
        void render(RenderWindow* window) override;
        void renderBlackhole(RenderWindow* window, int x, int y);
        void shiftDown(float distance, int score);
        Sprite getRocket();
        ~Rocket() {}
};
#endif
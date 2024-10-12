#ifndef HOT_AIR_BALLOON_H
#define HOT_AIR_BALLOON_H

#include "PowerUps.h"
#include "Boots.h"
#include <iostream>

class HotAirBalloon : public PowerUps {
    private:
        Sprite hotAirBalloon;
        Texture BalloonTexture;

    public:
        PowerUps::Point balloon;
        HotAirBalloon();
        void setupPowerUp() override;
        void applyEffect() override;
        void updateEffect(Platform* platform, bool powerUpCollected);
        void render(RenderWindow* window) override;
        void shiftDown(float distance, int score) override;
        Sprite getBalloon();
        ~HotAirBalloon() {}

};
#endif
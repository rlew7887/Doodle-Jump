#ifndef HOT_AIR_BALLOON_H
#define HOT_AIR_BALLOON_H

#include "PowerUps.h"

class HotAirBalloon : public PowerUps {
    private:
        Sprite hotAirBalloon;
        Texture BalloonTexture;

    public:
        void setupPowerUp();
        void applyEffect();
        void render(RenderWindow* window);

};
#endif
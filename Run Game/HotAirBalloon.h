#ifndef HOT_AIR_BALLOON_H
#define HOT_AIR_BALLOON_H

#include "PowerUps.h"
#include "Boots.h"
#include <iostream>

class HotAirBalloon : public PowerUps {
    private:
        bool deleteBalloon;
        bool hasBeenTrue;
        bool hasAppliedEffect;
        bool effectCompleted;
        int totalSteps;   
        int currentStep;
        Sprite hotAirBalloon;
        Texture BalloonTexture;

    public:
        PowerUps::Point balloon;
        HotAirBalloon();
        void setupPowerUp() override;
        void applyEffect() override;
        void updateEffect(Platform* platform, bool powerUpCollected) override;
        void render(RenderWindow* window) override;
        Sprite getBalloon();
        bool getDeleteStatus();
        void setDeleteStatus(bool status);
        bool getHasBeenTrue();
        void setHasBeenTrue(bool status);
        bool getHasAppliedEffect();
        void setHasAppliedEffect(bool status);
        ~HotAirBalloon() {}

};
#endif
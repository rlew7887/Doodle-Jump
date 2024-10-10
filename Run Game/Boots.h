#ifndef BOOTS_H
#define BOOTS_H

#include "PowerUps.h"
#include <iostream>

using namespace sf;

class Boots : public PowerUps {
    private:
        Sprite boots;
        Texture bootsTexture;
        bool deleteBoots;
        bool hasBeenTrue;
        bool hasAppliedEffect;
        bool effectCompleted;
        int totalSteps;   
        int currentStep;

    public:
        Boots();
        void setupPowerUp() override;
        void applyEffect() override;
        void updateEffect(Platform* platform, bool powerUpCollected);
        void render(RenderWindow* window) override;
        Sprite getBoots();
        bool getDeleteStatus();
        void setDeleteStatus(bool status);
        bool getHasBeenTrue();
        void setHasBeenTrue(bool status);
        bool getHasAppliedEffect();
        void setHasAppliedEffect(bool status);
        ~Boots() {}
};

#endif
#ifndef POWERUPS_H
#define POWERUPS_H

#include <iostream>
#include "Platform.h"

using namespace sf;

class PowerUps {
    protected:
        struct Point {int x, y;};
        bool deletePowerUp;
        bool hasBeenTrue;
        bool hasAppliedEffect;
        bool effectCompleted;
        int totalSteps;   
        int currentStep;
        bool powerUpCollected;
        

    public:
        Point powerups;
        PowerUps();
        // Pure virtual functions
        virtual void setupPowerUp() = 0;
        virtual void applyEffect() = 0;
        virtual void updateEffect(Platform* platform, bool powerUpCollected) = 0;
        virtual void render(RenderWindow* window) = 0;

        // Virtual functions
        virtual bool getDeleteStatus();
        virtual void setDeleteStatus(bool status);
        virtual bool getHasBeenTrue();
        virtual void setHasBeenTrue(bool status);
        virtual bool getHasAppliedEffect();
        virtual void setHasAppliedEffect(bool status);
        virtual bool getPowerUpCollected();
        
        void shiftDown(float distance, int score);
        Point getPoint();

        virtual ~PowerUps() {};
};

#endif
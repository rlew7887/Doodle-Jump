#ifndef POWERUPS_H
#define POWERUPS_H

#include <iostream>
#include "Platform.h"

using namespace sf;

class PowerUps {
    protected:
        bool deletePowerUp;
        bool hasBeenTrue;
        bool hasAppliedEffect;
        bool effectCompleted;
        int totalSteps;   
        int currentStep;
        bool powerUpCollected;
        

    public:
        struct Point {int x, y;};
        Point powerups;
        PowerUps();
        // Pure virtual functions
        virtual void setupPowerUp() = 0;
        virtual void applyEffect() = 0;
        virtual void render(RenderWindow* window) = 0;

        // Virtual functions
        virtual bool getDeleteStatus();
        virtual void setDeleteStatus(bool status);
        virtual bool getHasBeenTrue();
        virtual void setHasBeenTrue(bool status);
        virtual bool getHasAppliedEffect();
        virtual void setHasAppliedEffect(bool status);
        virtual bool getPowerUpCollected();
        
        virtual void shiftDown(float distance, int score) = 0;
        Point getPoint();

        virtual ~PowerUps() {};
};

#endif
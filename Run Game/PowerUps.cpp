#include "PowerUps.h"

// Constructor initializing the power-ups list
PowerUps::PowerUps() {
    // Initialise variables
    deletePowerUp = false;
    hasBeenTrue = false;
    hasAppliedEffect = false;
    effectCompleted = false;
    totalSteps = 80;   
    currentStep = 0;
}

void PowerUps::shiftDown(float distance, int score) {
    powerups.y += distance; 

    // Generate one powerup everytime the score is divisible by 1000
    if (score % 500 == 0) {
        powerups.x = rand() % 420;;
        powerups.y = rand() % 50; ; 
    }
}

PowerUps::Point PowerUps::getPoint() {
    return powerups;
}

bool PowerUps::getDeleteStatus() {
    return deletePowerUp;
}

void PowerUps::setDeleteStatus(bool status) {
    deletePowerUp = status;
}


bool PowerUps::getHasBeenTrue() {
    return hasBeenTrue;
}

void PowerUps::setHasBeenTrue(bool status) {
    hasBeenTrue = status;
}

bool PowerUps::getHasAppliedEffect() {
    return hasAppliedEffect;
}

void PowerUps::setHasAppliedEffect(bool status) {
    hasAppliedEffect = status;
}

bool PowerUps::getPowerUpCollected() {
    if (
        getDeleteStatus() == true && 
        getHasBeenTrue() == true &&
        getHasAppliedEffect() == false
    ) {
        return true;
    }
    return false;
}




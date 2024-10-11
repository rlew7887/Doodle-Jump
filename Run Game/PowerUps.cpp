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




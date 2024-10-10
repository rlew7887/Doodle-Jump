#include "HotAirBalloon.h"

HotAirBalloon::HotAirBalloon() {
    // Initialise variables
    deleteBalloon = false;
    hasBeenTrue = false;
    hasAppliedEffect = false;
    effectCompleted = false;
    totalSteps = 50;   
    currentStep = 0;
    setupPowerUp();
}
void HotAirBalloon::setupPowerUp() {
    if (!BalloonTexture.loadFromFile("HotAirBalloon.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    hotAirBalloon.setTexture(BalloonTexture); // set boots texture
    BalloonTexture.setSmooth(true); //smooths the outline
    Vector2u textureSize = BalloonTexture.getSize();  //Get the original texture size
    float scaleX = 60.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 60.0f / textureSize.y;  //Calculate scale factor for height
    hotAirBalloon.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite
}

void HotAirBalloon::applyEffect() {
    currentStep = 0;  // Reset the step counter
    hasAppliedEffect = true; // Set effect as true
}

void HotAirBalloon::updateEffect(Platform* platform, bool powerUpCollected) {
    // If the power-up is collected and the effect is not active
    if (powerUpCollected && !hasAppliedEffect && !hasAppliedEffect) {
        currentStep = 0;    // Reset the step counter
        hasAppliedEffect = true; // Mark effect as active
    }

    // If the effect is active, gradually shift the platform down
    if (hasAppliedEffect) {
        if (currentStep < totalSteps) {
            platform->shiftDown(10.0f); // Shift the platform down
            currentStep++; // Increment
        } else {
            hasAppliedEffect = false; // Set effect as false after moving down
            hasAppliedEffect = true; // Set effect as completed
        }
    }
}


void HotAirBalloon::render(RenderWindow* window) {
    hotAirBalloon.setPosition(powerups.x, powerups.y);
    window->draw(hotAirBalloon); 
}


Sprite HotAirBalloon::getBalloon() {
    return hotAirBalloon;
}

bool HotAirBalloon::getDeleteStatus() {
    return deleteBalloon;
}

void HotAirBalloon::setDeleteStatus(bool status) {
    deleteBalloon = status;
}


bool HotAirBalloon::getHasBeenTrue() {
    return hasBeenTrue;
}

void HotAirBalloon::setHasBeenTrue(bool status) {
    hasBeenTrue = status;
}

bool HotAirBalloon::getHasAppliedEffect() {
    return hasAppliedEffect;
}

void HotAirBalloon::setHasAppliedEffect(bool status) {
    hasAppliedEffect = status;
}


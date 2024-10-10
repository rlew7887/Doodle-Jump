#include "Boots.h"

Boots::Boots() {
    // Initialise variables
    deleteBoots = false;
    hasBeenTrue = false;
    hasAppliedEffect = false;
    effectCompleted = false;
    totalSteps = 50;   
    currentStep = 0;
    setupPowerUp();
}

void Boots::setupPowerUp() {
    if (!bootsTexture.loadFromFile("RubberBoots.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    boots.setTexture(bootsTexture); // set boots texture
    bootsTexture.setSmooth(true); //smooths the outline
    Vector2u textureSize = bootsTexture.getSize();  //Get the original texture size
    float scaleX = 60.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 60.0f / textureSize.y;  //Calculate scale factor for height
    boots.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite
}

void Boots::applyEffect() {
    currentStep = 0;  // Reset the step counter
    hasAppliedEffect = true; // Set effect as true
}

void Boots::updateEffect(Platform* platform, bool powerUpCollected) {
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


void Boots::render(RenderWindow* window) {
    boots.setPosition(powerups.x, powerups.y);
    window->draw(boots); 
}

Sprite Boots::getBoots() {
    return boots;
}

bool Boots::getDeleteStatus() {
    return deleteBoots;
}

void Boots::setDeleteStatus(bool status) {
    deleteBoots = status;
}


bool Boots::getHasBeenTrue() {
    return hasBeenTrue;
}

void Boots::setHasBeenTrue(bool status) {
    hasBeenTrue = status;
}

bool Boots::getHasAppliedEffect() {
    return hasAppliedEffect;
}

void Boots::setHasAppliedEffect(bool status) {
    hasAppliedEffect = status;
}

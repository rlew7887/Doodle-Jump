#include "Boots.h"

Boots::Boots() {
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
    boots.setPosition((100),(0)); // Initialise position
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

void Boots::shiftDown(float distance, int score) {
    powerups.y += distance; 

    // Generate one powerup everytime the score is divisible by 600
    if (score % 600 == 0) {
        powerups.x = rand() % 420;
        powerups.y = rand() % 20; 
        bool validPosition = false; // bool to check if hot air balloon position is valid
    
        while (!validPosition) {
            int tempX = rand() % 420; // Max x = window width - platform width = 500-80 = 420
            int tempY = rand() % 20;  // Randomize y position (0-50)

            validPosition = true; // Assume position is valid 

            int dx = abs(tempX - powerups.x); // Horizontal distance
            int dy = abs(tempY - powerups.y); // Vertical distance

            // Set minimum spacing
            const int minHorizontalGap = 50; // Min width difference
            const int minVerticalGap = 50;   // Min height difference

            // Check if the new position is too close to boots position
            if (dx < minHorizontalGap && dy < minVerticalGap) {
                validPosition = false; // set as false
                break; 
            } else if (tempY > 20) {
                validPosition = false;
                break;
            }

            // If position is valid, assign it as the hot air balloon's coordinates
            if (validPosition) {
                bootsPoint.x = tempX;
                bootsPoint.y = tempY; 
            }
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


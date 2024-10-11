#include "HotAirBalloon.h"

HotAirBalloon::HotAirBalloon() {
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
    hotAirBalloon.setPosition((rand()%420),(rand()%20)); // Initialsie position
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
            platform->shiftDown(50.0f); // Shift the platform down
            currentStep++; // Increment
        } else {
            hasAppliedEffect = false; // Set effect as false after moving down
            hasAppliedEffect = true; // Set effect as completed
        }
    }
}


void HotAirBalloon::render(RenderWindow* window) {
    if (balloon.x != 0 && balloon.y != 0) {
        hotAirBalloon.setPosition(balloon.x, balloon.y);
        window->draw(hotAirBalloon);
    } 
}


Sprite HotAirBalloon::getBalloon() {
    return hotAirBalloon;
}


void HotAirBalloon::shiftDown(float distance, int score) {
     balloon.y += distance;  // shift down balloon position

    // Generate one powerup everytime the score is divisible by 700
    if (score % 700 == 0) {

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
                balloon.x = tempX;
                balloon.y = tempY; 
            }
        }
    }
}


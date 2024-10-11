#include "Rocket.h"

Rocket::Rocket() {
    setupPowerUp();
}

void Rocket::setupPowerUp() {
    // Setup rocket
    if (!rocketTexture.loadFromFile("Rocket.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    rocket.setTexture(rocketTexture); // set boots texture
    rocketTexture.setSmooth(true); //smooths the outline
    Vector2u textureSize = rocketTexture.getSize();  //Get the original texture size
    float scaleX = 60.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 60.0f / textureSize.y;  //Calculate scale factor for height
    rocket.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite

    // Setup blackhole
    blackholeRadius = 0;
    blackhole.setFillColor(Color::Black);
    blackhole.setRadius(blackholeRadius);

}

void Rocket::applyEffect() {
    currentStep = 0;  // Reset the step counter
    hasAppliedEffect = true; // Set effect as true
}

void Rocket::updateEffect(Platform* platform, bool powerUpCollected) {
    // If the power-up is collected and the effect is not active
    if (powerUpCollected && !hasAppliedEffect && !hasAppliedEffect) {
        currentStep = 0;    // Reset the step counter
        hasAppliedEffect = true; // Mark effect as active
    }

    // If the effect is active, gradually shift the platform down
    if (hasAppliedEffect) {
        if (currentStep < totalSteps) {
            blackholeRadius += 2;
            blackhole.setRadius(blackholeRadius);

            currentStep++; // Increment
        } else {
            hasAppliedEffect = false; // Set effect as false after moving down
            hasAppliedEffect = true; // Set effect as completed
        }
    }
}

void Rocket::render(RenderWindow* window) {
    if (rocketPoint.x != 0 && rocketPoint.y != 0) {
        rocket.setPosition(rocketPoint.x, rocketPoint.y);
        window->draw(rocket);
    } 
}

void Rocket::renderBlackhole(RenderWindow* window, int x, int y) {
    if (x != 0 && y != 0) {
        blackhole.setPosition(x, y);
        window->draw(blackhole);
    } 
}

void Rocket::shiftDown(float distance, int score) {
     rocketPoint.y += distance;  // shift down balloon position

    // Generate one powerup everytime the score is divisible by 1000
    if (score % 1000 == 0) {

        bool validPosition = false; // bool to check if hot air balloon position is valid
    
        while (!validPosition) {
            int tempX = rand() % 420; // Max x = window width - platform width = 500-80 = 420
            int tempY = rand() % 50;  // Randomize y position (0-50)

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
            }

            // If position is valid, assign it as the hot air balloon's coordinates
            if (validPosition) {
                rocketPoint.x = tempX;
                rocketPoint.y = tempY; 
            }
        }
    }
}

Sprite Rocket::getRocket() {return rocket;}
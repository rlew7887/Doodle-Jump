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
    float scaleX = 100.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 100.0f / textureSize.y;  //Calculate scale factor for height
    rocket.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite
    rocket.setPosition(100,0); // Initialise position

    // Setup blackhole
    blackholeDrawn = false;
    blackholeRadius = 100;
    blackhole.setFillColor(Color::Black);
    blackhole.setRadius(blackholeRadius);

}

void Rocket::applyEffect() {
    currentStep = 0;  // Reset the step counter
    hasAppliedEffect = true; // Set effect as true
}


void Rocket::render(RenderWindow* window) {
    if (rocketPoint.x != 0 && rocketPoint.y != 0) {
        rocket.setPosition(rocketPoint.x, rocketPoint.y);
        window->draw(rocket);
    } 
}

void Rocket::renderBlackhole(RenderWindow* window) {
    blackhole.setPosition(rocketPoint.x, rocketPoint.y);
    window->draw(blackhole);
    blackholeDrawn = true;
}

void Rocket::shiftDown(float distance, int score) {
     rocketPoint.y += distance;  // shift down balloon position

    // Generate one powerup everytime the score is divisible by 800
    if (score % 800 == 0) {

        bool validPosition = false; // bool to check if rocket position is valid
    
        while (!validPosition) {
            int tempX = rand() % 420; // Randomize x position (0-420)
            int tempY = rand() % 20;  // Randomize y position (0-50)

            validPosition = true; // Assume position is valid 

            // Check if the new position is within the 0-20 range
            if (tempY > 20) {
                validPosition = false; // set as false
                break; 
            }

            // If position is valid, assign it as the rocket's coordinates
            if (validPosition) {
                rocketPoint.x = tempX;
                rocketPoint.y = tempY; 
            }
        }
    }
}

Sprite Rocket::getRocket() {return rocket;}

bool Rocket::getBlackholeDrawn() {return blackholeDrawn;}
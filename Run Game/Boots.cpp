#include "Boots.h"

Boots::Boots() {
    setupPowerUp();
}

void Boots::setupPowerUp() {
    if (!bootsTexture.loadFromFile("RubberBoots.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    boots.setTexture(bootsTexture);
    bootsTexture.setSmooth(true); //smooths the outline
    Vector2u textureSize = bootsTexture.getSize();  //Get the original texture size
    float scaleX = 80.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 80.0f / textureSize.y;  //Calculate scale factor for height
    boots.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite
}

void Boots::applyEffect() {}


void Boots::render(RenderWindow* window) {
    boots.setPosition(powerups.x, powerups.y);
    if (powerups.x != 0 && powerups.y != 0) {
            window->draw(boots); 
    }
}

Sprite Boots::getBoots() {
    return boots;
}
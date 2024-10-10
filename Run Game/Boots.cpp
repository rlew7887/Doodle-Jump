#include "Boots.h"

Boots::Boots() {
    deleteBoots = false;
    hasBeenTrue = false;
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

void Boots::applyEffect() {}


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
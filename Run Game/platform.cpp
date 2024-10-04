#include "Platform.h"
#include <iostream>

Platform::Platform(float x, float y, bool broken) : position(x, y), isBroken(broken) {
    platformShape.setSize(Vector2f(100.f, 20.f));  //platform size
    platformShape.setPosition(position);           //set initial position
    if (broken) {
        platformShape.setFillColor(Color::Red);    //broken platform could be red
    } else {
        platformShape.setFillColor(Color::Green);  //normal platform could be green
    }
}

//move the platform horizontally (for moving platforms)
void Platform::moveHorizontal(float speed) {
    position.x += speed;
    if (position.x > 500) position.x = 0;         //moop back if off the screen
    else if (position.x < 0) position.x = 500;

    platformShape.setPosition(position);
}

// Render the platform to the window
void Platform::render(RenderWindow &window) {
    window.draw(platformShape);
}

// Get the current position of the platform
Vector2f Platform::getPosition() const {
    return platformShape.getPosition();
}

// Check if the platform is broken
bool Platform::checkIfBroken() const {
    return isBroken;
}

// Set texture for the platform (load from a file)
void Platform::setPlatformTexture(const std::string& textureFile) {
    if (!platformTexture.loadFromFile(textureFile)) {
        std::cerr << "Error loading texture" << std::endl;
        return;
    }
    platformShape.setTexture(&platformTexture);
}

#include "Platform.h"

// Constructor
Platform::Platform(float width, float height, float posX, float posY) {
    shape.setSize(Vector2f(width, height)); // Set size
    shape.setFillColor(Color::Green); // Set color (you can customize it)
    shape.setPosition(Vector2f(posX, posY)); // Set position
}

// Render the platform
void Platform::render(RenderWindow& window) {
    window.draw(shape); // Draw the platform in the window
}

// Get the position of the platform
Vector2f Platform::getPosition() const {
    return shape.getPosition();
}

// Get the size of the platform
Vector2f Platform::getSize() const {
    return shape.getSize();
}

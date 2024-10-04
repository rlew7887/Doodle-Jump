#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Platform {
private:
    RectangleShape shape; // Shape representing the platform

public:
    // Constructor to initialize platform with size and position
    Platform(float width, float height, float posX, float posY);

    // Function to render the platform
    void render(RenderWindow& window);

    // Get the position of the platform
    Vector2f getPosition() const;

    // Get the size of the platform
    Vector2f getSize() const;
};


#endif

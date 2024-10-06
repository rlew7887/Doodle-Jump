#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Platform {
private:
    Texture platformTexture; // Texture for platform image
    Sprite platformSprite;   // Sprite to display the texture
    Vector2f position;       // Position of the platform

public:
    Platform(float posX, float posY, std::string texturePath); // Constructor
    void render(RenderWindow* target);                        // Render the platform
    void move(float offsetX, float offsetY);                  // Move the platform
    FloatRect getBounds();                                    // Get platform bounds (for collision detection)
    Vector2f getPosition();                                   // Get platform position
};

#endif

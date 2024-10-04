#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Platform {
private:
    RectangleShape platformShape;   // shape of the platform
    Texture platformTexture;        // texture for the platform
    bool isBroken;                  // to differentiate between normal and broken platforms
    Vector2f position;              // position of the platform

public:
    Platform(float x, float y, bool broken = false);

    // move platform horizontally (for moving platforms)
    void moveHorizontal(float speed);

    // render the platform to the window
    void render(RenderWindow &window);

    // get platform position
    Vector2f getPosition() const;

    //check if the platform is broken
    bool checkIfBroken() const;

    //set platform texture
    void setPlatformTexture(const std::string& textureFile);

    ~Platform() {}
};

#endif

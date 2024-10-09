#ifndef NORMALPLAT_H 
#define NORMALPLAT_H
#include "Platform.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class NormalPlat : public Platform {
    private:
        RectangleShape normalPlat;
        Texture platformTexture; // Texture for platform image
        Sprite platformSprite;   // Sprite to display the texture

    public:
        NormalPlat();
        ~NormalPlat() {}
};

#endif 
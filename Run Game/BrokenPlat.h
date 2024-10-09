#ifndef BROKENPLAT_H  
#define BROKENPLAT_H  
#include "Platform.h"  
#include <SFML/Graphics.hpp>  
using namespace sf;  
class BrokenPlat : public Platform {  
private:  
   RectangleShape brokenPlat;  
   Texture brokenPlatformTexture; // Texture for broken platform image  
   Sprite brokenPlatformSprite;  
   // Sprite to display the texture  
public:  
   BrokenPlat();  
   void render(RenderWindow* target) override;
   ~BrokenPlat() {}  
};  
#endif
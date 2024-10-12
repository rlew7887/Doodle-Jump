#ifndef MOVINGPLAT_H
#define MOVINGPLAT_H
#include "Platform.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class MovingPlat : public Platform {  
private:  
   float speed;  
   bool movingRight;  
  
public:  
   MovingPlat();  
   void update(float deltaTime);  
   void render(RenderWindow* target) override;  
};

#endif
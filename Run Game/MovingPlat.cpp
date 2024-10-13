#include "MovingPlat.h"

MovingPlatform::MovingPlatform() : moveSpeed(100.0f), movingRight(true) {  
   // Set initial position and bounds  
   plat[0].x = 250;  
   plat[0].y = 400;  
   leftBound = plat[0].x - 100;  
   rightBound = plat[0].x + 100;  
}  
  
void MovingPlatform::update(float deltaTime) {  
   if (movingRight) {  
      plat[0].x += moveSpeed * deltaTime;  
      if (plat[0].x >= rightBound) {  
        movingRight = false;  
      }  
   } else {  
      plat[0].x -= moveSpeed * deltaTime;  
      if (plat[0].x <= leftBound) {  
        movingRight = true;  
      }  
   }  
}  
  
void MovingPlatform::render(RenderWindow* target) {  
   platform.setPosition(plat[0].x, plat[0].y);  
   target->draw(platform);  
}
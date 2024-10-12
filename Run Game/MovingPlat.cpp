#include "MovingPlat.h"

MovingPlat::MovingPlat() : speed(100.0f), movingRight(true) {  
   platform.setFillColor(Color::Yellow);  
   generatePlatforms(3);  // Generate fewer moving platforms  
}  
  
void MovingPlat::update(float deltaTime) {  
   for (int i = 0; i < 3; i++) {  
      if (movingRight) {  
        plat[i].x += speed * deltaTime;  
        if (plat[i].x + 80 > 500) {  // Assuming window width is 500  
           movingRight = false;  
        }  
      } else {  
        plat[i].x -= speed * deltaTime;  
        if (plat[i].x < 0) {  
           movingRight = true;  
        }  
      }  
   }  
}  
  
void MovingPlat::render(RenderWindow* target) {  
   for (int i = 0; i < 3; i++) {  
      platform.setPosition(plat[i].x, plat[i].y);  
      if (plat[i].x != 0 && plat[i].y != 0) {  
        target->draw(platform);  
      }  
   }  
}
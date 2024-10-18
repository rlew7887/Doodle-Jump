#ifndef MOVINGPLATFORM_H  
#define MOVINGPLATFORM_H  
  
#include "Platform.h"  
  
class MovingPlat : public Platform {  
private:  
   float moveSpeed;  
   float leftBound;  
   float rightBound;  
   bool movingRight;  
  
public:  
   MovingPlat();  
   void update(float deltaTime);  
   void render(RenderWindow* target) override;  
};  
  
#endif
#include "Level1.h"  
NormalPlat* Level1::get_NormalPlat() {  
   return normalP;  
}
Level1::Level1() : normalP(nullptr), brokenP(nullptr) {};  
void Level1::setupLevel() {  
   // Initialise platforms  
   normalP = new NormalPlat;  
   brokenP = new BrokenPlat;  
   // boot = new Boots;  
}  
void Level1::renderLevel1(RenderWindow* window) {  
   if (normalP != nullptr) {  
      normalP->render(window);  
   }  
   if (brokenP != nullptr) {  
      brokenP->render(window);  
   }  
   // broken.render()  
   // boots.render()  
}  
BrokenPlat* Level1::get_BrokenPlat() {  
   return brokenP;  
}  
Level1::~Level1() {  
   delete normalP;  
   delete brokenP;  
   // delete boot;  
}
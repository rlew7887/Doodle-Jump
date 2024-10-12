#include "Level1.h"  

Level1::Level1() : normalP(nullptr), brokenP(nullptr), boot(nullptr) {};  

void Level1::setupLevel() {  
   // Initialise platforms  
   normalP = new NormalPlat;  
   brokenP = new BrokenPlat;  
   boot = new Boots;  
}  
void Level1::renderLevel1(RenderWindow* window) {  
   if (normalP != nullptr) {  
      normalP->render(window);  
   }  
   if (brokenP != nullptr) {  
      brokenP->render(window);  
   }  
   if (boot != nullptr && boot->getDeleteStatus() == false && boot->getHasBeenTrue() == false) {  
      boot->render(window);  
   }    
}  

NormalPlat* Level1::get_NormalPlat() {  
   return normalP;  
}

BrokenPlat* Level1::get_BrokenPlat() {  
   return brokenP;  
}  

Boots* Level1::get_Boots() {
   return boot;
}

Level1::~Level1() {  
   delete normalP;  
   delete brokenP;  
   delete boot; 
}
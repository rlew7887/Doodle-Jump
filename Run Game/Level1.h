#ifndef LEVEL1_H  
#define LEVEL1_H  
#include "Platform.h"  
#include "NormalPlat.h"  
#include "BrokenPlat.h"    
#include "PowerUps.h"
#include "Boots.h"

class Level1 {  
   protected:  
      NormalPlat* normalP;  
      BrokenPlat* brokenP;  
      Boots* boot;

   public:  
      Level1();  
      void setupLevel();  
      void renderLevel1(RenderWindow* window);  
      NormalPlat* get_NormalPlat();  
      BrokenPlat* get_BrokenPlat();  
      Boots* get_Boots(); 
      ~Level1();  
};

#endif
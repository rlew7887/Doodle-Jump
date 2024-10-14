#ifndef LEVEL2_H 
#define LEVEL2_H 


#include "Level1.h"
#include "HotAirBalloon.h"
#include <SFML/Graphics.hpp>


using namespace sf;


class Level2 : public Level1 { 
   private: 
       HotAirBalloon* hotAirBalloon;


   public: 
   Level2(); 
   void setupLevel(); 
   void renderLevel2(RenderWindow* window); 
   HotAirBalloon* get_HotAirBalloon(); 
   ~Level2(); 
};


#endif

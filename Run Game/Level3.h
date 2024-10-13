#ifndef LEVEL3_H
#define LEVEL3_H


#include "Level2.h"
#include "Rocket.h"
#include <SFML/Graphics.hpp>


class Rocket; // forward declaration


class Level3 : public Level2 {
   private:
       Rocket* rocket;


   public:
       Level3();
       void setupLevel(); 
       void renderLevel3(RenderWindow* window);
       Rocket* get_Rocket();
       ~Level3();
};


#endif

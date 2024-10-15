#ifndef LEVEL3_H
#define LEVEL3_H


#include "Level2.h"
#include "Rocket.h"
#include "Monster.h"
#include <SFML/Graphics.hpp>

// forward declaration
class Rocket;
class Monster;

class Level3 : public Level2 {
   private:
       Rocket* rocket;
       Monster* monster;
   public:
       Level3();
       void setupLevel(); 
       void renderLevel3(RenderWindow* window);
       Rocket* get_Rocket();
       Monster* get_Monster();
       ~Level3();
};


#endif

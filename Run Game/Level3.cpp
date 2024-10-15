#include "Level3.h"

Level3::Level3() : Level2::Level2(), rocket(nullptr), monster(nullptr) {}

void Level3::setupLevel() {
   Level2::setupLevel();
   rocket = new Rocket;
   monster = new Monster;
}

void Level3::renderLevel3(RenderWindow* window) {
   if (rocket != nullptr && rocket->getDeleteStatus() == false && rocket->getHasBeenTrue() == false) { 
     rocket->render(window); 
   } 
   monster->render(window);
}

Rocket* Level3::get_Rocket() {return rocket;}

Monster* Level3::get_Monster() {return monster;}

Level3::~Level3() {
   delete rocket;
   delete monster;
}

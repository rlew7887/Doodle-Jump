#include "Level2.h"


Level2::Level2() : Level1::Level1(), hotAirBalloon(nullptr) {}


void Level2::setupLevel() {
   Level1::setupLevel();
   hotAirBalloon = new HotAirBalloon;


}
void Level2::renderLevel2(RenderWindow* window) {
   if (hotAirBalloon != nullptr && hotAirBalloon->getDeleteStatus() == false && hotAirBalloon->getHasBeenTrue() == false) { 
     hotAirBalloon->render(window); 
   }   
}

HotAirBalloon* Level2::get_HotAirBalloon() {return hotAirBalloon;}


Level2::~Level2() {
   delete hotAirBalloon;
}

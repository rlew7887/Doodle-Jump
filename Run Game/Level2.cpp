#include "Level2.h"

Level2::Level2() : Level1::Level1() {} // initialise nullptr for movingplat and hot air balloon
void Level2::setupLevel() {
    Level1::setupLevel();
    // hotAirBalloon = new HotAirBalloon;
    // moving = new MovingPlat;

}
void Level2::renderLevel2(RenderWindow* window) {
    // if (moving != nullptr) {  
    //   moving->render(window);  
    // }  
    // if (hotAirBalloon != nullptr) {  
    //   hotAirBalloon->render(window);  
    // }    
}

//    MovingPlat* get_MovingPlat() {return moving;}  
//    HotAirBalloon* get_HotAirBalloon() {return hotAirBalloon} 

Level2::~Level2() {
    // delete moving;
    // delete hotAirBalloon;
}
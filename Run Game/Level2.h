#ifndef LEVEL2_H  
#define LEVEL2_H  

#include "Level1.h"
#include "HotAirBalloon.h"
#include "MovingPlat.h"
#include <SFML/Graphics.hpp>


using namespace sf;

class Level2 : public Level1 {  
    private:  
        // MovingPlat* moving;
        // HotAirBalloon* hotAirBalloon;
        std::unique_ptr<MovingPlat> moving;  
     std::unique_ptr<HotAirBalloon> hotAirBalloon;

    public:  
    Level2();  
    void setupLevel();  
    void renderLevel2(RenderWindow* window);  
    void updateLevel2(float deltaTime);
     MovingPlat* get_MovingPlat();  
    HotAirBalloon* get_HotAirBalloon();  
    ~Level2();  
};

#endif
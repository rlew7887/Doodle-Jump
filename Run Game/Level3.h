#ifndef LEVEL3_H
#define LEVEL3_H

#include "Level2.h"
#include "Rocket.h"
#include <SFML/Graphics.hpp>

class Level3 : public Level2 {
    private:
        Rocket* rocket;

    public:
        Level3();
        void setupLevel();  
        void renderLevel3(RenderWindow* window);
        Rocket getRocket();
        ~Level3();
};

#endif
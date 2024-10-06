#ifndef LEVEL1_H
#define LEVEL1_H

#include "Platform.h"
#include "NormalPlat.h"
#include "Player.h"
#include "inGame.h"

class Level1 {
    private:
        inGame* gameOver;

    public:
        Level1();
        void setupLevel(RenderWindow* window, Sprite& player);
        void renderLevel1(RenderWindow* window, NormalPlat normal);
        ~Level1();
};

#endif
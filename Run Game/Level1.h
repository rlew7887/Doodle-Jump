#ifndef LEVEL1_H
#define LEVEL1_H

#include "Platform.h"
#include "NormalPlat.h"
#include "Player.h"
#include "gameOver.h"

class Level1 {
    private:
        NormalPlat* normalP;
        // BrokenPlat* brokenP;
        // Boots* boot;

    public:
        Level1();
        void setupLevel();
        void renderLevel1(RenderWindow* window);
        NormalPlat* get_NormalPlat();
        // get_BrokenPlat();
        // get_Boots();
        ~Level1();
};

#endif
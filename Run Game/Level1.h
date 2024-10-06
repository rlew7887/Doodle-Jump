#ifndef LEVEL1_H
#define LEVEL1_H

#include "Platform.h"
#include "NormalPlat.h"
#include "Player.h"

class Level1 {
    private:

    public:
        Level1();
        void setupLevel(RenderWindow* window, NormalPlat normal);
        ~Level1() {}
};

#endif
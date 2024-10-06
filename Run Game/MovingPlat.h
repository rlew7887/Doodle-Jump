#ifndef MOVINGPLAT_H
#define MOVINGPLAT_H
#include "Platform.h"

class MovingPlat : public Platform {
    private:
    public:
        void move(float offsetX, float offsetY);                  // Move the platform
};

#endif
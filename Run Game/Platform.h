#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Platform {
    protected:
        struct Point {int x, y;};
        RectangleShape platform;

    public:
        Point plat[20];
        Platform(); // Constructor
        virtual void render(RenderWindow* target);
        void shiftDown(float distance);
        void generatePlatforms();
        ~Platform() {}
        
};

#endif

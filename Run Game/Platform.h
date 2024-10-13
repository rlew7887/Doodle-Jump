#ifndef PLATFORM_H
#define PLATFORM_H


#include <SFML/Graphics.hpp>


using namespace sf;


class Platform {
   protected:
       struct Point {int x, y;};
       RectangleShape platform;


   public:
       Point plat[11];
       Platform(); // Constructor
       virtual void render(RenderWindow* target);
       void shiftDown(float distance);
       void generatePlatforms(int numToGenerate); // Modify the frequency of platforms being generated
       Point getPlat(int index);
       virtual ~Platform() {}
      
};


#endif

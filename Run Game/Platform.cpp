#include "Platform.h"


// Constructor for the base Platform class
Platform::Platform() {
   platform.setSize(Vector2f(80.f, 20.f));
   platform.setFillColor(Color::Green);
   platform.setOutlineThickness(1);
   platform.setOutlineColor(Color::Black);


   // Generate a platform at player spawn position
   plat[0].x = 250;
   plat[0].y = 800;
   generatePlatforms(10);
}


// Render function, setting and drawing platforms at randomized positions
void Platform::render(RenderWindow* target) {
   for (int i = 0; i < 11; i++) {
       platform.setPosition(plat[i].x, plat[i].y);
       if (plat[i].x != 0 && plat[i].y != 0) {
               target->draw(platform);
           }
   }
}


void Platform::generatePlatforms(int numToGenerate) {
   // Randomize n platform positions
   for (int i = 1; i < numToGenerate; i++) {
       int tempX = rand() % 420; // Max x = window width = 500 - 80 = 420 to prevent exceeding window width
       int tempY = rand() % 800; // Max y = window height = 800


       // Make sure platform generated does not intersect each other
       if (tempY < plat[i-1].y-50 || tempY > plat[i-1].y+70) {
           plat[i].x = tempX;
           plat[i].y = tempY;
       } else {
          i--;
       }
   }
}


void Platform::shiftDown(float distance) {
   for (int i = 0; i < 11; ++i) {
       plat[i].y += distance; // Shift each platform down


       // When a platform moves off the screen, generate one new platform at the top
       if (plat[i].y >= 750) {
           bool validPosition = false; // bool to check if platform position is valid
  
           while (!validPosition) {
               int tempX = rand() % 420; // Max x = window width - platform width = 500-80 = 420
               int tempY = rand() % 50;  // Randomize a y position (0-50)


               validPosition = true; // Assume position is valid


               // Check if the new platform intersects any existing platforms
               for (int j = 0; j < 11; ++j) {
                   if (j != i) { // Skip the current platform being repositioned
                       int dx = abs(tempX - plat[j].x); // Horizontal distance
                       int dy = abs(tempY - plat[j].y); // Vertical distance


                       // Set minimum spacing
                       const int minHorizontalGap = 90; // Min width difference
                       const int minVerticalGap = 30;   // Min height difference


                       // Check if the new position is too close to another platform
                       if (dx < minHorizontalGap && dy < minVerticalGap) {
                           validPosition = false; // set as false
                           break;
                       }
                   }
               }


               // If position is valid, assign it as the platform's coordinates
               if (validPosition) {
                   plat[i].x = tempX;
                   plat[i].y = tempY;
               }
           }
       }
   }
}




Platform::Point Platform::getPlat(int index) {
   return plat[index];
}

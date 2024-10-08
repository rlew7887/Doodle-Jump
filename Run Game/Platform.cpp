#include "Platform.h"

// Constructor for the base Platform class
Platform::Platform() {
    platform.setSize(Vector2f(80.f, 20.f));
    platform.setFillColor(Color::Green);

    // Generate a platform at player spawn position
    plat[0].x = 250;
    plat[0].y = 800;
    generatePlatforms(10);
}

// Render function, setting and drawing platforms at randomized positions
void Platform::render(RenderWindow* target) {
    for (int i = 0; i < 11; i++) {
        platform.setPosition(plat[i].x, plat[i].y);
        target->draw(platform);
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
        if (plat[i].y >= 750) {
            // Randomize 1 platform position
            plat[i].x = rand() % 420;
            plat[i].y = rand() % 1;
            
        }
    }

}

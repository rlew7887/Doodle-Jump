#include "Platform.h"

// Constructor for the base Platform class
Platform::Platform() {
    platform.setSize(Vector2f(80.f, 20.f));
    platform.setFillColor(Color::Green);

    generatePlatforms();
}

// Render function, setting and drawing platforms at randomized positions
void Platform::render(RenderWindow* target) {
    for (int i = 0; i < 11; i++) {
        platform.setPosition(plat[i].x, plat[i].y);
        target->draw(platform);
    }
}

void Platform::generatePlatforms() {
    // Generate a platform at player spawn position
    plat[0].x = 250;
    plat[0].y = 800;
    // Randomize 10 platform positions
    for (int i = 1; i < 11; i++) {
        plat[i].x = rand() % 500; // Max x = window width = 500
        plat[i].y = rand() % 800; // Max y = window height = 800
    }
}

void Platform::shiftDown(float distance) {
    for (int i = 0; i < 11; ++i) {
        plat[i].y += distance; // Shift each platform down
        if (plat[i].y >= 750) {
            // Randomize 1 platform position
            plat[i].x = rand() % 500; // Max x = window width = 500
            plat[i].y = rand() % -10; // Max y = window height = 800
        }
    }

}


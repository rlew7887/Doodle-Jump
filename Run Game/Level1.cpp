#include "Level1.h"

Level1::Level1() : normalP(nullptr) {};

void Level1::setupLevel() {
    // Initialise platforms
    normalP = new NormalPlat;
    // brokenP = new BrokenPlat;
    // boot = new Boots;
}

void Level1::renderLevel1(RenderWindow* window) {
    if (normalP != nullptr) {
    normalP->render(window);
    }
    // broken.render()
    // boots.render()
}

NormalPlat* Level1::get_NormalPlat() {
    return normalP;
}

Level1::~Level1() {
    delete normalP;
    // delete brokenP;
    // delete boot;
}
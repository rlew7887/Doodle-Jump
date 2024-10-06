#include "NormalPlat.h"

NormalPlat::NormalPlat() {
    normalPlat.setFillColor(Color::Green);
}

void NormalPlat::render(RenderWindow* target) {
    for (int i = 0; i < 20; i++) {
        platform.setPosition(plat[i].x, plat[i].y);
        target->draw(platform);
    }
}
#include "BrokenPlat.h"  
BrokenPlat::BrokenPlat() {  
   brokenPlat.setSize(Vector2f(80.f, 20.f));
   brokenPlat.setFillColor(Color::Red);
   brokenPlat.setOutlineThickness(1);
   brokenPlat.setOutlineColor(Color::Black);

   // Generate a platform at player spawn position
   plat[0].x = 250;
   plat[0].y = 800;
   generatePlatforms(2);
}  


void BrokenPlat::render(RenderWindow* target) {
    for (int i = 0; i < 2; i++) {
        brokenPlat.setPosition(plat[i].x, plat[i].y);
        if (plat[i].x != 0 && plat[i].y != 0) {
                target->draw(brokenPlat); 
            }
    }
}


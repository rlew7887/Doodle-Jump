#include "PowerUps.h"

// Constructor initializing the power-ups list
PowerUps::PowerUps() {}

void PowerUps::shiftDown(float distance, int score) {
    powerups.y += distance; 

    // Generate one boot everytime the score is divisible by 1000
    if (score % 1000 == 0) {
        powerups.x = rand() % 420;;
        powerups.y = rand() % 50; ; 
    }
}

void PowerUps::deactivate() {
    isActive = false; // Deactivate the power-up (customize as needed)
}

PowerUps::Point PowerUps::getPoint() {
    return powerups;
}




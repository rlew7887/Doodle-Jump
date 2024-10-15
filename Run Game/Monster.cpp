#include "Monster.h"

Monster::Monster(){
    // Check whether image has loaded
    if (!fishMonster.loadFromFile("FishMonster.png")){
        std::cout << "Failed to load" << std::endl;
    }
    monster.setTexture(fishMonster);

    // Initialize location to prevent glitching
    X = 100;
    Y = 10;
    monster.setPosition(Vector2f(X, Y));

    fishMonster.setSmooth(true); // Smooths the outline
    sf::Vector2u textureSize = fishMonster.getSize();  // Get the original texture size
    float scaleX = 100.0f / textureSize.x;  // Calculate scale factor for width
    float scaleY = 100.0f / textureSize.y;  // Calculate scale factor for height
    monster.setScale(scaleX, scaleY);  // Apply the scale to resize the sprite
}

void Monster::randomizeEnemies(int score){
    // Generate a new monster position based on score
    if (score % 1000 == 0) {
        bool validPos = false; //Initialize
        while (!validPos){
            int tempX = rand() % 420;  // Randomize X position
            int tempY = rand() % 20;   // Randomize Y position
            if (X > 0 && Y > 0){
                validPos = true;
            }
            else{validPos = false;}
            if(validPos){
                X = tempX;
                Y = tempY;
            }
        }
    }
}

void Monster::shiftDown(float distance){
    Y += distance;
}

void Monster::render(RenderWindow* window){
    monster.setPosition(X, Y);
    window->draw(monster); 
}

Sprite Monster::getMonster(){
    return monster;
}

Monster::~Monster(){}
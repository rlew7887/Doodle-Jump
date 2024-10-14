#include "Monster.h"

Monster::Monster(){
    //Initialize Monster
    if (!fishMonster.loadFromFile("FishMonster.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    monster.setTexture(fishMonster);
    X = 100;
    Y = 10;
    monster.setPosition(Vector2f(X, Y)); //Initialize location to prevent glitching
    fishMonster.setSmooth(true); //smooths the outline
    sf::Vector2u textureSize = fishMonster.getSize();  //Get the original texture size
    float scaleX = 100.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 100.0f / textureSize.y;  //Calculate scale factor for height
    monster.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite
}

void Monster::randomizeEnemies(int score){ //Put restrictions such as cannot appear on platforms
    // Generate a new monster position based on score
    if (score % 500 == 0) {
        bool validPos = false; //Initialize
        while (!validPos){
            int tempX = rand() % 420;  // Randomize X position
            int tempY = rand() % 20;   // Randomize Y position
            if (X != 0 && Y != 0){
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
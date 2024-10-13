#include "Monster.h"

Monster::Monster(){
    //Initialize Monster
    if (!fishMonster.loadFromFile("FishMonster.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    monster.setTexture(fishMonster);
    monster.setPosition(Vector2f(250, 700)); //Initialize location to prevent glitching
    fishMonster.setSmooth(true); //smooths the outline
    sf::Vector2u textureSize = fishMonster.getSize();  //Get the original texture size
    float scaleX = 100.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 100.0f / textureSize.y;  //Calculate scale factor for height
    monster.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite
}

void Monster::randomizeEnemies(int score){
    // Generate a new monster position based on score
    if (score % 1000 == 0) {
        X = rand() % 420;  // Randomize X position
        Y = rand() % 20;   // Randomize Y position

        // Assign random position to monster
        monster.setPosition(X, Y);
    }
}

void Monster::render(RenderWindow* window){
    window->draw(monster); 
}

Sprite Monster::getMonster(){
    return monster;
}

Monster::~Monster(){}
#include "inGame.h"
#include <iostream>

inGame::inGame():score(score){}

void inGame::gameOver(){
    RenderWindow window(VideoMode(500, 800), "Game Over");
    sf::Texture t;
    t.loadFromFile("grid-bg.jpg");
    sf::Sprite s(t);
    sf::Vector2u windowSize = window.getSize(); //get window size
    sf::Vector2u textureSize = t.getSize(); //get image size

    //Calculate scale factors to make image fit to window
    float scaleX = (1.0f * windowSize.x) / textureSize.x;
    float scaleY = (1.0f * windowSize.y) / textureSize.y;

    s.setScale(scaleX, scaleY); //scale the sprite
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
                if (event.type == Event::Closed)
                    window.close();
        }
        window.clear();
        window.draw(s);
        window.display();
    }
}

void inGame::countScore(){
    //if (Y > previousY)
    //score ++;
}

int inGame::getScore(){
    return score;
}

void inGame::render(){
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
    sf::Texture t;
    t.loadFromFile("grid-bg.jpg");
    sf::Sprite s(t);
    sf::Vector2u windowSize = window.getSize(); //get window size
    sf::Vector2u textureSize = t.getSize(); //get image size

    //Calculate scale factors to make image fit to window
    float scaleX = (1.0f * windowSize.x) / textureSize.x;
    float scaleY = (1.0f * windowSize.y) / textureSize.y;

    s.setScale(scaleX, scaleY); //scale the sprite
    // Player player;
    // player.render(); This function in player.cpp will be changed to just render a rectangle/character that can move left/right
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
                if (event.type == Event::Closed)
                    window.close();
        }
        window.clear();
        window.draw(s);
        window.display();
    }
    //Should know when to switch between levels 
    //if (score > 500){
    //  void render(level2)} ??
    //render background and score only
}
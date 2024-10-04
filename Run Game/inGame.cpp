#include "inGame.h"
#include <iostream>

inGame::inGame():score(score){}

void inGame::gameOver(){
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
}

void inGame::countScore(){
    //score = gety();
}

int inGame::getScore(){
    return score;
}

void inGame::render(){
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
    sf::Texture t;
    t.loadFromFile("grid-bg.jpg");
    sf::Sprite s(t);
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
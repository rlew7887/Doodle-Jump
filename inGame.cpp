#include "inGame.h"
#include <iostream>

void inGame::render(){
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
    window.clear();
    window.display();
}

int inGame::getScore(){
    return position.y;
}
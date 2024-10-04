#include "inGame.h"
#include <iostream>

void inGame::gameOver(){
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
}

void inGame::countScore(){}

int inGame::getScore(){
    return position.y;
}

void inGame::render(){}
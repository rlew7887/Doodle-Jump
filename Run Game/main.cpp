#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Home.h"
#include "gameOver.h"

int main()
{
    Player test;
    test.render();
    // Home test;
    // test.displayGraphics();
    int testScore = test.getScore();
    std::cout << "Score: " << testScore << std::endl; //not supposed to be 0;
    // inGame test;
    // test.render();

    return 0;
}
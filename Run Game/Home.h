#ifndef HOME_H
#define HOME_H
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;

class Home {
    private:
        Button* startGameBTN;
        Button* showTutorialBTN;
        Button* showLeaderBoardBTN;
        Font font;
    
    public:
        Home();
        void displayGraphics();
        void startGame();
        void showTutorial();
        void showLeaderBoard();
        ~Home();
};

#endif
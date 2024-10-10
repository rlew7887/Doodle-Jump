#ifndef HOME_H
#define HOME_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Player.h"
#include "HighScore.h"

using namespace sf;

class Home {
    private:
        Button* startGameBTN;
        Button* showTutorialBTN;
        Button* showLeaderBoardBTN;

        RectangleShape tutorialPopup;
        Text tutorialText;

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
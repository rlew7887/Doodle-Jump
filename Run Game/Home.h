#ifndef HOME_H
#define HOME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "Player.h"
#include "HighScore.h"


using namespace sf;


class HighScore;


class Home {
   private:
       Button* startGameBTN;
       Button* showTutorialBTN;
       Button* showLeaderBoardBTN;
       HighScore* highscore;


       RectangleShape tutorialPopup;
       Text tutorialText;


       Font font;
  
   public:
       Home();
       void displayGraphics();
       void startGame();
       void showTutorial();
       void showLeaderBoard();
       void showErrorMessage(RenderWindow& window);
       ~Home();
};


#endif

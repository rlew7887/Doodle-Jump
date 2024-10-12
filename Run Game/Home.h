#ifndef HOME_H
#define HOME_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Player.h"
#include "HighScore.h"

using namespace sf;

class HighScore;

class Home {
    public:
        // enum GameState{
        //     Homepage,
        //     Game,
        //     Leaderboard,
        //     GameOver
        // };
        Home();
        //void setGameState(GameState newState); //method to change state
        void displayGraphics();
        void startGame();
        void showTutorial();
        void showLeaderBoard();
        ~Home();
    private:
        Button* startGameBTN;
        Button* showTutorialBTN;
        Button* showLeaderBoardBTN;
        HighScore* highscore;
        RectangleShape tutorialPopup;
        Text tutorialText;
        Font font;
        //GameState currentState;
};

#endif
#ifndef HOME_H
#define HOME_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Home {
    private:
    
    public:
        Home();
        void displayGraphics();
        void startGame();
        void showTutorial();
        void showLeaderBoard();
        ~Home() {}
};

#endif
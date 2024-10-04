#include "Home.h"
#include <iostream>

Home::Home() {
    font.loadFromFile("./SkeletonFont.ttf"); // load font file

    // Check if successfully loaded
    if (!font.loadFromFile("./SkeletonFont.ttf"))
    {
            std::cout << "File failed to load" << std::endl;
    }
}

void Home::displayGraphics() {
    // Create the window
    RenderWindow window(VideoMode(800, 600), "Doodle Jump Home Screen");

    // Make title
        Text title;
        title.setFont(this->font); // set font
        title.setString("Doodle Jump"); // set the string to display
        title.setCharacterSize(100); // set the character size
        title.setFillColor(sf::Color::Black); // set the color
        title.setStyle(sf::Text::Bold); // set the text style
        title.setPosition(230,30);



    // Make background 
        Texture homeBackground;
        homeBackground.loadFromFile("grid-bg.jpg"); // Load file
        if (!homeBackground.loadFromFile("grid-bg.jpg")) {
            std::cout << "Texture file failed to load" << std::endl;
        }

        Sprite background(homeBackground);
        Vector2u windowSize = window.getSize(); //get window size
        Vector2u textureSize = homeBackground.getSize(); //get image size
        //Calculate scale factors to make image fit to window
        float scaleX = (1.0f * windowSize.x) / textureSize.x;
        float scaleY = (1.0f * windowSize.y) / textureSize.y;
        background.setScale(scaleX, scaleY); //scale the sprite
        
        // Initialise home page buttons;
        startGame();
        showLeaderBoard();
        showTutorial();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        // Update button state according to mouse position
        startGameBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
        showLeaderBoardBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
        showTutorialBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));

        // clear the window with black color
        window.clear(sf::Color::White);
        
        window.draw(background);
        window.draw(title);

        // Draw buttons
        startGameBTN->render(&window);
        showLeaderBoardBTN->render(&window);
        showTutorialBTN->render(&window);

        // end the current frame
        window.display();
}

}


void Home::startGame() {
    this->startGameBTN = new Button(300,180,90,40,this->font,"Start Game",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void Home::showLeaderBoard() {
    this->showLeaderBoardBTN = new Button(300,300,90,40,this->font,"Leader Board",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void Home::showTutorial() {
    this->showTutorialBTN = new Button(300,420,90,40,this->font,"Tutorial",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

Home::~Home() {
    delete startGameBTN;
    delete showTutorialBTN;
    delete showLeaderBoardBTN;
}


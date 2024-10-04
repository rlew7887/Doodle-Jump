#include "Home.h"
#include <iostream>

Home::Home() {}

void Home::displayGraphics() {
    // Create the window
    RenderWindow window(VideoMode(800, 600), "Doodle Jump Home Screen");

    // Make title
        Font titleFont;
        titleFont.loadFromFile("./SkeletonFont.ttf"); // load font file
        if (!titleFont.loadFromFile("./SkeletonFont.ttf"))
        {
            std::cout << "File failed to load" << std::endl;
        }

        Text title;
        title.setFont(titleFont); // set font
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
        
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::White);
        
        window.draw(background);
        window.draw(title);

        // end the current frame
        window.display();
}

}


void Home::startGame() {}
void Home::showTutorial() {}
void Home::showLeaderBoard() {}


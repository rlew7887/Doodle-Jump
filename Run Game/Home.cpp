#include "Home.h"
#include <iostream>

Home::Home() {}

void Home::displayGraphics() {
    // create the window
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
        
        window.draw(title);

        // end the current frame
        window.display();
}

}


void Home::startGame() {}
void Home::showTutorial() {}
void Home::showLeaderBoard() {}

#include "HighScore.h"
#include <iostream>

HighScore::HighScore(){
    highScores = new int[10]{0};
    font.loadFromFile("./SkeletonFont.ttf"); // load font file

    // Check if successfully loaded
    if (!font.loadFromFile("./SkeletonFont.ttf"))
    {
            std::cout << "File failed to load" << std::endl;
    }
}

void HighScore::addScore(int score){
    if (score > highScores[9]) { //Compare with the lowest score in the top 10
        highScores[9] = score; //Replace the lowest score with the new score

        //Sort the scores in descending order
        for (int i = 8; i >= 0; i--) {
            if (highScores[i] < highScores[i + 1]) {
                std::swap(highScores[i], highScores[i + 1]); //Swap if the current score is lower than the next one
            }
        }
    }
}

int HighScore::getTopScores(int index){
    return topScore;
}

void HighScore::saveScoresToFile(){}

void HighScore::readScoresToFile(){}

void HighScore::displayTopScores(){ //still need to add a table to display scores and draw it
    //Get device screen size
    VideoMode desktop = VideoMode::getDesktopMode();
    
    RenderWindow window(VideoMode(500, 800), "Leaderboard");
    // Calculate the center position
    int windowPosX = (desktop.width - 500) / 2;
    int windowPosY = (desktop.height - 800) / 2;
    window.setPosition(Vector2i(windowPosX, windowPosY));

    sf::Texture background;
    background.loadFromFile("grid-bg.jpg");

    if (!background.loadFromFile("grid-bg.jpg")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }

    sf::Sprite bg(background);
    sf::Vector2u windowSize = window.getSize(); //get window size
    sf::Vector2u textureSize = background.getSize(); //get image size

    //Calculate scale factors to make image fit to window
    float scaleX = (1.0f * windowSize.x) / textureSize.x;
    float scaleY = (1.0f * windowSize.y) / textureSize.y;
    bg.setScale(scaleX, scaleY); //scale the sprite

    Text title;
    title.setFont(this->font); //set font
    title.setString("Leaderboard"); //set the string to display
    title.setCharacterSize(100); //set the character size
    title.setFillColor(Color::Black); //set the color
    title.setStyle(Text::Bold); //set the text style
    title.setPosition(120,120);

    // //Initialise buttons
    // //home();

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
                if (event.type == Event::Closed)
                    window.close();
        }

    //     // Update button state according to mouse position
    //     // homeBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));

    //     // //Check if left mouse button is pressed
    //     // if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
    //     //         if (homeBTN->isMouseOver(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y))) {
    //     //             //when home button is pressed, render homescreen
    //     //             window.close();
    //     //             Home home;
    //     //             home.displayGraphics();
    //     //         }
    //     //     }

        window.clear();
        window.draw(bg); //draw background image
        window.draw(title);

    //     // Draw buttons
    //     //homeBTN->render(&window);
        window.display();
    }
}

HighScore::~HighScore(){}
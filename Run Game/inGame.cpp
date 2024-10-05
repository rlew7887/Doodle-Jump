#include "inGame.h"
#include <iostream>

inGame::inGame():score(score){
    font.loadFromFile("./SkeletonFont.ttf"); // load font file

    // Check if successfully loaded
    if (!font.loadFromFile("./SkeletonFont.ttf"))
    {
            std::cout << "File failed to load" << std::endl;
    }
}

void inGame::countScore(){
    //score = gety();
    //if (Y > previousY)
    //score ++;
}

int inGame::getScore(){
    return score;
}

void inGame::playAgain(){
    this->playAgainBTN = new Button(300,180,90,40,this->font,"Play Again",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void inGame::home(){
    this->homeBTN = new Button(300,300,90,40,this->font,"Home",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void inGame::Leaderboard(){
    this->LeaderboardBTN = new Button(300,300,90,40,this->font,"Leader Board",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void inGame::gameOver(){
    RenderWindow window(VideoMode(500, 800), "Game Over");
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
    title.setString("Game Over"); //set the string to display
    title.setCharacterSize(100); //set the character size
    title.setFillColor(Color::Black); //set the color
    title.setStyle(Text::Bold); //set the text style
    title.setPosition(230,30);

    //Initialise buttons
    playAgain();
    home();
    Leaderboard(); 

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
                if (event.type == Event::Closed)
                    window.close();
        }

        // Update button state according to mouse position
        playAgainBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
        homeBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
        LeaderboardBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));

        window.clear();
        window.draw(bg); //draw background image
        window.draw(title);

        // Draw buttons
        playAgainBTN->render(&window);
        homeBTN->render(&window);
        LeaderboardBTN->render(&window);
        window.display();
    }
}

void inGame::render(){
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
    sf::Texture t;
    t.loadFromFile("grid-bg.jpg");
    sf::Sprite s(t);
    sf::Vector2u windowSize = window.getSize(); //get window size
    sf::Vector2u textureSize = t.getSize(); //get image size
    //Calculate scale factors to make image fit to window
    float scaleX = (1.0f * windowSize.x) / textureSize.x;
    float scaleY = (1.0f * windowSize.y) / textureSize.y;
    s.setScale(scaleX, scaleY); //scale the sprite
    // Player player;
    // player.render(); This function in player.cpp will be changed to just render a rectangle/character that can move left/right
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
                if (event.type == Event::Closed)
                    window.close();
        }
        window.clear();
        window.draw(s);
        window.display();
    }
    //Should know when to switch between levels 
    //if (score > 500){
    //  void render(level2)} ??
    //render background and score only
}

inGame::~inGame(){
    delete playAgainBTN;
    delete homeBTN;
    delete LeaderboardBTN;
}
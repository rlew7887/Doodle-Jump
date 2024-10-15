#include "gameOver.h"
#include "Home.h"
#include <iostream>

GameOver::GameOver():score(score){
    highscore = new HighScore();
    font.loadFromFile("./SkeletonFont.ttf"); // Load font file

    // Check if successfully loaded
    if (!font.loadFromFile("./SkeletonFont.ttf"))
    {
            std::cout << "File failed to load" << std::endl;
    }
}

void GameOver::playAgain(){
    this->playAgainBTN = new Button(170,280,90,40,this->font,"Play Again",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void GameOver::home(){
    this->homeBTN = new Button(170,400,90,40,this->font,"Home",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void GameOver::Leaderboard(){
    this->LeaderboardBTN = new Button(170,520,90,40,this->font,"Leader Board",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

void GameOver::render(Player& player){
    // Get device screen size
    VideoMode desktop = VideoMode::getDesktopMode();
    
    RenderWindow window(VideoMode(500, 800), "Game Over");
    // Calculate the center position
    int windowPosX = (desktop.width - 500) / 2;
    int windowPosY = (desktop.height - 800) / 2;
    window.setPosition(Vector2i(windowPosX, windowPosY));

    sf::Texture background;
    background.loadFromFile("grid-bg.jpg");

    if (!background.loadFromFile("grid-bg.jpg")){
        std::cout << "Failed to load" << std::endl; // Check whether image has loaded
    }

    sf::Sprite bg(background);
    sf::Vector2u windowSize = window.getSize(); // Get window size
    sf::Vector2u textureSize = background.getSize(); // Get image size

    // Calculate scale factors to make image fit to window
    float scaleX = (1.0f * windowSize.x) / textureSize.x;
    float scaleY = (1.0f * windowSize.y) / textureSize.y;
    bg.setScale(scaleX, scaleY); // Scale the sprite

    Text title;
    title.setFont(this->font);
    title.setString("Game Over!"); 
    title.setCharacterSize(100);
    title.setFillColor(Color::Black);
    title.setStyle(Text::Bold);
    title.setPosition(120,70);

    Text scoreText;
    scoreText.setFont(this->font); 
    scoreText.setCharacterSize(35); 
    scoreText.setFillColor(Color::Black);
    scoreText.setStyle(Text::Bold);
    scoreText.setPosition(190,180);
    int score = player.getScore();
    highscore->addScore(score); // Add new score to text file

    Text bestScoreText;
    bestScoreText.setFont(this->font); 
    bestScoreText.setCharacterSize(35); 
    bestScoreText.setFillColor(Color::Black);
    bestScoreText.setStyle(Text::Bold);
    bestScoreText.setPosition(190,220);
    int bestScore = highscore->getTopScore(); 

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

        scoreText.setString("Score: " + std::to_string(score));
        bestScoreText.setString("Best: " + std::to_string(bestScore));

        // Update button state according to mouse position
        playAgainBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
        homeBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
        LeaderboardBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));

        //Check if left mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (playAgainBTN->isMouseOver(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y))) {
                    // When play again button is pressed, render a new game
                    window.close();
                    Player newGame;
                    window.setPosition(Vector2i(windowPosX, windowPosY));
                    newGame.render();
                }
                if (homeBTN->isMouseOver(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y))) {
                    // When home button is pressed, render homescreen
                    window.close();
                    Home home;
                    window.setPosition(Vector2i(windowPosX, windowPosY));
                    home.displayGraphics();
                }
                if (LeaderboardBTN->isMouseOver(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y))) {
                    // When leaderboard button is pressed, render leaderboard
                    window.close();
                    HighScore highscore;
                    highscore.displayTopScores();
                    window.setPosition(Vector2i(windowPosX, windowPosY));
                }
            }

        window.clear();
        window.draw(bg); // Draw background image
        window.draw(title);

        // Render the scores
        window.draw(scoreText);
        window.draw(bestScoreText);

        // Draw buttons
        playAgainBTN->render(&window);
        homeBTN->render(&window);
        LeaderboardBTN->render(&window);
        window.display();
    }
}

GameOver::~GameOver(){
    delete playAgainBTN;
    delete homeBTN;
    delete LeaderboardBTN;
    delete highscore;
}
#include "HighScore.h"
#include <iostream>
#include <fstream> 

using namespace std;

HighScore::HighScore():scoreCount(0){
    highScores = new int[10]{};
    font.loadFromFile("./SkeletonFont.ttf"); // load font file

    // Check if successfully loaded
    if (!font.loadFromFile("./SkeletonFont.ttf"))
    {
            std::cout << "File failed to load" << std::endl;
    }
}

void HighScore::home(){
    this->homeBTN = new Button(170,670,90,40,this->font,"Home",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

// Initialize the static instance pointer to nullptr
HighScore* HighScore::instance = nullptr;

// Method to get the single instance of HighScore
HighScore* HighScore::getInstance() {
    if (instance == nullptr) {
        instance = new HighScore();
    }
    return instance;
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

        this->saveScoresToFile();
    }
}

int HighScore::getTopScore(){ //Function to get highest score and display in gameOver?
    return highScores[0];
}

void HighScore::saveScoresToFile(){
    // // Open file in read mode
    // ifstream infile("HighScores.txt");
    // if (!infile.is_open()) {
    //     std::cout << "Failed to open file for reading" << std::endl;
    //     return;
    // }

    // // Read the high scores from the file into the array
    // int score;
    // int i = 0;
    // while (infile >> score && i < 10) {
    //     highScores[i] = score; // Store score in array
    //     i++; // Increment the index to store the next score
    // }

    // infile.close();

    // // Ensure the remaining positions are set to zero if fewer than 10 scores were read
    // for (; i < 10; i++) {
    //     highScores[i] = 0;
    // }
    // Open file in write mode
    ofstream outfile("HighScores.txt");
    if (!outfile.is_open()) {
        cout << "Failed to open file for writing" << endl;
    }

    // Writing the highscores to the file
    for (int i = 0; i < 10; ++i) {
        outfile << highScores[i] << "\n ";
    }
    outfile.close();
}

void HighScore::readScoresToFile(){
    //Open file in read mode
    ifstream infile("HighScores.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file for reading" << endl;
    }

    // Read the high scores from the file into the array
    int i = 0;
    while (infile >> highScores[i] && i < 10) {
        i++; // Increment the index to store the next score
    }

    infile.close();

}

void HighScore::displayTopScores(Player& player){
    int score = player.getScore();
    addScore(score);
    readScoresToFile(); //Load scores from file to draw

    VideoMode desktop = VideoMode::getDesktopMode(); //Get device screen size
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
    title.setPosition(90,50);

    Text scoreText;
    scoreText.setFont(this->font); 
    scoreText.setCharacterSize(40); 
    scoreText.setFillColor(Color::Black);

    //Initialise buttons
    home();

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
                if (event.type == Event::Closed)
                    window.close();
        }

        // Update button state according to mouse position
        homeBTN->updateButton(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));

        //Check if left mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (homeBTN->isMouseOver(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y))) {
                    //when home button is pressed, render homescreen
                    window.close();
                    Home home;
                    home.displayGraphics();
                }
            }

        window.clear();
        window.draw(bg); //draw background image
        window.draw(title);

        // Draw buttons
        homeBTN->render(&window);

        float yPosition = 160; // Starting y position for the first score
        for (int i = 0; i < 10; i++) {
            scoreText.setString(std::to_string(i + 1) + ". " + std::to_string(highScores[i])); // Set score as string
            scoreText.setPosition(210, yPosition); // Set position for each score
            window.draw(scoreText); // Draw each score
            yPosition += 50; // Adjust position for the next score
        }
        window.display();
    }
}

HighScore::~HighScore(){
    delete[] highScores;
}
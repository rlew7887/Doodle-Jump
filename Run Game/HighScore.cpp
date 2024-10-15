#include "HighScore.h"
#include <iostream>
#include <fstream> 
#include <algorithm>

using namespace std;

HighScore::HighScore():capacity(10), size(0){
    highScores = new int[capacity]{0};
    font.loadFromFile("./SkeletonFont.ttf"); // Load font file

    // Check if successfully loaded
    if (!font.loadFromFile("./SkeletonFont.ttf"))
    {
        std::cout << "File failed to load" << std::endl;
    }
}

void HighScore::home(){
    this->homeBTN = new Button(170,670,90,40,this->font,"Home",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
}

int HighScore::getTopScore(){
    return highScores[0];
}

void HighScore::addScore(int score){
    saveScoresToFile(score);
    readScoresFromFile();
    // If the dynamic array is full, check if the new score should replace the lowest one
    if (size == capacity && score > highScores[size - 1]) {
        highScores[size - 1] = score; // Replace the lowest score
    }

    std::sort(highScores, highScores + size, std::greater<int>());

    // Ensure that the size doesn't exceed the capacity (10)
    size = min(size, capacity);
    saveSortedScores();
}

void HighScore::saveSortedScores(){
    // Open file in write mode
    ofstream outfile("HighScores.txt", ios::out);
    if (!outfile.is_open()) {
        cout << "Failed to open file for writing" << endl;
    }

    // Overwrite the top scores to the file
    for (int i = 0; i < size; ++i) {
        outfile << highScores[i] << "\n";
    }

    outfile.close();
}

void HighScore::saveScoresToFile(int score){
    // Open file in write mode
    ofstream outfile("HighScores.txt", ios::app);
    if (!outfile.is_open()) {
        cout << "Failed to open file for writing" << endl;
    }

    // Append the highscores to the file
    outfile << score << "\n ";
    outfile.close();
}

void HighScore::readScoresFromFile(){
    size = 0;
    // Open file in read mode
    ifstream infile("HighScores.txt");
    if (!infile.is_open()) {
        cout << "Failed to open file for reading" << endl;
    }

    // Read the high scores from the file into the array
    int score;
    while (infile >> score && size < 10) {
        highScores[size++] = score;
    }

    infile.close();
}

void HighScore::displayTopScores(){
    readScoresFromFile();

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

    home(); //Initialise button

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
                Home home; //why does this sometimes render player?
                window.setPosition(Vector2i(windowPosX, windowPosY));
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
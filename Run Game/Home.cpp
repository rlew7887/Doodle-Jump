#include "Home.h"
#include <iostream>


Home::Home() {
   highscore = new HighScore(); // Initialize the highscore object
   font.loadFromFile("./SkeletonFont.ttf"); // load font file


   // Check if successfully loaded
   if (!font.loadFromFile("./SkeletonFont.ttf"))
   {
           std::cout << "File failed to load" << std::endl;
   }
}


void Home::displayGraphics() {
   // Get the device screen size
   VideoMode desktop = VideoMode::getDesktopMode();


   // Create the window in the center of the screen
   RenderWindow window(VideoMode(800, 600), "Doodle Jump Home");


   // Calculate the center position
   int windowPosX = (desktop.width - 800) / 2;
   int windowPosY = (desktop.height - 600) / 2;
   window.setPosition(Vector2i(windowPosX, windowPosY));


   // Make title
       Text title;
       title.setFont(this->font); // set font
       title.setString("Doodle Jump"); // set the string to display
       title.setCharacterSize(100); // set the character size
       title.setFillColor(Color::Black); // set the color
       title.setStyle(Text::Bold); // set the text style
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


       // Initialise tutorial popup
       bool showPopup = false;
       bool showError = false;

   while (window.isOpen())
   {
       Event event;
       while (window.pollEvent(event))
       {
           // "close requested" event: we close the window
           if (event.type == Event::Closed)
               window.close();
                // Check for key presses when the tutorial popup is shown  
        if (showPopup && event.type == Event::KeyPressed) {  
           if (event.key.code == Keyboard::X) {  
              showPopup = false;  
           } else {  
              showError = true;  
           }  
        } 
       }


       // Update button state according to mouse position
       Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
       startGameBTN->updateButton(mousePos);
       showLeaderBoardBTN->updateButton(mousePos);
       showTutorialBTN->updateButton(mousePos);


       // Set showPopup to true if tutorial button is pressed
       if (showTutorialBTN->getButtonState() == true) {
           showPopup = true;
           showError = false;
       }


       // Transition to game page when start game button is pressed
       if (startGameBTN->getButtonState() == true) {
           window.close();
           Player newGame;
           newGame.render();
       }


       //Transition to HighScores page when showLeaderBoard button is pressed
       if (showLeaderBoardBTN->getButtonState() == true) {
           window.close();
           highscore->displayTopScores();
       }
      
       // clear the window with black color
       window.clear(Color::Black);
      
       window.draw(background);
       window.draw(title);


       // Draw buttons
       startGameBTN->render(&window);
       showLeaderBoardBTN->render(&window);
       showTutorialBTN->render(&window);


       // Draw tutorial popup
       if (showPopup == true) {
           window.draw(tutorialPopup);
           window.draw(tutorialText);
           }

            // Show error message if needed  
      if (showError) {  
        showErrorMessage(window);  
        showError = false;  
      }  


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
  
   // Tutorial popup box
   tutorialPopup.setSize(Vector2f(500,300));
   tutorialPopup.setFillColor(Color::White);
   tutorialPopup.setPosition(Vector2f(150,180));
   tutorialPopup.setOutlineThickness(2);
   tutorialPopup.setOutlineColor(Color::Black);


   // Set popup text
   tutorialText.setFont(this->font);
   tutorialText.setString("\n                                     Tutorial \n Controls: Left and right arrow keys to move the character \n \n Progress through the game by jumping on the \n platforms. Collect power up tools \n by landing on them and avoid the monsters! \n \n (Press X to exit)");
   tutorialText.setFillColor(Color::Black);
   tutorialText.setCharacterSize(30);


   // Set popup text position to middle of popup screen
   tutorialText.setPosition(
       this->tutorialPopup.getPosition().x + (this->tutorialPopup.getSize().x * this->tutorialPopup.getScale().x) / 2.0f - (tutorialText.getGlobalBounds().width / 2.0f),
       this->tutorialPopup.getPosition().y + (this->tutorialPopup.getSize().y * this->tutorialPopup.getScale().y) / 2.0f - (tutorialText.getGlobalBounds().height / 2.0f) - (tutorialText.getGlobalBounds().height * 0.15f)
   );


}
void Home::showErrorMessage(RenderWindow& window) {  
   RectangleShape errorBox(Vector2f(300, 100));  
   errorBox.setFillColor(Color::White);  
   errorBox.setOutlineThickness(2);  
   errorBox.setOutlineColor(Color::Red);  
   errorBox.setPosition(250, 250);  
  
   Text errorText;  
   errorText.setFont(this->font);  
   errorText.setString("Please press 'X' to exit");  
   errorText.setCharacterSize(20);  
   errorText.setFillColor(Color::Red);  
   errorText.setPosition(  
      errorBox.getPosition().x + (errorBox.getSize().x - errorText.getGlobalBounds().width) / 2,  
      errorBox.getPosition().y + (errorBox.getSize().y - errorText.getGlobalBounds().height) / 2  
   );  
  
   window.draw(errorBox);  
   window.draw(errorText);  
   window.display();  
  
   // Wait for a moment before closing the error message  
   sf::sleep(sf::seconds(2));  
}


Home::~Home() {
   delete startGameBTN;
   delete showTutorialBTN;
   delete showLeaderBoardBTN;
   delete highscore;
}

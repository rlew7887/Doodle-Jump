#include "Player.h"
#include <iostream>


Player::Player() : score(0), blackholeActive(false), scale_count(0) {
   // Initialize the player
   if (!sharkPlayer.loadFromFile("sharkPlayer.png")){
       std::cout << "Failed to load" << std::endl; //Check whether image has loaded
   }
   defaultPlayer.setTexture(sharkPlayer);
   defaultPlayer.setPosition(Vector2f(250, 700)); //Initialize location to prevent glitching
   sharkPlayer.setSmooth(true); //smooths the outline
   sf::Vector2u textureSize = sharkPlayer.getSize();  //Get the original texture size
   scaleX = 100.0f / textureSize.x;  //Calculate scale factor for width
   scaleY = 100.0f / textureSize.y;  //Calculate scale factor for height
   defaultPlayer.setScale(scaleX, scaleY);  //Apply the scale to resize the sprite


   // Check if successfully loaded
   if (!font.loadFromFile("./SkeletonFont.ttf"))
   {
           std::cout << "File failed to load" << std::endl;
   }
}


void Player::moveLeft(float FPS) {
   // Get current position
   Vector2f position = defaultPlayer.getPosition();
   // Move left, scaled with FPS
   position.x -= 370 * FPS;
   defaultPlayer.setPosition(position);
}


void Player::moveRight(float FPS) {
   // Get current position
   Vector2f position = defaultPlayer.getPosition();
   // Move right, scaled with FPS
   position.x += 370 * FPS; 
   defaultPlayer.setPosition(position);
}


void Player::jump(float& velocity, float FPS, Platform& platform, BrokenPlat& brokenPlatform) {
   onPlatform = false;


   // Get current position
   Vector2f position = defaultPlayer.getPosition();
   int jumpX = position.x;
   int jumpY = position.y;


   velocity += 0.2; // Gravity effect -> character falling
   jumpY += velocity * (120 * FPS); // Update character y position according to velocity and FPS


   // Define maximum height the player can reach
   const float maxHeight = 0.0f; //Ensure player does not jump higher than top of the screen


   // Ensure the player doesn't move above the maximum height
   if (jumpY < maxHeight) {
       jumpY = maxHeight; // Restrict the player to maxHeight
   }


   // Collision detection with platforms, as before
   FloatRect playerBounds = defaultPlayer.getGlobalBounds();
   float playerBottom = playerBounds.top + playerBounds.height;


   for (int i = 0; i < 20; i++) {
       float platformTop = platform.plat[i].y;
       float platformBottom = platformTop + 20;


       if (playerBottom >= platformTop && playerBottom <= platformBottom && velocity > 0) {
           if ((defaultPlayer.getPosition().x >= platform.plat[i].x || defaultPlayer.getPosition().x + 50 >= platform.plat[i].x) &&
               (defaultPlayer.getPosition().x <= platform.plat[i].x + 80 || defaultPlayer.getPosition().x + 50 <= platform.plat[i].x + 80)) {
               jumpY = platformTop - playerBounds.height;
               velocity = -9;
               onPlatform = true;
           }
       }
   }


   // Update the player's position after applying the restriction
   defaultPlayer.setPosition(jumpX, jumpY);
}


int Player::getScore(){
   return score;
}


void Player::render() {
    // Get the device screen size
    VideoMode desktop = VideoMode::getDesktopMode();
    // Create the window for the game in the center of the screen
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");
    // Calculate the center position to set window
    int windowPosX = (desktop.width - 500) / 2;
    int windowPosY = (desktop.height - 800) / 2;
    window.setPosition(Vector2i(windowPosX, windowPosY));
    
    // Create background
    sf::Texture background;
    background.loadFromFile("grid-bg.jpg");
    sf::Sprite bg(background);
    sf::Vector2u windowSize = window.getSize(); //get window size
    sf::Vector2u textureSize = background.getSize(); //get image size
    //Calculate scale factors to make image fit to window
    float scaleX = (1.0f * windowSize.x) / textureSize.x;
    float scaleY = (1.0f * windowSize.y) / textureSize.y;
    bg.setScale(scaleX, scaleY); //scale the sprite

    Text scoreText;
    scoreText.setFont(this->font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::Black);
    scoreText.setStyle(Text::Bold);
    scoreText.setPosition(430, 10);

    // Limit framerate to 120 FPS
    window.setFramerateLimit(120);

    velocity = 0; // Initialize velocity for jumping
    Clock clock; // Create a clock to measure time between frames
    Level1 level1; // Initialise level1
    Level2 level2; // Initialise level2
    Level3 level3; // Initialise level3
    level1.setupLevel(); // Setup level1
    level2.setupLevel(); // Setup level2
    level3.setupLevel(); // Setup level3

    while (window.isOpen()) {
        // Time between each frame in seconds (delta time)
        Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        if (!blackholeActive) {
            this->score++;
            scoreText.setString(std::to_string(score));

            Event event;
            while (window.pollEvent(event)) {
                // Close window when 'X' is pressed
                if (event.type == Event::Closed)
                    window.close();
            }

            // Movement when specific keys are pressed
            if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
                moveLeft(deltaTime);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
                moveRight(deltaTime);
            }

            // Make the player reappear on the opposite side if they go off-screen
            if (defaultPlayer.getPosition().x >= 500) {
                defaultPlayer.setPosition(0, defaultPlayer.getPosition().y);
            } else if (defaultPlayer.getPosition().x <= -70) {
                defaultPlayer.setPosition(500, defaultPlayer.getPosition().y);
            }

            // When player falls out of screen
            if (onPlatform == false && defaultPlayer.getPosition().y >= 720) {
                window.close();
                GameOver GameOver;
                GameOver.render(*this);
            }

            // When the player reaches the middle of the window
            if (defaultPlayer.getPosition().y <= window.getSize().y / 2) {
                // Shift all platforms down by 2 pixels
                level1.get_NormalPlat()->shiftDown(2);
                level1.get_BrokenPlat()->shiftDown(2);


                // Shift all powerups down by 2 pixels
                level1.get_Boots()->shiftDown(2,getScore());
                level2.get_HotAirBalloon()->shiftDown(2,getScore());
                level3.get_Rocket()->shiftDown(2,getScore());

                //Shift monster down by 2 pixels
                level3.get_Monster()->shiftDown(2);
            }

            // Reset powerups bool variables according to score
            if (level1.get_Boots()->getDeleteStatus() == true && level1.get_Boots()->getHasBeenTrue() == true) {
                if (getScore() % 600 < 5) { // Until score = 3000
                    level1.get_Boots()->setDeleteStatus(false);
                    level1.get_Boots()->setHasBeenTrue(false);
                    level1.get_Boots()->setHasAppliedEffect(false);
                }
            } else if (level2.get_HotAirBalloon()->getDeleteStatus() == true && level2.get_HotAirBalloon()->getHasBeenTrue() == true) {
                if (getScore() % 700 < 6) { // Until score = 6000
                    level2.get_HotAirBalloon()->setDeleteStatus(false);
                    level2.get_HotAirBalloon()->setHasBeenTrue(false);
                    level2.get_HotAirBalloon()->setHasAppliedEffect(false);
                }
            } else if (level3.get_Rocket()->getDeleteStatus() == true && level3.get_Rocket()->getHasBeenTrue() == true) {
                if (getScore() % 800 < 6) { // Until score = 7200
                    level3.get_Rocket()->setDeleteStatus(false);
                    level3.get_Rocket()->setHasBeenTrue(false);
                    level3.get_Rocket()->setHasAppliedEffect(false);
                }
            }

           // Collision detection for powerups, the powerup disappear as the player collide with it
           if(defaultPlayer.getGlobalBounds().intersects(level1.get_Boots()->getBoots().getGlobalBounds())) {
           level1.get_Boots()->setDeleteStatus(true);
           level1.get_Boots()->setHasBeenTrue(true);
           }
           if (defaultPlayer.getGlobalBounds().intersects(level2.get_HotAirBalloon()->getBalloon().getGlobalBounds())) {
           level2.get_HotAirBalloon()->setDeleteStatus(true);
           level2.get_HotAirBalloon()->setHasBeenTrue(true);
           }
           if (defaultPlayer.getGlobalBounds().intersects(level3.get_Rocket()->getRocket().getGlobalBounds())) {
           level3.get_Rocket()->setDeleteStatus(true);
           level3.get_Rocket()->setHasBeenTrue(true);
           }
          
           // Update boots effect for normal and broken platforms
           level1.get_Boots()->updateEffect(level1.get_NormalPlat(), level1.get_Boots()->getPowerUpCollected());
           level1.get_Boots()->updateEffect(level1.get_BrokenPlat(), level1.get_Boots()->getPowerUpCollected());

           // Update hot air balloon effect
           level2.get_HotAirBalloon()->updateEffect(level1.get_NormalPlat(), level2.get_HotAirBalloon()->getPowerUpCollected());
           level2.get_HotAirBalloon()->updateEffect(level1.get_BrokenPlat(), level2.get_HotAirBalloon()->getPowerUpCollected());
          
           // Jumping implementation
           jump(velocity, deltaTime, *level1.get_NormalPlat(), *level1.get_BrokenPlat()); // for level1 normal platform    
        }

        window.clear();

        // Render the background
        window.draw(bg);

        level1.renderLevel1(&window); // Render level 1

        if (getScore() > 500) {
            level2.renderLevel2(&window); // render level 2 when score reaches 500
        }
        if (getScore() > 700) {
            level3.get_Monster()->randomizeEnemies(getScore());
            level3.renderLevel3(&window); // Render level 3 when score reaches 700
            
            // Initialise temp player positions
            int temp_player_X = 0;
            int temp_player_Y = 0;

            // Check collision with rocket and render the blackhole
            if (defaultPlayer.getGlobalBounds().intersects(level3.get_Rocket()->getRocket().getGlobalBounds())) {
                blackholeActive = true; // Mark blackhole as active


                // Assign to player position when collided with the rocket
                temp_player_X = defaultPlayer.getPosition().x;
                temp_player_Y = defaultPlayer.getPosition().y;
            }

            // Render blackhole if active
            if (blackholeActive) {
                level3.get_Rocket()->renderBlackhole(&window); // draw blackhole
                
                // Check if blackhole is drawn
                if (level3.get_Rocket()->getBlackholeDrawn() == true) {
                    // Shrinking the player smoothly
                    if (scaleX > 0 && scaleY > 0) {
                        scaleX -= 0.02f;  // Decrease scale gradually
                        scaleY -= 0.02f;
                        if (scaleX < 0) scaleX = 0;  // Prevent negative scale
                        if (scaleY < 0) scaleY = 0;


                        defaultPlayer.setScale(scaleX, scaleY);
                        defaultPlayer.setPosition(temp_player_X,temp_player_Y); // Ensure player gets scaled down in the same position
                        scale_count++; // Increment
                    }
                }

                // Once the player is completely gone, trigger the game-over screen
                if (scale_count == 80) {
                    window.close();
                    GameOver gameOver;
                    gameOver.render(*this);
                }
            }

            //Check collision with monster and render game over page
            if (defaultPlayer.getGlobalBounds().intersects(level3.get_Monster()->getMonster().getGlobalBounds())) {
                window.close();
                GameOver gameOver;
                gameOver.render(*this);
            }
        }

        //Render the score
        window.draw(scoreText);

        // Render the player
        window.draw(defaultPlayer);

        window.display();
    }
}

Vector2f Player::get_Position() {
   return defaultPlayer.getPosition();
}



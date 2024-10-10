#include "Player.h"
#include "BrokenPlat.h"
#include <iostream>

Player::Player() : score(0){
    // Initialize the player 
    if (!sharkPlayer.loadFromFile("sharkPlayer.png")){
        std::cout << "Failed to load" << std::endl; //Check whether image has loaded
    }
    defaultPlayer.setTexture(sharkPlayer);
    defaultPlayer.setPosition(Vector2f(250, 700)); //Initialize location to prevent glitching
    sharkPlayer.setSmooth(true); //smooths the outline
    sf::Vector2u textureSize = sharkPlayer.getSize();  //Get the original texture size
    float scaleX = 100.0f / textureSize.x;  //Calculate scale factor for width
    float scaleY = 100.0f / textureSize.y;  //Calculate scale factor for height
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

    float velocity = 0; // Initialize velocity for jumping
    Clock clock; // Create a clock to measure time between frames
    Level1 level1; // Initialise level1
    level1.setupLevel(); // Setup level1

    while (window.isOpen()) {
        // Time between each frame in seconds (delta time)
        Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

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
        }

        // Reset powerups bool variables for every 1000 score
        if (level1.get_Boots()->getDeleteStatus() == true && level1.get_Boots()->getHasBeenTrue() == true) {
            if (getScore() % 1000 < 5) { // Until score = 5000, which is the end of level 1
                level1.get_Boots()->setDeleteStatus(false);
                level1.get_Boots()->setHasBeenTrue(false);
                level1.get_Boots()->setHasAppliedEffect(false);
            }
        }

        // Collision detection for powerups, the powerup disappear as the player collide with it
        if(defaultPlayer.getGlobalBounds().intersects(level1.get_Boots()->getBoots().getGlobalBounds())) {
           level1.get_Boots()->setDeleteStatus(true);
           level1.get_Boots()->setHasBeenTrue(true);
        }
        
        // Redefine bool
        bool powerUpCollected = (level1.get_Boots()->getDeleteStatus() == true && 
                                level1.get_Boots()->getHasBeenTrue() == true &&
                                level1.get_Boots()->getHasAppliedEffect() == false);

        // Update boots effect
        level1.get_Boots()->updateEffect(level1.get_NormalPlat(), powerUpCollected);
        level1.get_Boots()->updateEffect(level1.get_BrokenPlat(), powerUpCollected);


        // Jumping implementation
        jump(velocity, deltaTime, *level1.get_NormalPlat(), *level1.get_BrokenPlat()); // for level1 normal platform
        
        window.clear();

        // Render the background
        window.draw(bg);

        // Render level 1
        level1.renderLevel1(&window);

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
//Player::~Player() {delete gameOver;}

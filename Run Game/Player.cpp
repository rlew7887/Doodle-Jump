#include "Player.h"
#include <iostream>

Player::Player() {
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

void Player::jump(float& velocity, float FPS, Platform& platform) {
    // Initialise bool
    onPlatform = false;

    // Get current position
    Vector2f position = defaultPlayer.getPosition();
    int jumpX = position.x;
    int jumpY = position.y;

    velocity += 0.2; // gravity affect -> character falling
    jumpY += velocity * (120*(FPS)); // change character y position according to velocity * (desired FPS / current FPS = delta time)

    // Create bounding boxes for the player
    FloatRect playerBounds = defaultPlayer.getGlobalBounds();
    float playerBottom = playerBounds.top + playerBounds.height; // bottom bounds of the player

    for (int i = 0; i < 20; i++) {
        // Get top position of the current platform
        float platformTop = platform.plat[i].y; 
        // Get bottom position of the current platform
        float platformBottom = platformTop + 20; 

        // Check if the player's bottom is above the platform and if the player is falling
        if (playerBottom >= platformTop && playerBottom <= platformBottom && velocity > 0) {
            // Check if player position is within the width of the platforms
            if ((defaultPlayer.getPosition().x >= platform.plat[i].x || defaultPlayer.getPosition().x+55 >= platform.plat[i].x) && (defaultPlayer.getPosition().x <= platform.plat[i].x+80 || defaultPlayer.getPosition().x+55 <= platform.plat[i].x+80)) {
                // Player has landed on the platform
                jumpY = platformTop - playerBounds.height; // Position the player on top of the platform
                velocity = -10; // jumping
                onPlatform = true;
                }
            } 
        }

    defaultPlayer.setPosition(jumpX,jumpY); // redefine character position
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

    // Limit framerate to 120 FPS
    window.setFramerateLimit(120);

    float velocity = 0; // Initialize velocity for jumping
    Clock clock; // Create a clock to measure time between frames
    Level1 level1; // Initialise level1
    NormalPlat normalPlatform; // Initialise platforms

    while (window.isOpen()) {
        // Time between each frame in seconds (delta time)
        Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

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
            gameOver = new inGame;
            gameOver->render();
        }


        // When the player reaches the middle of the window
        if (defaultPlayer.getPosition().y <= window.getSize().y / 2) {
            normalPlatform.shiftDown(2); // Shift all platforms down by 2 pixels
        }

        // Jumping implementation
        jump(velocity, deltaTime, normalPlatform);
        
        window.clear();

        // Render the background
        window.draw(bg);

        // Render level 1
        level1.renderLevel1(&window,normalPlatform);

        // Render the player
        window.draw(defaultPlayer);

        window.display();
    }
}

//Player::~Player() {delete gameOver;}

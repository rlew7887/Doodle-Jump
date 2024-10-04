#include "Player.h"

Player::Player() {
    // Initialize the player with size, color, and position
    defaultPlayer.setSize(Vector2f(40.f, 80.f));
    defaultPlayer.setFillColor(Color::Blue);
    defaultPlayer.setPosition(Vector2f(250, 720));
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

void Player::jump(float& velocity, float FPS) {
    // Get current position
    Vector2f position = defaultPlayer.getPosition();
    int jumpX = position.x;
    int jumpY = position.y;

    velocity += 0.2; // gravity affect -> character falling
    jumpY += velocity * (120*(FPS)); // change character y position according to velocity * (desired FPS / current FPS = delta time)
            

    // If character touches the ground (Edit to apply for platforms)
    if (position.y >= 720) {
        velocity = -10; // Jumping 
    }

    defaultPlayer.setPosition(jumpX,jumpY); // redefine character position
}

void Player::render() {
    // Create window for the game
    RenderWindow window(VideoMode(500, 800), "Doodle Jump");

    // Limit framerate to 120 FPS
    window.setFramerateLimit(120);

    // Initialize velocity for jumping
    float velocity = 0;

    // Create a clock to measure time between frames
    Clock clock;

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
        } else if (defaultPlayer.getPosition().x <= 0) {
            defaultPlayer.setPosition(500, defaultPlayer.getPosition().y);
        }

        // Jumping implementation
        jump(velocity, deltaTime);

        // Render the player
        window.clear();
        window.draw(defaultPlayer);
        window.display();
    }
}

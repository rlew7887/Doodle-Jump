// #include "Player.h"

// Player::Player() {
//     defaultPlayer.setSize(Vector2f(40.f,80.f));
//     defaultPlayer.setFillColor(Color::Blue);
//     defaultPlayer.setPosition(Vector2f(250,720));
// }

// void Player:: moveLeft(RectangleShape& player) {
//         Vector2f position = player.getPosition();
//         position.x = position.x-15;
//         player.setPosition(position);
//     }

// void Player::moveRight(RectangleShape& player) {
//         Vector2f position = player.getPosition();
//         position.x = position.x+15;
//         player.setPosition(position);
//     }


// void Player::jump(RectangleShape& player, float& velocity, float FPS) {
//     Vector2f position = player.getPosition();
//     int jumpX = position.x;
//     int jumpY = position.y;

//     velocity += 0.2; // gravity affect -> character falling
//     jumpY += velocity * (120*(FPS)); // change character y position according to velocity * (desired FPS / current FPS = delta time)
            

//     // If character touches the ground (Edit to apply for platforms)
//     if (position.y >= 720) {
//         velocity = -10; // Jumping 
//     }

//     player.setPosition(jumpX,jumpY); // redefine character position
// }

// void Player::render() {
//         RenderWindow window(VideoMode(500, 800), "Doodle Jump");

//         // Limit framerate to 120
//         window.setFramerateLimit(120);

//         // Reset velocity to 0 
//         float velocity = 0;

//         // Clock to measure elasped time between each frame
//         Clock clock;
   
//         while (window.isOpen())
//         {
//             // Define player
//             Player();

//             // Calculate time between each frame in seconds
//             Time elapsed = clock.restart();
//             float timeBetweenFrames = elapsed.asSeconds();
            

//             Event event;
//             while (window.pollEvent(event))
//             {
//                 if (event.type == Event::Closed)
//                     window.close();

//                 // Move left
//                 if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
//                     moveLeft(defaultPlayer);

//                 // Move right
//                 } else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
//                     moveRight(defaultPlayer);
//                 }

//                 // Player reappear from other side of screen if moved out of range
//                 if (defaultPlayer.getPosition().x >= 500) {
//                     defaultPlayer.setPosition(0,defaultPlayer.getPosition().y);
//                 } else if (defaultPlayer.getPosition().x <= 0) { 
//                     defaultPlayer.setPosition(500,defaultPlayer.getPosition().y);
//                 }          
//             }

//             // Jumping 
//             jump(defaultPlayer,velocity,timeBetweenFrames);


//             window.clear();
//             window.draw(defaultPlayer);
//             window.display();
//         }
//     }
#include "Player.h"

Player::Player() {
    // Initialize the player with size, color, and position
    defaultPlayer.setSize(Vector2f(40.f, 80.f));
    defaultPlayer.setFillColor(Color::Blue);
    defaultPlayer.setPosition(Vector2f(250, 720));
}

void Player::moveLeft(float deltaTime) {
    // Get current position and move left, scaled with deltaTime for smooth movement
    Vector2f position = defaultPlayer.getPosition();
    position.x -= 200.f * deltaTime;  // Adjust this value to control speed (200.f is slower)
    defaultPlayer.setPosition(position);
}

void Player::moveRight(float deltaTime) {
    // Get current position and move right, scaled with deltaTime for smooth movement
    Vector2f position = defaultPlayer.getPosition();
    position.x += 200.f * deltaTime;  // Adjust this value to control speed
    defaultPlayer.setPosition(position);
}

void Player::jump(float& velocity, float deltaTime) {
    // Get current position
    Vector2f position = defaultPlayer.getPosition();
    int jumpX = position.x;
    int jumpY = position.y;

    // Apply gravity effect, tweak gravity strength for faster fall
    float gravity = 0.8f;
    velocity += gravity * deltaTime * 60.f;

    // Update Y position based on velocity
    jumpY += velocity * deltaTime * 60.f;

    // If the player hits the ground (y position = 720)
    if (jumpY >= 720) {
        velocity = -20.f;  // Increase jump strength for a higher jump
        jumpY = 720;       // Ensure player doesn't fall below ground level
    }

    // Update the player's position
    defaultPlayer.setPosition(jumpX, jumpY);
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

        // Movement logic - check continuously outside event polling
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

        // Handle jumping logic
        jump(velocity, deltaTime);

        // Render the player
        window.clear();
        window.draw(defaultPlayer);
        window.display();
    }
}

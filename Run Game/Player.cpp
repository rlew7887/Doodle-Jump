#include "Player.h"

Player::Player() {
    defaultPlayer.setSize(Vector2f(40.f,80.f));
    defaultPlayer.setFillColor(Color::Blue);
    defaultPlayer.setPosition(Vector2f(250,720));
}

void Player:: moveLeft(RectangleShape& player, float FPS) {
        Vector2f position = player.getPosition();
        position.x -= 15*(120*(FPS));
        player.setPosition(position);
    }

void Player::moveRight(RectangleShape& player, float FPS) {
        Vector2f position = player.getPosition();
        position.x += 15*(120*(FPS));
        player.setPosition(position);
    }


void Player::jump(RectangleShape& player, float& velocity, float FPS) {
    Vector2f position = player.getPosition();
    int jumpX = position.x;
    int jumpY = position.y;

    velocity += 0.2; // gravity affect -> character falling
    jumpY += velocity * (120*(FPS)); // change character y position according to velocity * (desired FPS / current FPS = delta time)
            

    // If character touches the ground (Edit to apply for platforms)
    if (position.y >= 720) {
        velocity = -10; // Jumping 
    }

    player.setPosition(jumpX,jumpY); // redefine character position
}

void Player::render() {
        RenderWindow window(VideoMode(500, 800), "Doodle Jump");

        // Limit framerate to 120
        window.setFramerateLimit(120);

        // Reset velocity to 0 
        float velocity = 0;

        // Clock to measure elasped time between each frame
        Clock clock;
   
        while (window.isOpen())
        {
            // Define player
            Player();

            // Calculate time between each frame in seconds
            Time elapsed = clock.restart();
            float timeBetweenFrames = elapsed.asSeconds();
            

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();

                // Move left
                if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
                    moveLeft(defaultPlayer,timeBetweenFrames);

                // Move right
                } else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
                    moveRight(defaultPlayer,timeBetweenFrames);
                }

                // Player reappear from other side of screen if moved out of range
                if (defaultPlayer.getPosition().x >= 500) {
                    defaultPlayer.setPosition(0,defaultPlayer.getPosition().y);
                } else if (defaultPlayer.getPosition().x <= 0) { 
                    defaultPlayer.setPosition(500,defaultPlayer.getPosition().y);
                }          
            }

            // Jumping 
            jump(defaultPlayer,velocity,timeBetweenFrames);


            window.clear();
            window.draw(defaultPlayer);
            window.display();
        }
    }
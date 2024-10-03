#include "Player.h"
#include <iostream> 

void Player:: moveLeft(RectangleShape& rect) {
        Vector2f position = rect.getPosition();
        position.x = position.x-15;
        rect.setPosition(position);
    }

void Player::moveRight(RectangleShape& rect) {
        Vector2f position = rect.getPosition();
        position.x = position.x+15;
        rect.setPosition(position);
    }


void Player::jump(RectangleShape& rect, float& velocity, float FPS) {
     Vector2f position = rect.getPosition();
    int x = position.x;
    int y = position.y;

    velocity += 0.2; // gravity affect -> character falling
    y += velocity * (120*(FPS)); // change character y position according to velocity * (desired FPS / current FPS = delta time)
            

    // If character touches the ground (Edit to apply for platforms)
    if (position.y >= 720) {
        velocity = -10; // Jumping 
    }

    rect.setPosition(x,y); // redefine character position
}
void Player::render() {
        RenderWindow window(VideoMode(500, 800), "Doodle Jump");
        RectangleShape rectangle(Vector2f(40.f,80.f));
        rectangle.setFillColor(Color::Blue);
        rectangle.setPosition(Vector2f(250,720));

        // Limit framerate to 120
        window.setFramerateLimit(120);

        // Reset velocity to 0 
        float velocity = 0;

        // Clock to measure elasped time between each frame
        Clock clock;
   
        while (window.isOpen())
        {
            Time elapsed = clock.restart();
            float timeBetweenFrames = elapsed.asSeconds();
            

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();

                // Move left
                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    moveLeft(rectangle);

                // Move right
                } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    moveRight(rectangle);
                }

                // Player reappear from other side of screen if moved out of range
                if (rectangle.getPosition().x >= 500) {
                    rectangle.setPosition(0,rectangle.getPosition().y);
                } else if (rectangle.getPosition().x <= 0) { 
                    rectangle.setPosition(500,rectangle.getPosition().y);
                }          
            }

            // Jumping 
            jump(rectangle,velocity,timeBetweenFrames);


            window.clear();
            window.draw(rectangle);
            window.display();
        }
    }
#include "Player.h"

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


void Player::jump(RectangleShape& rect, float& velocity) {
     Vector2f position = rect.getPosition();
    int x = position.x;
    int y = position.y;

    velocity += 0.015; // gravity affect -> character falling
    y += velocity; // change character y position according to velocity 
            

    // If character touches the ground (Edit to apply for platforms)
    if (position.y >= 720) {
        velocity = -2.5; // Jumping 
    }

    rect.setPosition(x,y); // redefine character position
}


void Player::render() {
        RenderWindow window(VideoMode(500, 800), "Doodle Jump");
        RectangleShape rectangle(Vector2f(40.f,80.f));
        rectangle.setFillColor(Color::Blue);
        rectangle.setPosition(Vector2f(250,720));

        // Reset velocity to 0 
        float velocity = 0;
   
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();

                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    moveLeft(rectangle);
                } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    moveRight(rectangle);
                }
           
            }
            
            jump(rectangle,velocity);

            window.clear();
            window.draw(rectangle);
            window.display();
        }
    }
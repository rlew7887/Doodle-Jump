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


void Player::jump() {
    }


void Player::render() {
        RenderWindow window(VideoMode(500, 800), "Doodle Jump");
        RectangleShape rectangle(Vector2f(40.f,80.f));
        rectangle.setFillColor(Color::Blue);
        rectangle.setPosition(Vector2f(250,720));

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

            window.clear();
            window.draw(rectangle);
            window.display();
        }
    }
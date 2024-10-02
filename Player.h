#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:


  public:  
    void moveLeft(RectangleShape& rect) {
        Vector2f position = rect.getPosition();
        position.x = position.x-15;
        rect.setPosition(position);
    }
    void moveRight(RectangleShape& rect) {
        Vector2f position = rect.getPosition();
        position.x = position.x+15;
        rect.setPosition(position);
    }

    void render() {
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

};

#endif
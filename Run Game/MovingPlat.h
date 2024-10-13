#ifndef MOVINGPLAT_H  
#define MOVINGPLAT_H  
  
#include "Platform.h"  
#include <SFML/Graphics.hpp>  
  

class MovingPlatform {
public:
    MovingPlatform(float startX, float startY) {
        platform.setSize(sf::Vector2f(80.f, 20.f));
        platform.setFillColor(sf::Color::Green);
        platform.setOutlineThickness(1);
        platform.setOutlineColor(sf::Color::Black);
        platform.setPosition(startX, startY);
        direction = 1; // 1 for right, -1 for left
    }

    void update(float deltaTime) {
        sf::Vector2f position = platform.getPosition();
        
        // Move platform
        position.x += direction * speed * deltaTime;
        
        // Switch direction if it hits window borders
        if (position.x <= 0 || position.x + platform.getSize().x >= 500) {
            direction = -direction;
        }
        
        platform.setPosition(position);
    }

    void render(sf::RenderWindow& window) {
        window.draw(platform);
    }

private:
    sf::RectangleShape platform;
    float speed = 100.f; // Speed of movement in pixels per second
    int direction;
};
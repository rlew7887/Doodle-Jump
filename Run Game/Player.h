// #ifndef PLAYER_H
// #define PLAYER_H
// #include <SFML/Graphics.hpp>

// using namespace sf;

// class Player {
//   private:
//     RectangleShape defaultPlayer;

//   public:  
//     Player();

//     void moveLeft(RectangleShape& rect);

//     void moveRight(RectangleShape& rect);

//     void jump(RectangleShape& rect, float& velocity, float FPS);

//     void render();

//     ~Player() {}

// };

// #endif

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:
    RectangleShape defaultPlayer;

  public:  
    Player();

    // Update the function signatures to accept deltaTime as a parameter
    void moveLeft(float deltaTime);

    void moveRight(float deltaTime);

    void jump(float& velocity, float deltaTime);

    void render();

    ~Player() {}

};

#endif

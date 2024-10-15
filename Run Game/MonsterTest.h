#ifndef MONSTERTEST_H
#define MONSTERTEST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Monster.h"

using namespace sf;
using namespace std;

class MonsterTest{
    public:
        void runTests(){
            testConstructor();
            testRandomizeEnemies();
            testShiftDown();
        }
    private:
        void testConstructor(){
            Monster testMonster;
            Vector2f testPosition = testMonster.getMonster().getPosition();  // Check initial position
            if (testPosition.x != 100 || testPosition.y != 10) {
                cout << "Monster constructor test failed!" << endl;
            }
        }

        void testRandomizeEnemies(){
            Monster testMonster;
            testMonster.randomizeEnemies(1000);
            Vector2f testPosition = testMonster.getMonster().getPosition();
            
            // Check if monster generates in valid position
            if (testPosition.x < 0 || testPosition.x > 420 || testPosition.y < 0 || testPosition.y > 20) {
                cout << "Monster randomize enemies test failed!" << endl;
            }
        }

        void testShiftDown(){
            Monster testMonster;
            testMonster.shiftDown(2);
            Vector2f newPos = testMonster.getMonster().getPosition();
            if (newPos.x !=100 || newPos.y !=12){
                cout << "Monster shift down test failed!" << endl;
            }
        }
};

#endif
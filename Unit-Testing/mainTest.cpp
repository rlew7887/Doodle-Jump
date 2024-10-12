#include "PlayerTest.h"
#include "BootsTest.h"
#include "HighScoreTest.h"
#include "HotAirBalloonTest.h"
#include "RocketTest.h"
#include "Level1Test.h"

int main () {
    PlayerTest playerTest;
    playerTest.runTests();

    HighScoreTest highscoreTest;
    highscoreTest.runTests();

    BootsTest bootsTest;
    bootsTest.runTests();

    HotAirBalloonTest balloonTest;
    balloonTest.runTests();

    RocketTest rocketTest;
    rocketTest.runTests();

    Level1Test level1Test;
    level1Test.runTests();

    return 0;
}
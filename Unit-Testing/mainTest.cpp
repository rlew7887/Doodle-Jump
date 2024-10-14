#include "PlayerTest.h"
#include "BootsTest.h"
#include "HighScoreTest.h"
#include "HotAirBalloonTest.h"
#include "RocketTest.h"
#include "Level1Test.h"
#include "Level2Test.h"
#include "Level3Test.h"

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

    Level2Test level2Test;
    level2Test.runTests();

    Level3Test level3Test;
    level3Test.runTests();


    return 0;
}
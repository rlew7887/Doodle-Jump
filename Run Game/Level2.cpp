#include "Level2.h"
Level2::Level2()
    : Level1::Level1(),
      hotAirBalloon(nullptr),
      moving(nullptr) {
}  // initialise nullptr for movingplat and hot air balloon

void Level2::setupLevel() {
  Level1::setupLevel();
  moving = std::make_unique<MovingPlat>();
  hotAirBalloon = std::make_unique<HotAirBalloon>();
  // moving = new MovingPlat;
  // hotAirBalloon = new HotAirBalloon;
}
void Level2::renderLevel2(RenderWindow* window) {
  if (moving != nullptr) {
    moving->render(window);
  }
  if (hotAirBalloon != nullptr && hotAirBalloon->getDeleteStatus() == false &&
      hotAirBalloon->getHasBeenTrue() == false) {
    hotAirBalloon->render(window);
  }
}

void Level2::updateLevel2(float deltaTime) {
  if (moving != nullptr) {
    moving->update(deltaTime);
  }
}

MovingPlat* Level2::get_MovingPlat() { return moving; }
HotAirBalloon* Level2::get_HotAirBalloon() { return hotAirBalloon; }

Level2::~Level2() {
  if (moving) delete moving;
  if (hotAirBalloon) delete hotAirBalloon;
}
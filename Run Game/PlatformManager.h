#ifndef PLATFORMMANAGER_H
#define PLATFORMMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Platform.h"

using namespace sf;

class PlatformManager {
public:
    PlatformManager();
    void addPlatform(float x, float y, float width, float height);
    void renderPlatforms(RenderWindow& window);
    
private:
    std::vector<Platform> platforms;
};

#endif

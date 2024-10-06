#include "PlatformManager.h"

PlatformManager::PlatformManager() {}

void PlatformManager::addPlatform(float x, float y, float width, float height) {
    platforms.emplace_back(x, y, width, height);
}

void PlatformManager::renderPlatforms(RenderWindow& window) {
    for (auto& platform : platforms) {
        platform.render(window);
    }
}
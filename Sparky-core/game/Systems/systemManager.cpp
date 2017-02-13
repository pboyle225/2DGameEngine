#include "systemManager.h"

std::unordered_map<int, std::vector<std::string>> SystemManager::messages;
std::vector<Sprite *> SystemManager::notRenderedSprites;
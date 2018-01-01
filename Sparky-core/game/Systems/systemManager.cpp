#include "systemManager.h"

std::unordered_map<int, std::vector<std::string>> SystemManager::messages;
std::vector<Sprite *> SystemManager::notRenderedSprites;
std::vector<Sprite *> SystemManager::addRenderedSprites;
std::vector<Label *> SystemManager::addLabels;
std::vector<Label *> SystemManager::notRenderedLabels;
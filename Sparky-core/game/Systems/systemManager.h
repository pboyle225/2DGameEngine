#pragma once

#include <unordered_map>
#include "../../graphics/sprite.h"
#include "../../graphics/label.h"

using namespace engine;
using namespace graphics;

class SystemManager
{
public:
	static std::unordered_map<int, std::vector<std::string>> messages;
	static std::vector<Sprite *> notRenderedSprites;
	static std::vector<Sprite *> addRenderedSprites;
	static std::vector<Label *> addLabels;
	static std::vector<Label *> notRenderedLabels;
private:
};

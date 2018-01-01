#pragma once

#include <unordered_map>
#include "../../graphics/sprite.h"
#include "../../graphics/label.h"

using namespace engine;
using namespace graphics;

class SystemManager
{
public:
	static void addMessage(int key, std::string message)
	{
		messages[key].push_back(message);
	}

	static void removeMessage(int key, std::string message)
	{
		for (int i = 0; i < messages[key].size(); i++)
		{
			if (messages[key][i] == message)
			{
				messages[key].erase(messages[key].begin() + i);
			}
		}
	}

	static std::unordered_map<int, std::vector<std::string>> messages;
	static std::vector<Sprite *> notRenderedSprites;
	static std::vector<Sprite *> addRenderedSprites;
	static std::vector<Label *> addLabels;
	static std::vector<Label *> notRenderedLabels;
private:
};

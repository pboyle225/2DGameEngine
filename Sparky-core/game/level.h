#pragma once

#include "tilelayer.h"
#include "scene.h"
#include "TmxFile.h"

class Level
{
public:

	Level(int levelNumber, SpriteSheet * tileSprites);
	~Level();

	std::vector<Scene *> scenes;
	int indexOfCurrScene;

	void loadLevel(int levelNumber, SpriteSheet * tileSprites);

private:

};
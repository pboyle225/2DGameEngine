#pragma once

#include "Components\timerComponent.h"
#include "tilelayer.h"
#include "scene.h"
#include "TmxFile.h"
#include "Entities\chest.h"
#include "Entities\key.h"
#include "Entities\disappearingTile.h"
#include "Components\Transform.h"
#include "Components\collectible.h"
#include "Components\rectangleAppearance.h"
#include "Components\SpriteComponent.h"
#include "Components\attack.h"

class Level
{
public:

	Level(int levelNumber, SpriteSheet * tileSprites);
	~Level();

	std::vector<Scene *> scenes;
	int indexOfCurrScene;

	void loadLevel(int levelNumber, SpriteSheet * tileSprites);
	Entity * findClosestEntity(math::vec3 location);
	float getDistance(math::vec3 loc1, math::vec3 loc2);

	static math::vec3 worldToScreenCoords(math::vec3);
	static math::vec3 screenToWorldCoords(math::vec3);
	static math::vec3 screenToTileCoords(math::vec3);

	static int width;
	static int height;

	std::vector<Entity *> entities;
private:
	static std::vector<bool> isWalkable; //Tiles that are walkable (used for collision)


};
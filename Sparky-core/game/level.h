#pragma once

#include "Components\timerComponent.h"
#include "tilelayer.h"
#include "scene.h"
#include "TmxFile.h"
#include "Entities\chest.h"
#include "Entities\key.h"
#include "Entities\disappearingTile.h"
#include "Entities\slime.h"
#include "Entities\fireball.h"
#include "Entities\attackTextEntity.h"
#include "Components\Transform.h"
#include "Components\collectible.h"
#include "Components\rectangleAppearance.h"
#include "Components\SpriteComponent.h"
#include "Components\attack.h"
#include "Components\collision.h"
#include "Components\AIComponent.h"
#include "Components\circleAppearance.h"
#include "Components\healthComponent.h"
#include "Components\direction.h"
#include "Components\projectile.h"
#include "Components\animationComponent.h"

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
	static math::vec3 playerLoc;

	static std::vector<Entity *> entities;
	static math::vec3 cursorPos;
private:
	static std::vector<bool> isWalkable; //Tiles that are walkable (used for collision)


};
#pragma once

#include "../graphics/layers/layer.h"

#define DEBUG_DRAW 0

using namespace engine;
using namespace graphics;

class Entity;

class Scene
{
public:
	Scene(Layer * backgroundLayer, Layer * objectLayer, Layer * collisionLayer,
		Layer * playerLayer, Layer * hudLayer);
	~Scene();

	void renderLayers(math::vec3 pos, bool isPlayerBehindObjects, std::vector<Entity *> & entities);
	void update(math::vec3 playerLoc);
	Layer * getBackgroundLayer() { return backgroundLayer; }
	Layer * getObjectLayer() { return objectLayer; }
	Layer * getCollisionLayer() { return collisionLayer; }
	Layer * getPlayerLayer() { return playerLayer; }
	Layer * getHudLayer() { return hudLayer; }

	Layer * backgroundLayer; //scene can have any # of layers
	Layer * objectLayer;
	Layer * collisionLayer;
	Layer * playerLayer;
	Layer * hudLayer;
};
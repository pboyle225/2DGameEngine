#pragma once

#include "../graphics/layers/layer.h"

using namespace engine;
using namespace graphics;

class Scene
{
public:
	Scene(Layer * backgroundLayer, Layer * objectLayer, Layer * collisionLayer,
		Layer * playerLayer, Layer * hudLayer);
	~Scene();

	void renderLayers(math::vec3 pos);
	void update(math::vec3 playerLoc);
	Layer * getBackgroundLayer() { return backgroundLayer; }
	Layer * getObjectLayer() { return objectLayer; }
	Layer * getCollisionLayer() { return collisionLayer; }
	Layer * getPlayerLayer() { return playerLayer; }
	Layer * getHudLayer() { return hudLayer; }
private:
	Layer * backgroundLayer; //scene can have any # of layers
	Layer * objectLayer;
	Layer * collisionLayer;
	Layer * playerLayer;
	Layer * hudLayer;
};
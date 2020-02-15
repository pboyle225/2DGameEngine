#pragma once

#include "../graphics/layers/layer.h"

using namespace engine;
using namespace graphics;

class Entity;

class Scene
{
public:
	Scene();
	~Scene();

	void renderLayers();
	void updateCamera(math::vec3 loc);
	std::vector<Layer*> backgroundLayers;
	Layer* objectLayer;
	Layer* hudLayer;
private:
};
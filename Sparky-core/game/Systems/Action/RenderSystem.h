#pragma once

#include "..\system.h"
#include "../../scene.h"

class RenderSystem : public System
{
public:
	void update(std::vector<Entity*>& entities, Layer* layer);
};


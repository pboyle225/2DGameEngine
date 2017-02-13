#pragma once

#include "component.h"
#include "../../graphics/sprite.h"

using namespace engine;
using namespace graphics;

class SpriteComponent : public Component
{
public:
	
	SpriteComponent(Sprite * sprite);
	Sprite * sprite;
	
};
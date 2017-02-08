#pragma once

#include "../Engine.h"

class Entity
{
public:
	Entity() {}
	virtual void update() = 0;
	
protected:
	Sprite* sprite;
};


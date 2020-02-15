#pragma once

#include "..\\system.h"

class CollisionSystem : public System
{
public:
	void HandleCollisions(std::vector<Collision> collisions);
private:

};
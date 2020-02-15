#pragma once

#include "..\system.h"

class PhysicsSystem : public System
{
public:
	void update(std::vector<Entity*>& entities, Timer& deltaTime);
	bool AreRectanglesCollided(RectangleCollider* rect1, math::vec3 loc1, RectangleCollider* rect2, math::vec3 loc2);
private:
	std::vector<Entity*> removeVel;
	void HandleCollisions(std::vector<Entity*>& entities, const math::vec3& dt);
};

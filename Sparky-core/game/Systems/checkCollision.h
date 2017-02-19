#pragma once

#include "system.h"

class CheckCollision : public System
{
public:
	void update(std::vector<Entity*> &entities) override;
private:
	bool checkTile(math::vec3 location);
};

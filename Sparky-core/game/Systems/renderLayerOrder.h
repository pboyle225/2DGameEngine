#pragma once
#include "system.h"

class RenderLayerOrder : public System
{
public:
	void update(std::vector<Entity*> &entities) { } //never use this
	bool update(std::vector<Entity*> &entities, math::vec3 playerLoc);
private:
	Transform * findClosestEntity(std::vector<Entity *> entities, math::vec3 playerLoc);
	float getDistance(math::vec3 loc1, math::vec3 loc2);

};

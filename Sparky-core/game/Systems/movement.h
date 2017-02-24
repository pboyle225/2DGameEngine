#pragma once

#include "system.h"

class Movement : public System
{
public:
	void update(std::vector<Entity*> &entities)  override;
	bool checkTile(math::vec3 location);
	void playBoundrySound();
private:

};

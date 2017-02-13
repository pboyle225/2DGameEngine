#pragma once

#include "../Entities/entity.h"
#include "../Components/input.h"
#include "../player.h"
#include "../Components/Transform.h"
#include "../Components/collision.h"
#include "../Components/velocity.h"
#include "../Components/toDelete.h"
#include "../Components/timerComponent.h"
#include "systemManager.h"
#include <vector>

/*
	Keys for Systems for message:
	0 - userInput
	1 - checkCollision
	2 - movement
	3 - objectDestroyer
	4 - rendering 
	5 - renderLayerOrder
*/


class System
{
public:
	virtual void update(std::vector<Entity *> &entities) = 0;
};

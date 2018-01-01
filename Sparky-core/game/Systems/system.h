#pragma once

#include "../Components/input.h"
#include "../Components/Transform.h"
#include "../Components/collision.h"
#include "../Components/velocity.h"
#include "../Components/toDelete.h"
#include "../Components/timerComponent.h"
#include "../Components/healthComponent.h"
#include "../Components/knockBack.h"
#include "../Components/labelComponent.h"
#include "../player.h"
#include "systemManager.h"
//#include "../Entities/entity.h"
#include <vector>

/*
	Keys for Systems for message:
	0 - userInput
	1 - checkCollision
	2 - movement
	3 - objectDestroyer
	4 - rendering 
	5 - renderLayerOrder
	6 - AISystem
*/


class System
{
public:
	virtual void update(std::vector<Entity*> &entities) = 0;
	std::vector<Entity *> systemEntities; //Each system will only hold the entities w/ components they care about
};

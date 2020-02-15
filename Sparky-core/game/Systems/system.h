#pragma once

#include "../Components/Control/input.h"
#include "../Entities/fireball.h"
#include "../Entities/attackTextEntity.h"
#include "../Components/attack.h"
#include "../Components/Control/Transform.h"
#include "../Components/Physics/Collision.h"
#include "../Components/Physics/Velocity.h"
#include "../Components/toDelete.h"
#include "../Components/Action/Render.h"
#include "../Components/timerComponent.h"
#include "../Components/healthComponent.h"
#include "../Components/knockBack.h"
#include "..\\Components\Action\Animation.h"
#include "..\\Components\Physics\RectangleCollider.h"
#include "../player.h"
#include "systemManager.h"
#include "..\\Enums\GlobalId.h"
#include "..\\Enums\ComponentIDEnum.h"
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
	virtual void update(std::vector<Entity*> &entities) { }
	std::vector<Entity *> systemEntities;
};

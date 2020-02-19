#pragma once

#include "../Components/Control/input.h"
#include "../Entities/fireball.h"
#include "../Entities/attackTextEntity.h"
#include "../Components/Control/Transform.h"
#include "../Components/Physics/Collision.h"
#include "../Components/Physics/Velocity.h"
#include "../Components/toDelete.h"
#include "../Components/Action/Render.h"
#include "../Components/timerComponent.h"
#include "../Components/healthComponent.h"
#include "../Components/knockBack.h"
#include "..\\Components\Action\Animation.h"
#include "..\\Components\Attacks\Attack.h"
#include "..\\Components\Physics\RectangleCollider.h"
#include "..\\\Entities\Player.h"
#include "..\\Enums\GlobalId.h"
#include "..\\Enums\ComponentIDEnum.h"
#include "..\\Enums\EntityEnum.h"
#include "..\\Components\Control\CursorC.h"
#include <vector>

class System
{
public:
	virtual void update(std::vector<Entity*> &entities) { }
	std::vector<Entity *> systemEntities;
};

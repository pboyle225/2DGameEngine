#pragma once
#include <vector>
#include <unordered_map>
#include <bitset>
#include "../../math/_math.h"
#include "..\\Enums\ComponentIDEnum.h"

#define MAX_COMPONENTS 20

const std::bitset <MAX_COMPONENTS> INPUT_MASK = 0x1 << ComponentIDEnum::InputComp;
const std::bitset <MAX_COMPONENTS> AI_MASK = INPUT_MASK;
const std::bitset <MAX_COMPONENTS> TRANSFORM_MASK = 0x1 << ComponentIDEnum::TransformComp;
const std::bitset <MAX_COMPONENTS> MOVEMENT_MASK = INPUT_MASK;
const std::bitset <MAX_COMPONENTS> ANIMATION_MASK = 0x1 << ComponentIDEnum::AnimComp;
const std::bitset <MAX_COMPONENTS> RENDER_MASK = 0x1 << ComponentIDEnum::RenderComp;
const std::bitset <MAX_COMPONENTS> RECTANGLE_COLLIDER_MASK = 0x1 << ComponentIDEnum::RectangleColliderComp;
const std::bitset <MAX_COMPONENTS> PHYSICS_MASK = RECTANGLE_COLLIDER_MASK;
const std::bitset <MAX_COMPONENTS> COLLISION_MASK = 0x1 << ComponentIDEnum::CollisionComp;
const std::bitset <MAX_COMPONENTS> CURSOR_MASK = 0x1 << ComponentIDEnum::CursorComp;

//const std::bitset <MAX_COMPONENTS> TIMER_MASK = 0x100;
//const std::bitset <MAX_COMPONENTS> OBJECT_DESTROYER_MASK = 0x200;
//const std::bitset <MAX_COMPONENTS> KNOCKBACK_MASK = 0x4000;
//const std::bitset <MAX_COMPONENTS> ATTACK_MASK = 0x400;

class Entity;

using namespace engine;

class Component
{
public:
	Component() { }

	Component(Entity* entity)
	{
		this->entity = entity;
	}

	virtual ~Component() { }

	int getID()
	{
		return id;
	}

	Entity* getEntity()
	{
		return entity;
	}

	std::bitset<MAX_COMPONENTS> bitmask;
protected:
	std::string name;
	int id;
	Entity* entity;
};
#pragma once
#include "../../../math/_math.h"
#include "CombatSkill.h"

using namespace engine;

class JumpAttack : public CombatSkill
{
public:

	JumpAttack(Entity * entityUsingAttack, math::vec3 jumpLoc)
	{
		this->entityUsingAttack = entityUsingAttack;
		this->jumpLoc = jumpLoc;
		this->currFrame = 0;
		this->id = 0;
		this->isJumping = false;
	}

	math::vec3 jumpLoc;
	int currFrame;
	Entity * entityUsingAttack;
	bool isJumping;
};
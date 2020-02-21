#pragma once

#include "..\\System.h"
#include "..\..\\Components\Attacks\FireballAttack.h"

class AttackSystem : public System
{
public:
	void update(std::vector<Entity*>& entities, math::vec2 mousePos);
private:
	void CreateFireballAttack(Entity* ent, Attack* attack, math::vec2 mousePos);
};
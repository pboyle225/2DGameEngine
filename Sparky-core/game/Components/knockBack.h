#pragma once

#include "component.h"

class KnockBack : public Component {
public:
	KnockBack(float amount, math::vec3 direction, math::vec3 entityLoc);
	KnockBack(math::vec3 endLocation, float howFast);

	float amount;
	math::vec3 knockBackLoc;
	math::vec3 direction;
	float currFrameDistance;

};
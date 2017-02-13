#pragma once

#include "system.h"

class TimerSystem : public System
{
public:
	void update(std::vector<Entity *> &entitiesvector) override;
};

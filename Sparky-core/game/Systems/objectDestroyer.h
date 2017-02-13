#pragma once

#include "system.h"

class ObjectDestroyer : public System
{
public:
	void update(std::vector<Entity *>& entitiesvector) override;
private:

};
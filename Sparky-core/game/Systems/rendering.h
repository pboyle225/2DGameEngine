#pragma once


#include "system.h"

class Rendering : public System
{
public:
	void update(std::vector<Entity *> &entitiesvector) override { }
	void update(std::vector<Entity *> &entitiesvector, Scene * currScene);
};


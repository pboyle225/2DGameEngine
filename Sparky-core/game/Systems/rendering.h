#pragma once


#include "system.h"

class Rendering : public System
{
public:
	void update(std::vector<Entity*> &entities)  override { }
	void update(std::vector<Entity*> &entities, Scene * currScene);
};


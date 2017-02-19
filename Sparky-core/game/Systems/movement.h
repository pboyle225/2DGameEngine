#pragma once

#include "system.h"

class Movement : public System
{
public:
	void update(std::vector<Entity*> &entities)  override;
private:

};

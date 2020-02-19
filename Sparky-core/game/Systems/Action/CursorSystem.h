#pragma once

#include "..\\system.h"

class CursorSystem : public System
{
public:
	void update(std::vector<Entity*>& entities, math::vec2 cursorPos, math::vec2 windowDim);
private:
};
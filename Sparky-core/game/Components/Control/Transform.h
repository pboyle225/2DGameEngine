#pragma once

#include "..\component.h"

enum
{

};

class Transform : public Component
{
public:
	Transform(math::vec3 loc);
	~Transform();
	engine::math::vec3 location;

private:
};

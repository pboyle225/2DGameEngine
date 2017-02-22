#include "Transform.h"

Transform::Transform(math::vec3 loc)
{
	name = "Transform";
	id = 0;
	location = loc;
	bitmask = 0x1 << 0;
}

Transform::~Transform()
{

}
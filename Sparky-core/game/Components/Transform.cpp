#include "Transform.h"

Transform::Transform(math::vec3 loc)
{
	name = "location";
	id = 0;
	location = loc;
	bitmask = 0x1 << 0;
}

Transform::~Transform()
{

}
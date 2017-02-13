#include "Transform.h"

Transform::Transform(math::vec3 loc)
{
	name = "location";
	id = 0;
	location = loc;
}

Transform::~Transform()
{

}
#include "Transform.h"

Transform::Transform(math::vec3 loc)
{
	name = "Transform";
	id = ComponentIDEnum::TransformComp;
	location = loc;
	bitmask = TRANSFORM_MASK;
}

Transform::~Transform()
{

}
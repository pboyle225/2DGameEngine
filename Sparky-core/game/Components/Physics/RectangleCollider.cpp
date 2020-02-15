#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(math::vec2 size)
{
	id = ComponentIDEnum::RectangleColliderComp;
	name = "Rectangle Collider";
	this->width = size.x;
	this->height = size.y;

	bitmask = RECTANGLE_COLLIDER_MASK;
}

RectangleCollider::RectangleCollider(float width, float height) : RectangleCollider(math::vec2(width, height))
{

}

RectangleCollider::RectangleCollider(math::vec2 size, bool isEnabled, bool isSolid) : RectangleCollider(size)
{
	this->isEnabled = isEnabled;
	this->isSolid = isSolid;
}
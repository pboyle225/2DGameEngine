#include "rectangleAppearance.h"

RectangleAppearance::RectangleAppearance(float width, float height)
{
	id = 6;
	name = "Rectangle Appearance";
	this->width = width;
	this->height = height;

	bitmask = 0x1 << 6;
}
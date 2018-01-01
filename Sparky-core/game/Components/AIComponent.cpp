#include "AIComponent.h"

AIComponent::AIComponent(bool canMove, float speed)
{
	id = 11;
	name = "AI Component";
	bitmask = 0x1 << 11;

	this->canMove = canMove;
	this->isAggro = false;
	this->speed = speed;
	this->entThatAggro = NULL;
}
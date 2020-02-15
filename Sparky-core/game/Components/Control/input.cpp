#include "Input.h"

Input::Input(float speed, InputType type)
{
	id = ComponentIDEnum::InputComp;
	name = "Input";
	bitmask = INPUT_MASK;
	this->speed = speed;
	this->direction = DOWN;
	this->isMainAttacking = false;
	this->type = type;
	this->movementDir = math::vec3(0,0,0);
}

Input::~Input()
{

}

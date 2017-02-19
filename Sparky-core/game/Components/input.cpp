#include "input.h"

Input::Input(Window * window)
{
	id = 2;
	name = "Input";
	this->window = window;
	bitmask = 0x1 << 2;
}

Input::~Input()
{

}

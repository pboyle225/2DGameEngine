#pragma once

#include "component.h"
#include "../../graphics/window.h"

using namespace engine;
using namespace graphics;

class Input : public Component
{
public:
	Input(Window * window);
	~Input();
	Window * window; //Access to window functions for keypresses;
private:
};
#pragma once

#include "component.h"
#include "../../graphics/label.h"

using namespace engine;
using namespace graphics;

class LabelComponent : public Component
{
public:
	LabelComponent(Label * label);

	Label * label;
};
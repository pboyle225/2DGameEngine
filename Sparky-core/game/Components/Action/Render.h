#pragma once

#include "..\\component.h"
#include "..\\..\\..\\graphics\renderable2d.h"

using namespace graphics;

class Render : public Component
{
public:
	Render(Renderable2D* renderable);
	Renderable2D* GetRenderable();
private:
	Renderable2D* renderable;
};

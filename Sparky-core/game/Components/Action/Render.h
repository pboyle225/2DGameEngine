#pragma once

#include "..\\component.h"
#include "..\\..\\..\\graphics\renderable2d.h"

using namespace graphics;

class Render : public Component
{
public:
	Render(Renderable2D* renderable);
	Render(Renderable2D* renderable, bool isShown);
	Renderable2D* GetRenderable();
	bool isShown = true;
private:
	Renderable2D* renderable;
};

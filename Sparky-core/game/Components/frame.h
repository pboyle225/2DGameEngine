#pragma once

#include "../../graphics/sprite.h"

using namespace engine;
using namespace graphics;

class Frame
{
public:
	Frame(Sprite* sprite, int duration)
	{
		this->frame = sprite;
		this->duration = duration;
	}

	Sprite* getFrame()
	{
		return frame;
	}

	void setFrame(Sprite* sprite)
	{
		this->frame = sprite;
	}

	int getDuration()
	{
		return duration;
	}

	void setDuration(int duration)
	{
		this->duration = duration;
	}

	Sprite* frame;
private:
	int duration;

};
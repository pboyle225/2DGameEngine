#pragma once

#include "../../graphics/sprite.h"

using namespace engine;
using namespace graphics;

class Frame
{
public:
	Frame(Texture* sprite, int duration)
	{
		this->frame = sprite;
		this->duration = duration;
	}

	Texture * getFrame()
	{
		return frame;
	}

	void setFrame(Texture* sprite)
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

	Texture * frame;
private:
	int duration;

};
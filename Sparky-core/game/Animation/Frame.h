#pragma once

#include "../../graphics/sprite.h"

using namespace engine;
using namespace graphics;

class Frame
{
public:
	Frame(Texture* texture, int duration)
	{
		this->frame = texture;
		this->duration = duration;
	}

	Texture* getFrame()
	{
		return frame;
	}

	void setFrame(Texture* texture)
	{
		this->frame = texture;
	}

	int getDuration()
	{
		return duration;
	}

	void setDuration(int duration)
	{
		this->duration = duration;
	}

private:
	Texture* frame;
	int duration;
};
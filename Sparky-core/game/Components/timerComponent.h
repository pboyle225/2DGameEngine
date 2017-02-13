#pragma once

#include "../../utils/timer.h"
#include "component.h"

class TimerComponent : public Component
{
public:
	TimerComponent(float timeAlive);
	TimerComponent(float timeAlive, float timeDead);

	Timer * timer;
	float timeAlive;
	float timeDead;
	bool isAlive;
};

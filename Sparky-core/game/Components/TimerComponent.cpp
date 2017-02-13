#include "timerComponent.h"

TimerComponent::TimerComponent(float timeAlive)
{
	id = 8;
	name = "Timer Component";
	this->timeAlive = timeAlive;
	this->timeDead = 0;
	timer = new Timer();
	isAlive = true;
}

TimerComponent::TimerComponent(float timeAlive, float timeDead)
{
	id = 8;
	name = "Timer Component";
	this->timeAlive = timeAlive;
	this->timeDead = timeDead;
	timer = new Timer();
	isAlive = true;
}
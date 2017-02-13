#pragma once
#include "system.h"

class UserInput : public System
{
public:
	UserInput() { }
	~UserInput() { }
	void update(std::vector<Entity *> &entities) override;
private:

};

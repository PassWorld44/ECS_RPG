#pragma once

#include "Entity.h"

class Component
{
private:
	ID idEnt;
protected:
	Component(); //deleting instanciation from base class
public:
	ID get_id();
};

struct PositionComponent : public Component {
	int x{};
	int y{};
};

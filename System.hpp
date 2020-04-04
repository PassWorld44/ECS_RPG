#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class System
{
private:
	std::map<ID, std::vector<Component&>> listComponents;
public:
	virtual void update() = 0; //the wole fonc
};


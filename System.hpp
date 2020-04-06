#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class System
{
private:
	std::map<ID, std::vector<std::reference_wrapper<Component>>> listComponent;
public:
	virtual ~System();

	virtual void update() = 0; //the wole fonc

	void addComponent(Component& conp);
};

// Je sais pas si on devrai commencer par celui la XD
class InputSystem : public System
{
private:

public:
};
#include "Entity.h"
#include "Component.h"

ID getID()
{
	static size_t id{ 0 };

	return id++; //return id, then increments it
}

Entity::Entity()
{
	this->id = getID();
}


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

template<class T, class ...Args>
inline void Entity::addComponent(Args&& ...args)
{
	listComponent.push_back(std::make_shared<T>(args));
}


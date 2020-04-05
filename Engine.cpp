#include "Engine.hpp"

ID Engine::createID()
//ID factory, create a unique ID for each Entity
{
	static int id{ 0 };
	return id++; //return id, then increments it
}

void Engine::loop()
{
	while (this->is_continuing)
	{
		for (std::unique_ptr<System>& i : listSystems)
		{
			i->update(); //Tadaaa
		}
	}
}

Engine::Engine()
{
	this->is_continuing = true;
}

ID Engine::addEntity() //creating a new entity by inserting it
{
	ID id = createID();

	this->listEntity.insert({ id, std::make_unique<Entity>(id) });
	//(i hope this actually works)

	return id;
}

template<typename ComponentChild, typename... Args>
void Engine::addComponent(const ID& entity, const ComponentChild& comp, Args&&... args)
{
	this->listEntity[entity]->addComponent<ComponentChild>(Args);
}

template<typename ComponentChild>
void Engine::removeComponent(const ID& entity)
{
	this->listEntity[entity]->removeComponent<ComponentChild>();
}

#pragma once

#include "Entity.hpp"
#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"
#include "System.hpp"

class Engine
{
private:
	std::map<ID, Entity> listEntity;
	std::vector<std::unique_ptr<System>> listSystems;

	bool is_continuing; //for the main loop

	ID createID();

	void loop();

public:
	Engine();

	ID addEntity();

	template<typename ComponentChild, typename... Args>
	void addComponent(const ID& entity, Args&&... args);

	template<typename ComponentChild>
	void removeComponent(const ID& entity);

	std::ostream& sortie(std::ostream& output) const;
};

std::ostream& operator<<(std::ostream& output, const Engine& e);

template<typename ComponentChild, typename... Args>
void Engine::addComponent(const ID& entity, Args&&... args)
{
	this->listEntity[entity].addComponent<ComponentChild>(entity, args...);
}

template<typename ComponentChild>
void Engine::removeComponent(const ID& entity)
{
	this->listEntity[entity].removeComponent<ComponentChild>();
}
#pragma once

#include "Entity.hpp"
#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class Engine
{
private:
	std::map<ID, std::unique_ptr<Entity>> listEntity;

	ID createID();

public:
	Engine();

	ID addEntity();

	template<typename ComponentChild, typename... Args>
	void addComponent(const ID& entity, const ComponentChild& comp, Args&&... args);
};


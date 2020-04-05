#pragma once

#include "Entity.hpp"
#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"
#include "System.hpp"

class Engine
{
private:
	std::map<ID, std::unique_ptr<Entity>> listEntity;
	std::vector<std::unique_ptr<System>> listSystems;

	bool is_continuing; //for the main loop

	ID createID();

	void loop();

public:
	Engine();

	ID addEntity();

	template<typename ComponentChild, typename... Args>
	void addComponent(const ID& entity, const ComponentChild& comp,Args&&... args);

	template<typename ComponentChild>
	void removeComponent(const ID& entity);


};


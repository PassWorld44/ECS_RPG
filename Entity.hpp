#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class Component;

class Entity
{
private:
	ID id;
	std::map<const char*,std::unique_ptr<Component>> listComponent;
public:
	Entity(ID const& id_g);

	template<typename T, typename... Args>
	void addComponent(Args&&... args);

	template<typename T> void inline removeComponent();

	template<typename T>
	T& getComponent() const;  //pour l'init

	std::ostream& sortie(std::ostream& output) const;
};

std::ostream& operator<<(std::ostream& output, const Entity& ent);




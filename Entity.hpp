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
	~Entity() { std::cout << "Destroyed Entity => ID : " << id << std::endl; }

	template<typename T>
	void addComponent(T const& component);

	template<typename T> void removeComponent();

	template<typename T>
	T& getComponent() const;  //pour l'init

	std::ostream& sortie(std::ostream& output) const;
};

std::ostream& operator<<(std::ostream& output, const Entity& ent);

template<typename T>
void Entity::addComponent(T const& component)
{
	listComponent.emplace(std::pair<const char*,std::unique_ptr<T>>{typeid(T).name(),std::make_unique<T>(component)});
}

template<typename T> 
void Entity::removeComponent()
{
	std::map<const char*,std::unique_ptr<Component>>::iterator it = listComponent.find(typeid(T).name());
	if(it != this->listComponent.end())
		listComponent.erase(it);
}

template<typename T>
T& Entity::getComponent() const
{
	std::map<const char*, std::unique_ptr<Component>>::iterator it = listComponent.find(typeid(T).name());
	return &(it->second);
}
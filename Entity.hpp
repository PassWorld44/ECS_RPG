#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class Component;

class Entity
{
private:
	ID id;
	std::map<IDTypeComponent,std::unique_ptr<Component>> listComponent;
public:
	Entity(ID const& id_g);
	~Entity() { std::cout << "Destroyed Entity => ID : " << id << std::endl; }

	template<typename T, typename... Args>
	void addComponent(ID const& id, Args&&... args);

	template<typename T> void removeComponent();

	template<typename T>
	T& getComponent() const;  //pour l'init

	std::ostream& sortie(std::ostream& output) const;
};

std::ostream& operator<<(std::ostream& output, const Entity& ent);

template<typename T, typename... Args>
void Entity::addComponent(ID const& id, Args&&... args)
{
	listComponent.emplace(Component::getIDType<T>(), std::make_unique<T>(id,args...));
}

template<typename T> 
void Entity::removeComponent()
{
	std::map<IDTypeComponent,std::unique_ptr<Component>>::iterator it = 
		listComponent.find(Component::getIDType<Component>());
	if(it != this->listComponent.end())
		listComponent.erase(it);
}

template<typename T>
T& Entity::getComponent() const
{
	std::map<IDTypeComponent, std::unique_ptr<Component>>::iterator it = 
		listComponent.find(Component::getIDType<Component>());
	return &(it->second);
}
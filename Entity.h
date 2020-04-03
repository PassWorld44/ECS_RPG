#pragma once

#include <vector>
#include <memory>

using ID = size_t;

class Component;

ID getID();


class Entity
{
private:
	ID id;
	std::vector<std::unique_ptr<Component>> listComponent;
public:
	Entity();

	template< class T, class... Args >
	void addComponent(Args&&... args);

	//void removeComponent() => how ?
};
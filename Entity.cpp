#include "Entity.hpp"

Entity::Entity(ID const& id_g)
:id(id_g)
{
	std::cout << "Creation de l'Entity ID : " << id << std::endl;
}

/*void Entity::removeComponent()
{
	// on supprime tous les components
	for(std::vector<std::unique_ptr<Component>>::iterator it = listComponent.begin(); it != listComponent.end(); it++)
	{
		delete it;
	}
} */

void Entity::removeComponent(const Component& component) // Pour 1 component //TO DO : resolve this problem
{
	// Il cherche si il y a le component dans la liste
	std::vector<std::unique_ptr<Component>>::iterator it = find_if(listComponent.begin(), listComponent.end(), 
		[component](std::unique_ptr<Component> ptr) {return component == *ptr;  });

	if (it != this->listComponent.end()) // si il en trouve un
		this->listComponent.erase(it); // on le supprime
}


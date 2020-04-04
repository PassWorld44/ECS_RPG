#include "Headers"

Entity::Entity(ID const& id_g)
:id(id_g)
{
	std::cout << "Creation de l'Entity ID : " << id << std::endl;
}

void Entity::removeComponent()
{
	// on supprime tous les components
	for(std::vector<std::unique_ptr<Component>>::iterator it = listComponent.begin(); it != listComponent.end(); it++)
	{
		delete it;
	}
}

void Entity::removeComponent(Component component) // Pour 1 component
{
	// Il cherche si il y a le component dans la liste
	std::vector<std::unique_ptr<Component>>::iterator it = find(listComponent.begin(), listComponent.end(), component);
	if(it != nullptr) // si il en trouve un
		delete it; // on le supprime
}
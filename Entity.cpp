#include "Entity.hpp"

Entity::Entity(ID const& id_g)
:id(id_g)
{
	std::cout << "Creation de l'Entity ID : " << this->id << std::endl;
}

std::ostream& Entity::sortie(std::ostream& output) const
{
	output << "Entity : " << id << std::endl;
	for (auto it = listComponent.begin();
		it != listComponent.end() ; it++ )
	{
		output << it->first << " " << *(it->second) << std::endl;
	}

	return output;
}

std::ostream& operator<<(std::ostream& output, const Entity& ent)
{
	ent.sortie(output);
	return output;
}

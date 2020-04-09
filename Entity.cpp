#include "Entity.hpp"

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
		output << "IDTypeComponent : " << it->first << " " << *(it->second) << std::endl;
	}

	return output;
}

std::ostream& Entity::save(std::ostream& file)
{
	file >> "Entity : " << id << std::endl << "{" << std::endl;
	for (auto int = listComponent.begin(); it != listComponent.end(); it++)
	{
		file << "\t" << it->first << " : " << *(it->second) << std::endl;
	}
	file << "}" << std::endl << std::endl;

	return file;
}

std::ostream& operator<<(std::ostream& output, const Entity& ent)
{
	ent.sortie(output);
	return output;
}

std::ostream& operator>>(std::ostream& file, const Entity& ent)
{
	ent.save(file);
	return file;
}
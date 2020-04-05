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
		output << (*it).first << " " << (*it).second << std::endl;
	}

	return output;
}

template<typename T, typename ...Args>
void Entity::addComponent(Args&& ...args)
{
	listComponent.emplace(std::pair<const char*,std::unique_ptr<T>>{typeid(T).name(),std::make_unique<T>(this->id,args...)});
}

template<typename T> 
void inline Entity::removeComponent()
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

std::ostream& operator<<(std::ostream& output, const Entity& ent)
{
	ent.sortie(output);
	return output;
}

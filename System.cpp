#include "System.hpp"

void System::addComponent(Component& comp)
{
	if (!(this->listComponents.emplace(comp.getID(), std::vector<std::reference_wrapper<Component>>{ comp })).second)
	if (!(this->listComponent.emplace(comp.getID(), 
		std::vector<std::reference_wrapper<Component>>{ comp })).second)
	//this means compo.get_id() is aleady a key
	{
		this->listComponent[comp.getID()].push_back(comp);
	}
}

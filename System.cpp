#include "System.hpp"

void System::addComponent(Component& comp)
{
	if (!(this->listComponents.emplace(comp.getID(), comp)).second)
	//this means compo.get_id() is aleady a key
	{
		this->listComponents[comp.getID()].push_back(comp);
	}
}

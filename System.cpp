#include "System.hpp"

void System::addComponent(Component& comp)
{
	if (!(this->listComponents.emplace(comp.get_id(), comp)).second)
	//this means compo.get_id() is aleady a key
	{
		this->listComponents[comp.get_id()].push_back(comp);
	}
}

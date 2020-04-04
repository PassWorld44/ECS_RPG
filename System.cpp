#include "System.hpp"

void System::addComponent(Component& comp)
{
	this->listComponents.insert({ comp.get_id() , comp });
}

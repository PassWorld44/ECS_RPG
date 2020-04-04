#pragma once

#include "System.hpp"

class Systems
{
private:
	std::vector<std::unique_ptr<System>> listSystems; //pareil faut un moyen de trier les systems
public:

	//void addSystem(); TO DO

	void update();
};

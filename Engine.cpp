#include "Engine.hpp"

ID Engine::createID()
//ID factory, create a unique ID for each Entity
{
	static int id{ 0 };
	return id++; //return id, then increments it
}

void Engine::loop()
{
	while (this->is_continuing)
	{
		for (std::unique_ptr<System>& i : listSystems)
		{
			i->update(); //Tadaaa
		}
	}
}

Engine::Engine()
{
	this->is_continuing = true;
}

ID Engine::addEntity() //creating a new entity by inserting it
{
	ID id = createID();
	this->listEntity.insert(std::make_pair(id, id));

	return id;
}

std::ostream& Engine::sortie(std::ostream& output) const 
{
	output << "Engine :" << std::endl;
	for (auto it  = listEntity.begin() ; it != listEntity.end() ; it++)
	{
		output << it->second;
	}
	output << std::endl;

	return output;
}

std::ostream& operator<<(std::ostream& output, const Engine& e)
{
	e.sortie(output);
	return output;
}

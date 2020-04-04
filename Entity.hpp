#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class Component;

class Entity
{
private:
	ID id;
	std::vector<std::unique_ptr<Component>> listComponent;
public:
	Entity(ID const& id_g);

	template<typename T, typename... Args>
	void addComponent(Args&&... args);

	//void removeComponent(); // je savais plus si c'était pour 1 ou tous les component alors j'en ai fait deux
	void removeComponent(const Component& component); // ici c'est juste pour 1 component

	//Component& getComponent();  //pour l'init
	//pareil ici faut trouver un moyen de sort les components par type si y'en a 1 max de chaque type
};



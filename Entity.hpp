#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class Component;

class Entity
{
private:
	ID id;
	std::map<const char*,std::unique_ptr<Component>> listComponent;
public:
	Entity(ID const& id_g);

	template<typename T, typename... Args>
	void addComponent(Args&&... args);

	template<typename T> void inline removeComponent();

	template<typename T>
	T* getComponent() const;  //pour l'init

	//pareil ici faut trouver un moyen de sort les components par type si y'en a 1 max de chaque type
	//c'est ce que une map fait, elle sort en fonction du 1er arg :kappa:
};



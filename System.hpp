#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class System
{
private:
	std::map<ID, std::map<IDTypeComponent, std::reference_wrapper<Component>>> listComponent;
public:
	virtual ~System();

	virtual void update() = 0; //the wole fonc

	template <typename CompT>
	void addComponent(CompT& comp);
};

template <typename CompT>
void System::addComponent(CompT& comp)
{
	auto a = this->listComponent.emplace(comp.getID(), std::map<IDTypeComponent, std::reference_wrapper<Component>>{});
	if (a.second)
		//this means compo.get_id() isn't aleady a key
	{
		this->listComponent.at(comp.getID()).emplace(Component::getIDType<CompT>(), comp);
	}
}

/* class DisplaySystem : public System, public SDLDisplay
{
public:
	DisplaySystem(const char* name, int width, int height, Uint32 flag)
	:SDLDisplay(name,width,height,flag)
	{}

	void update() override;
private:
}; */
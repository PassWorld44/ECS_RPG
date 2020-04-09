#pragma once

#include "Headers.hpp"
#include "ID.hpp"
#include "Component.hpp"

class System
{
private:
	std::map<ID, std::vector<std::reference_wrapper<Component>>> listComponent;
public:
	//System();
	//virtual ~System();

	virtual void update() = 0; //the wole fonc

	void addComponent(Component& comp);
};

class DisplaySystem : public System, public SDLDisplay
{
public:
	DisplaySystem(const char* name, int width, int height, Uint32 flag)
	:SDLDisplay(name,width,height,flag)
	{}

	void update() override;
private:
};
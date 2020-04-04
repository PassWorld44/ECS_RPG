#pragma once

#include "Headers.hpp"

typedef struct PositionComponent // c'est pas mal pour condenser les informations
{
	int x,
	int y
} Pos;

class Component
{
private:
	ID idEntity;
protected:
	Component(); // A réfléchir
	virtual void update(); // je pense
public:
	ID get_id(); // ok
};

class positionComponent : public Component 
{
public:
	Pos position; // position : x, y
};

class imageComponent : public Component // c'est pour afficher une image
{
public:
	std::string path;
};
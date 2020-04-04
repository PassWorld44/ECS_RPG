#pragma once

#include "Headers.hpp"
#include "ID.hpp"

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

typedef struct PositionComponent : Component// c'est pas mal pour condenser les informations
{
	int x;
	int y;
} Pos;

class positionComponent : public Component 
{
public:
	Pos position;
public:
	Pos getPosition() const
	{
		return position;
	}

	void update(); // je sais pas trop quoi ...
};

struct imageComponent : public Component // c'est pour afficher une image
{
public:
	std::string path;
};
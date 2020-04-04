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
private:
	Pos position;
public:
	Pos getPosition() const
	{
		return position;
	}

	void update(); // je sais pas trop quoi ...
};

class imageComponent : public Component // c'est pour afficher une image
{
private:
	std::string path;
public:
};
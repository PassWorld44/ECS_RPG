#pragma once

#include "Headers.hpp"
#include "ID.hpp"

class Component
{
private:
	ID idEntity;
protected:
	Component(ID const& id_g);
public:
	ID getID() const { return idEntity; }
};

// POSITION

typedef struct ComponentPosition// : public Component
{
	int x;
	int y;
} Pos;

//Faire une classe autour n'est juste qu'un wrapper inutile
class componentPosition : public Component
{
public:
	componentPosition(ID const& id_g, int const& x_g, int const& y_g);
	Pos position;
};

// END POSITION

// DIMENSION

typedef struct ComponentDimension// : public Component
{
	int width;
	int height;
} Dim;

//Faire une classe autour n'est juste qu'un wrapper inutile
class componentDimension : public Component
{
public:
	componentDimension(ID const& id_g, int const& width_g, int const& height_g);
	Dim dimension;
}; 

// END DIMENSION
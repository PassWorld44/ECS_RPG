#pragma once

#include "Headers.hpp"

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

typedef struct ComponentPosition
{
	int x,
	int y
} Pos;

class componentPosition : public Component
{
public:
	componentPosition(ID const& id_g, int const& x_g, int const& y_g);
	Pos position;
};

// END POSITION

// DIMENSION

typedef struct ComponentDimension
{
	int width,
	int height
} Dim;

class componentDimension : public Component
{
public:
	componentDimension(ID const& id_g, int const& width_g, int const& height_g);
	Dim dimension;
};

// END DIMENSION
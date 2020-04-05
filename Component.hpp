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

//Faire une classe autour n'est juste qu'un wrapper inutile
class componentPosition : public Component
{
public:
	componentPosition(ID const& id_g, int const& x_g, int const& y_g);
	double x;
	double y;
};

// END POSITION

// DIMENSION

//Faire une classe autour n'est juste qu'un wrapper inutile
class componentDimension : public Component
{
public:
	componentDimension(ID const& id_g, int const& width_g, int const& height_g);
	double width;
	double height;
}; 

// END DIMENSION
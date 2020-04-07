#include "Component.hpp"

// CONSTRUCTORS OF COMPONENT

Component::Component(ID const& id_g)
:idEntity(id_g)
{
	std::cout << "Creation d'un Component : ";
}

std::ostream& Component::sortie(std::ostream& output) const
{
	output << idEntity;
	return output;
}

// CONSTRUCTOR OF POSITION

componentPosition::componentPosition(ID const& id_g, int const& x_g, int const& y_g)
:Component(id_g),x(x_g),y(y_g)
{
	std::cout << "Position -> {Entity : " << id_g << "}" << std::endl;
}

std::ostream& componentPosition::sortie(std::ostream& output) const 
{
	Component::sortie(output) << " x: " << x << " y: " << y;
	return output;
}

// CONSTRUCTOR OF DIMENSION

componentDimension::componentDimension(ID const& id_g, int const& width_g, int const& height_g)
:Component(id_g),width(width_g),height(height_g)
{
	std::cout << "Dimension -> {Entity : " << id_g << "}" << std::endl;
}

std::ostream& componentDimension::sortie(std::ostream& output) const 
{
	Component::sortie(output) << " width: " << width << " height: " << height;
	return output;
}

std::ostream& operator<<(std::ostream& output, const Component& comp)
{
	comp.sortie(output);
	return output;
}

#include "Component.hpp"

// CONSTRUCTORS OF COMPONENT

Component::Component(ID const& id_g)
:idEntity(id_g)
{
	std::cout << "Creation d'un Component : " << std::endl;
}

// CONSTRUCTOR OF POSITION

componentPosition::componentPosition(ID const& id_g, int const& x_g, int const& y_g)
:Component(id_g),position{x_g,y_g}
{
	std::cout << "Position -> {Entity : " << id_g << "}" << std::endl;
}

// CONSTRUCTOR OF DIMENSION

componentDimension::componentDimension(ID const& id_g, int const& width_g, int const& height_g)
:Component(id_g),dimension{width_g,height_g}
{
	std::cout << "Dimension -> {Entity : " << id_g << "}" << std::endl;
}
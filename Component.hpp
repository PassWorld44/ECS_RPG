#pragma once

#include "Headers.hpp"
#include "ID.hpp"

class Component
{
private:
	ID idEntity;

	static inline IDTypeComponent m_maxId = 0;
protected:
	Component(ID const& id_g);
public:
	ID getID() const { return idEntity; }

	virtual std::ostream& sortie(std::ostream& output) const;

	template <typename Comp> static IDTypeComponent getIDType();
};

std::ostream& operator<<(std::ostream& output, const Component& comp);

// POSITION

class componentPosition : public Component
{
public:
	componentPosition(ID const& id_g, int const& x_g, int const& y_g);
	double x;
	double y;

	virtual std::ostream& sortie(std::ostream& output) const override;
};

// END POSITION

// DIMENSION

class componentDimension : public Component
{
public:
	componentDimension(ID const& id_g, int const& width_g, int const& height_g);
	double width;
	double height;

	virtual std::ostream& sortie(std::ostream& output) const override;
}; 

// END DIMENSION

// INPUT COMPONENT

class componentInput : public Component
{
public:

};

template<typename Comp>
inline IDTypeComponent Component::getIDType()
{
	if (!std::is_base_of_v<Component, Comp>)
	{
		throw std::invalid_argument("arg type must be derived from Component");
	}
	if (std::is_same_v<Component, Comp>)
	{
		throw std::invalid_argument("arg type must be a child class from component");
	}

	static const IDTypeComponent id = m_maxId++;
	return id;
}

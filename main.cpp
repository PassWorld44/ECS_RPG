#include "Headers.hpp"
#include "Engine.hpp"

int main()
{
	std::cout << "Hello world !" << std::endl;

	Engine e;

	ID ent1 = e.addEntity();

	e.addComponent<componentPosition>(ent1, 0, 0);

	return 0;
}
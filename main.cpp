#include "Headers.hpp"
#include "Engine.hpp"

int main()
{
	try
	{
		Engine e;
		std::vector<ID> RectTestListID;

		RectTestListID.push_back(e.addEntity());
		e.addComponent<componentPosition>(RectTestListID[0], 0, 0);
		e.addComponent<componentDimension>(RectTestListID[0], 100, 100);

		RectTestListID.push_back(e.addEntity());
		e.addComponent<componentPosition>(RectTestListID[1], 100, 100);
		e.addComponent<componentDimension>(RectTestListID[1], 100, 100);

		std::cout << e << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
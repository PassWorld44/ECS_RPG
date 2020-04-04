#include "Systems.hpp"

inline void Systems::update()
{
	for (std::unique_ptr<System>& s : listSystems)
	{
		s->update();
	}
}


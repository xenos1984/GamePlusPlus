#include <gamepp/base/State.h>

namespace GamePP
{
	namespace Base
	{
		std::ostream& operator<<(std::ostream& os, const State& state)
		{
			state.Serialize(os);
			return os;
		}
	}
}

#ifndef GAMEPP_BASE_STATE_H
#define GAMEPP_BASE_STATE_H

#include <ostream>

namespace GamePP
{
	namespace Base
	{
		class State
		{
		public:
			virtual void Serialize(std::ostream& os) const = 0;

			virtual ~State(void) {};
		};

		std::ostream& operator<<(std::ostream& os, const State& state);
	}
}

#endif

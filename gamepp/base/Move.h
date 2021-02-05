#ifndef GAMEPP_BASE_MOVE_H
#define GAMEPP_BASE_MOVE_H

#include <ostream>

namespace GamePP
{
	namespace Base
	{
		class Move
		{
		public:
			virtual void Serialize(std::ostream& os) const = 0;

			virtual ~Move(void) {};
		};

		std::ostream& operator<<(std::ostream& os, const Move& move);
	}
}

#endif

#include <gamepp/base/Move.h>

namespace GamePP
{
	namespace Base
	{
		std::ostream& operator<<(std::ostream& os, const Move& move)
		{
			move.Serialize(os);
			return os;
		}
	}
}

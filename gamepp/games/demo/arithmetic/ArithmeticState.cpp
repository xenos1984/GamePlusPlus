#include <gamepp/games/demo/arithmetic/ArithmeticState.h>

namespace GamePP
{
	namespace Games
	{
		void ArithmeticState::Serialize(std::ostream& os) const
		{
			os << "[";
			for(auto r : nums)
				os << " " << r;
			os << " ]";
		}
	}
}

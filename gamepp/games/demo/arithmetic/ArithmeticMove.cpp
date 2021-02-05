#include <gamepp/games/demo/arithmetic/ArithmeticMove.h>

namespace GamePP
{
	namespace Games
	{
		void ArithmeticMove::Serialize(std::ostream& os) const
		{
			os << "( " << op << " " << x << " " << y << " )";
		}
	}
}


#include <sstream>
#include <gamepp/games/demo/arithmetic/ArithmeticGame.h>

namespace GamePP
{
	namespace Games
	{
		std::string make_name(const std::multiset<Rational>& i, Rational f)
		{
			std::ostringstream os;

			os << "demo/arithmetic [ ";
			for(auto r : i)
				os << r << " ";
			os << "] -> " << f;

			return os.str();
		}

		ArithmeticGame::ArithmeticGame(const std::multiset<Rational>& i, Rational f) : Game(make_name(i, f)), ini(i), fin(f)
		{
		}
	}
}

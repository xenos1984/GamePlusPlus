#include <gamepp/games/demo/arithmetic/ArithmeticGame.h>

namespace GamePP
{
	namespace Games
	{
		ArithmeticGame::ArithmeticGame(const std::multiset<Rational>& i, Rational f) : Game("demo/arithmetic"), ini(i), fin(f)
		{
		}
	}
}

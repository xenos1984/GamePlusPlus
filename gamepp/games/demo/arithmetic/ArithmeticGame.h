#ifndef GAMEPP_GAMES_DEMO_ARITHMETIC_ARITHMETICGAME_H
#define GAMEPP_GAMES_DEMO_ARITHMETIC_ARITHMETICGAME_H

#include <set>
#include <gamepp/base/Game.h>
#include "Rational.h"

namespace GamePP
{
	namespace Games
	{
		class ArithmeticGame : public Base::Game
		{
		private:
			std::multiset<Rational> ini;
			Rational fin;

		public:
			ArithmeticGame(const std::multiset<Rational>& i, Rational f);

			unsigned int numRoles(void) { return 1; }
		};
	}
}

#endif

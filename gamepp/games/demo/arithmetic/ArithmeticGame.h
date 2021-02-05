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

			std::unique_ptr<Base::State> getInitialState(void);
			bool isLegalMove(const Base::State& state, const Base::Move& move);
			std::unique_ptr<Base::State> getNextState(const Base::State& state, const Base::Move& move);
			std::vector<std::unique_ptr<Base::Move>> getAllowedMoves(const Base::State& state);
		};
	}
}

#endif

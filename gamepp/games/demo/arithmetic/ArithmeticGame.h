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

			unsigned int numRoles(void) const { return 1; }

			std::unique_ptr<Base::State> getInitialState(void) const;
			bool isLegalMove(const Base::State& state, const Base::Move& move) const;
			std::unique_ptr<Base::State> getNextState(const Base::State& state, const Base::Move& move) const;
			std::vector<std::unique_ptr<Base::Move>> getLegalMoves(const Base::State& state) const;
			bool isTerminal(const Base::State& state) const;
			double getGoal(const Base::State& state) const;
		};
	}
}

#endif

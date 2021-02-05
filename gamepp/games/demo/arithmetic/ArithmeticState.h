#ifndef GAMEPP_GAMES_DEMO_ARITHMETIC_ARITHMETICSTATE_H
#define GAMEPP_GAMES_DEMO_ARITHMETIC_ARITHMETICSTATE_H

#include <set>
#include <ostream>
#include <gamepp/base/State.h>
#include <gamepp/games/demo/arithmetic/Rational.h>

namespace GamePP
{
	namespace Games
	{
		class ArithmeticState : public Base::State
		{
		private:
			std::multiset<Rational> nums;

		public:
			ArithmeticState(const std::multiset<Rational>& s) : nums(s) {};

			void Serialize(std::ostream& os) const;

			friend class ArithmeticGame;
		};
	}
}

#endif

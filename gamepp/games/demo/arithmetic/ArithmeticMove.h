#ifndef GAMEPP_GAMES_DEMO_ARITHMETIC_ARITHMETICMOVE_H
#define GAMEPP_GAMES_DEMO_ARITHMETIC_ARITHMETICMOVE_H

#include <ostream>
#include <gamepp/base/Move.h>
#include <gamepp/games/demo/arithmetic/Rational.h>

namespace GamePP
{
	namespace Games
	{
		class ArithmeticMove : public Base::Move
		{
		private:
			char op;
			Rational x, y;

		public:
			ArithmeticMove(char op, Rational x, Rational y) : op(op), x(x), y(y) {};

			void Serialize(std::ostream& os) const;

			friend class ArithmeticGame;
		};
	}
}

#endif

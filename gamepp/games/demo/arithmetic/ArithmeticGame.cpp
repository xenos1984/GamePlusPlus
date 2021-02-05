#include <sstream>
#include <gamepp/games/demo/arithmetic/ArithmeticGame.h>
#include <gamepp/games/demo/arithmetic/ArithmeticState.h>
#include <gamepp/games/demo/arithmetic/ArithmeticMove.h>

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

		std::unique_ptr<Base::State> ArithmeticGame::getInitialState(void)
		{
			return std::make_unique<ArithmeticState>(ini);
		}

		bool ArithmeticGame::isLegalMove(const Base::State& state, const Base::Move& move)
		{
			try
			{
				auto s = dynamic_cast<const ArithmeticState&>(state);
				auto m = dynamic_cast<const ArithmeticMove&>(move);

				if(m.y == 0 && m.op == '/')
					return false;

				if(!s.nums.contains(m.x))
					return false;

				if(!s.nums.contains(m.y))
					return false;

				return m.op == '+' || m.op == '-' || m.op == '*' || m.op == '/';
			}
			catch(const std::bad_cast&)
			{
				return false;
			}
		}

		std::unique_ptr<Base::State> ArithmeticGame::getNextState(const Base::State& state, const Base::Move& move)
		{
			if(!isLegalMove(state, move))
				return nullptr;

			auto s = dynamic_cast<const ArithmeticState&>(state);
			auto m = dynamic_cast<const ArithmeticMove&>(move);
			auto n = s.nums;

			n.erase(n.find(m.x));
			n.erase(n.find(m.y));

			switch(m.op)
			{
			case '+':
				n.insert(m.x + m.y);
				break;
			case '-':
				n.insert(m.x - m.y);
				break;
			case '*':
				n.insert(m.x * m.y);
				break;
			case '/':
				n.insert(m.x / m.y);
				break;
			}

			return std::make_unique<ArithmeticState>(n);
		}
	}
}

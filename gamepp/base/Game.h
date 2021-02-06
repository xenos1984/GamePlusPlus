#ifndef GAMEPP_BASE_GAME_H
#define GAMEPP_BASE_GAME_H

#include <memory>
#include <string>
#include <map>
#include <vector>
#include <mutex>
#include <gamepp/base/Move.h>
#include <gamepp/base/State.h>

namespace GamePP
{
	namespace Base
	{
		class Game
		{
		private:
			std::string name;

			static std::map<std::string, std::weak_ptr<Game>> games;
			static std::mutex games_mutex;
			static void remove(const std::string& type);

		public:
			Game(const std::string& name) : name(name) {};

			const std::string& getName(void) const { return name; }

			// Primary game properties
			virtual unsigned int numRoles(void) const = 0;
			virtual bool isSimultaneous(void) const = 0;
			virtual bool isDeterministic(void) const = 0;
			virtual bool isPerfectInf(void) const = 0;

			// Secondary (derived) game properties
			bool isAlternating(void) const { return !isSimultaneous(); }
			bool isRandom(void) const { return !isDeterministic(); }
			bool isHiddenInf(void) const { return !isPerfectInf(); }
			bool isSinglePlayer(void) const { return numRoles() == 1; }
			bool isMultiPlayer(void) const { return numRoles() > 1; }
			bool isPuzzle(void) const { return isPerfectInf() && isDeterministic() && isSinglePlayer(); }

			virtual std::unique_ptr<State> getInitialState(void) const = 0;
			virtual bool isLegalMove(const State& state, const Move& move) const = 0;
			virtual std::unique_ptr<State> getNextState(const State& state, const Move& move) const = 0;
			virtual std::vector<std::unique_ptr<Move>> getLegalMoves(const State& state) const = 0;
			virtual bool isTerminal(const State& state) const = 0;
			virtual double getGoal(const State& state) const = 0;

			static std::shared_ptr<Game> create(const std::string& type);

			virtual ~Game(void);
		};
	}
}

#endif

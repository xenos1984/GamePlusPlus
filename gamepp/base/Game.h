#ifndef GAMEPP_BASE_GAME_H
#define GAMEPP_BASE_GAME_H

#include <memory>
#include <string>
#include <map>
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

			bool isPuzzle(void);
			virtual unsigned int numRoles(void) = 0;

			const std::string& getName(void) { return name; }

			virtual std::unique_ptr<State> getInitialState(void) = 0;
			virtual bool isLegalMove(const State& state, const Move& move) = 0;
			virtual std::unique_ptr<State> getNextState(const State& state, const Move& move) = 0;

			static std::shared_ptr<Game> create(const std::string& type);

			virtual ~Game(void);
		};
	}
}

#endif

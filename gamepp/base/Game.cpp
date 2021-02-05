#include <gamepp/base/Game.h>
#include <gamepp/games/demo/arithmetic/ArithmeticGame.h>

namespace GamePP
{
	namespace Base
	{
		std::shared_ptr<Game> Game::create(const std::string& type)
		{
			std::lock_guard<std::mutex> lock(games_mutex);

			auto it = games.find(type);
			if(it != games.end())
			{
				if(auto sp = it->second.lock())
					return sp;
			}

			auto sp = std::make_shared<Games::ArithmeticGame>(std::multiset<Rational>{3, 3, 8, 3}, 24);
			games.insert({type, sp});
			return sp;
		}

		Game::~Game(void)
		{
			std::lock_guard<std::mutex> lock(games_mutex);

			auto it = games.find(name);
			if(it != games.end())
				games.erase(it);
		}

		bool Game::isPuzzle(void)
		{
			return numRoles() == 1;
		}

		std::map<std::string, std::weak_ptr<Game>> Game::games;
		std::mutex Game::games_mutex;
	}
}

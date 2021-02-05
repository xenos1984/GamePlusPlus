#include <gamepp/base/Game.h>

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

			auto sp = std::make_shared<Game>(type);
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

		std::map<std::string, std::weak_ptr<Game>> Game::games;
		std::mutex Game::games_mutex;
	}
}

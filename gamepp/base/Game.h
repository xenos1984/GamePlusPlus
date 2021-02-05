#ifndef GAMEPP_BASE_GAME_H
#define GAMEPP_BASE_GAME_H

#include <memory>
#include <string>
#include <map>
#include <mutex>

namespace GamePP
{
	namespace Base
	{
		class Game
		{
		private:
			static std::map<std::string, std::weak_ptr<Game>> games;
			static std::mutex games_mutex;

		protected:
			static void remove(const std::string& type);

		public:
			static std::shared_ptr<Game> create(const std::string& type);
		};
	}
}

#endif

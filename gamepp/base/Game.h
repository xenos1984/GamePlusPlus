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
			std::string name;

			static std::map<std::string, std::weak_ptr<Game>> games;
			static std::mutex games_mutex;
			static void remove(const std::string& type);

		public:
			Game(const std::string& name) : name(name) {};

			bool isPuzzle(void);
			virtual unsigned int numRoles(void) = 0;

			const std::string& getName(void) { return name; }

			static std::shared_ptr<Game> create(const std::string& type);

			virtual ~Game(void);
		};
	}
}

#endif

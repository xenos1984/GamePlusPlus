#include <iostream>
#include <gamepp/base/Game.h>

bool solve(const GamePP::Base::Game& game, const GamePP::Base::State& state)
{
	auto moves = game.getLegalMoves(state);

	for(auto it = moves.begin(); it != moves.end(); it++)
	{
		auto next = game.getNextState(state, **it);
		if(game.isTerminal(*next))
			return game.getGoal(*next) == 1.0;

		if(solve(game, *next))
		{
			std::cout << *next << std::endl;
			std::cout << **it << std::endl;
			return true;
		}
	}

	return false;
}

int main(int argc, char** argv)
{
	if(argc <= 1)
		return 1;

	auto game = GamePP::Base::Game::create(argv[1]);
	auto ini = game->getInitialState();

	std::cout << "Solving " << game->getName() << " :" << std::endl;

	if(solve(*game, *ini))
		std::cout << *ini << std::endl << "Solution found!" << std::endl;
	else
		std::cout << "No solution found!" << std::endl;

	return 0;
}

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
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	if(argc <= 1)
		return 1;

	auto g = GamePP::Base::Game::create(argv[1]);

	std::cout << g->getName() << " : " << solve(*g, *(g->getInitialState())) << std::endl;

	return 0;
}

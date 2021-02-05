#include <iostream>
#include <gamepp/base/Game.h>

int main(int argc, char** argv)
{
	if(argc <= 1)
		return 1;

	auto g = GamePP::Base::Game::create(argv[1]);

	std::cout << "Success." << std::endl;

	return 0;
}

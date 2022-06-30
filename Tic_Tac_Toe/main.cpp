// Tic_Tac_Toe

#include <iostream>
#include "Tic_Tac_Toe.hpp"


int main()
{
	std::cout << "\033[0;33mWELCOME TO TIC TAC TOE GAME!\033[0m";
	std::cout << std::endl;
	Player* p1 = new Player(CheckerState::X);
	Player* p2 = new Player(CheckerState::O);
	Game g(p1, p2);
	g.start();

	delete p1;
	delete p2;

	return 0;
}

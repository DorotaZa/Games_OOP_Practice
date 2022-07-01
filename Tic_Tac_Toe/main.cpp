// Tic_Tac_Toe

#include <iostream>
#include "Tic_Tac_Toe.hpp"


int main()
{
	std::cout << "\033[0;33mWELCOME TO TIC TAC TOE GAME!\033[0m";
	std::cout << std::endl;
	//

	char choice = 'N';
	std::cout << "Are you AI player (Y/N/A)?" << std::endl;
	std::cin >> choice;
	Player* p1 = new HumanPlayer(CheckerState::X);
	Player* p2 = nullptr;

	if (choice == 'N')
	{
		p2 = new HumanPlayer(CheckerState::O);
	}
	else if (choice == 'Y')
	{
		p2 = new AIPlayer(CheckerState::O);
	}
	else
	{
		; //tutaj dwa AI
	}

	
	Game g(p1, p2);
	g.start();

	delete p1;
	delete p2;

	return 0;
}

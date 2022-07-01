#include "Tic_Tac_Toe.hpp"
#include <iostream>
#include <random>

void Game::swapPlayer()
{
	if (currentPlayer == player1)
	{
		currentPlayer = player2;
	}
	else if (currentPlayer == player2)
	{
		currentPlayer = player1;
	}
}

Game::Game(Player* p1, Player* p2)
{
	this->player1 = p1;
	this->player2 = p2;
	this->currentPlayer = player1;
	reset();
	
}

void Game::start()
{
	do
	{
		currentPlayer->makeTurn(&board);
		std::cout << board;
		swapPlayer();

	} while (!board.isOver());

	if (board.xWon())
	{
		std::cout << "Congratulations X! You won!" << std::endl;
	}
	else
	{
		std::cout << "Congratulations O! You won!" << std::endl;
	}
	
}

void Game::reset()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board.set(CheckerState::Empty, i, j);
		}
	}
	
}


bool Board::checkDiagonal()
{
	bool result = false;
	for (int i = 0; i < 3; ++i)
	{
		if ((table[0][0] != CheckerState::Empty) &&
			(table[0][0] == table[1][1]) &&
			(table[1][1] == table[2][2]) ||
			(table[0][2] == table[1][1]) &&
			(table[1][1] == table[2][0]))
		{
			result = true;
		}
		return result;
	}

	return result;
}

bool Board::checkRows()
{
	bool result = false;
	for (int i = 0; i < 3; ++i)
	{
		if ((table[i][0] != CheckerState::Empty) &&
			(table[i][0] == table[i][1]) &&
			(table[i][1] == table[i][2]))
		
		{
			result = true;
		}

	}
	return result;
}


bool Board::checkColumns()
{
	bool result = false;
	for (int i = 0; i < 3; i++)
	{
		if ((table[0][i] != CheckerState::Empty) &&
			(table[0][i] == table[1][i]) &&
			(table[1][i] == table[2][i]))
			result = true;
	}
	return result;
}

Board::Board()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			table[i][j] = CheckerState::Empty;
		}
	}
}

CheckerState Board::check(int x, int y) const
{
	return table[x][y];
}

bool Board::set(CheckerState cs, int x, int y) //przypisanie danemu polu o wspolrzendych x i y znaku uzytkownika X lub Y
{
	table[x][y] = cs;
	return true;
}

bool Board::isOver()
{
	return checkRows() || checkColumns() || checkDiagonal();
}

bool Board::xWon()
{
	return true;
}


Player::Player(CheckerState _colour)
{
	this->colour = _colour;
}

bool Player::makeTurn(Board* board)
{
	
}

std::ostream& operator<<(std::ostream& s, const CheckerState& cs)
{ //jak rozumiec? 1st step - zamiana std::cout na s
	if (cs == CheckerState::Empty)
	{
		s << "_";
	}
	else if (cs == CheckerState::X)
	{
		s << "X";
	}
	else if (cs == CheckerState::O)
	{
		s << "O";
	}
	return s;
}

std::ostream& operator<<(std::ostream& s, const Board& board)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			s << board.check(i, j); //nie mamy bezposredniego dostepu do pola czyli tablicy w obiekcie board-musimy sie dostac do tablicy pole przez funkcje check
			s << " ";
		}
		s << std::endl;

		//MEGA WAZNY MOMENT! przez to ze argument ze wskaznika jest staly w deklaracji operatora, musimy zmienic funkcje check w hpp na const!!!
	}
	std::cout << std::endl;
	return s;
}

AIPlayer::AIPlayer()
{
}

bool AIPlayer::makeTurn(Board* board)
{
	return false;
}

void AIPlayer::random(Board* board)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, range); // define the range

	this->hiddenNumber = distr(gen);
}

HumanPlayer::HumanPlayer()
{
}

bool HumanPlayer::makeTurn(Board* board)
{
	int x = 0;
	int y = 0;
	std::cout << "Your turn " << colour << ". Enter x, y coordinates for your next move: " << std::endl;
	std::cin >> x;
	std::cin >> y;
	std::cout << std::endl;



	if ((x >= 0 && x < 3) && (y >= 0 && y < 3))
	{
		board->set(colour, x, y);
	}

	return true;
}

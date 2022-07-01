#pragma once
#include <ostream>

enum class CheckerState {Empty, X, O}; //3 stany; jak nie prypiszemy wartosci to tablica wypisze 1,2,3

class Board
{
	CheckerState table[3][3]; 
	bool checkDiagonal();
	bool checkRows();
	bool checkColumns();


public:
	Board();
	CheckerState check(int x, int y) const;
	bool set(CheckerState cs, int x, int y);
	bool isOver();
	bool xWon();
};

class Player
{
protected:
	CheckerState colour;
public:

	Player(CheckerState _colour);
	bool virtual makeTurn(Board* board) = 0;
	//CheckerState getColour(); //pomijamy jesli zmienimy pole color na protected 
};

class AIPlayer : public Player
{

public:
	AIPlayer(CheckerState _colour) : Player(_colour) {}
	bool virtual makeTurn(Board* board);
	void random(Board* board);
};

class HumanPlayer : public Player
{
public:
	HumanPlayer(CheckerState _colour): Player(_colour){}
	bool virtual makeTurn(Board* board);
};

class Game
{
	Player* currentPlayer; //wskaznik na danego gracza ktory ma ruch
	Player* player1;
	Player* player2; 
	Board board;
	void swapPlayer();
public:
	Game(Player* p1, Player* p2);
	void start(); //to jest przebieg gry
	void reset(); //czysci widok
 };

std::ostream& operator<<(std::ostream& s, const Board& board);

std::ostream& operator<<(std::ostream& s, const CheckerState& cs);

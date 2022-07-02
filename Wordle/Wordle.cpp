#include "Wordle.hpp"
#include <iostream>
#include <stdlib.h>
//#include <ostream>
//#define GREEN

bool Wordle::findIfExists(char c)
{
	for (int i = 0; i < 5; i++)
	{
		if (secret[i] == c)
		{
			return true;
		}
	}
	return false;
}

Wordle::Wordle(std::string secret)
{
	this->secret = secret;
}

std::string Wordle::test(std::string guess)
{
	if (attempt < 6)
	{
		guesses[attempt] = guess;

		//std::string answer(5, 'B'); // nowa zmienna answer o wartosci BBBBB; wersja A
		answers[attempt] = std::string(5, 'B'); // wersja B
		for (int i = 0; i < 5; i++) // sprawdzamy kazdy znak
		{
			if (secret[i] == guess[i]) // jesli znak w zgadywanym i sekrecie pokrywa sie w 100%
			{
				//answer[i] = 'G'; //podmien w odpowiedzi na 'G'; wersja A
				answers[attempt][i] = 'G'; // wersja B
				
			}
			else if (findIfExists(guess[i]))
			{
				answers[attempt][i] = 'O';
			}

		}
		//answers[attempt] = answer; // wstaw string z kolorem do tablicy odpowiedzi; wersja A
		attempt++; //przechodzi do nowego wiersza; attempt nr = wiersz nr
		return answers[attempt - 1];
	}
	
	return std::string(); // ktos probuje odgadnac haslo po 6 probie - nie powinnismys sie tutaj dostac, ale better safe than sorry; przezorny zawsze ubezpieczony
}
bool Wordle::isFinished()
{
	if (attempt == 0)
		return false;

	return (attempt == 6) || (answers[attempt - 1] == "GGGGG");
	//if (attempt == 6 || answers[attempt - 1] == "GGGGG")
	//	return true;
	//else 
	//	return false;
}

//void Wordle::draw()
//{
//	for (int i = 0; i < attempt; i++) //6 bo mamy 6 wierszy
//	{
//		std::cout << guesses[i] << "\t" << answers[i] << std::endl;
//	}
//}

void Wordle::draw1()
{

	for (int i = 0; i < attempt; i++) //6 bo mamy 6 wierszy
	{
		
		for (int j = 0; j < 5; ++j)
		{
			if (answers[i][j] == 'G')
			{
				//std::cout << "\033[0;32mG\033[0m";
				std::cout << "\033[0;32m" << guesses[i][j] << "\033[0m";
			}
			else if (answers[i][j] == 'O')
			{
				//std::cout << "\033[0;33mO\033[0m";
				std::cout << "\033[0;33m" << guesses[i][j] << "\033[0m";
			}
			else
			{
				//std::cout << "\033[0;37mB\033[0m";
				std::cout << "\033[0;37m" << guesses[i][j] << "\033[0m";
			}
		}
		std::cout << "\t";
		std::cout << answers[i];
		std::cout << std::endl;
	}
}

//void Wordle::draw2()
//{
//	//std::cout << "\033[0;32mOUTPUT\033[0m";
//	//system("cls");// czysci 'linijke wpisywania', zeby jej nie powtarzac przy wypisywaniu z petla z kolorami
//
//
//	for (int i = 0; i < attempt; i++) //6 bo mamy 6 wierszy
//	{
//		std::cout << guesses[i] << '\t';
//
//		for (int j = 0; j < 5; ++j)
//		{
//			if (answers[i][j] == 'G')
//			{
//				std::cout << "\033[0;32mG\033[0m";
//			}
//			else if (answers[i][j] == 'O')
//			{
//				std::cout << "\033[0;33mO\033[0m";
//			}
//			else
//			{
//				std::cout << "\033[0;37mB\033[0m";
//			}
//		}
//	}
//	std::cout << std::endl;
//
//}




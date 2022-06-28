#include "Hangman_v2.hpp"
#include <iostream>

Hangman::Hangman(std::string secret)
{
	this->secret = secret;
	this->guessWord = secret; //nadpisanie zeby taka sam ilosc liter byla
	for (int i = 0; i < secret.length(); ++i)
	{
		guessWord[i] = '_';
		//guessWord[i] = ' '; //to nie dziala bo jest przypisanie innej wartosci 


	}
	for (int i = 0; i < 26; ++i)
	{
		alphabet[i] = false;
	}
}

std::string Hangman::getGuess()
{
	return guessWord;
}

std::string Hangman::getAlphabet()
{
	std::string result;
	for (int i = 0; i < 26; i++)
	{
		//if (alphabet[i] == false) // tak raczej nie piszemy - to samo co nizej
		if (!alphabet[i])
		{
			result += 'a' + i;
			result += ' ';
		}
		else
		{
			result += '_';
			result += ' ';
		}
	}
	return result;
}


bool Hangman::guess(char c)
{
	//for (int i = 0; i < 26; i++)
	//{
	//	if ('a' + i == c)
	//	{
	//		alphabet[i] = true;
	//	}
	//}
	//linijka nizej robi to co petla wyzej
	alphabet[c - 'a'] = true; // int index = c - 'a'
	bool guessed = false; //zapamaietuje fakt ze weszlam do ifa
	std::string previous = guessWord; //zapamietanie slowa przed petla 
	for (int i = 0; i < secret.length(); i++)
	{
		if (secret[i] == c)
		{
			guessWord[i] = c;
			guessed = true;

		}
	}
	//bool result = (guessedWord == secret); // to samo co ponizej

	if (previous == guessWord)
	 {
	 attempt--;
	 }
	//alternatywna wersja linijki nizej 

	if (!guessed)
	{
		std::cout << "Oooooops! The word doesn't include " << c << ". Try again!" << std::endl;
		std::cout << "You've got " << attempt << " attempts left." << std::endl;
	}
	return guessWord == secret;

}


std::string Hangman::getSecret()
{
	return secret;
}

//int Hangman::attemptsLeft(int attempt)
//{
//	return 0;
//}

//void Hangman::print()
//{
//	if (attempt >=1)
//	{
//		std::cout << "   -------    " << std::endl;
//		std::cout << "   |     |    " << std::endl;
//		std::cout << "   |          " << std::endl;
//		std::cout << "   |          " << std::endl;
//		std::cout << "   |          " << std::endl;
//		std::cout << "   |          " << std::endl;
//		std::cout << "  _|_         " << std::endl;
//	}
//}

void Hangman::drawHangman()
{
	switch (attempt)
	{
	case 4:
		std::cout << "   -------    " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "  _|_         " << std::endl;
		break;

	case 3:
		std::cout << "   -------    " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |     O    " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "  _|_         " << std::endl;

	case 2:
		std::cout << "   -------    " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |     O    " << std::endl;
		std::cout << "   |    /|\\  " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "  _|_         " << std::endl;

	case 1:
		std::cout << "   -------    " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |     O    " << std::endl;
		std::cout << "   |    /|\\  " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |          " << std::endl;
		std::cout << "  _|_         " << std::endl;

		break;

	case 0:
		std::cout << "   -------    " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |     O    " << std::endl;
		std::cout << "   |    /|\\  " << std::endl;
		std::cout << "   |     |    " << std::endl;
		std::cout << "   |    / \\  " << std::endl;
		std::cout << "  _|_         " << std::endl;
	}

}


	/*std::cout << "   -------    " << std::endl;
	std::cout << "   |     |    " << std::endl;
	std::cout << "   |     O    " << std::endl;
	std::cout << "   |    /|\\  " << std::endl;
	std::cout << "   |     |    " << std::endl;
	std::cout << "   |    / \\  " << std::endl;
	std::cout << "  _|_         " << std::endl;
*/


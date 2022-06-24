#include "Hangman.hpp"

Hangman::Hangman(std::string secret)
{
	//this->attend = attend;
	this->secret = secret;
	this->guessWord = secret;//nadpisanie zeby taka sam ilosc liter byla
	for (int i = 0; i < secret.length(); ++i)
	{
		guessWord[i] = '_';
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
		}
		else
		{
			result += '_';
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
	for (int i = 0; i < secret.length(); i++)
	{
		if (secret[i] == c)
		{
			guessWord[i] = c;
		}
	}
	//bool result = (guessedWord == secret); // to samo co ponizej
	return guessWord == secret;
}


std::string Hangman::getSecret()
{
	return secret;
}

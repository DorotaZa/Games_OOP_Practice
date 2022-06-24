#pragma once
#include <string>

class Hangman
{
	std::string secret; //przekazane z konstruktora
	bool alphabet[26]; //warto zainicjowac w konstruktorze
	std::string guessWord; //na samym poczatku bedzie miala same __
	int attend; //ignorujemy poki co
public:
	Hangman(std::string secret);
	std::string getGuess();
	std::string getAlphabet();
	//returns true if all characters guessed
	bool guess(char c);
	std::string getSecret();

};


//zdefiniowac konstruktor: wprowadzic secreta; wypelnic tablice; guessed word -same kreski


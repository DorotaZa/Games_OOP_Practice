#pragma once
#include <string>
#include <fstream>
#include <ctime> //srand

class Hangman
{
	std::string secret; //przekazane z konstruktora
	bool alphabet[26]; //warto zainicjowac w konstruktorze
	std::string guessWord; //na samym poczatku bedzie mialo same __
	int attempt = 5; //ignorujemy poki co
	//RANDOM
	std::string wordList[99];
	

public:

	Hangman(std::string secret);
	std::string getGuess();
	std::string getAlphabet();
	bool guess(char c); //returns true if all characters guessed
	std::string getSecret(); 
	//int attemptsLeft(int attempt);
	void drawHangman();
	//RANDOM
	std::string getRandom();


};


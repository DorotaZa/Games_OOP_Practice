// Hangman_RandomWord

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

int main()
{

	int tries = 5;
	char guess;
	bool correctGuess = false;
	std::string word;
	srand(time(NULL));
	std::ifstream randomWord;
	randomWord.open("Words.txt");
	std::string wordList[99];

	for (int i = 0; i < 99; ++i)
	{
		randomWord >> wordList[i];
		//std::cout << wordList[i] << std::endl; //test line
	}

	int randomNum = rand() % 100;
	word = wordList[randomNum];
	std::cout << word << std::endl; //test line
	randomWord.close();


	std::string secret(word.length(), '*');
	//std::cout << secret << std::endl;

	while (tries >= 0)
	{
		correctGuess = false;
		std::cout << "The word you have to guess is: " << std::endl;
		std::cout << secret << std::endl;
		std::cout << "There are " << secret.length() << " letters in the word." << std::endl;
		std::cout << "You have " << tries << " guesses left." << std::endl;
		std::cout << "Guess a letter: " << std::endl; 
		std::cin >> guess;

		for (int i = 0; i < secret.length(); ++i)
		{
			if (word[i] == guess)
			{
				secret[i] = guess;
				std::cout << "Congratulations! " << guess << " is one of the letters." << std::endl;
				correctGuess = true;
			}
		}
		if (word == secret)
		{
			std::cout << "Congratulations! You've got the word correct: "<< secret << std::endl;
			break;
		}

		if (correctGuess == false)
		{
			tries--;
			std::cout << "Sorry... " << guess << " is not a part of the word." << std::endl;
		}

	}









}


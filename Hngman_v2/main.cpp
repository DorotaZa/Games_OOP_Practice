// Hngman_v2
#include <iostream>
#include "Hangman_v2.hpp"
#include <string>
#include <fstream>
#include <ctime> //srand

int main()

{
    std::cout << " WELCOME TO HANGMAN GAME! " << std::endl;
    //pozniej dojdzie kawalek generujacy secret
    Hangman game("hangman");
    bool finished;
    //int attempt = 5;

    do
    {
        std::string guess = game.getGuess(); //zwrocic _A___A_
        std::cout << guess << std::endl;;
        std::string alphabet = game.getAlphabet(); // zwraca _BCDE
        std::cout << alphabet << std::endl;

        char letter;
        std::cout << "Guess a letter: ";
        std::cin >> letter;


        finished = game.guess(letter); //zgadujemy- zmieniamy zarowno guess jak i alfabet
        //attempt--;
        game.drawHangman();

    } while (!finished/*&& attempt > 0*/);
    // !while (finished || attempt <= 0);! //prawo de Morgana
    std::cout << "Oooops! GAME OVER!!!" << std::endl;
    std::cout << "Secret keyword was: " << game.getSecret() <<std::endl;
}



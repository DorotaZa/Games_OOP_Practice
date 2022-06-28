// Hangman

#include <iostream>
#include "Hangman.hpp"
#include <string>

int main()

{
    //pozniej dojdzie kawalek generujacy secret
    Hangman game("hangman"); 
    bool finished;
    //int attempt = 10;
    do
    {
        std::string guess = game.getGuess(); //zwrocic _A___A_
        std::cout << guess << std::endl;;
        std::string alphabet = game.getAlphabet(); // zwraca _BCDE
        std::cout << alphabet << std::endl;


        std::cout << "Guess a letter: ";
        char letter;
        std::cin >> letter;

        finished = game.guess(letter); //zgadujemy- zmieniamy zarowno guess jak i alfabet
        //attempt--;

    } while (!finished /*&& attempt > 0*/);
      // !while (finished || attempt <= 0);! //prawo de Morgana

    std::cout << "Secret keyword was: " << game.getSecret();

}

// Hangman

#include <iostream>
#include "Hangman.hpp"
#include <string>

int main()

{
    //pozniej dojdzie kawalek generujacy secret
    Hangman game("hangman"); 
    bool finished;
    int attend = 10;
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
        attend--;

    } while (!finished && attend > 0);
    std::cout << "Secret keyword was: " << game.getSecret();

}

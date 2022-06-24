// OOP_practice

#include <iostream>
#include "blackBox.hpp"

int main()
{
    BlackBoxGuess  box(50);
    do
    {
        int chosenNumber;
        std::cout << "Guess the number: " << std::endl;
        std::cin >> chosenNumber;
        int result = box.is(chosenNumber);
        if (result > 0)
        {
            std::cout << "Secret number is smaller than yours." << std::endl;
        }
        else if (result == 0)
        {
            std::cout << "CONGRATULATIONS! You guessed my number!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Secret number is greater than yours." << std::endl;
        }
    } while (true);
    return 0;
}

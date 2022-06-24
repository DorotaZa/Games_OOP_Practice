#include "blackBox.hpp"
#include <iostream>
#include <random>

BlackBoxGuess::BlackBoxGuess(int range)
{
    hiddenNumber = 42;
}

int BlackBoxGuess::is(int guess)
{
    if (hiddenNumber < guess)
    {
        return -1;
    }
    else if (hiddenNumber == guess)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

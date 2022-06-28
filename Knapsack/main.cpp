// Knapsack

#include <iostream>
#include "Knapsack.hpp"

int main()
{
    Robber robber(30);
    Shop shop;
    robber.robWhatever(shop);
    std::cout << robber.getValue() <<std::endl;

}

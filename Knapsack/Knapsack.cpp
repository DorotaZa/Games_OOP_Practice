#include "Knapsack.hpp"
#include <string>
#include <random>

Backpack::Backpack(int capacity) : backpack(capacity) {}

int Backpack::calculateCurrentValue()
{
	return 0;
}
int Backpack::put(Item item)
{
	return 0;
}
;


Shop::Shop()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 15); // define the range

	for (int )
	item->weigth= distr(gen);
	item->value = distr(gen);
}

Item Shop::steal(int index)
{
	Item result;
	result.value = items[index].value;
	result.weigth = items[index].weigth;
	items.[index].value = 0;
	items[index].weigth = 0;
	return Item();
}

Item Shop::peek(int index)
{
	return Item();
}

Robber::Robber(int capacity)
{
}

void Robber::robWhatever(Shop* shop)
{
}

int Robber::getValue()
{
	return 0;
}

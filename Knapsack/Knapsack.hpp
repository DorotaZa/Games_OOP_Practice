#pragma once
#include "Knapsack.hpp"

struct Item
{
	int value;
	int weigth; //kg
};

class Shop
{
	Item item[100];
public:
	Shop(); // konstruktor powinienien wypelniac tablice przedmiotow losowymi przedmiotami
	Item steal(int index); //kradnij - odejmij od tablicy
	Item peek(int index); //zajrzyj/sprawdz - nie zabieraj ze sklepu

};

class Backpack
{
	const int capacity; //15kg
	Item stolen[100];
	//int value;
public:
	Backpack(int _capacity); //zainicjalizowac naszego consta
	int calculateCurrentValue(); //zwraca wartosc plecaka
	int put(Item item); //zwraca ile miejsca zostalo w plecaku
};

class Robber
{
	Backpack& backpack; //plecak powinien bycs skonstruowany w konstruktprze zlodzieja
	//Shop* shop; //sklep powinien byc przekazany do zlodzieja
public:
	Robber(int capacity); // powinien zainicjalizowac plecak odpowiednia pojemnoscia
	//sklep powinien byc przekazany do zlodzieja
	void robWhatever(Shop* shop); //logika 1sza - pierwsze lepsze
	//void robRandom(); //losowo
	//void robGreedy(); //logika 2ga
	int getValue();

};




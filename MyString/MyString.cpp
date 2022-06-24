#include "MyString.hpp"
#include <iostream>
#include <cstdint>
#include <cstring>


MyString::MyString()
{
	this->arr = new char[1]; //1-elementowa tablica
	this->arr[0] = '\0';
}

MyString::MyString(char* input)
{
	int length = std::strlen(input); //metoda z jezyka C
	//this->arr = input; // unikamy - uzalezniamy sie od tablicy zarzadzanej przez obiekt zewnetrzny
	//skopiowac input -> arr, na koncu dopisac 0
	this->arr = new char[length + 1]; //tworzymy tablice o dlugosci ktora wyliczy program w linijce 13
	//skopiowac input -> arr, na koncu dopisac 0
	//memcpy, strcpy - z ANSI C; albo petla for

	for (int i = 0; i < length; i++)
		arr[i] = input[i];
	arr[length] = '\0';

}

void MyString::print()
{
	std::cout << arr << std::endl;
}

MyString MyString::append(char* input)
{
	char* result = nullptr;
	// duzo opperacji zeby to wyliczyc.....
#include "MyString.hpp"

	MyString::MyString()
	{
		this->arr = new char[1]; //1-elementowa tablica
		this->arr[0] = '\0';
	}

	MyString::MyString(char* input)
	{
		int length = std::strlen(input);
		//this->arr = input; // unikamy - uzalezniamy sie od tablicy zarzadzanej przez obiekt zewnetrzny
		this->arr = new char[length + 1];

		//skopiowac input -> arr, na koncu dopisac 0
		//memcpy, strcpy - z ANSI C; albo petla for
		for (int i = 0; i < length; i++)
			arr[i] = input[i];
		arr[length] = '\0';
	}

	void MyString::print()
	{
		std::cout << arr << std::endl;
	}

	MyString MyString::append(char* input)
	{
		int length1 = std::strlen(arr); //zlicza dugo pierwszej tablicy - 3
		int length2 = std::strlen(input); // zlicza dugo drugiej tablicy - 3
		int length3 = length1 + length2;// dodaje te dugoci - 6
		char* newArr = new char[length3 + 1]; // tworzymy nowego stringa - dodajemy do dugoci +1 dla zera - 7
		for (int i = 0; i < length1; i++) //wypeniamy znakami z pierwszej tablicy
		{
			newArr[i] = arr[i]; // [a,l,a]
		}
		for (int i = 0; i < length2; i++) //wypeniamy znakami z drugiej tablicy
		{
			newArr[i + length1] = input[i];// [a,l,a, k, o, t]
		}
		newArr[length3] = '\0'; //ustawia ostatnie miejsce w tablicy na zero
		return MyString(newArr);
	}

	MyString MyString::append(MyString input)
	{
		MyString result = this->append(input.arr);
		return result;
	}

	MyString MyString::firstWord()
	{
		return MyString();
	}

	//void MyString::foo4() {}
	//void MyString::foo3() {foo4();}
	//void MyString::foo2() {foo3();}
	//void MyString::foo1() {this->foo2();}

	//MyString first;
	//first.foo1();
	//MyString second;
	//second.foo2();

	
	//	return MyString(result);
//}
//
//MyString MyString::append(MyString input)
//{
//	//wywolanie metody append z charem tutaj ma sie zadziac
//	//wywoalnie metody na obiekcie na ktorym jesesmy 
//	//arr - mam dostep 
//	MyString result;
//	result = /*this->*/append(input.arr); //dolaczenie stworzonego stringa do obiektu arr ktory juz istnieje 
//
//	return result;
//}
//
//MyString MyString::firstWord(MyString input)
//{
//
//	return MyString();
//}

#pragma once
#include <string>

enum class FormOfEmployment{B2B, Mandate, ContractOfEmployment};


//abstrakcyjna klasa - nie mozna tworzyc obiektow tej klasy
class Employee 
{
protected:
	FormOfEmployment contract;
	std::string firstName;
	std::string secondName;
	double salary;

public:
	Employee(FormOfEmployment);
	double getEmployeeNetSalary();
	virtual bool isTeachingStaff();// = 0; zmiana z czystej virtualnej, bo nie moglibysmy stworzyc obiektu tej klaasy a potrzebujemy 
};

class Professor : public Employee
{
public:
	virtual bool isTeachingStaff();
};

class Lecturer : public Employee
{
public:
	virtual bool isTeachingStaff();
};

class Assistant : public Employee
{
public:
	virtual bool isTeachingStaff();
};

class Keeper : public Employee
{
public:
	virtual bool isTeachingStaff();
};

class Guard : public Employee
{
public:
	virtual bool isTeachingStaff();
};

class University
{
	Employee employees[10]; // - nie mozemy jesli Employee jest abstrakcyjna klasa
	//Employee* employees = new Employee[100]; // rule of 3 bo destruktor konieczny, ale
	int count = 0; //do zliczania employees
public:
	double calculateEmployerCost();
	void printTeachingStaff();
	void printAllStaffNetIncomes();

};
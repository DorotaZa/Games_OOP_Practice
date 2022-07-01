#include "University_Management.hpp"

bool Professor::isTeachingStaff()
{
	return true;
}

bool Lecturer::isTeachingStaff()
{
	return true;
}

bool Assistant::isTeachingStaff()
{
	return true;
}

bool Keeper::isTeachingStaff()
{
	return false;
}

bool Guard::isTeachingStaff()
{
	return false;
}

Employee::Employee(FormOfEmployment)
{
}

double Employee::getEmployeeNetSalary()
{
	return 0.0;
}

bool Employee::isTeachingStaff()
{
	return false;
}

double University::calculateEmployerCost()
{
	return 0.0;
}

void University::printTeachingStaff()
{
	if (isTeachingStaff())
	{
		std::count << std::endl;
	}
}

void University::printAllStaffNetIncomes()
{
}

#include "employee.h"

Employee::Employee(const Employee & other) : Person(other)
{
	*this = other;
}

const Employee & Employee::operator=(const Employee & other)
{
	if (this != &other)
	{
		Employee::salary = other.salary;
		Person::operator=(other);
	}
	return *this;
}

Employee::Employee(const char * name, float salary) : Person(name)
{
	setSalary(salary);
}

void Employee::toOs(std::ostream & os) const
{
	os << *this;
}

void Employee::setSalary(float salary) throw(const char *)
{
	if ((salary >= MIN_SALARY) && (salary <= MAX_SALARY))
		Employee::salary = salary;
	else
		throw "You are fired!!!";
}

float Employee::getSalary() const
{
 	return salary;
}

std::ostream & operator<<(std::ostream & os, const Employee & e)
{
	os << "Salary: " << e.getSalary() << "\n";
	e.toOs(os);
	return os;
}

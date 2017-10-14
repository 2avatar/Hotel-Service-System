#pragma once
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include "person.h"
#include <iostream>


class Employee : public Person {
protected:
	float salary;
	Employee(const Employee& other);
	const Employee& operator= (const Employee& other);

public:

	static const int MIN_SALARY = 1000;
	static const int MAX_SALARY = 50000;

	Employee(const char* name, float salary);
	virtual void toOs(std::ostream& os) const;
	virtual ~Employee() { } // for polymorphism
	//getters and setters
	void setSalary(float salary) throw (const char*);
	friend std::ostream& operator<< (std::ostream& os, const Person& e);

	float getSalary() const;
};
#endif //__EMPLOYEE_H
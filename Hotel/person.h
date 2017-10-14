#pragma once
#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#pragma warning( disable : 4290 ) // disable the exception throwing warning 
class Person {
protected:
	int id;   //auto generated starting with START_ID
	char* name;

	Person(const Person& other);
	const Person& operator= (const Person& other);

public:
	Person(const char* name) throw (const char*);
	virtual ~Person();
	friend std::ostream& operator<< (std::ostream& os, const Person& e);
	virtual void toOs(std::ostream& os) const;
	int static const START_ID = 100;
	//setters & getters
	void setName(const char* name) throw (const char*);

	int getId() const;
	const char* getName()	const;
};
#endif  // __PERSON_H
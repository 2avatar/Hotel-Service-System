#pragma once
#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <vector>
#include <string>
#pragma warning( disable : 4290 )// disable the exception throwing warning 
using namespace std;
class Person {
protected:
	int id;   //auto generated starting with START_ID
	string name;

	Person(const Person& other);
	const Person& operator= (const Person& other);

public:
	Person(const string& name) throw (const char*);
	virtual ~Person();
	friend std::ostream& operator<< (std::ostream& os, const Person& e);
	bool operator==(const Person& other) const;
	virtual void toOs(std::ostream& os) const;
	int static const START_ID = 100;
	//setters & getters
	void setName(const string& name) throw (const char*);

	int getId() const;
	const string& getName()	const;
};
#endif  // __PERSON_H
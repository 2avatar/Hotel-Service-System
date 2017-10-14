#include "person.h"

int static generatorId = Person::START_ID;

Person::Person(const Person& other) : name(NULL)
{
	*this = other;
}

const Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		Person::id = other.id;
		delete[] name;
		Person::name = _strdup(other.name);
	}
	return *this;
}

Person::Person(const char * name) throw(const char *)
{
	id = generatorId;
	generatorId++;
	setName(name);

}

Person::~Person()
{
	delete[] name;
}

void Person::toOs(std::ostream & os) const 
{
}

void Person::setName(const char * name) throw(const char *)
{
	if (name != nullptr)
		Person::name = _strdup(name);
	else
		throw "Invalid name.\n";
}

int Person::getId() const
{
	return id;
}

const char * Person::getName() const
{
	return name;
}

std::ostream & operator<<(std::ostream & os, const Person & e)
{
	os << "id: " << e.getId() << "\n";
	os << "name: " << e.getName() << "\n";
	e.toOs(os);
	return os;
}

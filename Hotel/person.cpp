#include "person.h"

int static generatorId = Person::START_ID;

Person::Person(const Person& other)
{
	*this = other;
}

const Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		Person::id = other.id;
		Person::name = other.name;
	}
	return *this;
}

Person::Person(const string& name) throw(const char *)
{
	id = generatorId;
	generatorId++;
	setName(name);

}

Person::~Person()
{
}

bool Person::operator==(const Person & other) const
{
		return getId() == other.getId();
}

void Person::toOs(std::ostream & os) const
{
}

void Person::setName(const string& name) throw(const char *)
{
	if (!name.empty())
		Person::name = name;
	else
		throw "Invalid name.\n";
}

int Person::getId() const
{
	return id;
}

const string& Person::getName() const
{
	return name;
}

std::ostream & operator<<(std::ostream & os, const Person & e)
{
	os << "id: " << e.getId() << "\n";
	os << "name: " << e.getName().c_str() << "\n";
	e.toOs(os);
	return os;
}

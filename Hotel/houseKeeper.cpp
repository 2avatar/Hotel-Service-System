#include "houseKeeper.h"

const HouseKeeper & HouseKeeper::operator=(const HouseKeeper & other)
{
	if (this != &other)
		Employee::operator=(other);
	return *this;
}

HouseKeeper::HouseKeeper(const char * name, float salary) throw(const char *) : Employee(name, salary)
{
}

void HouseKeeper::toOs(std::ostream & os) const
{
	os << "Salary: " << salary << "\n";
	os << "Title: HouseKeeper\n";
}

void HouseKeeper::cleanRoom(int roomNumber) const throw(const char *)
{
	if (roomNumber > 0)
		std::cout << getName().c_str() << " is cleaning room number: " << roomNumber << ".\n";
	else
		throw "Invalid room number.\n";
}

void HouseKeeper::cleanAllRooms() const
{
	std::cout << getName().c_str() << " is cleaning all rooms in hotel.\n";
}

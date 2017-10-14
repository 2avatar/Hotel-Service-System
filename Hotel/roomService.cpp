#include "roomService.h"

RoomService::RoomService(const RoomService & other) : Employee(other)
{
	*this = other;
}

const RoomService & RoomService::operator=(const RoomService & other)
{
	if (this != &other)
	{
		Employee::operator=(other);
	}
	return *this;
}

RoomService::RoomService(const char * name, float salary) : Employee(name, salary)
{
}

void RoomService::toOs(std::ostream & os) const
{
	os << "Salary: " << salary << "\n";
	os << "Title: RoomService\n";
}

void RoomService::serveRoom(int roomNumber) const throw(const char *)
{
	if (roomNumber < 0)
		throw "Invalid room number.\n";
	std::cout << "Room number " << roomNumber << " got service from: " << getName() << ".\n";
}

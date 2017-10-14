#include "shiftManager.h"

ShiftManager::ShiftManager(const ShiftManager & other) : Employee(other), Receptionist(other), RoomService(other)
{
	*this = other;
}

const ShiftManager & ShiftManager::operator=(const ShiftManager & other)
{
	if (this != &other) 
	{
		Receptionist::operator=(other);
		RoomService::operator=(other);
	}
	return *this;
}

ShiftManager::ShiftManager(const char * name, float salary) throw(const char *) : Employee(name, salary), RoomService(name, salary), Receptionist(name, salary)
{
}

void ShiftManager::toOs(std::ostream & os) const
{
	os << "Salary: " << salary << "\n";
	os << "Title: Shift Manager\n";
}

void ShiftManager::handleComplaint(int roomNumber, const string& complaint) const throw(const char *)
{
	if (roomNumber > 0)
		std::cout << getName().c_str() << " is handling room number: " << roomNumber << ", complaint saying " << complaint << ".\n";
	else
		throw "Invalid room number.\n";
}

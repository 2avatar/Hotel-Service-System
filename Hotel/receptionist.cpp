#include "receptionist.h"

Receptionist::Receptionist(const Receptionist & other) : Employee(other)
{
	*this = other;
}

const Receptionist & Receptionist::operator=(const Receptionist & other)
{
	if (this != &other)
	{
		Employee::operator=(other);
	}
	return *this;
}

Receptionist::Receptionist(const char * name, float salary) throw(const char *) : Employee(name, salary)
{
}

void Receptionist::toOs(std::ostream & os) const
{
	os << "Salary: " << salary << "\n";
	os << "Title: Receptionist\n";
}

int Receptionist::checkRoomAvailability(int numberOfGuests, vector<Room*> rooms) const throw(const char *) 
{
	if ((numberOfGuests <= 0) || (numberOfGuests > Room::MAX_NUM_OF_BEDS))
		throw "Invalid number of guests.\n";
	
	vector<Room*>::const_iterator itrBegin = rooms.begin();
	vector<Room*>::const_iterator itrEnd = rooms.end();
	for (; itrBegin != itrEnd; ++itrBegin)
	{
		if ((*itrBegin)->getNumOfBeds() >= numberOfGuests)
		{
			if ((*itrBegin)->getNumberOfGuests() == 0)
				return (*itrBegin)->getRoomNumber();
		}
	}

	return NO_ROOM_AVAILBLE;
}

void Receptionist::collectPayment(int roomNumber, float amount) throw(const char *)
{
	if ((amount <= 0) || (roomNumber <= 0))
		throw "Invalid payment params.\n";
	std::cout << "payment " << amount << " from room number: " << roomNumber << " has been collected.\n";
}
